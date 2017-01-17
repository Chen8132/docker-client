
#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <string>
#include <algorithm>
#include <functional>

#include "version.h"

namespace RestClient {

namespace Callbacks {

  typedef struct {
    const char* data;
    size_t length;
  } UploadInfo;

  // writedata callback function
  size_t write_callback(void *ptr, size_t size, size_t nmemb,
                              void *userdata);

  // header callback function
  size_t header_callback(void *ptr, size_t size, size_t nmemb,
                                void *userdata);
  // read callback function
  size_t read_callback(void *ptr, size_t size, size_t nmemb,
                              void *userdata);

  // trim from start
  static inline std::string &ltrim(std::string &s) {  // NOLINT
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
          std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
  }

  // trim from end
  static inline std::string &rtrim(std::string &s) { // NOLINT
    s.erase(std::find_if(s.rbegin(), s.rend(),
          std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
  }

  // trim from both ends
  static inline std::string &trim(std::string &s) {  // NOLINT
    return ltrim(rtrim(s));
  }
};  // namespace Helpers

};  // namespace RestClient

#endif  // INCLUDE_RESTCLIENT_CPP_HELPERS_H_
