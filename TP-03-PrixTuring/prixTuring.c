/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c
 Exécution
 ./prixTuring < turingWinners.txt > out.txt
 Tests
 diff out.txt turingWinners.txt
 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

typedef struct{
	int annee;
	char* nom;
	char* travaux;
} Gagnant;


Gagnant *renvoieUnGagnant(){
	Gagnant *leMeilleur;
	leMeilleur=malloc(sizeof(Gagnant));
	leMeilleur->annee=scanLineAsInt();
	leMeilleur->nom=scanLine();
	leMeilleur->travaux=scanLine();
	return(leMeilleur);
}

Gagnant *readWinners(int nbGagnants){
	Gagnant *tab;
	tab=calloc(nbGagnants, sizeof(Gagnant));
	for(int k=0; k<nbGagnants; k++){
		Gagnant *nouveau;
		nouveau=malloc(sizeof(Gagnant));
		nouveau=renvoieUnGagnant();
		tab[k]=*nouveau;
		free(nouveau);
	}
	return(tab);
}
	
void printWinners(Gagnant *listeGagnants, int nbGagnants){
	for(int k=0; k<nbGagnants; k++){
		printf("%i\n", listeGagnants[k].annee);
		printf("%s\n", listeGagnants[k].nom);
		printf("%s\n", listeGagnants[k].travaux);
	}
}

int main(void)
{

	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);
	
	Gagnant *listeGagnants;
	listeGagnants=readWinners(nbGagnants);
	printWinners(listeGagnants, nbGagnants);
	
	free(listeGagnants);
	// free
	
	return EXIT_SUCCESS;
}
