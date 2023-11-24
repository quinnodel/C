/*---------------------
Author : Quinn Hiaasen
----------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
    // CURL is not hard, its just new

    CURL* curl = curl_easy_init(); // we need a pointer to a curl handle
    
    if (curl)
    {
        char* url = "";
        CURLcode curl_easy_setopt(curl, CURLOPT_URL, url); // CURLcode is a status code




        curl_easy_cleanup(curl);
    }

    return 0;
}
