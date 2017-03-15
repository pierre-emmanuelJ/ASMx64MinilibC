/*
** test.c for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Mar  9 15:50:17 2017 Pierre-Emmanuel Jacquier
** Last update Wed Mar 15 18:58:59 2017 Pierre-Emmanuel Jacquier
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
char *my_rindex(const char *s, int c);

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

  printf("***** TEST end *****\n");
  return 0;
}
