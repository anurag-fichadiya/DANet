#include <stdio.h>
#include <regex.h>
#include <curl/curl.h>

#define INTRANET_URL "http://intranet.daiict.ac.in/~daiict_nt01/"

int main(void)
{
  CURL *curl;
  CURLcode res;

  char *url;

  int i = 0;
  const char *dirs[2];
  dirs[0] = "blah";
  dirs[1] = "umm";

  curl = curl_easy_init();
  if(curl) {
    for(i = 0; i < 2; i++){
      curl_easy_setopt(curl, CURLOPT_URL, INTRANET_URL);
      res = curl_easy_perform(curl);

      if(CURLE_OK == res) {
        char *ct;
        res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);

        if((CURLE_OK == res) && ct)
          printf("We received Content-Type: %s\n", ct);
        else
          printf("Error");
      }
    }

    curl_easy_cleanup(curl);
  }
  return 0;
}
