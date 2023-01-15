/**
 * @file rectangle.h
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include"../couleur.h"
#include"point.h"
#include <SDL2/SDL.h>

typedef struct rectangle{
    void (*detruire)(void *);
    void (*afficher)(SDL_Renderer * ,void *);
    void (*coordonne)(void *, int *);
    char * (*get_type)(void *);
    point_t *point1;
    point_t *point2;
    couleur_t couleur;
}rectangle_t;

/**
 * @brief Cette fonction initialise une figure de type rectangle_t.
     Un rectangle possède deux points, une couleur et
     qautre pointeurs de fonctions qui permettent de l'afficher, de le détruire,
     d'identifier son type ainsi que les information necessaire pour la representer.

 * @param point1  est un pointeur sur un point.
 * @param point2  est un pointeur sur un point.
 * @param couleur est la couleur du rectangle.
 * @requires point1 et point2 ont été initialisé par creer_point.
 * @requires point1 et point2 dinstincts.
 * @requires couleur a été crée par la fonction creer_couleur.
 * @ensures resultat->detruire pointe vers une fonction de libération de l'espace mémoire.
 * @ensures resultat->afficher pointe vers une fonction d'affichage.
 * @ensures resultat->get_type pointe vers une fonction qui renvoie le type de la figure.
 * @ensures resultat->coordonne pointe vers une fonction d'information sur la figure.
 * @ensures resultat->point1 = point1 et resultat->point2 = point2.
 * @ensures resultat->couleur = couleur.
 * @return un pointeur vers un rectangle de type rectangle_t. 
 */
rectangle_t * creer_rectangle( point_t * p1,point_t * p2,couleur_t couleur);

#endif
