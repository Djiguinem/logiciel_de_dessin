/**
 * @file segment.h
 * @author Mamady Djiguiné 
 * @id      22110369
 */

#ifndef __SEGMENT_H__
#define __SEGMENT_H__
#include"point.h"
#include"../couleur.h"
#include <SDL2/SDL.h>

typedef struct segment{
   void (*detruire)(void *);
   void (*afficher)(SDL_Renderer *,void *);
   void (*coordonne)(void *, int *);
   char * (*get_type)(void *);
   point_t * pointOxy;
	point_t * pointAxy;
   couleur_t  couleur;
}segment_t;

/**
 * @brief Cette fonction initialise une figure de type segment_t.
   Un segment possède deux points pointOxy et pointAxy, une couleur et
   qautre pointeurs de fonctions qui permettent de l'afficher, de le détruire,
   d'identifier son type ainsi que les information necessaire pour la representer.

 * @param point1  est un pointeur sur un point.
 * @param point2  est un pointeur sur un point.
 * @param couleur est la couleur du segment.
 * @requires point1 et point2 ont été initialisé par creer_point.
 * @requires point1 et point2 dinstinctents.
 * @requires couleur a été crée par la fonction creer_couleur.
 * @ensures resultat->detruire pointe vers une fonction de libération de l'espace mémoire.
 * @ensures resultat->afficher pointe vers une fonction d'affichage.
 * @ensures resultat->get_type pointe vers une fonction qui renvoie le type de la figure.
 * @ensures resultat->coordonne pointe vers une fonction d'information sur la figure.
 * @ensures resultat->pointOxy = point1, resultat->pointAxy = point2, resultat->couleur = couleur.
 * @return un pointeur vers un segment de type segment_t. 
 */
segment_t * creer_segment(point_t *point1, point_t *point2 ,couleur_t couleur);

#endif
