# Compiler and options
CC = gcc
CFLAGS = -g -Wall -Wextra -Iinclude

# Libraries
# LDFLAGS = -lSDL2 -lSDL2_mixer

# Modules dir
MODULES_DIR = modules

# Source files
SRCS = main.c \
       $(MODULES_DIR)/board.c \
       $(MODULES_DIR)/player.c \
       $(MODULES_DIR)/menu.c \
       $(MODULES_DIR)/getch.c \
       $(MODULES_DIR)/game.c \
       $(MODULES_DIR)/render.c \
       $(MODULES_DIR)/dynarray.c
       #$(MODULES_DIR)/music.c \ 

# Object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = game

# Default target
all: $(TARGET)

# Create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the project
clean:
	rm -f $(OBJS) $(TARGET)

# Recompile everything
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild