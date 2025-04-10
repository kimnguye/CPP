#var

NAME	= ex02

SRCS	= main.cpp

#template

OBJS	= $(SRCS:%.c=obj/%.o)

CC		= c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

#supprimer les objets
clean:
	@rm -rf objs
	@echo "remove objs directory"

#supprimer les objets et les programmes
fclean: clean
	@rm -rf $(NAME) $(BONUS)
	@echo "remove pgm"

re: fclean all

b: $(BONUS)

# Compilation du programme
$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

# Compilation du programme
$(BONUS): $(OBJS_B)
	$(CC) -o $(BONUS) $(OBJS_B)

# Compilation des fichiers objets
obj/%.o : %.cpp | obj
	$(CC) -c $< -o $@

# Créer le dossier objs s'il n'existe pas
obj:
	mkdir -p obj

.PHONY: clean fclean re all