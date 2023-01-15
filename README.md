Projet: Logiciel de dessin 
Langage: C
Discipline: Structure Algébrique

Information: Nous avons implémenté une fonction afin d'afficher les raccourcis permettant de dessiner sur 
la fénétre graphique, mais nous nous sommes rendu compte que les ordinateurs de l'université 
n'avaient pas la librairie "SDL_ttf.h" installée, alors on a opté pour un README et un menu sur 
la console decrivant comment utiliser les fonctionnalités de notre application.

## Membres du groupe:

	DJIGUINE Mamady				22110369	(Les figures)
	DIALLO Elhadj Alseiny		22011830	(Les contrats et les tests unitaire et Niveau 1 interface G )
	DIALLO Abdoulaye Djibril 	22112788	(Les images)
	DIALLO Mamadou Alpha	  	22107614	(interface graphique)
	
Les commandes principales sont : placez vous sur la racine du projet :
```bash
	
	make 		pour compiler le projet
	make test 	pour lancer le test 
	./projet  	pour exécuter le projet
```
	
Les raccourcis claviers pour dessiner  les figures sont :	

- Un point correspond à un clic de la souris dans une zone du rendu graphique 

	```bash 
	s -> pour le segment nécéssites deux points 
	t -> pour dessiner un triangle  nécéssite trois points 
	r -> pour dessiner un rectangle nécéssite deux points
	c -> pour dessiner un cercle 	 nécéssite un centre et un rayon 
	f -> pour dessiner un polygone  nécéssites cinq points coté graphique
	g -> pour creer une couleur (voir la console )

	```
-Les raccourcis de sauvegarde et de chargement:
	```bash 
	i ->  pour sauvegarder dessin dans un fichier.ppm 
	e ->  pour sauvegarder le dessin  dans un fichier .txt
	m ->  pour charger la liste des figures d'un fichier.txt
	l ->  charger un bitmap_t a partir d’un fichier au format .ppm 
	z ->  pour supprimer une figure dans la liste
	```
## Problème possible:

Lors du chargement d'image d'un fichier .ppm dans liste figure on remarque une distorsion
de l'image plus ou moins importante, par consequence la fonction charger_image(..) ne 
valide pas le test.

Merci de la tester tout de même.
