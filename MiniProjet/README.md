# Description du projet

Mon mini projet Ouroboros est une modification du jeu classique "Snake".
Le principe du jeu reste sensiblement le même, à quelques exceptions près. 
En effet ici, en plus de chercher à grandir en mangeant les fruits, on souhaite réaliser un Ouroboros, c'est à dire faire en sorte que la tête du serpent mange sa queue.

J'ai également décidé de faciliter le jeu en enlevant le game over lors de la collision avec un mur.
Quand ceci arrive, le serpent se téléporte simplement de l'autre côté de la grille, en ayant perdu l'une de ses cases (si le nombre de case atteint 0, alors game over)

Ajout d'un score: 
	+1 pour chaque fruit mangé
	+(taille du serpent) lors de la réalisation d'un Ouroboros
	-1 pour chaque traversée du mur
	
# Comment compiler
Dans le terminal : 
cc Ouroboros.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Comment exécuter
Dans le terminal :
./a.out

# Comment utiliser le projet
Utiliser les flèches directionnelles pour se déplacer.
Appuyer sur P pour faire une pause, et réappuyer pour relancer le jeu.

