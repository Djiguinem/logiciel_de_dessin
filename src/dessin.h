/**
Projet L2 Structures Algébriques 2022
Auteur(e): Mamady Djiguiné 22110369
*/
#ifndef __DESSIN_H__
#define __DESSIN_H__
#include <SDL2/SDL.h>

void tracer_ligne(SDL_Renderer * rendu,int x1, int y1, int x2, int y2);
void tracer_rectangle(SDL_Renderer * rendu,int x1, int y1, int x2, int y2);
void tracer_triangle(SDL_Renderer * rendu,int x1, int y1, int x2, int y2, int x3,int y3);
void tracer_octant(SDL_Renderer * rendu,int centre_x, int centre_y, int rayon);
  

#endif 
