#include <stdio.h>
#include <libgen.h>
#include <curl/curl.h>


int main(int argc, char* args[]){

  if(argc != 2){
    printf("Please give url\n");
    return 0;
  }
  // take url;
  char *url = args[1];

  CURL *curl;
  CURLcode res;
  FILE *fp;

  curl = curl_easy_init();
  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, url);

    char *output = basename(args[1]);
    fp = fopen(output, "wb");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    res = curl_easy_perform(curl);
    if(res != CURLE_OK){
      fprintf(stderr, "Could not download file: %s\n", curl_easy_strerror(res));
    }

    // Cleanup
    curl_easy_cleanup(curl);
  }
  return 0;
}
