NAME = program

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror \
	-I$(HOME)/.local/include/SDL2 \
	-D_REENTRANT

LDFLAGS = -L$(HOME)/.local/lib -lSDL2

SRC = \
	main.cpp \
	$(wildcard src/dom/*.cpp) \
	$(wildcard src/utils/*.cpp) \
	$(wildcard src/parser/*.cpp) \
	$(wildcard src/render/*.cpp)

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
