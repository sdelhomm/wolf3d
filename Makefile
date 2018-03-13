# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/15 17:57:32 by sdelhomm          #+#    #+#              #
#    Updated: 2018/03/13 14:13:07 by sdelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_map.c \
	  main.c \
	  raycasting.c \
	  events.c \
	  draw.c \
	  show_menu.c \
	  free_map.c \

SRCPATH = ./srcs/

OBJ = $(SRC:.c=.o)

LIB = libft.a

LIBPATH = ./libft/

NAME = wolf3d

FLAGS = -O3 -Wall -Werror -Wextra

all : $(NAME)
$(NAME) :
	@make -C $(LIBPATH)
	@gcc -c $(FLAGS) $(addprefix $(SRCPATH),$(SRC))
	@echo "[Create objects]"
	@gcc ./libfmod.dylib -o $(NAME) $(FLAGS) $(OBJ) $(LIBPATH)$(LIB) -lmlx -framework OpenGL -framework AppKit
	@echo "[Create $(NAME)]"
	@install_name_tool -change @loader_path/../Frameworks/libfmodex.dylib /Users/sdelhomm/wolf3d/wolf3d/libfmod.dylib wolf3d
	@echo "[DyLib linked]"

clean :
	@make clean -C $(LIBPATH)
	@rm -f $(OBJ)
	@echo "[Clean objects]"

fclean : clean
	@rm -f $(LIBPATH)$(LIB)
	@rm -f $(NAME)
	@echo "[Clean $(NAME)]"

re : fclean all
