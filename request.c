//
// Created by sid on 9/9/24.
//

#include "request.h"

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>


static size_t mem_write(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    HTTP_Response *mem = (HTTP_Response *)userp;
    char *ptr = realloc(mem->buffer, mem->size + realsize + 1);
    if (ptr == NULL) {
        printf("Out of memory\n");
        return -1;
    }

    mem->buffer = ptr;
    memcpy(&(mem->buffer[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->buffer[mem->size] = 0;

    return realsize;
}

void http_get(const char *url, HTTP_Response *http_response) {
    CURL *curl_handle;
    CURLcode  res;
    http_response->buffer = malloc(1);
    http_response->size = 0;

    curl_global_init(CURL_GLOBAL_ALL);

    curl_handle = curl_easy_init();

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, mem_write);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)http_response);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "custom-agent");

    res = curl_easy_perform(curl_handle);

    if(res != CURLE_OK){
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
}