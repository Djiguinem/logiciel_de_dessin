/**
Projet L2 Structures Algébriques 2022
Auteur(e):Djiguiné Mamady  22110369
*/
#include <stdlib.h>
#include <stdio.h>
#include"dessin.h"

void tracer_ligne(SDL_Renderer * rendu,int x1, int y1, int x2, int y2){

	int x,y;
  	int Dx,Dy;
  	int xincr,yincr;
 	int erreur;
  	int i;
	xincr = 0;
	yincr = 0;
	Dx = abs(x2-x1);
  	Dy = abs(y2-y1);

	if (x1 < x2)
		xincr = 1;
	else if (x1 > x2)
		xincr = -1;
	if (y1 < y2)
		yincr = 1;
	else if (y1 > y2)
		yincr = -1;
	
	x = x1;
	y = y1;
	if(Dx>Dy){
		erreur = Dx/2;
		for(i=0;i<Dx;i++){
			x += xincr;
			erreur += Dy;
			if(erreur>Dx){
				erreur -= Dx;
				y += yincr;
			}
			SDL_RenderDrawPoint(rendu,x, y);
		}
	}
	else
		{
		erreur = Dy/2;
		for(i=0;i<Dy;i++){
			y += yincr;
			erreur += Dx;
			if(erreur>Dy){
				erreur -= Dy;
				x += xincr;
			}
			SDL_RenderDrawPoint(rendu,x, y);
		}
	}
		SDL_RenderDrawPoint(rendu,x1,y1);
		SDL_RenderDrawPoint(rendu,x2,y2);
	
}

void tracer_triangle(SDL_Renderer * rendu,int x1, int y1, int x2, int y2, int x3, int y3){
	tracer_ligne(rendu,x1,y1,x2,y2);
	tracer_ligne(rendu,x2,y2,x3,y3);
	tracer_ligne(rendu,x1,y1,x3,y3);
}


void tracer_rectangle(SDL_Renderer * rendu,int x1, int y1, int x2, int y2){
	tracer_ligne(rendu,x1,y1,x2,y1);
	tracer_ligne(rendu,x1,y1,x1,y2);
	tracer_ligne(rendu,x2,y1,x2,y2);
	tracer_ligne(rendu,x1,y2,x2,y2);
}

void tracer_octant(SDL_Renderer * rendu,int centre_x, int centre_y, int rayon){
	
	int x,y,m;
	x=0;
	y=rayon;
	m=5-(4*rayon);
	
	while( x <= y){
		SDL_RenderDrawPoint(rendu,x+centre_x,y+centre_y);
		SDL_RenderDrawPoint(rendu,y+centre_x,x+centre_y);
		SDL_RenderDrawPoint(rendu,-x+centre_x,y+centre_y);
		SDL_RenderDrawPoint(rendu,-y+centre_x,x+centre_y);
		SDL_RenderDrawPoint(rendu,x+centre_x,-y+centre_y);
		SDL_RenderDrawPoint(rendu,y+centre_x,-x+centre_y);
		SDL_RenderDrawPoint(rendu,-x+centre_x,-y+centre_y);
		SDL_RenderDrawPoint(rendu,-y+centre_x,-x+centre_y);
		if( m > 0 ){
			y-=1;
			m-=8*y;
		}
		x+=1;
		m+=((8*x)+4);
	}
}





