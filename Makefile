#COMPILATION

CC = clang
GFLAG = -g
WFLAG = -Werror -Wextra -Wall

#NAME
PUSH = push_swap

# LIB


#PUSH

PUSH_SRC =  check_error.c \
ft_big_sort.c \
ft_big_sort2.c \
ft_tab.c \
ft_five.c \
ft_init.c \
ft_itoa.c \
ft_write_algo.c \
lib.c \
algo.c \
push_swap.c

PUSH_OBJ = $(PUSH_SRC:.c=.o)

all : $(PUSH)


#PUSH INSTRUCTION

$(PUSH) : $(PUSH_OBJ)
	$(CC) $(GFLAG) $(WFLAG) -v -o $(PUSH) $(PUSH_OBJ) $(LIB) $(WFLAG) -I.

%.o : %.c
	clang -I. -o $@ -c $< $(WFLAG)

clean :
	@- rm -f $(PUSH_OBJ) 

fclean : clean
	@- rm -f $(PUSH)

re : fclean all

re-bonus : fclean bonus

.PHONY: all bonus clean fclean re re-bonus makelib
