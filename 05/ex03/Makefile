NAME		= inter
SRCS		= src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp
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
	$(RM) F1_shrubbery 
	$(RM) Amazon_shrubbery 
clean:
	$(RM) -f $(OBJS)
    
re: fclean all	

.PHONY: all clean fclean re .cpp.o