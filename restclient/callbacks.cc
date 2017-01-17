#include "callbacks.h"
#include <cstring>
#include "restclient.h"

size_t RestClient::Callbacks::write_callback(void *data, size_t size,
                                           size_t nmemb, void *userdata) {
  RestClient::Response* r;
  r = reinterpret_cast<RestClient::Response*>(userdata);
  r->body.append(reinterpret_cast<char*>(data), size*nmemb);

  return (size * nmemb);
}


size_t RestClient::Callbacks::header_callback(void *data, size_t size,
                                            size_t nmemb, void *userdata) {
  RestClient::Response* r;
  r = reinterpret_cast<RestClient::Response*>(userdata);
  std::string header(reinterpret_cast<char*>(data), size*nmemb);
  size_t seperator = header.find_first_of(":");
  if ( std::string::npos == seperator ) {
    // roll with non seperated headers...
    trim(header);
    if (0 == header.length()) {
      return (size * nmemb);  // blank line;
    }
    r->headers[header] = "present";
  } else {
    std::string key = header.substr(0, seperator);
    trim(key);
    std::string value = header.substr(seperator + 1);
    trim(value);
    r->headers[key] = value;
  }

  return (size * nmemb);
}

size_t RestClient::Callbacks::read_callback(void *data, size_t size,
                                          size_t nmemb, void *userdata) {
  RestClient::Callbacks::UploadInfo* u;
  u = reinterpret_cast<RestClient::Callbacks::UploadInfo*>(userdata);
  size_t curl_size = size * nmemb;
  size_t copy_size = (u->length < curl_size) ? u->length : curl_size;
  std::memcpy(data, u->data, copy_size);
  u->length -= copy_size;
  u->data += copy_size;
  return copy_size;
}
