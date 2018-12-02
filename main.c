#include <stdio.h>
#include <regex.h>
#include <curl/curl.h>

#define INTRANET_URL "http://intranet.daiict.ac.in/~daiict_nt01/"

int main(void)
{
  CURL *curl;
  CURLcode res;

  int i = 0;
  const char *dirs[2];
  dirs[0] = "blah";
  dirs[1] = "umm";

  for(i = 0; i < 2; i++){
    printf("%s\n", dirs[i]);
  }

  regex_t regex;
  int reti;
  char msgbuf[100];

  reti = regcomp(&regex, "^[[:alnum:]]a[[:alnum:]]", 0);
  if(reti){
    fprintf(stderr, "Could not compile regex\n");
    return 1;
  }


  // Execute regular expression
  reti = regexec(&regex, "helloabc", 0, NULL, 0);
  if(!reti){
    printf("%d\n", reti);
  }
  else if(reti == REG_NOMATCH){
    puts("No Match");
  } else {
    regerror(reti, &regex, msgbuf, sizeof(msgbuf));
    fprintf(stderr, "Regex match failed: %s\n", msgbuf);
    return 1;
  }

  regfree(&regex);
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

