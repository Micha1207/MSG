# Makefile for MSG.
# This is part of the Micha1207's Snake Game (MSG)
#
# Author:  Micha1207
# Date:    Apr 19, 2025
# License: GNU GPL v3 (full license in LICENSE file)
# This program comes with NO WARRANTY; to the extent permitted by law.
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -Iinclude -g
LIBS    = -lncurses
TARGET  = msg
SRC_DIR = src
OBJ_DIR = obj
INSTALL_PATH = /usr/local/bin

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all
all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/ $(TARGET)

install:
	install -m 775 $(TARGET) $(INSTALL_PATH)
