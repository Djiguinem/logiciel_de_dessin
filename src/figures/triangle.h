/**
 * @file triangle.h
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__
#include"point.h"
#include"../couleur.h"
#include <SDL2/SDL.h>

typedef struct triangle{
    void (*detruire)(void *);
    void(*afficher)(SDL_Renderer * ,void *);
    void (*coordonne)(void *, int *);
    char * (*get_type)(void *);
    point_t *point1;
    point_t *point2;
    point_t *point3;
    couleur_t couleur;
}triangle_t;

/**
 * @brief Cette fonction initialise une figure de type triangle_t.
     Un triangle possède trois points point1, point2 et point3, une couleur et
     qautre pointeurs de fonctions qui permettent de l'afficher, de le détruire,
     d'identifier son type ainsi que les information necessaire pour la représenter.

 * @param point1  est un pointeur sur un point.
 * @param point2  est un pointeur sur un point.
 * @param point3  est un pointeur sur un point.
 * @param couleur est la couleur du triangle.
 * @requires point1, point2 et point3 ont été initialisés par creer_point.
 * @requires point1, point2 et point3 dinstincts.
 * @requires couleur a été crée par la fonction creer_couleur.
 * @ensures resultat->detruire pointe vers une fonction de libération de l'espace mémoire.
 * @ensures resultat->afficher pointe vers une fonction d'affichage.
 * @ensures resultat->get_type pointe vers une fonction qui renvoie le type de la figure.
 * @ensures resultat->coordonne pointe vers une fonction d'information sur la figure.
 * @ensures resultat->point1 = point1, resultat->point2 = point2, et resultat->point3 = point3.
 * @ensures resultat->couleur = couleur.
 * @return un pointeur vers un triangle de type triangle_t. 
 */
triangle_t * creer_triangle(point_t *point1,point_t *point2,point_t *point3,couleur_t couleur);

#endif
