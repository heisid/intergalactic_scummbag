//
// Created by sid on 9/9/24.
//

#ifndef INTERGALACTIC_SCUMMBAG_REQUEST_H
#define INTERGALACTIC_SCUMMBAG_REQUEST_H

#include <stddef.h>

typedef struct HTTP_Response {
    char *buffer;
    size_t size;
} HTTP_Response;

void http_get(const char *url, HTTP_Response *http_response);

#endif //INTERGALACTIC_SCUMMBAG_REQUEST_H
