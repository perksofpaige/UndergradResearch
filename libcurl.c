//
//  main.c
//  Lib_C_Script
//
//  Created by Paige Lee on 10/15/19.
//  Copyright © 2019 Paige Lee. All rights reserved.
//

#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

int main(){
    
    CURL *curl;
    CURLcode res;
        char *url = "http://www.youtube.com";

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        //youtube.com is redirected, so we tell libcurl to follow redirection
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        //Perform the request, res will get the return code
        res = curl_easy_perform(curl);
        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
        ///always cleanup
        curl_easy_cleanup(curl);
    }
    return 0;
}
