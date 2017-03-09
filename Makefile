##
## Makefile for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
##
## Made by Pierre-Emmanuel Jacquier
## Login   <jacqui_p@epitech.eu>
##
## Started on  Thu Mar  9 15:40:43 2017 Pierre-Emmanuel Jacquier
## Last update Thu Mar  9 15:47:55 2017 Pierre-Emmanuel Jacquier
##

RM		= rm -f

NASM		= nasm -f elf64

LD		= gcc

SRCS		= strlen.S

OBJS		= $(SRCS:.S=.o)

LFLAGS		= -shared

CFLAGS		= -fpic

NAME		= libasm.so

all:		$(NAME)

$(NAME):	$(OBJS)
		$(LD) $(LFLAGS) -o $(NAME) $(OBJS) $(CFLAGS)
		gcc $(OBJS) test.c

%.o:		%.S
		@$(NASM) -o $@ $<

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re: fclean all

test:	$(OBJS)
	@$(LD) $(LFLAGS) -o $(NAME) $(OBJS) $(CFLAGS)
	@gcc main.c src/*.o -g
	@./a.out
	make fclean && rm a.out

.PHONY	: all clean fclean re
