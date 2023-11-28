/*---------------------
Author : Quinn Hiaasen
----------------------*/

/*
TODO
- write function to parse and assemble the API request
    so that the parseLatLong function can function

*/

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <cJSON.h>
#include <string.h>

/*

*/
typedef struct
{
    double latitude;
    double longitude;
} LatLong;

/*

*/
void printLatLong(LatLong ll)
{
    printf("Your latitude is: %f\n", ll.latitude);
    printf("Your longitude is: %f\n", ll.longitude);
}

/*

*/
LatLong parseLatLong(const char *json_string)
{
    LatLong latlong = {0, 0};
    cJSON *json = cJSON_Parse(json_string);

    if (json == NULL)
    {
        const char *err_ptr = cJSON_GetErrorPtr();
        if (err_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", err_ptr);
        }
    }

    const cJSON *location = cJSON_GetObjectItemCaseSensitive(json, "loc");
    if (cJSON_IsString(location) && (location->valuestring != NULL))
    {
        char *token = strtok(location->valuestring, ",");
        double latitude = atof(token);
        token = strtok(NULL, ",");
        double longitude = atof(token);
        latlong.latitude = latitude;
        latlong.longitude = longitude;
    }

    cJSON_Delete(json);
    return latlong;
}

/*

*/
LatLong getLocation()
{
    LatLong latlong = {0, 0};
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL; // Declare a list to hold HTTP headers

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl)
    {
        headers = curl_slist_append(headers, "Authorization: 946421b30f902f");

        curl_easy_setopt(curl, CURLOPT_URL, "https://ipinfo.io/json"); // LibCurl documentation for help here
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        LatLong latlong = parseLatLong(res);

        return latlong;

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

/*
ENTRY POINT
*/
int main(void)
{
    LatLong ll = getLocation();
    printLatLong(ll);
    return 0;
}
