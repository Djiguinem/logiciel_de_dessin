#ifndef __POINT_H__
#define __POINT_H__
#include"../couleur.h"
#include <SDL2/SDL.h>


typedef struct point_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
  void (*coordonne)(void *, int *);
  char * (*get_type)(void *);
  unsigned int x;
  unsigned int y;
  couleur_t couleur;
}point_t;

/**
   @brief Cette fonction initialise une figure de type point_t.
   Un point possède une coordonnée en x et en y, une couleur et
   qautre pointeurs de fonctions qui permettent de l'afficher, de le détruire,
   d'identifier son type ainsi que les information necessaire pour la representer.

   @param x est la coordonnée en x.
   @param y est la coordonnée en y.
   @param couleur est la couleur du point.
   @requires x < Taille de la fenêtre de dessin.
   @requires y < Taille de la fenêtre de dessin.
   @requires c a été crée par la fonction creer_couleur.
   @ensures resultat->detruire pointe vers une fonction de libération de l'espace mémoire.
   @ensures resultat->afficher pointe vers une fonction d'affichage.
   @ensures resultat->get_type pointe vers une fonction qui renvoie le type de la figure.
   @ensures resultat->coordonne pointe vers une fonction d'information sur la figure.
   @ensures resultat->x = x, resultat->y = y, resultat->couleur = c
*/
point_t * creer_point(unsigned int x, unsigned int y, couleur_t c);

#endif
