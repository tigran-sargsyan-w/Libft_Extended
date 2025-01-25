CC = cc
CFLAGS = -Wall -Wextra -Werror -I./ -I./ft_printf

NAME = libft.a

PRINTF_DIR = ft_printf

SRCS = ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_toupper.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_memcpy.c \
	ft_memset.c ft_tolower.c ft_memmove.c ft_putchar_fd.c ft_strlcpy.c ft_strlcat.c \
	ft_strdup.c ft_atoi.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

PRINTF_SRCS = $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_number_functions.c \
	$(PRINTF_DIR)/ft_ptr_functions.c $(PRINTF_DIR)/ft_string_functions.c

SRCS += $(PRINTF_SRCS)
	
OBJS = $(SRCS:.c=.o)

HEADER = libft.h $(PRINTF_DIR)/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
