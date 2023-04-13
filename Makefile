# E89 Pedagogical & Technical Lab
# project:     rev
# created on:  2022-11-28 - 11:34 +0100
# 1st author:  victor.vandeputte - victor.vandeputte
# description: Makefile

NAME	=	printf.a

SRCS	=	src/strlen.c		\
		src/cputs.c		\
		src/dputs.c		\
		src/sputs.c		\
		src/nb_len.c		\
		src/get_digit.c		\
		src/dprintf.c		\
		src/strdup.c		\
		src/strcpy.c		\
		src/xputs.c		\
		src/d_bourrage.c	\
		src/c_bourrage.c	\
		src/s_bourrage.c	\
		src/x_bourrage.c	\
		src/counter.c		\
		src/hexa.c		\
		src/d_bourrage_ne.c	\
		src/d_bour_3.c		\
		src/test_dprintf.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

ar: $(OBJS)
	ar rc $(NAME) $(OBJS)

comp:
	$(CC) $(CFLAGS) src/main.c printf.a -o printf

save:
	git status
	git add Makefile src/*.c include/*.h
	git commit -m "$(NAME) sauvegarde"
	git push

exe:
	make ar
	make comp
	./printf

mclean:
	rm src/*.c~ src/*.o include/*.h~ Makefile~

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clean fclean re ar
