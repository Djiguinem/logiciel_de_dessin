/**
 * @file cercle.h
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#ifndef __CERCLE_H__
#define __CERCLE_H__
#include"../couleur.h"
#include"point.h"
#include <SDL2/SDL.h>

typedef struct cercle{
    void (*detruire)(void *);
    void (*afficher)(SDL_Renderer * ,void *);
	void (*coordonne)(void *, int *);
  	char * (*get_type)(void *);
	point_t * centre;
	unsigned int rayon;
	couleur_t couleur;
}cercle_t;

/**
 * @brief Cette fonction initialise une figure de type cercle_t,
   Un cercle possède un centre de type point_t, un rayon, une couleur et 
   qautre pointeurs de fonctions qui permettent de l'afficher, de le détruire,
   d'identifier son type ainsi que les information necessaire pour la representer.
 * @param centre_c est le centre du cercle.
 * @param ray est le rayon du cercle.
 * @param couleur est la couleur du cercle.
 * @requires centre_c a été initialisé par creer_point.
 * @requires 0 < ray < taille ecrant
 * @requires couleur a été crée par la fonction creer_couleur.
 * @ensures resultat->detruire pointe vers une fonction de libération de l'espace mémoire.
 * @ensures resultat->afficher pointe vers une fonction d'affichage.
 * @ensures resultat->get_type pointe vers une fonction qui renvoie le type de la figure.
 * @ensures resultat->coordonne pointe vers une fonction d'information sur la figure.
 * @ensures resultat->centre=centre_c, resultat->rayon=ray, resultat->couleur=couleur.
 * @return un pointeur vers un cercle de type cercle_t. 
 */
cercle_t * creer_cercle(point_t * centre_c,unsigned int ray,couleur_t couleur);


#endif
