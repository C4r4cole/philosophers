# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 14:02:02 by fmoulin           #+#    #+#              #
#    Updated: 2025/11/26 11:37:52 by fmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===========================
#           CONFIG
# ===========================

NAME        = philo

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -f

# ===========================
#           SOURCES
# ===========================

SRCS =  $(SRC_DIR)/main.c \
        $(SRC_DIR)/init.c \
        $(SRC_DIR)/parsing.c \
        $(SRC_DIR)/dinner.c \
        $(SRC_DIR)/monitoring.c \
        $(SRC_DIR)/time.c \
        $(SRC_DIR)/utils.c \
        $(SRC_DIR)/safe_functions.c \
        $(SRC_DIR)/getters_setters.c \
        $(SRC_DIR)/synchro_utils.c \
        $(SRC_DIR)/write.c
		
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ===========================
#           RULES
# ===========================

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
