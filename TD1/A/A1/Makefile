# Nom de l'exécutable
EXEC = A1

# Fichier source
SRC = A1.c

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
	$(CC) -E $(SRC) -o A1.i

# Nettoyage des fichiers compilés
clean:
	rm -f $(OBJ) $(EXEC) A1.i

# Supprime tout et recompile proprement
re: clean all
