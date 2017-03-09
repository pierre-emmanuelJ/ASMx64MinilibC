/*
** test.c for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Mar  9 15:50:17 2017 Pierre-Emmanuel Jacquier
** Last update Thu Mar  9 17:18:16 2017 Pierre-Emmanuel Jacquier
*/
#include <stdio.h>
#include <assert.h>

size_t my_strlen(const char *s);

int main()
{
  printf("***** TEST begin *****\n");
  assert(my_strlen("hello") == 5); //test
  printf("***** TEST end *****\n");
  return 0;
}
