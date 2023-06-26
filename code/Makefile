# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:09:49 by tde-souz          #+#    #+#              #
#    Updated: 2022/10/20 21:33:43 by tde-souz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								   FILE NAME
NAME				:= minitalk
CLIENT				:= client
CLIENT_BONUS		:= client_bonus
SERVER				:= server
SERVER_BONUS		:= server_bonus


# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  DIRECTORIES
LIBFT		:= libft/libft.a
LIBFT_DIR	:= ./libft/

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								  TEXT CODES
GREEN		:= \e[38;5;118m
GOLD		:= \e[38;5;220m
RESET		:= \e[0m
BOLD		:= \e[1m

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									ALIASES
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= /bin/rm -rf
#MAKEFLAGS	+= --silent

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 								 SOURCE FILES
SRC_CLIENT			:= client.c
SRC_CLIENT_BONUS	:= client_bonus.c
SRC_SERVER			:= server.c
SRC_SERVER_BONUS	:= server_bonus.c

# '-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
# 									 RULES
.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(CLIENT) $(SERVER) 

$(CLIENT):	$(LIBFT) $(SRC_CLIENT) minitalk.h 
			$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(CLIENT)
			printf "$(BOLD)$(CLIENT) [$(GREEN)READY$(RESET)]\n"

$(SERVER):	$(LIBFT) $(SRC_SERVER) minitalk.h
			$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(SERVER)
			printf "$(BOLD)$(SERVER) [$(GREEN)READY$(RESET)]\n"

bonus:		$(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(LIBFT) $(SRC_CLIENT_BONUS) minitalk.h 
			$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)
			printf "$(BOLD)$(CLIENT_BONUS) [$(GREEN)READY$(RESET)]\n"

$(SERVER_BONUS): $(LIBFT) $(SRC_SERVER_BONUS) minitalk.h
			$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)
			printf "$(BOLD)$(SERVER_BONUS) [$(GREEN)READY$(RESET)]\n"

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
			$(RM) $(OBJ_CLIENT)
			$(RM) $(OBJ_CLIENT_BONUS)
			$(RM) $(OBJ_SERVER)
			$(RM) $(OBJ_SERVER_BONUS)
			printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing objects\n"

fclean:		clean
			$(RM) $(CLIENT)
			$(RM) $(CLIENT_BONUS)
			$(RM) $(SERVER)
			$(RM) $(SERVER_BONUS)
			$(MAKE) -C $(LIBFT_DIR) fclean
			printf "$(BOLD)$(NAME) [$(GOLD)INFO$(RESET)] - removing programs\n"

re:			fclean all

