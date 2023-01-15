#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include "src/couleur.h"
#include"src/liste_figure.h"
#include"src/figures/point.h"
#include"src/figures/segment.h"
#include"src/figures/triangle.h"
#include"src/figures/cercle.h"
#include"src/dessin.h"
#include"src/gestion_evenement.h"

#include"src/fichiers_images.h"


int inialisation_SDL(SDL_Window ** fenetre, int largeur, int hauteur, SDL_Renderer ** renderer);
void fermeture_SDL(SDL_Window * fenetre, SDL_Renderer * renderer);
void gestion_evenements(int * close, liste_figure_t * l, int * type,int *nb_point,point_t ** tab_points,couleur_t * couleur);
void rendu_fenetre(SDL_Renderer * renderer, liste_figure_t * l);



int main(int argc, char *argv[])
{
  SDL_Window * fenetre;
  SDL_Renderer * rendu;
  

  int close = inialisation_SDL(&fenetre, 1000, 1000, &rendu);
  if( close < 0 )
    return EXIT_FAILURE;

  liste_figure_t * l = creer_liste();
    affiche_raccourci();
  int i=0,type_figure;
  point_t * tab_points[5];
  couleur_t couleur = creer_couleur(0, 0, 0);
  while (!close) {
    gestion_evenements(&close,l,&type_figure,&i, tab_points,&couleur);
    rendu_fenetre(rendu, l); 
    
  }
  
  fermeture_SDL(fenetre, rendu);
  return EXIT_SUCCESS;
}



void rendu_fenetre(SDL_Renderer * rendu, liste_figure_t * l){
  SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
  SDL_RenderClear(rendu);
  for(maillon_figure_t * tmp = l->premier; tmp != NULL; tmp = tmp->suivant){
    tmp->figure->afficher(rendu, tmp->figure);
  }
  // affiche_raccourci(rendu);
  SDL_RenderPresent(rendu);  
}



int inialisation_SDL(SDL_Window ** fenetre, int largeur, int hauteur, SDL_Renderer ** rendu){
  // Quitte le programme en cas d'erreur
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return -1;
  }
  *fenetre = SDL_CreateWindow("PROJET L2 Structures Algébriques",
			      SDL_WINDOWPOS_CENTERED,
			      SDL_WINDOWPOS_CENTERED,
			      largeur, hauteur, 0);
  *rendu = SDL_CreateRenderer(*fenetre, -1, 0);
  return 0;
}



void fermeture_SDL(SDL_Window * fenetre, SDL_Renderer * rendu){
  SDL_DestroyRenderer(rendu);
  SDL_DestroyWindow(fenetre);   
  SDL_Quit();
}


