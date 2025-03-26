CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# Noms des fichiers
EXEC = ahissouexo1
OBJS = ahissouexo1.o ahissoulisteint.o
HEADERS = ahissoulisteint.h

# Règle par défaut : compilation complète
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers .c en .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers intermédiaires et binaires
# Détection de l'OS pour choisir la bonne commande de suppression
OS := $(shell uname 2>/dev/null || echo Windows)

tidy:
ifeq ($(OS), Windows)
	del /Q $(OBJS)
else
	rm -f $(OBJS)
endif

clean: tidy
ifeq ($(OS), Windows)
	del /Q $(EXEC) saveliste.bin
else
	rm -f $(EXEC) saveliste.bin
endif
