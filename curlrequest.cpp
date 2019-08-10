#include "curlrequest.h"
#include <string.h>

CurlRequest::CurlRequest()
{
    CURLcode curCode = curl_global_init(CURL_GLOBAL_ALL);
    printf("hello %d\n",(uint32_t) curCode);

    curl_version_info_data * data =curl_version_info(CURLVERSION_NOW);
    if(data){
        printf("version %s, version num = %u, features = %x\n",data->version,data->version_num, data->features);
    }

}

size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
    fprintf(stderr,"writeFunction\n");fflush(stderr);
    data->append(static_cast<char*>(ptr), size * nmemb);
    return size * nmemb;
}

void CurlRequest::request(const std::string &url,const std::map<char*,char*> &headers)
{
    m_curl = curl_easy_init();

    std::string response_string;
    std::string header_string;

    curl_easy_setopt(m_curl,CURLOPT_URL,url.data());
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(m_curl, CURLOPT_HEADERDATA, &header_string);

    CURLcode curl_error =    curl_easy_perform(m_curl);
    fprintf(stderr,"curl_error %d\n",(uint32_t) curl_error);
    fprintf(stderr,"response :%s \n",response_string.c_str());fflush(stderr);
#if 0
    auto version_info = curl_version_info(CURLVERSION_NOW);
    auto version = std::string{"curl/"} + std::string{version_info->version};
    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, version.data());
    curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(m_curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(m_curl, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(m_curl, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(m_curl, CURLOPT_NOBODY, 0L);
    curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "POST");
#endif
}
