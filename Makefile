NAME = program
SOURCES = $(wildcard src/dom/*.cpp) $(wildcard src/utils/*.cpp) $(wildcard src/parser/*.cpp) \
main.cpp $(wildcard src/render/*.cpp)
FLAGS = -Wall -Wextra -Werror
OBJ = $(SOURCES:.cpp=.o)
HEADER = include/*.hpp
SDL_FLAGS = $(shell sdl2-config --cflags --libs)

%.o: %.cpp $(HEADER)
	c++ $(FLAGS) $(SDL_FLAGS) -c $< -o $@

$(NAME): $(OBJ) 
	c++ $(FLAGS) $(OBJ) $(SDL_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f src/**/*.o main.o

fclean: clean
	rm -f $(NAME)

re: fclean all
