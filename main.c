#include <stdio.h>

#include "cJSON.h"

#include "request.h"
#include "constants.h"

int main(int argc, char** args) {
    HTTP_Response response;
    http_get(URL_FACTION_LIST, &response);
//    printf("\nresp:\n%s", response.buffer);
    cJSON *parsed = cJSON_Parse(response.buffer);
    char *string = cJSON_Print(parsed);
    printf("%s\n", string);

    cJSON_Delete(parsed);
    return 0;
}
