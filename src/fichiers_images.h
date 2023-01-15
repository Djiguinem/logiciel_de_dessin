
/**
 * @file fichiers_images.c
 * @author Abdoulaye Djibril Diallo 22112788
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __FICHIERS_IMAGES_H__
#define __FICHIERS_IMAGES_H__

#include"liste_figure.h"
#include"couleur.h"

typedef struct figure {
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
  char * (*get_type)(void *);
  unsigned int row, col, max_color;
  couleur_t ** pixels;
} bitmap_t;

typedef struct coordonne_s {
  unsigned int x,y;
} coordonne_t;


int charger_image(char * chemin, bitmap_t * b);

// typedef struct figure {
//   void (*detruire)(void *);
//   void (*afficher)(SDL_Renderer *, void *);
//   unsigned int row, col, max_color;
//   couleur_t ** pixels;
// }bitmap_t;



/**
 * @brief cette fonction permet de sauvegarder un bitmap au format de fichier ppm
 * 
 * @param chemin est un chemin vers un fichier de type ppm.
 * @param l est un pointeur vers une liste de figures.
 * @require l a été initialisé par creer_liste.
 */
void sauvegarder_image(char * chemin, liste_figure_t * l);

/**
 * @brief permet de charger un bitmap_t a partir d’un fichier au format ppm
 * 
 * @param chemin est un chemin vers un fichier de type ppm.
 * @param b est un pointeur vers une bitmap
 * @ensures resulat
 * @return return 1 si le chargement a reussi, 0 sinon 
 */
int charger_image(char * chemin, bitmap_t * b);

/**
 * @brief cette fonction crée une sauvegarde d'une liste de figure dans un fichier txt.
 * 
 * @param chemin est un chemin vers un fichier de type txt.
 * @param l est un pointeur vers une liste de figures.
 * @require l a été initialisé par creer_liste.
 * @ensures ligne(resultat) =  liste_taille(l).
 */
void sauvegarder_liste_figures(char * chemin, liste_figure_t * l);

/**
 * @brief cette fonction charge la liste de figure d'un fichier txt vers
   une liste de figure de type liste_figure_t.
 * 
 * @param chemin est un chemin  vers un fichier de type txt.
 * @param l est un pointeur vers une liste de figures.
 * @require l a été initialisé par creer_liste.
 * @ensures liste_taille(resultat) == liste_taille(l) + ligne(chemin).
 */
int charger_liste_figures(char * chemin, liste_figure_t * l);

/**
 * @brief cette fonction dessine les figures des liste_figure_t dans une bitmap.
 * @param l est un pointeur vers une liste de figures.
 * @param c est la couleur de fon du bitmap de type couleur_t.
 * @param row est un entier.
 * @param col est un entier.
 * @requires l a été initialisé par creer_liste.
 * @requires couleur a été crée par la fonction creer_couleur.
 * @ensures resultat->row = row, resultat->col = col et resultat->max = 255 
 * @return un pointeur vers une structure de type bitmap_t
 */
bitmap_t * creer_bitmap(liste_figure_t * l, couleur_t c, int row, int col);

/**
 * @brief cette fonction permet de retrouver les point du segment reliant deux points.
 * 
 * @param points est un pointeur vers un coordonée dans lespace
 * @param x1 est un antier
 * @param y1 est un antier
 * @param x2 est un antier
 * @param y2 est un antier
 * @return le nombre de points qui existe entre la position (x1,y1) et (x2,y2) de type entier. 
 */
int get_points(coordonne_t * points, int x1, int y1, int x2, int y2);

/**
 * @brief fonction de destruction d'un bitmap
 * 
 * @param bitmap est un pointeur vers une figure de type bitmap
 * @requires bitmap a eté initalisé par la fonction creer_bitmap
 */
void detruire_bitmap(void * bitmap);

/**
 * @brief fonction d'identification du type d'une figure
 * 
 * @return une chaine de caractere 
 */
char * get_type_bitmap();

/**
 * @brief fonction d'affichage d'un bitmap
 * 
 * @param rendu est un pointeur vers un SDL_Renderer
 * @param bitmap est un pointeur vers une bitmap
 */
void afficher_bitmap(SDL_Renderer * rendu, void * bitmap);

/**
 * @brief cette fonction permet d'enumerer les points constituant un cercle
 * 
 * @param points  est un pointeur sur un point.
 * @param centre_y est un antier
 * @param centre_x est un antier
 * @param rayon est un antier
 * @return return un le nombre de point qui constituent le cercle de centre (centre_x,centre_y) et de rayon r de type int 
 */
int get_cercles(coordonne_t * points, int centre_y, int centre_x, int rayon);

#endif
