/*---------------------
Author : Quinn Hiaasen
----------------------*/

/*
TODO
---------------------------
* write function to parse and assemble the API request
    so that the parseLatLong function can function

*/

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <cJSON.h>
#include <string.h>

/*
Struct: LatLong
---------------
* contains two doubles for lat/long
*/
typedef struct
{
    double latitude;
    double longitude;
} LatLong;

/*
Function: printLatLong()
------------------------
* prints latitude and longitude to console
*/
void printLatLong(LatLong ll)
{
    printf("Your latitude is: %f\n", ll.latitude);
    printf("Your longitude is: %f\n", ll.longitude);
}

/*
Function: parseLatLong()
------------------------
* makes use of cJSON to parse the JSON string
* obtained in the API request
* returns a LatLong object
*/
LatLong parseLatLong(const char *json_string)
{
    LatLong latlong = {0, 0};
    cJSON *json = cJSON_Parse(json_string); // returns a pointer to a cJSON object

    if (json == NULL) // if parse was unsuccessful
    {
        const char *err_ptr = cJSON_GetErrorPtr();
        if (err_ptr != NULL)
        {
            fprintf(stderr, "Error before: %s\n", err_ptr);
        }
    }

    const cJSON *location = cJSON_GetObjectItemCaseSensitive(json, "loc"); // pointer to a cJSON object key/value pair
    if (cJSON_IsString(location) && (location->valuestring != NULL))
    {
        char *token = strtok(location->valuestring, ","); // pointer to a char arr with the [lat,long] data?
        double latitude = atof(token);                    // typecasting the latitude as a double, but the whole token?
        token = strtok(NULL, ",");                        // I do not understand what's going on here
        double longitude = atof(token);
        latlong.latitude = latitude;   // this, yes and I only acces the members this way because I'm not
        latlong.longitude = longitude; // manipulate a pointer to a struct right?
    }

    cJSON_Delete(json);
    return latlong;
}

/*
Function: getLocation()
-----------------------
* uses libcurl to make an API call to IPInfo
* returns a LatLong struct containing the data
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
