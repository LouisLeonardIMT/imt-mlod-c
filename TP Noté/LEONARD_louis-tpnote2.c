#include <stdlib.h>
#include <stdio.h>

// To compile : gcc -Wall -o LEONARD_louis-tpnote LEONARD_louis-tpnote2.c

// DEFINE

#define CHUNK_SIZE_MAX 5

//1. Définition 

typedef struct{
	char chaine[5];
	unsigned int chunkSize;
	struct String* suiv;
	} String;

//2. Implémentation de string_new

char* decoupe(char* texte){
	char* texteTronque=(char*) malloc(5*sizeof(char));
	for (int i=0 ; i<5; i=i+1){
		texteTronque[i]=texte[i];
		}
	return texteTronque;
	} 

String* string_new(char* texte){
	int i=0;
	int tailleTexte = sizeof(texte);
	if (tailleTexte<5){
		String* texteEnString = malloc(sizeof(String));
		for (i=0 ; i<tailleTexte ; i=i+1){
			texteEnString->chaine[i]=texte[i];
			}
		texteEnString->chunkSize=tailleTexte;
		return texteEnString;
		}
	printf("Supérieur à 5");
	}
/*
	while (i <= tailleTexte){
		if (i%5==0){
			String* texteEnString = malloc(sizeof(String);
			texteEnString->chaine = decoupe(texte);
			
			}
		nouveauString.chaine[i%5]=texte[i];
		i=i+1;
*/

// 3. Afficher le texte

void AfficheString(String* texte){
	for (int i=0; i<sizeof(texte->chaine); i=i+1){
		printf("%c", texte->chaine[i]);
		}
	AfficheString(texte->suiv);
	return;
	}

int main(void){
	String* Test;
	Test=string_new("tes");
	AfficheString(Test);
	return 0;
	}
