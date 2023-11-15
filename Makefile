NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES_LIBFT = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

SRC_LIBFT = $(addprefix libft/, $(FILES_LIBFT))

LIBFT = libft

SRC_PRINTF =	ft_printf \
				printf_hexa \
				printf_nb
SRC = $(addsuffix .c, $(SRC_PRINTF))
OBJ = $(addsuffix .o, $(SRC_PRINTF))

################################################################################################################
###RULES

all: $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re: fclean all

.PHONY : all clean fclean re
