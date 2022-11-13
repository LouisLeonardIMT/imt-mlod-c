// Pour compiler : gcc -W -Wall linkedList.c linkedListOfMusic.c MySpitofy.c -o MySpitofy
// Pour exécuter : ./MySpitofy < music.csv > out.txt
// A l'exécution, on rencontre une erreur de segmentation à chaque fois qu'on cherche à afficher un élément de la liste, ou alors la liste en entier.

#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

Music* lineAsMusic(char* line){
	Music* newMusic = malloc(sizeof(Music));
	newMusic->Name = strdup(strsep(&line, ","));
	newMusic->Artist = strdup(strsep(&line, ","));
	newMusic->Album = strdup(strsep(&line, ","));
	newMusic->Genre = strdup(strsep(&line, ","));
	newMusic->DiscNumb = atoi(strsep(&line, ","));
	newMusic->TrackNumb = atoi(strsep(&line, ","));
	newMusic->Year = atoi(strsep(&line, ","));
	return newMusic;
	}
	
Liste creerLaListeMusiques(FILE* f){
	char line[1024];
	Music* mus;
	Liste l = malloc(sizeof(Liste));
	while(fgets(line,1024,f) != NULL){
		mus = lineAsMusic(fgets(line,1024,f));
		ajoutFin_i(mus,l);
	}
	return(l);
	}

int main(void){
	//Ouverture du fichier
	char fileName[] = "music.csv";
	FILE* f;
	f = fopen(fileName,"r");
	//Gestion des erreurs
	if((f=fopen(fileName,"r")) == NULL) {
		printf("Code de l'erreur : %d\n", errno);
		return EXIT_FAILURE;}
	
	//Traitement du contenu
	Liste L;
	L=creerLaListeMusiques(f);
	printf("La liste a été créée");
	printf("%d\n", estVide(L));
	afficheElement((Music*)L->val);
	
	//Libération de la mémoire
	
	return EXIT_SUCCESS;
}
