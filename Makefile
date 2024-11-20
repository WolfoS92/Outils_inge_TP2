CC=gcc
CFLAGS=-O3 -g

TARGET=test mandel

# Construction de la bibliothèque partagée libppm.so
libppm.so: ppm.c
	$(CC) $(CFLAGS) -fpic -shared $^ -o $@

# Construction de l'exécutable test
test: main.c libppm.so
	$(CC) $(CFLAGS) main.c -L. -lppm -o test

# Construction de l'exécutable mandel
mandel: mandel.c libppm.so
	$(CC) $(CFLAGS) mandel.c -L. -lppm -o mandel

# Nettoyage des fichiers générés
clean:
	rm -fr $(TARGET) *.so
