# **************************************************************************** #
#                                  Makefile                                    #
# **************************************************************************** #

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I./

# -------------------------------
#   Directories with source 
# -------------------------------
LIBFT_DIR   = src/libft
PRINTF_DIR  = src/printf
GNL_DIR     = src/get_next_line

# -------------------------------
#   Source for libft
# -------------------------------
LIBFT_SRCS  = $(LIBFT_DIR)/ft_atoi.c \
              $(LIBFT_DIR)/ft_atol.c \
              $(LIBFT_DIR)/ft_atoi_hex.c \
              $(LIBFT_DIR)/ft_bzero.c \
              $(LIBFT_DIR)/ft_calloc.c \
              $(LIBFT_DIR)/ft_isalnum.c \
              $(LIBFT_DIR)/ft_isalpha.c \
              $(LIBFT_DIR)/ft_isascii.c \
              $(LIBFT_DIR)/ft_isdigit.c \
              $(LIBFT_DIR)/ft_isprint.c \
              $(LIBFT_DIR)/ft_isspace.c \
              $(LIBFT_DIR)/ft_isvalid_hex.c \
              $(LIBFT_DIR)/ft_isvalid_int.c \
              $(LIBFT_DIR)/ft_isxdigit.c \
              $(LIBFT_DIR)/ft_itoa.c \
              $(LIBFT_DIR)/ft_count_tokens.c \
              $(LIBFT_DIR)/ft_lstadd_back.c \
              $(LIBFT_DIR)/ft_lstadd_front.c \
              $(LIBFT_DIR)/ft_lstclear.c \
              $(LIBFT_DIR)/ft_lstdelone.c \
              $(LIBFT_DIR)/ft_lstiter.c \
              $(LIBFT_DIR)/ft_lstlast.c \
              $(LIBFT_DIR)/ft_lstmap.c \
              $(LIBFT_DIR)/ft_lstnew.c \
              $(LIBFT_DIR)/ft_lstsize.c \
              $(LIBFT_DIR)/ft_memchr.c \
              $(LIBFT_DIR)/ft_memcmp.c \
              $(LIBFT_DIR)/ft_memcpy.c \
              $(LIBFT_DIR)/ft_memmove.c \
              $(LIBFT_DIR)/ft_memset.c \
              $(LIBFT_DIR)/ft_putchar_fd.c \
              $(LIBFT_DIR)/ft_putendl_fd.c \
              $(LIBFT_DIR)/ft_putnbr_fd.c \
              $(LIBFT_DIR)/ft_putstr_fd.c \
              $(LIBFT_DIR)/ft_split.c \
              $(LIBFT_DIR)/ft_strchr.c \
              $(LIBFT_DIR)/ft_strdup.c \
              $(LIBFT_DIR)/ft_strndup.c \
              $(LIBFT_DIR)/ft_striteri.c \
              $(LIBFT_DIR)/ft_strjoin.c \
              $(LIBFT_DIR)/ft_strlcat.c \
              $(LIBFT_DIR)/ft_strlcpy.c \
              $(LIBFT_DIR)/ft_strlen.c \
              $(LIBFT_DIR)/ft_strmapi.c \
              $(LIBFT_DIR)/ft_strcmp.c \
              $(LIBFT_DIR)/ft_strncmp.c \
              $(LIBFT_DIR)/ft_strnstr.c \
              $(LIBFT_DIR)/ft_strrchr.c \
              $(LIBFT_DIR)/ft_strtrim.c \
              $(LIBFT_DIR)/ft_substr.c \
              $(LIBFT_DIR)/ft_tolower.c \
              $(LIBFT_DIR)/ft_toupper.c

# -------------------------------
#   Source for printf
# -------------------------------
FT_PRINTF_SRCS = $(PRINTF_DIR)/ft_printf.c \
                  $(PRINTF_DIR)/ft_dprintf.c \
				  $(PRINTF_DIR)/ft_number_functions.c \
                  $(PRINTF_DIR)/ft_ptr_functions.c \
                  $(PRINTF_DIR)/ft_string_functions.c
                  
# -------------------------------
#   Source for get_next_line
# -------------------------------
GNL_SRCS    = $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

# -------------------------------
#   Combine all into SRCS
# -------------------------------
SRCS        = $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(GNL_SRCS)

# -------------------------------
#   Convert .c files to .o
# -------------------------------
OBJS        = $(SRCS:.c=.o)

# -------------------------------
#         Header files
# -------------------------------
HEADERS     = libft.h \
              ft_printf.h \
              get_next_line.h

# -------------------------------
#          Build rules
# -------------------------------
all: $(NAME)
	@echo "🔥 Libft built successfully!"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "✅ Libft object files compiled."
	@echo "🚀 $(NAME) created!"

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJS)
	@echo "🗑️ Libft object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "😒 $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
