/**
 * @file polygone.h
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#ifndef __POLYGONE_H__
#define __POLYGONE_H__
#include"../couleur.h"
#include"point.h"
#include <SDL2/SDL.h>

typedef struct polygone_s{
  void (*detruire)(void *);
  void (*afficher)(SDL_Renderer *, void *);
  void (*coordonne)(void *, int *);
  char * (*get_type)(void *);
  point_t ** points;
  unsigned int nb_points;
  couleur_t couleur;
}polygone_t;

/**
 * @brief Cette fonction initialise une figure de type polygone_t,
   Un polygone possède quatre points point1, point2, point3 et point4, une couleur et
   qautre pointeurs de fonctions qui permettent de l'afficher, de le détruire,
   d'identifier son type ainsi que les information necessaire pour la representer.

 * @param liste_points est un tableau de point qui represente les sommet du polygone.
 * @param nb  est la taille du tableau.
 * @param couleur est la couleur du polygone.
 * @requires les points de liste_points ont été initialisé par creer_point.
 * @requires les points de liste_points sont dinstincts.
 * @requires couleur a été crée par la fonction creer_couleur.
 * @require taille(liste_points) >= n.
 * @ensures resultat->detruire pointe vers une fonction de libération de l'espace mémoire.
 * @ensures resultat->afficher pointe vers une fonction d'affichage.
 * @ensures resultat->point[i] = point[i], resultat->couleur = couleur.
 * @return un pointeur vers un polygone de type polygone_t. 
 */
polygone_t * creer_polygone(point_t ** liste_points ,unsigned int nb,couleur_t couleur);

#endif