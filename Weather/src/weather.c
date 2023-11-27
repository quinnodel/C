#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <cJSON.h>
#include <string.h>

// need a structure to hold the latitude and longitude data
// need a function to parse the JSON and return the lattitude and longitude

typedef struct
{
    double latitude;
    double longitude;
} LatLong;

// now a function that returns a LatLong struct with the JSON data

LatLong parseLatLong(const char *json_string)
{
    LatLong latlong = {0, 0}; // initialize the default struct

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

int main(void)
{
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL; // Declare a list to hold HTTP headers

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl)
    {
        // Set the URL to IPinfo API endpoint
        curl_easy_setopt(curl, CURLOPT_URL, "https://ipinfo.io/json");

        // Add the Authorization header with your token
        headers = curl_slist_append(headers, "Authorization: 946421b30f902f"); // Replace with your actual token
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Direct output to stdout
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_slist_free_all(headers); // Free the header list
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}
