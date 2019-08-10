#ifndef CURLREQUEST_H
#define CURLREQUEST_H

#include <functional>
#include <unistd.h>
#include <string>
#include <map>
#include <curl/curl.h>

/**
 * @brief curl请求类
 */
class CurlRequest
{
public:
    CurlRequest();

    void request(const std::string &url,const std::map<char*,char*> &headers);
    void response();

private :
    CURL * m_curl =nullptr;
};

#endif // CURLREQUEST_H
