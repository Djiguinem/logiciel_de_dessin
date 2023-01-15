/**
 * @file rectangle.c
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#include <stdlib.h>
#include <stdio.h>
#include"rectangle.h"
#include"../dessin.h"

void detruire_rectangle(void * rectangle){
  rectangle_t *rect=rectangle;
  rect->point1->detruire(rect->point1);
  rect->point2->detruire(rect->point2);
  free(rect);
}

void afficher_rectangle(SDL_Renderer *rendu, void * rectangle){
  rectangle_t * rect=rectangle;
  SDL_SetRenderDrawColor(rendu,rect->couleur.rouge,rect->couleur.vert,rect->couleur.bleu,255);
  tracer_rectangle(rendu,rect->point1->x,rect->point1->y,rect->point2->x,rect->point2->y);
}

void coordonne_rectangle(void * rectangle, int * liste) {
  rectangle_t * rec = rectangle;
  liste[0] = rec->point1->x;
  liste[1] = rec->point1->y;
  liste[2] = rec->point2->x;
  liste[3] = rec->point2->y;
  liste[4] = rec->couleur.rouge;
  liste[5] = rec->couleur.vert;
  liste[6] = rec->couleur.bleu;
}

char * get_type_rectangle() {
  return "rectangle";
}

rectangle_t * creer_rectangle(point_t * p1,point_t * p2,couleur_t c){
  rectangle_t *rect=malloc(sizeof(rectangle_t));
  rect->detruire=detruire_rectangle;
  rect->afficher=afficher_rectangle;
  rect->coordonne = coordonne_rectangle;
  rect->get_type = get_type_rectangle;
  rect->point1=p1;
  rect->point2=p2;
  rect->couleur=c;
  return rect;
}
