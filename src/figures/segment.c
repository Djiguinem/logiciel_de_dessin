/**
 * @file segment.c
 * @author Mamady Djiguiné 
 * @id      22110369
 */
#include <stdlib.h>
#include <stdio.h>
#include"segment.h"
#include"../dessin.h"



void detruire_segment(void * segment){
	segment_t *seg=segment;
	seg->pointOxy->detruire(seg->pointOxy);
	seg->pointAxy->detruire(seg->pointAxy);
	free(seg);
}

void afficher_segment(SDL_Renderer * rendu, void * segment){
 	segment_t *seg=segment;
 	SDL_SetRenderDrawColor(rendu,seg->couleur.rouge,seg->couleur.vert,seg->couleur.bleu,255);
	tracer_ligne(rendu,seg->pointOxy->x,seg->pointOxy->y,seg->pointAxy->x,seg->pointAxy->y);
}

void coordonne_segment(void * segment, int * liste) {
	segment_t * seg = segment;
	liste[0] = seg->pointOxy->x;
	liste[1] = seg->pointOxy->y;
	liste[2] = seg->pointAxy->x;
	liste[3] = seg->pointAxy->y;
	liste[4] = seg->couleur.rouge;
	liste[5] = seg->couleur.vert;
	liste[6] = seg->couleur.bleu;
}

char * get_type_segment() {
	return "segment";
}




segment_t * creer_segment(point_t * point1, point_t * point2 ,couleur_t  c){
	segment_t *segment=malloc(sizeof(segment_t));
	segment->detruire=detruire_segment;
	segment->afficher=afficher_segment;
	segment->coordonne = coordonne_segment;
  	segment->get_type = get_type_segment;
	segment->pointOxy=point1;
	segment->pointAxy=point2;
	segment->couleur=c;
	return segment;
	
}
