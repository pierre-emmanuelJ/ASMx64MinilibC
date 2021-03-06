##
## Makefile for  in /home/jacqui_p/rendu/ASM/asm_minilibc/
##
## Made by Pierre-Emmanuel Jacquier
## Login   <jacqui_p@epitech.eu>
##
## Started on  Thu Mar  9 15:40:43 2017 Pierre-Emmanuel Jacquier
## Last update Wed Mar 22 18:45:24 2017 Pierre-Emmanuel Jacquier
##

RM		= rm -f

NASM		= nasm -f elf64 -g

LD		= ld

SRCS		= strlen.S \
          strcmp.S \
					strncmp.S \
					rindex.S \
					strchr.S \
					memmove.S \
					memcpy.S \
					memset.S \
					strstr.S \
                                        read_write.S \
					strcspn.S \
					strpbrk.S

OBJS		= $(SRCS:.S=.o)

LFLAGS		= -shared

CFLAGS		= -fpic -g

NAME		= libasm.so

all:		$(NAME)

$(NAME):	$(OBJS)
		$(LD) $(LFLAGS) -o $(NAME) $(OBJS) $(CFLAGS)

%.o:		%.S
		@$(NASM) -o $@ $<

clean:
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)

re: fclean all

test:	$(OBJS)
	@$(LD) $(LFLAGS) -o $(NAME) $(OBJS) $(CFLAGS)
	@gcc test.c *.o -g
	@LD_PRELOAD=./libasm.so ./a.out
	make fclean && rm a.out

vgtest:
	@make re
	@gcc test.c *.o -g
	@valgrind ./a.out
	make fclean && rm a.out

.PHONY	: all clean fclean re
