# Nom de l'exécutable
EXEC = code

# Répertoires
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
LIB_DIR = lib

# Fichiers sources
SRC = $(wildcard $(SRC_DIR)/*.c)

# Fichiers objets dans build/
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

# Commande de compilation
CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -std=c99 -g -I$(INCLUDE_DIR)

# Nom de la bibliothèque statique
STATIC_LIB = $(LIB_DIR)/libprime.a

# Cible par défaut
all: $(EXEC)

# L'exécutable dépend de la bibliothèque statique et des fichiers objets
$(EXEC): $(STATIC_LIB) $(BUILD_DIR)/main.o
	$(CC) $(BUILD_DIR)/main.o -L$(LIB_DIR) -lprime -o $(EXEC)

# Compilation des fichiers .c en .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Création de la bibliothèque statique
$(STATIC_LIB): $(BUILD_DIR)/prime.o
	$(AR) rcs $@ $^

# Nettoyage
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC) $(STATIC_LIB)

# Rebuild complet
re: clean all
