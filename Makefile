RED     = \033[31m
GRN     = \033[32m
YEL     = \033[33m
BLU     = \033[34m
MAG     = \033[35m
STD     = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc -g
RM = rm -rf
NAME = libftprintf.a
SRCS = src/ft_printf.c \
	src/prt_str.c \
	src/prt_ptr.c \
	src/prt_int.c \
	src/prt_unsigned.c \
	src/prt_hexa.c
SRCSB = srcb/ft_convert_nbrs_utils.c \
	srcb/ft_handle_nbrs_d_i_u_data.c \
	srcb/ft_print_nbrs_d_i_u_bonus.c \
	srcb/ft_print_hex_utils.c \
	srcb/ft_print_hex_p_bonus.c \
	srcb/ft_print_hex_o_bonus.c \
	srcb/ft_print_hex_x_bonus.c \
	srcb/ft_print_chars_bonus.c \
	srcb/ft_parse_bonus.c \
	srcb/ft_format_bonus.c \
	srcb/ft_parse_utils.c \
	srcb/ft_printf_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

srcb/%.o: srcb/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
	@echo "$(YEL)libftprintf.a: $(GRN)Mandatory$(YEL) part compiled and archived.$(STD)"

bonus:  $(OBJSB)
	$(MAKE) -C ./libft bonus
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJSB)
	@echo "$(YEL)libftprintf.a: $(MAG)Bonus$(YEL) part compiled and archived.$(STD)"
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(OBJSB)
fclean:	clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus