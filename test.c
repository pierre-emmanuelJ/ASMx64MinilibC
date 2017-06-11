/*
** test.c for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Mar  9 15:50:17 2017 Pierre-Emmanuel Jacquier
** Last update Sun Jun 11 23:26:27 2017 Pierre-Emmanuel Jacquier
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

size_t strlen(const char *s);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *rindex(const char *s, int c);
char *strchr(const char *s, int c);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
char *strstr(const char *haystack, const char *needle);
char *strpbrk(const char *s, const char *accept);
size_t strcspn(const char *s, const char *reject);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);

int main()
{
  int ret;

  printf("***** TEST begin *****\n");
  assert(strlen("") == strlen(""));
  assert(strlen("hello") == strlen("hello"));
  assert(strlen("h") == strlen("h"));
  assert(strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

  ret = strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd"));
  ret = strcmp("", "");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("", ""));
  ret = strcmp("aaa", "aa");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("aaa", "aa"));
  ret = strcmp("ac", "dc");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("ac", "dc"));


  char *s1;
  char *s2;

  s1 = malloc(50);
  s2 = malloc(50);

  sprintf(s1, "test");
  sprintf(s2, "test");

  s1 = rindex(s1, 's');
  s2 = rindex(s2, 's');
  assert(!strcmp(s1, s2));


  s1 = malloc(50);
  s2 = malloc(50);

  sprintf(s1, "test");
  sprintf(s2, "test");

  s1 = rindex(s1, 't');
  s2 = rindex(s2, 't');
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  sprintf(s1, "test");
  sprintf(s2, "test");


  s1 = rindex(s1, 'f');
  s2 = rindex(s2, 'f');
  assert(s1 == NULL && s2 == NULL);

  s1 = malloc(50);
  s2 = malloc(50);
  sprintf(s1, "hello");
  sprintf(s2, "hello");

  s1 = rindex(s1, 0);
  s2 = rindex(s2, 0);
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  s1[0] = 0;
  s2[0] = 0;

  s1 = rindex(s1, 0);
  s2 = rindex(s2, 0);
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  *s1 = 0;
  *s2 = 0;

  s1 = rindex(s1, 'z');
  s2 = rindex(s2, 'z');
  assert(s1 == NULL && s2 == NULL);


  s1 = malloc(50);
  s2 = malloc(50);
  sprintf(s1, "test");
  sprintf(s2, "test");

  s1 = strchr(s1, 's');
  s2 = strchr(s2, 's');
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  sprintf(s1, "test");
  sprintf(s2, "test");


  s1 = strchr(s1, 't');
  s2 = strchr(s2, 't');
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  sprintf(s1, "test");
  sprintf(s2, "test");


  s1 = strchr(s1, 'f');
  s2 = strchr(s2, 'f');
  assert(s1 == NULL && s2 == NULL);

  s1 = malloc(50);
  s2 = malloc(50);
  sprintf(s1, "hello");
  sprintf(s2, "hello");


  s1 = strchr(s1, 0);
  s2 = strchr(s2, 0);
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  *s1 = 0;
  *s2 = 0;


  s1 = strchr(s1, 0);
  s2 = strchr(s2, 0);
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  *s1 = 0;
  *s2 = 0;

  s1 = strchr(s1, 'z');
  s2 = strchr(s2, 'z');
  assert(s1 == NULL && s2 == NULL);

  s1 = malloc(12);
  s2 = malloc(12);
  sprintf(s1, "hello test\n");
  sprintf(s2, "hello test\n");
  assert(!strcmp(s1, s2));

  memset(s1, 'Z', 11);
  memset(s2, 'Z', 11);
  assert(!strcmp(s1, s2));

  s1 = malloc(50);
  s2 = malloc(50);
  *s1 = 0;
  *s2 = 0;

  assert(!strcmp(s1, s2));
  memset(s1, 0, 11);
  memset(s2, 0, 11);
  assert(!strcmp(s1, s2));


  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "fdjsfkljs");
  assert(s1 == NULL);

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "k");
  assert(s1 == NULL);


  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "tes");
  assert(!strcmp(s1, "test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "llo");
  assert(!strcmp(s1, "llo test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "h");
  assert(!strcmp(s1, "hello test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "t");
  assert(!strcmp(s1, "test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "he");
  assert(!strcmp(s1, "hello test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "lo");
  assert(!strcmp(s1, "lo test"));

  s1 = malloc(12);
  sprintf(s1, "h");
  s1 = strstr(s1, "h");
  assert(!strcmp(s1, "h"));


  s1 = malloc(12);
  *s1 = 0;
  s1 = strstr(s1, "");
  if (s1 == NULL)
    printf("NULL\n");
  else
    assert(!strcmp(s1, ""));

  s1 = malloc(12);
  *s1 = 0;
  s1 = strstr(s1, "");
  if (s1 == NULL)
    printf("NULL\n");
  else
    assert(!strcmp(s1, ""));


  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = strstr(s1, "hello test");
  assert(!strcmp(s1, "hello test"));

  s1 = strstr(NULL, NULL);
  assert(s1 == NULL);


  ret = strncmp("aaaaaaaaaaaaaaaa", "aaaadddddd", 3);
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("aaaaaaaaaaaaaaaa", "aaaadddddd", 3));
  ret = strncmp("", "", 1);
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("", "", 1));
  ret = strncmp("aaa", "aa", 1);
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("aaa", "aa", 2));
  ret = strncmp("ac", "dc", 9);
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("ac", "dc", 9));

  char  *st = malloc(50);
  sprintf(st, "hello world\n");
  char *res = strpbrk(st, "om");
  char *res2 = strpbrk(st, "om");
  assert(!strcmp(res, res2));


  size_t test1 = strcspn(st, "l");
  size_t test2 = strcspn(st, "l");
  assert(test1 == test2);

  test1 = strcspn(st, "k");
  test2 = strcspn(st, "k");
  assert(test1 == test2);

  test1 = strcspn(st, "ol");
  test2 = strcspn(st, "ol");
  assert(test1 == test2);


  test1 = strcspn(st, "");
  test2 = strcspn(st, "");
  assert(test1 == test2);


  test1 = strcspn(st, "jfk");
  test2 = strcspn(st, "jfk");
  assert(test1 == test2);


  test1 = strcspn(st, "d");
  test2 = strcspn(st, "d");
  assert(test1 == test2);


  s1 = malloc(50);
  s2 = malloc(50);
  sprintf(s1, "hello test");
  sprintf(s2, "hello test");

  s1 = memcpy(s1, s1 + 5, 5);
  s2 = memcpy(s2, s2 + 5, 5);

  assert(!strcmp(s1, s2));

  char *out1;
  char *out2;

  char *test11 = malloc(50);
  char *test22 = malloc(50);
  out1 = malloc(50);
  out2 = malloc(50);
  sprintf(out2, "gros con");
  sprintf(out1, "gros con");
  sprintf(test11, "hello world");
  sprintf(test22, "hello world");

  assert(!strcmp(memmove(out1, test11, 5), memmove(out2, test22, 5)));


  test11 = malloc(50);
  test22 = malloc(50);

  sprintf(test11, "hello world");
  sprintf(test22, "hello world");

  assert(!strcmp(memmove(test11, test11 + 2, 5), memmove(test22, test22 + 2, 5)));

  test11 = malloc(50);
  test22 = malloc(50);

  sprintf(test11, "hello world");
  sprintf(test22, "hello world");

  assert(!strcmp(memmove(test11 + 2, test11, 5), memmove(test22 + 2, test22, 5)));

  printf("%s\n", "--------------ALL TEST PASSED--------------");
  printf("***** TEST end *****\n");
  return 0;
}
