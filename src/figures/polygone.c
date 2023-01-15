/**
 * @file polygone.c
 * @author Mamady Djiguiné
 * @id          22110369 
 * @date 2022-04-10
 * 
 */
#include"polygone.h"
#include <stdlib.h>
#include <stdio.h>
#include"../dessin.h"


void detruire_polygone(void * polygone){
    polygone_t * poly = polygone;

    for(int i=0 ; i < poly->nb_points ; i++)
        poly->points[i]->detruire(poly->points[i]);
    free(poly);
}

void affiche_polygone(SDL_Renderer * rendu, void * polygone){
    polygone_t * poly=polygone;
    SDL_SetRenderDrawColor(rendu,poly->couleur.rouge, poly->couleur.vert, poly->couleur.bleu, 255);
    int i;
    for (i=0 ; i< poly->nb_points-1;i++){
       tracer_ligne(rendu,poly->points[i]->x,poly->points[i]->y,poly->points[i+1]->x,poly->points[i+1]->y);
    }
    tracer_ligne(rendu,poly->points[i]->x,poly->points[i]->y,poly->points[0]->x,poly->points[0]->y);
}

void coordonne_polygone(void * polygone, int * liste) {
    polygone_t * pol = polygone;
    int j = 0;
    liste[0] = pol->nb_points;
    for (int i = 0; i < pol->nb_points; i++) {
        point_t * p = pol->points[i];
        liste[j+1] = p->x;
        liste[j+2] = p->y;
        liste[j+3] = pol->couleur.rouge;
        liste[j+4] = pol->couleur.vert;
        liste[j+5] = pol->couleur.bleu;
        j += 5;
    }
}

char * get_type_polygone() {
    return "polygone";
}

polygone_t * creer_polygone(point_t ** list_points,unsigned int nb,couleur_t c){
    polygone_t * poly=malloc(sizeof(polygone_t));
    poly->points=malloc(nb*sizeof(**list_points));
    poly->detruire=detruire_polygone;
    poly->afficher=affiche_polygone;
    poly->coordonne = coordonne_polygone;
    poly->get_type = get_type_polygone;
     
    for(int i=0 ; i<nb ; i++){
        poly->points[i]=list_points[i];
     } 
    poly->nb_points=nb;
    poly->couleur=c;
    return poly;
}


