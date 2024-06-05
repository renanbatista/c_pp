NAME		= Account
SRCS		= src/Account.cpp src/tests.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -std=c++98
COMPILER	= c++
INCLUDE		= -I include/

.cpp.o:
	${COMPILER} ${FLAGS} -c $(INCLUDE) $< -o ${<:.cpp=.o}

$(NAME): ${OBJS}
	${COMPILER} ${FLAGS} $(OBJS) -o $(NAME)

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)
    
clean:
	$(RM) -f $(OBJS)
    
re: fclean all	

.PHONY: all clean fclean re .cpp.o