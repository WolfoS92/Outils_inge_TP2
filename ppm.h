#ifndef PPM_H
#define PPM_H

// Structure pour représenter un pixel avec ses trois composantes (rouge, vert, bleu)
struct ppm_pixel {
  unsigned char r;
  unsigned char g; 
  unsigned char b; 
};

// Fonction inline pour définir les valeurs d'un pixel
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r; 
  px->g = g; 
  px->b = b; 
}

// Structure pour représenter une image PPM
struct ppm_image {
  unsigned int width;  // Largeur de l'image (en pixels)
  unsigned int height; // Hauteur de l'image (en pixels)
  struct ppm_pixel *px; // Tableau contenant tous les pixels de l'image
};

// Fonction pour initialiser une image avec une largeur et une hauteur données
int ppm_image_init(struct ppm_image *im, int w, int h);

// Fonction pour libérer la mémoire utilisée par une image
int ppm_image_release(struct ppm_image *im);

// Fonction inline pour définir un pixel dans l'image à des coordonnées (x, y)
static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  // Calcule l'adresse du pixel correspondant dans le tableau
  struct ppm_pixel *px = im->px + im->width * y + x;
  // Définit les valeurs du pixel
  ppm_setpixel(px, r, g, b);
}

// Fonction pour enregistrer une image dans un fichier au format PPM
int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */

