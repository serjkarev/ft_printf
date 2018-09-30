#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarev <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 15:44:38 by skarev            #+#    #+#              #
#    Updated: 2018/07/20 15:44:39 by skarev           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAG = -c -Wall -Wextra 

SRCS = ft_printf.c \
		parce_particles.c \
		processing_small_d.c \
		dop_1.c dop_2.c \
		processing_small_u.c \
		processing_small_s.c \
		processing_small_x.c \
		processing_small_o.c \
		processing_small_c.c \
		processing_percent.c \
		processing_p.c \
		processing_big_d.c \
		processing_i.c \
		processing_big_s.c \
		processing_big_x.c \
		processing_big_u.c \
		processing_big_o.c \
		processing_big_c.c \
		proces_inv_conv_spec.c

OBJS = $(SRCS:.c=.o)

LIB_OBJS = ./libft/ft_atoi.o \
			./libft/ft_bzero.o \
			./libft/ft_isalnum.o \
			./libft/ft_isalpha.o \
			./libft/ft_isascii.o \
			./libft/ft_isdigit.o \
			./libft/ft_isprint.o \
			./libft/ft_isspace.o \
			./libft/ft_itoa.o \
			./libft/ft_lst_create_elem.o \
			./libft/ft_lst_push_back.o \
			./libft/ft_lstadd.o \
			./libft/ft_lstdel.o \
			./libft/ft_lstdelone.o \
			./libft/ft_lstiter.o \
			./libft/ft_lstmap.o \
			./libft/ft_lstnew.o \
			./libft/ft_memalloc.o \
			./libft/ft_memccpy.o \
			./libft/ft_memchr.o \
			./libft/ft_memcmp.o \
			./libft/ft_memcpy.o \
			./libft/ft_memdel.o \
			./libft/ft_memmove.o \
			./libft/ft_memset.o \
			./libft/ft_nbrlen.o \
			./libft/ft_putchar.o \
			./libft/ft_putchar_fd.o \
			./libft/ft_putendl.o \
			./libft/ft_putendl_fd.o \
			./libft/ft_putnbr.o \
			./libft/ft_putnbr_fd.o \
			./libft/ft_putstr.o \
			./libft/ft_putstr_fd.o \
			./libft/ft_strcat.o \
			./libft/ft_strchr.o \
			./libft/ft_strclr.o \
			./libft/ft_strcmp.o \
			./libft/ft_strcpy.o \
			./libft/ft_strdel.o \
			./libft/ft_strdup.o \
			./libft/ft_strequ.o \
			./libft/ft_striter.o \
			./libft/ft_striteri.o \
			./libft/ft_strjoin.o \
			./libft/ft_strlcat.o \
			./libft/ft_strlen.o \
			./libft/ft_strmap.o \
			./libft/ft_strmapi.o \
			./libft/ft_strncat.o \
			./libft/ft_strncmp.o \
			./libft/ft_strncpy.o \
			./libft/ft_strnequ.o \
			./libft/ft_strnew.o \
			./libft/ft_strnstr.o \
			./libft/ft_strrchr.o \
			./libft/ft_strsplit.o \
			./libft/ft_strstr.o \
			./libft/ft_strsub.o \
			./libft/ft_strtrim.o \
			./libft/ft_swap.o \
			./libft/ft_tolower.o \
			./libft/ft_toupper.o \
			./libft/ft_itoa_ll.o \
			./libft/ft_nbrlen_ll.o \
			./libft/ft_itoa_u.o \
			./libft/ft_itoa_base_ull.o \
			./libft/ft_itoa_base_ull_big.o 

LIBS = ./libft/libft.a

all: $(NAME)

$(OBJS):
	@gcc $(CFLAG) $(SRCS) 

$(LIB_OBJS):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIB_OBJS)
	@ar rcs $(NAME) $(LIB_OBJS) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)
	@$(MAKE) -C ./libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C ./libft/ fclean

re:		fclean all

.PHONY: all clean fclean re