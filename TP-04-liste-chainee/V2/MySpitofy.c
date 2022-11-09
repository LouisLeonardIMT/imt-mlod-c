#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>




int main(void){
	/*//Ouverture du fichier
	char fileName[] = "music.csv";
	FILE* f;
	
	//Gestion des erreurs
	if((f=fopen(fileName,"r")) == NULL) {
		printf("Code de l'erreur : %d\n", errno);
		return EXIT_FAILURE;}
	
	//Traitement du contenu
	*/
	
	char* string;
	char* found;
	string = strdup("Come Together,The Beatles,Abbey Road,Pop,1,1,1969");
	printf("Original string: '%s'\n",string);
	while((found = strsep(&string, ",")) !=NULL) {
		printf("%s\n", found);
	}
	return EXIT_SUCCESS;
}
