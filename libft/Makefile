NAME		= libft.a

SRCS		= ft_calloc.c  ft_isascii.c ft_memcpy.c  ft_strlcat.c ft_toupper.c \
			ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memmove.c ft_strlcpy.c \
			ft_bzero.c ft_isalpha.c ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c \
			ft_tolower.c ft_strdup.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		    ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c \
		    ft_putstr_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			get_next_line_utils.c get_next_line.c ft_printf.c ft_printtype.c

SRC_OBJS	= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SRC_OBJS)
			ar rcs $(NAME) $(SRC_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_OBJS)

fclean:	clean 
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:		all clean fclean re bonus
