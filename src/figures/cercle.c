/**
 * @file cercle.c
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#include <stdlib.h>
#include <stdio.h>
#include"cercle.h"
#include"../dessin.h"

void detruire_cercle(void * cercle_c){
	cercle_t *cercle=cercle_c;
  cercle->centre->detruire(cercle->centre);
	free(cercle);
}

void afficher_cercle(SDL_Renderer * rendu,void * cercle_c){
  cercle_t * cercle=cercle_c;
  SDL_SetRenderDrawColor(rendu,cercle->couleur.rouge,cercle->couleur.vert,cercle->couleur.bleu,255);
  tracer_octant(rendu,cercle->centre->x,cercle->centre->y,cercle->rayon);
  
}

void coordonne_cercle(void * cercle, int * liste) {
  cercle_t * c = cercle;
  liste[0] = c->centre->x;
  liste[1] = c->centre->y;
  liste[2] = c->rayon;
  liste[3] = c->couleur.rouge;
  liste[4] = c->couleur.vert;
  liste[5] = c->couleur.bleu;
}

char * get_type_cercle() {
  return "cercle";
}

cercle_t * creer_cercle(point_t * centre_c,unsigned int ray,couleur_t couleur){
  cercle_t * cercle=malloc(sizeof(cercle_t));
  cercle->detruire=detruire_cercle;
  cercle->afficher=afficher_cercle;
  cercle->get_type = get_type_cercle;
  cercle->coordonne = coordonne_cercle;
  cercle->centre=centre_c;
  cercle->rayon=ray;
  cercle->couleur=couleur;
  return cercle;
}