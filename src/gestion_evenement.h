#ifndef __GESTION_EVENEMENTS_H__
#define __GESTION_EVENEMENTS_H__

#include"couleur.h"
#include <SDL2/SDL.h>
#include"liste_figure.h"
#include "figures/point.h"
// #include "SDL2/SDL_ttf.h"

//author: Mamadou Alpha Diallo
//numero: 22107614
void gestion_evenements(int * close, liste_figure_t * l, int * type,int *nb_point,point_t ** tab_points,couleur_t * couleur);
// void affiche_raccourci(SDL_Renderer *rendu);
void affiche_raccourci();


#endif
