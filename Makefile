CC = gcc
CFLAGS = -O3 -g
LDFLAGS = -lm

TARGET=test mandel

all: $(TARGET)

# Construction de la bibliothèque partagée libppm.so
libppm.so: ppm.c
	$(CC) $(CFLAGS) -fpic -shared $^ -o $@

# Construction de l'exécutable test
test: main.c libppm.so
	$(CC) $(CFLAGS) main.c -L. -Wl,-rpath,. -lppm $(LDFLAGS) -o $@

# Construction de l'exécutable mandel
mandel: mandel.c libppm.so
	$(CC) $(CFLAGS) mandel.c -L. -Wl,-rpath,. -lppm $(LDFLAGS) -o $@



# Nettoyage des fichiers générés
clean:
	rm -fr $(TARGET) *.so

