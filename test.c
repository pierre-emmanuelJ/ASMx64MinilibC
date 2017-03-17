/*
** test.c for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Mar  9 15:50:17 2017 Pierre-Emmanuel Jacquier
** Last update Fri Mar 17 14:51:22 2017 Pierre-Emmanuel Jacquier
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
char *my_rindex(const char *s, int c);
char *my_strchr(const char *s, int c);
void *my_memmove(void *dest, const void *src, size_t n);
void *my_memset(void *s, int c, size_t n);

int main()
{
  int ret;

  printf("***** TEST begin *****\n");
  assert(my_strlen("") == strlen(""));
  assert(my_strlen("hello") == strlen("hello"));
  assert(my_strlen("h") == strlen("h"));
  assert(my_strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") == strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));

  ret = my_strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd"));
  ret = my_strcmp("", "");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("", ""));
  ret = my_strcmp("aaa", "aa");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("aaa", "aa"));
  ret = my_strcmp("ac", "dc");
  assert(ret > 0 ? 1 : ret < 0 ? -1 : 0 == strcmp("ac", "dc"));

  char *s1 = rindex("test", 's');
  char *s2 = my_rindex("test", 's');
  assert(!strcmp(s1, s2));

  s1 = rindex("test", 't');
  s2 = my_rindex("test", 't');
  assert(!strcmp(s1, s2));

  s1 = rindex("test", 'f');
  s2 = my_rindex("test", 'f');
  assert(s1 == NULL && s2 == NULL);

  s1 = rindex("hello", 0);
  s2 = my_rindex("hello", 0);
  assert(!strcmp(s1, s2));

  s1 = rindex("", 0);
  s2 = my_rindex("", 0);
  assert(!strcmp(s1, s2));

  s1 = rindex("", 'z');
  s2 = my_rindex("", 'z');
  assert(s1 == NULL && s2 == NULL);


  s1 = strchr("test", 's');
  s2 = my_strchr("test", 's');
  assert(!strcmp(s1, s2));

  s1 = strchr("test", 't');
  s2 = my_strchr("test", 't');
  assert(!strcmp(s1, s2));

  s1 = strchr("test", 'f');
  s2 = my_strchr("test", 'f');
  assert(s1 == NULL && s2 == NULL);

  s1 = strchr("hello", 0);
  s2 = my_strchr("hello", 0);
  assert(!strcmp(s1, s2));

  s1 = strchr("", 0);
  s2 = my_strchr("", 0);
  assert(!strcmp(s1, s2));

  s1 = strchr("", 'z');
  s2 = my_strchr("", 'z');
  assert(s1 == NULL && s2 == NULL);

  s1 = malloc(12);
  s2 = malloc(12);
  sprintf(s1, "hello test\n");
  sprintf(s2, "hello test\n");
  assert(!strcmp(s1, s2));
  my_memset(s1, 'Z', 11);
  memset(s2, 'Z', 11);
  assert(!strcmp(s1, s2));

  sprintf(s1, "");
  sprintf(s2, "");
  assert(!strcmp(s1, s2));
  my_memset(s1, 0, 11);
  memset(s2, 0, 11);
  assert(!strcmp(s1, s2));

  printf("***** TEST end *****\n");
  return 0;
}
