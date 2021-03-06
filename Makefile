##
## Makefile for Abstract_VM in /home/paasch_j/rendu/cpp_abstractvm
## 
## Made by Johan Paasche
## Login   <paasch_j@epitech.net>
## 
## Started on  Mon Feb 16 22:46:29 2015 Johan Paasche
## Last update Sun Mar  1 16:53:38 2015 David Tran
##

NAME		=	philo


CC		=	gcc
RM		=	rm -f

LINK		=	ln -fs


DEBUG		=	no

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic  -I$(INCLUDE_D) -pthread -lSDL -lSDLmain -ldl -lSDL_image -lSDL_ttf -lSDL_mixer

ifeq			($(DEBUG),yes)
			CFLAGS += -g3
else
			CFLAGS += -O3
endif


SRC		=	main.c		\
			display.c	\
			philosophy.c	\
			main_sound.c



#########################################
#		TREE			#
#########################################

BIN_D		=	bin

OBJ_D		=	obj

INCLUDE_D	=	include

SRC_D		=	src

SRCS		= 	$(addprefix $(SRC_D)/, $(SRC))

PRO		= 	$(addprefix $(BIN_D)/, $(NAME))

OBJS		= 	$(addsuffix .o, $(basename $(subst $(SRC_D), $(OBJ_D), $(SRCS))))

#########################################
#		RULES			#
#########################################

FIRST		:=	$(shell test -d $(OBJ_D) || mkdir $(OBJ_D))	\
			$(shell test -d $(BIN_D) || mkdir $(BIN_D))

$(NAME)		:	$(PRO)
		 	@$(LINK) $(PRO) $(NAME)

$(OBJ_D)/%.o	:	$(SRC_D)/%.c
		 	$(CC) $(CFLAGS) -c $< -o $@

$(PRO)		: 	$(OBJS)
		  	$(CC) $(CFLAGS) $(OBJS) -o $(PRO)

all		:	$(NAME)

clean		:
		  	$(RM)		$(OBJS)

fclean		: 	clean
		  	$(RM)		$(PRO)
		  	$(RM)		$(NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re
