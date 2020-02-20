# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 19:59:23 by vdelsie           #+#    #+#              #
#    Updated: 2020/02/18 20:11:14 by vdelsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  MLX      ----------------------------------------------------- #

MLX_BASEDIR = ./minilibx/

TARGETOS := $(shell uname -s)

ifeq ($(TARGETOS), Darwin)
	OSXRELEASE := $(shell uname -r | sed 's/\..*//')
	ifeq ($(OSXRELEASE), 17)
		OSXVER = highsierra
		MLX = $(addprefix $(MLX_BASEDIR), $(join minilibx_macos_, $(OSXVER)))
	endif
	ifeq ($(OSXRELEASE), 16)
		OSXVER = sierra
		MLX = $(addprefix $(MLX_BASEDIR), $(join minilibx_macos_, $(OSXVER)))
	endif
	ifeq ($(OSXRELEASE), 15)
		OSXVER = elcapitan
		MLX = $(addprefix $(MLX_BASEDIR), $(join minilibx_macos_, $(OSXVER)))
	endif
	ifeq ($(OSXRELEASE), 14)
		OSXVER = yosemite
	endif
	ifeq ($(OSXRELEASE), 13)
		OSXVER = maverick
	endif
	ifeq ($(OSXRELEASE), 12)
		OSXVER = mountainlion
	endif
	ifeq ($(OSXRELEASE), 11)
		OSXVER = lion
	endif
endif

MLX_LIB	= mlx.a

# ------------  PROJECT  ----------------------------------------------------- #
NAME		=	vdelsie.filler
NAME_VIZ	=	filler.visual	

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR		=	srcs
SRC_VIS_DIR	=	viz
HDR_DIR		=	includes
OBJ_DIR		=	objects
OBJ_VIS_DIR	=	objects_vis

# ------------  LIBFT  ------------------------------------------------------- #
LFT			=	libft.a
LFT_DIR		=	libft
LHS_DIR		=	$(LFT_DIR)/includes

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC_FLS		=   tools_basics.c \
				debug_files_off.c \
				tools_player.c \
				tools_strat.c \
				tools_read.c \
				first_init.c \
				get_data.c \
				put_piece.c \
				border_check.c \
				border_calc.c \
				border_clear.c \
				heat_calc_main.c \
				heat_calc_sub_fct.c \
				strat_calc.c \
				strat_adjustment.c \
				delete_and_clear.c \
				main.c

SRC_VIS_FLS	=	color.c \
				image.c \
				key_hooks.c \
				game_state_list_utils.c \
				read_utils.c \
				render.c \
				render_str.c \
				general_utils.c \
				sound.c \
				main.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FLS))
SRCS_VIS	=	$(addprefix $(SRC_VIS_DIR)/, $(SRC_VIS_FLS))
OBJS		=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
OBJS_VIS	=	$(patsubst $(SRC_VIS_DIR)/%.c,$(OBJ_VIS_DIR)/%.o, $(SRCS_VIS))
DEPS		=	$(OBJS:.o=.d)
DEPS_VIS	=	$(OBJS_VIS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC			=	gcc
RM			=	rm -rf
CFLGS		=	-Wall -Werror -Wextra
IFLGS		=	-I $(HDR_DIR) -I $(LHS_DIR) -I $(MLX)
LFLGS		=	-L $(LFT_DIR) -lft
MLX_FLGS	=	-L $(MLX) -l mlx -framework OpenGL -framework AppKit
DFLGS		=	-MMD -MP
DEBUG		=	-g -pg -fsanitize=address

# ------------  RULES  ------------------------------------------------------- #
.PHONY: all clean fclean re

all: $(NAME) $(NAME_VIZ)

$(MLX)/$(MLX_LIB):
	$(MAKE) -C $(MLX)

$(LFT_DIR)/$(LFT):
	$(MAKE) -C $(LFT_DIR)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

-include $(DEPS_VIS)
$(OBJ_VIS_DIR)/%.o: $(SRC_VIS_DIR)/%.c | $(OBJ_VIS_DIR)
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_VIS_DIR):
	mkdir -p $(OBJ_VIS_DIR)

$(NAME): $(LFT_DIR)/$(LFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLGS)

$(NAME_VIZ): $(LFT_DIR)/$(LFT) $(OBJS_VIS) | $(MLX)/$(MLX_LIB)
	$(CC) -o $(NAME_VIZ) $(OBJS_VIS) $(LFLGS) $(MLX_FLGS)

clean:
	$(MAKE) -C $(LFT_DIR) clean
	$(MAKE) -C $(MLX) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_VIZ)

re: fclean all
