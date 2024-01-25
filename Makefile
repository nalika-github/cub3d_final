# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:19:47 by pnopjira          #+#    #+#              #
#    Updated: 2024/01/25 20:59:42 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= 	cub3d
HDF						=	cub3d.h game_setup.h get_next_line.h
LIBFT					=	libft/libft.a
CC						=	gcc
CFLAGS					=
# CFLAGS					=	-Wall -Werror -Wextra

# Variable declaration of directory
INCS_DIR				= ./include
BUILD_DIR				= ./build
SRCS_PARSER_DIR			= ./parser
SRCS_RAYCASTER_DIR		= ./raycaster

# Variable declaration of file

SRCS_PASER				=	00map_setup.c 01map_setup.c 02map_setup.c 03map_setup.c \
							04map_setup.c 05map_setup.c check_dataformat.c check_invalid.c\
							frame_setup.c ft_get_next_line.c player_setup.c \
							free_allocated01.c free_allocated02.c

SRCS_RAYCASTER			=	animate_loop.c bresenham.c cub3d_render.c draw_wall.c \
							get_tex_image.c init_ray_data.c movement.c rotate.c

MAIN					=	cub3d.c

# Variable declaration of header file

HDFS					=	$(HDF:%.h=$(INCS_DIR)/%.h)

# Variable declaration of object

OBJS_PASER				=	$(SRCS_PASER:%.c=$(BUILD_DIR)/%.o)
OBJS_RAYCASTER			=	$(SRCS_RAYCASTER:%.c=$(BUILD_DIR)/%.o)
OBJS_MAIN				=	$(MAIN:%.c=$(BUILD_DIR)/%.o)

# Variable declaration of linking lib

# OPENDIR					=	-I./libft -I$(INCS_DIR) -L./libft -Lmlx_linux -L/usr/lib
# LIBLINK					=	-lft -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

# Conditional compilation for macOS

#ifdef __APPLE__
OPENDIR					+=	-framework OpenGL -framework AppKit
HDFS					+=	$(INCS_DIR)/macos_additional_headers.h
OPENDIR					=	-I./libft -I$(INCS_DIR) -L./libft -Imlx -Lmlx
LIBLINK					=	-lft -lmlx -framework OpenGL -framework AppKit
#endif

# Build step

all: $(NAME)

$(NAME): $(OBJS_PASER) $(OBJS_RAYCASTER) $(OBJS_MAIN) $(LIBFT)
	$(CC) $(CFLAGS) $(OPENDIR) $^ $(LIBLINK) -o $@

$(OBJS_PASER): $(BUILD_DIR)/%.o: $(SRCS_PARSER_DIR)/%.c $(HDFS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(OPENDIR) -c $< -o $@ $(LIBLINK)

$(OBJS_RAYCASTER): $(BUILD_DIR)/%.o: $(SRCS_RAYCASTER_DIR)/%.c $(HDFS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(OPENDIR) -c $< -o $@ $(LIBLINK)

$(OBJS_MAIN): $(BUILD_DIR)/%.o: $(MAIN) $(HDFS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(OPENDIR) -c $< -o $@ $(LIBLINK)

$(LIBFT):
	make -C libft

clean:
	@rm -rf $(BUILD_DIR)

fclean:
	@rm -rf $(NAME) $(BUILD_DIR)
	@make fclean -C libft

re: fclean all
	@make re -C libft

.PHONY: all clean fclean re
