/**
 * @file triangle.c
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#include <stdlib.h>
#include <stdio.h>
#include"triangle.h"
#include"../dessin.h"

void detruire_triangle(void * tri_angle){
  triangle_t *triangle=tri_angle;
  triangle->point1->detruire(triangle->point1);
  triangle->point2->detruire(triangle->point2);
  triangle->point3->detruire(triangle->point3);
  free(triangle);
}


void afficher_triangle(SDL_Renderer * rendu , void * tri_angle){
  triangle_t * triangle=tri_angle;
  SDL_SetRenderDrawColor(rendu,triangle->couleur.rouge,triangle->couleur.vert,triangle->couleur.bleu,255); 
  tracer_triangle(rendu,triangle->point1->x,triangle->point1->y,triangle->point2->x,triangle->point2->y,triangle->point3->x,triangle->point3->y);
}

void coordonne_triangle(void * triangle, int * liste) {
  triangle_t * tri = triangle;
  liste[0] = tri->point1->x;
  liste[1] = tri->point1->y;
  liste[2] = tri->point2->x;
  liste[3] = tri->point2->y;
  liste[4] = tri->point3->x;
  liste[5] = tri->point3->y;
  liste[6] = tri->couleur.rouge;
  liste[7] = tri->couleur.vert;
  liste[8] = tri->couleur.bleu;
}

char * get_type_triangle() {
  return "triangle";
}

triangle_t * creer_triangle(point_t *point1,point_t *point2,point_t *point3,couleur_t c){
  triangle_t *triangle=malloc(sizeof(triangle_t));
  triangle->detruire=detruire_triangle;
  triangle->afficher=afficher_triangle;
  triangle->coordonne = coordonne_triangle;
  triangle->get_type = get_type_triangle;
  triangle->point1=point1;
  triangle->point2=point2;
  triangle->point3=point3;
  triangle->couleur=c;
  return triangle;
}