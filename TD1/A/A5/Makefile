# Nom de l'exécutable
EXEC = A5

# Fichier source
SRC = A5.c

# Fichier objet
OBJ = $(SRC:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra

# Règle principale : compiler l'exécutable
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# 💡 Target pour arrêter la compilation après le pré-processing
preprocess:
	$(CC) -E $(SRC) -o A5.i

# Nettoyage des fichiers compilés
clean:
	rm -f $(OBJ) $(EXEC) A5.i

# Supprime tout et recompile proprement
re: clean all
