#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

//v1 
bool isInterleave(char * s1, char * s2, char * s3){
  if (NULL == s1) {
      return strcmp(s2, s3);
  }

  if (NULL == s2) {
      return strcmp(s1, s3);
  }

  if (NULL == s3) {
      return false;
  }
  if (strlen(s1) + strlen(s2) != strlen(s3)) {
      return false;
  }

  while(*s3) {
    if((*s1 == *s3) || (*s2 == *s3)) {
       (*s1 == *s3) ? s1++ : s2++;
       s3++;
    }else {
        return false;
    }

  }
  return true;
}
