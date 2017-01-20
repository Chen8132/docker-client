
#include "connection.h"

#include <curl/curl.h>

#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <stdexcept>

#include "restclient.h"
#include "callbacks.h"
#include "version.h"


RestClient::Connection::Connection(const std::string baseUrl)
                               : lastRequest(), headerFields() {
  this->curlHandle = curl_easy_init();
  if (!this->curlHandle) {
    throw std::runtime_error("Couldn't initialize curl handle");
  }
  this->baseUrl = baseUrl;
}

RestClient::Connection::~Connection() {
  if (this->curlHandle) {
    curl_easy_cleanup(this->curlHandle);
  }
}

RestClient::Connection::Info RestClient::Connection::GetInfo() {
  RestClient::Connection::Info ret;
  ret.baseUrl = this->baseUrl;
  ret.headers = this->GetHeaders();
  ret.timeout = this->timeout;
  ret.basicAuth.username = this->basicAuth.username;
  ret.basicAuth.password = this->basicAuth.password;
  ret.customUserAgent = this->customUserAgent;
  ret.lastRequest = this->lastRequest;

  return ret;
}


void RestClient::Connection::AppendHeader(const std::string& key,
                                     const std::string& value) {
  this->headerFields[key] = value;
}

void RestClient::Connection::SetHeaders(RestClient::HeaderFields headers) {
  this->headerFields = headers;
}


RestClient::HeaderFields RestClient::Connection::GetHeaders() {
  return this->headerFields;
}


void RestClient::Connection::FollowRedirects(bool follow) {
  this->followRedirects = follow;
}

void RestClient::Connection::SetUserAgent(const std::string& userAgent) {
  this->customUserAgent = userAgent;
}


std::string RestClient::Connection::GetUserAgent() {
  std::string prefix;
  if (this->customUserAgent.length() > 0) {
    prefix = this->customUserAgent + " ";
  }
  return std::string(prefix + "" + RESTCLIENT_VERSION);
}

void RestClient::Connection::SetTimeout(int seconds) {
  this->timeout = seconds;
}

void RestClient::Connection::SetBasicAuth(const std::string& username,
                                     const std::string& password) {
  this->basicAuth.username = username;
  this->basicAuth.password = password;
}


RestClient::Response RestClient::Connection::performCurlRequest(const std::string& uri) {
  // init return type
  RestClient::Response ret = {};

  std::string url = std::string(this->baseUrl + uri);
  std::string headerString;
  CURLcode res = CURLE_OK;
  curl_slist* headerList = NULL;

  if(url.find("http://127.0.0.1/") == 0){
    
     curl_easy_setopt(this->curlHandle, CURLOPT_UNIX_SOCKET_PATH, "/var/run/docker.sock");
  }
  
  /** set query URL */
  curl_easy_setopt(this->curlHandle, CURLOPT_URL, url.c_str());
  /** set callback function */
  curl_easy_setopt(this->curlHandle, CURLOPT_WRITEFUNCTION,
                   Callbacks::write_callback);
  /** set data object to pass to callback function */
  curl_easy_setopt(this->curlHandle, CURLOPT_WRITEDATA, &ret);
  /** set the header callback function */
  curl_easy_setopt(this->curlHandle, CURLOPT_HEADERFUNCTION,
                   Callbacks::header_callback);
  /** callback object for headers */
  curl_easy_setopt(this->curlHandle, CURLOPT_HEADERDATA, &ret);
  /** set http headers */
  for (HeaderFields::const_iterator it = this->headerFields.begin();
      it != this->headerFields.end(); ++it) {
    headerString = it->first;
    headerString += ": ";
    headerString += it->second;
    headerList = curl_slist_append(headerList, headerString.c_str());
  }
  curl_easy_setopt(this->curlHandle, CURLOPT_HTTPHEADER,
      headerList);

  // set basic auth if configured
  if (this->basicAuth.username.length() > 0) {
    std::string authString = std::string(this->basicAuth.username + ":" +
                                         this->basicAuth.password);
    curl_easy_setopt(this->curlHandle, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
    curl_easy_setopt(this->curlHandle, CURLOPT_USERPWD, authString.c_str());
  }
  /** set user agent */
  curl_easy_setopt(this->curlHandle, CURLOPT_USERAGENT,
                   this->GetUserAgent().c_str());

  // set timeout
  if (this->timeout) {
    curl_easy_setopt(this->curlHandle, CURLOPT_TIMEOUT, this->timeout);
    // dont want to get a sig alarm on timeout
    curl_easy_setopt(this->curlHandle, CURLOPT_NOSIGNAL, 1);
  }
  // set follow redirect
  if (this->followRedirects == true) {
    curl_easy_setopt(this->curlHandle, CURLOPT_FOLLOWLOCATION, 1L);
  }
  res = curl_easy_perform(this->curlHandle);
  if (res != CURLE_OK) {
    if (res == CURLE_OPERATION_TIMEDOUT) {
      ret.code = res;
      ret.body = "Operation Timeout.";
    } else {
      ret.body = "Failed to query.";
      ret.code = -1;
    }
  } else {
    int64_t http_code = 0;
    curl_easy_getinfo(this->curlHandle, CURLINFO_RESPONSE_CODE, &http_code);
    ret.code = static_cast<int>(http_code);
  }

  curl_easy_getinfo(this->curlHandle, CURLINFO_TOTAL_TIME,
                    &this->lastRequest.totalTime);
  curl_easy_getinfo(this->curlHandle, CURLINFO_NAMELOOKUP_TIME,
                    &this->lastRequest.nameLookupTime);
  curl_easy_getinfo(this->curlHandle, CURLINFO_CONNECT_TIME,
                    &this->lastRequest.connectTime);
  curl_easy_getinfo(this->curlHandle, CURLINFO_APPCONNECT_TIME,
                    &this->lastRequest.appConnectTime);
  curl_easy_getinfo(this->curlHandle, CURLINFO_PRETRANSFER_TIME,
                    &this->lastRequest.preTransferTime);
  curl_easy_getinfo(this->curlHandle, CURLINFO_STARTTRANSFER_TIME,
                    &this->lastRequest.startTransferTime);
  curl_easy_getinfo(this->curlHandle, CURLINFO_REDIRECT_TIME,
                    &this->lastRequest.redirectTime);
  curl_easy_getinfo(this->curlHandle, CURLINFO_REDIRECT_COUNT,
                    &this->lastRequest.redirectCount);
  // free header list
  curl_slist_free_all(headerList);
  // reset curl handle
  curl_easy_reset(this->curlHandle);
  return ret;
}


RestClient::Response RestClient::Connection::get(const std::string& url) {
  return this->performCurlRequest(url);
}

RestClient::Response RestClient::Connection::post(const std::string& url,
                             const std::string& data) {
  /** Now specify we want to POST data */
  curl_easy_setopt(this->curlHandle, CURLOPT_POST, 1L);
  /** set post fields */
  curl_easy_setopt(this->curlHandle, CURLOPT_POSTFIELDS, data.c_str());
  curl_easy_setopt(this->curlHandle, CURLOPT_POSTFIELDSIZE, data.size());

  return this->performCurlRequest(url);
}

RestClient::Response RestClient::Connection::put(const std::string& url,
                            const std::string& data) {
  /** initialize upload object */
  RestClient::Callbacks::UploadInfo up_obj;
  up_obj.data = data.c_str();
  up_obj.length = data.size();

  /** Now specify we want to PUT data */
  curl_easy_setopt(this->curlHandle, CURLOPT_PUT, 1L);
  curl_easy_setopt(this->curlHandle, CURLOPT_UPLOAD, 1L);
  /** set read callback function */
  curl_easy_setopt(this->curlHandle, CURLOPT_READFUNCTION,
                   RestClient::Callbacks::read_callback);
  /** set data object to pass to callback function */
  curl_easy_setopt(this->curlHandle, CURLOPT_READDATA, &up_obj);
  /** set data size */
  curl_easy_setopt(this->curlHandle, CURLOPT_INFILESIZE,
                     static_cast<int64_t>(up_obj.length));

  return this->performCurlRequest(url);
}

RestClient::Response RestClient::Connection::del(const std::string& url) {
  /** we want HTTP DELETE */
  const char* http_delete = "DELETE";

  /** set HTTP DELETE METHOD */
  curl_easy_setopt(this->curlHandle, CURLOPT_CUSTOMREQUEST, http_delete);

  return this->performCurlRequest(url);
}

