#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mylen(char *d){
  int len = 0;
  while (*d){
    len++;
    d++;
  }
  return len;
}

char * mycpy(char *dest, char *src){
  while (*src){
    *dest = *src;
    src++;
    dest++;
  }
  *dest = 0;
  return dest;
}

char * myncat(char *dest, char *src, int n){
  char *p = &(dest[mylen(dest)]);
  while (*src && n){
    *p = *src;
    p++;
    src++;
    n--;
  }
  *p = 0;
  return dest;
}

int mycmp(char * s1, char * s2){
  if (*s1 > *s2)
    return 1;
  else if (*s2 > *s1)
    return -1;
  else if (!(*s1 || *s2))
    return 0;
  else return mycmp(++s1, ++s2);
}

int main(){
  char a[] = "horseman";
  mycpy(a, "goose");
  printf("copy test: goose = %s\n", a);

  char b[10] = "cat";
  myncat(b, "fishmonger", 4);
  printf("cat test: catfish = %s\n", b);

  char c[] = "goose";
  printf("comp test: %d\n", mycmp(c, "moose"));
  return 0;
}
