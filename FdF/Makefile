# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldione <ldione@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 18:53:42 by ldione            #+#    #+#              #
#    Updated: 2022/07/06 19:58:01 by ldione           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	FdF

GREEN 				=	\033[0;32m
RED					=	\033[0;31m
RESET				=	\033[0m

CC					=	gcc
SANITAZE			=	-fsanitize=address
FLAGS				=	-Wall -Wextra -Werror -Ofast
LIBRARIES			=	-lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES			=	-I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT				=	$(LIBFT_DIR)libft.a
LIBFT_DIR			=	./libft/
LIBFT_HEADERS		=	$(LIBFT_DIR)includes/

MINILIBX			=	$(MINILIBX_DIR)libmlx.a
MINILIBX_DIR		=	minilibx_macos/
MINILIBX_HEADERS	=	$(MINILIBX_DIR)

HEADERS_LIST		=	functions.h	\
						errors.h	\
						colors.h	\
						key.h		\
					#еще добавишь#
HEADERS_DIR			=	./includes/
HEADERS				=	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_DIR			=	sources/
SOURCES_LIST		=	main.c					\
						utils.c					\
						draw.c					\
						draw_menu.c				\
						draw_menu_utils.c		\
						draw_utils.c			\
						other_utils.c			\
						construct.c				\
						key_control.c			\
						key_control_utils.c		\
						work_with_colors.c		\
						mouse_control.c			\
						utils2.c

						#еще добавишь#
SOURCES				=	$(addprefix $(SOURCES_DIR), $(SOURCES_LIST))


OBJECTS_DIR			=	objects/
OBJECTS_LIST		=	$(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS				=	$(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

all					:	$(NAME)

$(NAME)				:	$(LIBFT) $(MINILIBX) $(OBJECTS_DIR) $(OBJECTS)
					@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
					@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
					@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIR)		:
					@mkdir -p $(OBJECTS_DIR)
					@echo "$(NAME): $(GREEN)$(OBJECTS_DIR) was created$(RESET)"

$(OBJECTS_DIR)%.o	: $(SOURCES_DIR)%.c $(HEADERS)
					@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
					@echo "$(GREEN)*$(RESET)\c"


$(LIBFT)			:
					@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
					@$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX)			:
					@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
					@$(MAKE) -sC $(MINILIBX_DIR)

clean				:
					@$(MAKE) -sC $(LIBFT_DIR) clean
					@$(MAKE) -sC $(MINILIBX_DIR) clean
					@rm -rf $(OBJECTS_DIR)
					@echo "$(NAME): $(RED)$(OBJECTS_DIR) was deleted$(RESET)"
					@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean				: clean
					@rm -f $(MINILIBX)
					@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
					@rm -f $(LIBFT)
					@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
					@rm -f $(NAME)
					@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"


re					:
					@$(MAKE) fclean
					@$(MAKE) all

					#удали это перед сдачей!!!!!!!#

.PHONY				:	all clean fclean re
