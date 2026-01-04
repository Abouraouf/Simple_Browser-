# Program name
NAME = program

# Compiler
CXX = c++

# Header directories
HEADERS_DIR = include
INCLUDES = -I$(HEADERS_DIR) -I$(HOME)/.local/include/SDL2

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -D_REENTRANT

# Linker flags
LDFLAGS  = -L$(HOME)/.local/lib -lSDL2 -lSDL2_ttf


# Sources
SRC = \
	main.cpp \
	$(wildcard src/dom/*.cpp) \
	$(wildcard src/utils/*.cpp) \
	$(wildcard src/parser/*.cpp) \
	$(wildcard src/render/*.cpp)

# Objects
OBJ = $(SRC:.cpp=.o)

# Headers
HEADERS = $(wildcard include/*.hpp)

# Default target
all: $(NAME)

# Link program
$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

# Compile source files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
