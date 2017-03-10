/*
** test.c for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Mar  9 15:50:17 2017 Pierre-Emmanuel Jacquier
** Last update Fri Mar 10 12:30:59 2017 Pierre-Emmanuel Jacquier
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);

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


  printf("***** TEST end *****\n");
  return 0;
}
