#include <stdio.h>

int get_size(char *pattern){
  char ch = pattern[0];
  int size = 0;

  while(ch != '\0'){
    pattern[size++];
  }

  return size;
}

void hello(char *str, char *pattern){
  char ch = ' ';

  int ch_ind = 0;
  int pattern_size = get_size(pattern);

  while(ch != '\0'){
    printf("%c", ch);
    ch = str[ch_ind++];
    if(ch == pattern[ch_ind]){
      ch_ind += 1;
      if(ch_ind == pattern_size){
        
      }

    } else {
      ch_ind = 0;
    }
  }
}
