NAME =  program
SOURCES = $(wildcard src/dom/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/parser/*.cpp) main.cpp
FLAGS = -Wall -Wextra -Werror
OBJ = $(SOURCES:.cpp=.o)
HEADER = include/*.hpp
%.o: %.cpp $(HEADER)
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	c++ $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f src/**/*.o main.o

fclean: clean
	rm -f $(NAME)

re: fclean all