/*
** test.c for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Mar  9 15:50:17 2017 Pierre-Emmanuel Jacquier
** Last update Thu Mar 23 16:33:36 2017 Pierre-Emmanuel Jacquier
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_rindex(const char *s, int c);
char *my_strchr(const char *s, int c);
void *my_memmove(void *dest, const void *src, size_t n);
void *my_memset(void *s, int c, size_t n);
char *my_strstr(const char *haystack, const char *needle);
char *my_strpbrk(const char *s, const char *accept);
size_t my_strcspn(const char *s, const char *reject);
void *my_memcpy(void *dest, const void *src, size_t n);

int main()
{
  // int ret;
  //
  // printf("***** TEST begin *****\n");
  // assert(my_strlen("") == strlen(""));
  // assert(my_strlen("hello") == strlen("hello"));
  // assert(my_strlen("h") == strlen("h"));
  // assert(my_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
  //
  // ret = my_strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd");
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd"));
  // ret = my_strcmp("", "");
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("", ""));
  // ret = my_strcmp("aaa", "aa");
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("aaa", "aa"));
  // ret = my_strcmp("ac", "dc");
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("ac", "dc"));
  //
  //
  // char *s1;
  // char *s2;
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  //
  // sprintf(s1, "test");
  // sprintf(s2, "test");
  //
  // s1 = rindex(s1, 's');
  // s2 = my_rindex(s2, 's');
  // assert(!strcmp(s1, s2));
  //
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  //
  // sprintf(s1, "test");
  // sprintf(s2, "test");
  //
  // s1 = rindex(s1, 't');
  // s2 = my_rindex(s2, 't');
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // sprintf(s1, "test");
  // sprintf(s2, "test");
  //
  //
  // s1 = rindex(s1, 'f');
  // s2 = my_rindex(s2, 'f');
  // assert(s1 == NULL && s2 == NULL);
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // sprintf(s1, "hello");
  // sprintf(s2, "hello");
  //
  // s1 = rindex(s1, 0);
  // s2 = my_rindex(s2, 0);
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // s1[0] = 0;
  // s2[0] = 0;
  //
  // s1 = rindex(s1, 0);
  // s2 = my_rindex(s2, 0);
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // *s1 = 0;
  // *s2 = 0;
  //
  // s1 = rindex(s1, 'z');
  // s2 = my_rindex(s2, 'z');
  // assert(s1 == NULL && s2 == NULL);
  //
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // sprintf(s1, "test");
  // sprintf(s2, "test");
  //
  // s1 = strchr(s1, 's');
  // s2 = my_strchr(s2, 's');
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // sprintf(s1, "test");
  // sprintf(s2, "test");
  //
  //
  // s1 = strchr(s1, 't');
  // s2 = my_strchr(s2, 't');
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // sprintf(s1, "test");
  // sprintf(s2, "test");
  //
  //
  // s1 = strchr(s1, 'f');
  // s2 = my_strchr(s2, 'f');
  // assert(s1 == NULL && s2 == NULL);
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // sprintf(s1, "hello");
  // sprintf(s2, "hello");
  //
  //
  // s1 = strchr(s1, 0);
  // s2 = my_strchr(s2, 0);
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // *s1 = 0;
  // *s2 = 0;
  //
  //
  // s1 = strchr(s1, 0);
  // s2 = my_strchr(s2, 0);
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // *s1 = 0;
  // *s2 = 0;
  //
  // s1 = strchr(s1, 'z');
  // s2 = my_strchr(s2, 'z');
  // assert(s1 == NULL && s2 == NULL);
  //
  // s1 = malloc(12);
  // s2 = malloc(12);
  // sprintf(s1, "hello test\n");
  // sprintf(s2, "hello test\n");
  // assert(!strcmp(s1, s2));
  //
  // my_memset(s1, 'Z', 11);
  // memset(s2, 'Z', 11);
  // assert(!strcmp(s1, s2));
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // *s1 = 0;
  // *s2 = 0;
  //
  // assert(!strcmp(s1, s2));
  // my_memset(s1, 0, 11);
  // memset(s2, 0, 11);
  // assert(!strcmp(s1, s2));

  char *s1;

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "fdjsfkljs");
  assert(s1 == NULL);

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "k");
  assert(s1 == NULL);


  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "tes");
  assert(!strcmp(s1, "test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "llo");
  assert(!strcmp(s1, "llo test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "h");
  assert(!strcmp(s1, "hello test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "t");
  assert(!strcmp(s1, "test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "he");
  assert(!strcmp(s1, "hello test"));

  s1 = malloc(12);
  sprintf(s1, "hello test");
  s1 = my_strstr(s1, "lo");
  assert(!strcmp(s1, "lo test"));

  s1 = malloc(12);
  sprintf(s1, "h");
  s1 = my_strstr(s1, "h");
  assert(!strcmp(s1, "h"));


  s1 = malloc(12);
  *s1 = 0;
  s1 = my_strstr(s1, "");
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
  s1 = my_strstr(s1, "hello test");
  assert(!strcmp(s1, "hello test"));

  s1 = my_strstr(NULL, NULL);
  assert(s1 == NULL);


  // ret = my_strncmp("aaaaaaaaaaaaaaaa", "aaaadddddd", 3);
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("aaaaaaaaaaaaaaaa", "aaaadddddd", 3));
  // ret = my_strncmp("", "", 1);
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("", "", 1));
  // ret = my_strncmp("aaa", "aa", 1);
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("aaa", "aa", 2));
  // ret = my_strncmp("ac", "dc", 9);
  // assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strncmp("ac", "dc", 9));
  //
  // char  *st = malloc(50);
  // sprintf(st, "hello world\n");
  // char *res = strpbrk(st, "om");
  // char *res2 = my_strpbrk(st, "om");
  // assert(!strcmp(res, res2));
  //
  //
  // size_t test1 = strcspn(st, "l");
  // size_t test2 = my_strcspn(st, "l");
  // assert(test1 == test2);
  //
  // test1 = strcspn(st, "k");
  // test2 = my_strcspn(st, "k");
  // assert(test1 == test2);
  //
  // test1 = strcspn(st, "ol");
  // test2 = my_strcspn(st, "ol");
  // assert(test1 == test2);
  //
  //
  // test1 = strcspn(st, "");
  // test2 = my_strcspn(st, "");
  // assert(test1 == test2);
  //
  //
  // test1 = strcspn(st, "jfk");
  // test2 = my_strcspn(st, "jfk");
  // assert(test1 == test2);
  //
  //
  // test1 = strcspn(st, "d");
  // test2 = my_strcspn(st, "d");
  // assert(test1 == test2);
  //
  //
  // s1 = malloc(50);
  // s2 = malloc(50);
  // sprintf(s1, "hello test");
  // sprintf(s2, "hello test");
  //
  // s1 = memcpy(s1, s1 + 5, 5);
  // s2 = my_memcpy(s2, s2 + 5, 5);
  //
  // assert(!strcmp(s1, s2));


  printf("%s\n", "--------------ALL TEST PASSED--------------");
  printf("***** TEST end *****\n");
  return 0;
}
