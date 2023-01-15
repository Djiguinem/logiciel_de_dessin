/**
 * @file gestion_evenement.c
 * @author Mamadou Alpha Diallo (22107614)
 * @author Elhadj Alseiny Diallo (22011830)
 * @brief classe de gestion d'evenement
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include"gestion_evenement.h"
#include "couleur.h"
#include "figures/cercle.h"
#include "figures/point.h"
#include "figures/segment.h"
#include "figures/rectangle.h"
#include "figures/polygone.h"
#include "figures/triangle.h"
#include"liste_figure.h"
#include"fichiers_images.h"
#include <math.h>

void gestion_evenements(int * close, liste_figure_t * l, int * type,int *nb_point,point_t ** tab_points,couleur_t * couleur){
  SDL_Event event;
  // Events management
  int r=55,g=123,b=200;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      
    case SDL_KEYUP:
      switch (event.key.keysym.sym){
      case SDLK_q:
        printf("Au revoir\n");
        *close = 1;
      break;
      case SDLK_g:
      do{
        printf("Veuillez entrer la couleur en rgb\nr g b = ");
        scanf("%d %d %d",&r,&g,&b);
      }while(0>r || r>255 || 0>g || g>255 || 0>b || b>255);
        *couleur = creer_couleur(r, g, b);
      break;
      case SDLK_p:
        printf("en mode point\n");
        *type=1;
      break;
      case SDLK_s:
        printf("en mode segment\n");
        *type=2;
      break;
      case SDLK_r:
        printf("en mode rectanle\n");
        *type=3;
      break;
      case SDLK_c:
        printf("en mode cercle\n");
        *type=4;
      break;
      case SDLK_f:
        printf("en mode polygone\n");
        *type=5;
      break;
      case SDLK_t:
        printf("en mode triangle\n");
        *type=6;
      break;
      case SDLK_l:
        printf("Chargement de l'image ppm\n");
        char name_image[150] = "";
        bitmap_t * b = creer_bitmap(creer_liste(), creer_couleur(255, 255, 255), 1000, 1000);
        printf("Saisir le nom de l'image de format ppm (ex: images.ppm):\n");
        scanf("%s", name_image);
        charger_image(name_image, b);
        while (!liste_est_vide(l))
        {
          liste_extraire_debut(l);
        }
        liste_inserer_fin(l, b);
      break;
      case SDLK_z:
        printf("back\n");
        liste_extraire_debut(l);
      break;
      case SDLK_e:
        printf("enregistrement listefigure\n");
        printf("Saisir le nom du fichier text(fichier.txt)\n");
        char name_file[155]="";
        scanf("%s",name_file);
        sauvegarder_liste_figures(name_file,l);
      break;
      case SDLK_m:
        printf("restaure listefigure\n");
        printf("Saisir le nom du fichier text(fichier.txt)\n");
        char name_figures[155]="";
        scanf("%s",name_figures);
        while (!liste_est_vide(l))
        {
          liste_extraire_debut(l);
        }
        charger_liste_figures(name_figures,l);
      break;
      case SDLK_i:
        printf("sauvegarder image\n");
         printf("Saisir le nom de l'image en .ppm\n");
        char name_imageP[155]="";
        scanf("%s",name_imageP);
        sauvegarder_image(name_imageP,l);
      break;
          }      
      break;
    case SDL_QUIT:
      printf("Au revoir\n");
      *close = 1;
      break;
    case SDL_MOUSEBUTTONDOWN:
      printf("Vous avez cliqué sur la souris :\n");
      printf("\tfenêtre : %d\n",event.button.windowID);
      printf("\tbouton : %d\n",event.button.button);
      printf("\tposition : %d;%d\n",event.button.x,event.button.y);
      printf("\tnb_points : %d\n",*nb_point);
      printf("\ttype : %d\n",*type);
      if (*type==1){
        liste_inserer_fin(l,creer_point(event.button.x, event.button.y,*couleur));
      }
      else if (*type==2){
        tab_points[*nb_point]=creer_point(event.button.x, event.button.y,*couleur);
        *nb_point =*nb_point+1;
        if(*nb_point==2){
          liste_inserer_fin(l,creer_segment(tab_points[0],tab_points[1],*couleur));
          *nb_point = 0;
        }
      }
      else if (*type==3){
        tab_points[*nb_point]=creer_point(event.button.x, event.button.y,*couleur);
        *nb_point =*nb_point+1;
        if(*nb_point==2){
          liste_inserer_fin(l,creer_rectangle(tab_points[0],tab_points[1],*couleur));
          *nb_point = 0;
        }
      }
      else if (*type==4){
        tab_points[*nb_point]=creer_point(event.button.x, event.button.y,*couleur);
        *nb_point =*nb_point+1;
        if(*nb_point==2){
          int a=(tab_points[1]->x - tab_points[0]->x)*(tab_points[1]->x - tab_points[0]->x);
          int b=(tab_points[1]->y - tab_points[0]->y)*(tab_points[1]->y - tab_points[0]->y);
          int rayon = sqrt(a+b);
          liste_inserer_fin(l,creer_cercle(tab_points[0], rayon,*couleur));
          *nb_point = 0;
        }
      }
      else if (*type==5){
        tab_points[*nb_point]=creer_point(event.button.x, event.button.y,*couleur);
        *nb_point =*nb_point+1;
        if(*nb_point==5){
          liste_inserer_fin(l,creer_polygone(tab_points,*nb_point, *couleur));
          *nb_point = 0;
        }
      }else if (*type==6){
        tab_points[*nb_point]=creer_point(event.button.x, event.button.y,*couleur);
        *nb_point =*nb_point+1;
        if(*nb_point==3){
          liste_inserer_fin(l,creer_triangle(tab_points[0],tab_points[1],tab_points[2], *couleur));
          *nb_point = 0;
        }
      }
      break;
    }
  }
}

void affiche_raccourci(){
  printf("*------------------------------*\n");
  printf("*----liste des raccourcis------*\n");
  printf("*---G-creer une Couleur--------*\n");
  printf("*---P-creer un Point-----------*\n");
  printf("*---S-creer un Segment---------*\n");
  printf("*---T-creer un Triangel--------*\n");
  printf("*---R-creer un Rectangle-------*\n");
  printf("*---F-creer un Polygone--------*\n");
  printf("*---C-creer un Cercle----------*\n");
  printf("*---E-Enregidtrer des figures--*\n");
  printf("*---I-Sauvegarder une image----*\n");
  printf("*---M-Restaurer des figures----*\n");
  printf("*---Z-Retour-------------------*\n");
  printf("*---Q-Quiter-------------------*\n");
  printf("*------------------------------*\n\n");
  printf("*selon votre choix vous pouver cliquer sur la fenetre pour déssiner*\n");

}

// void affiche_raccourci(SDL_Renderer *rendu){
//   TTF_Init();
//   TTF_Font *font;
//   SDL_Surface *text;
//   SDL_Surface *text1;

//   SDL_Texture *texture;
//   SDL_Texture *texture1;
//   SDL_Color color = {0, 0, 0, 255};
//   font = TTF_OpenFont("Gotham.ttf", 30);
//   char chaine[1000] = "q=>Quiter,\t\tg=>Couleur,\t\tt=>Triangle,\t\tr=>rectangle,\t\te=>Enregistrement liste Figure,\t\tf=>Polygone";
//   char chaine1[1000] = "P=>Point,\t\tC=>Cercle,\t\ti=>Sauvegarde image,\t\tm=>Restaure Figure,\t\ts=>Segment,\t\tz=>Retour";

//   int texW = 800;
//   int texH = 50;
//   SDL_Rect dstrect = {0, 0, texW, texH};
//   SDL_Rect dstrect1 = {0,55, texW, texH};
//   text = TTF_RenderText_Blended(font, chaine, color);
//   text1 = TTF_RenderText_Blended(font, chaine1, color);

//   texture = SDL_CreateTextureFromSurface(rendu, text);
//   texture1 = SDL_CreateTextureFromSurface(rendu, text1);
//   SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
//   SDL_QueryTexture(texture1, NULL, NULL, &texW, &texH);
//   SDL_RenderCopy(rendu, texture, NULL, &dstrect);
//   SDL_RenderCopy(rendu, texture1, NULL, &dstrect1);
//   TTF_CloseFont(font);
//   SDL_DestroyTexture(texture);
//   SDL_FreeSurface(text);
//   SDL_DestroyTexture(texture1);
//   SDL_FreeSurface(text1);
//   TTF_Quit();
// }
