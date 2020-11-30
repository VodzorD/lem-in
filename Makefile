NAME	=	lem-in
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -O2
FLAGS	=	

LEMC	=	main.c init.c \
			argparse.c free.c \
			valid.c roomparse.c \
			alg.c ants.c print.c \
			matrix.c paths.c \
			queue.c steps.c \
			check_rooms.c markup.c \
			helpers.c

LIBDIR	=	libft
LIBINC	=	$(LIBDIR)
LIB		=	$(LIBDIR)/libft.a

LEMH = lem.h

all: $(NAME)

$(LIB): $(LIBDIR)
	make -C $(LIBDIR)

$(NAME): $(LEMC) $(LIB) $(LEMH)
	$(CC) $(FLAGS) -o $(NAME) $(LEMC) $(LIB) -I $(LIBINC)

clean:
	rm -f $(NAME)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all
