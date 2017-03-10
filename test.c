/*
** test.c for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Mar  9 15:50:17 2017 Pierre-Emmanuel Jacquier
** Last update Fri Mar 10 01:44:55 2017 Pierre-Emmanuel Jacquier
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);

int main()
{
  printf("***** TEST begin *****\n");
  assert(my_strlen("hello") == 5);
  printf("%d\n", my_strcmp("hello", "test"));
  assert(my_strcmp("hello", "test") == strcmp("hello", "test"));
  // printf("%d\n", my_strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd"));
  // assert(my_strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd") == strcmp("aaaaaaaaaaaaaaaa", "aaaadddddd"));

  // printf("%d\n", strcmp("hello", "test"));
  // printf("%s\n", my_strcmp("hello", "test"));
  printf("***** TEST end *****\n");
  return 0;
}
