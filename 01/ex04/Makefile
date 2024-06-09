NAME        = account
SRCS        = src/main.cpp src/FileReplacer.cpp
OBJS        = $(SRCS:.cpp=.o)
RM          = rm -f
FLAGS       = -Wall -Wextra -Werror -std=c++98
COMPILER    = c++
INCLUDE     = -I include/

.cpp.o:
	${COMPILER} ${FLAGS} -c $(INCLUDE) $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
	${COMPILER} ${FLAGS} $(OBJS) -o $(NAME)
	echo "este aqui escrevendo em um arquivo txt bem doido,\n\
	simplesmente porque preciso de um pouco de testou este aqui\n\
	aqui escrevendo nesse arquivo de texto. este aqui" > test.txt

all: $(NAME)

fclean: clean
	$(RM) $(NAME)
	$(RM) test.txt
    
clean:
	$(RM) $(OBJS)
    
re: fclean all    

.PHONY: all clean fclean re .cpp.o
