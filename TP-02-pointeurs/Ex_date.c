#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef enum {
	Janvier=1,
	Fevrier,
	Mars,
	Avril,
	Mai,
	Juin,
	Juillet,
	Aout,
	Septembre,
	Octobre,
	Novembre,
	Decembre
} Mois;
	
typedef struct {
	int jour;
	Mois mois;
	int annee;
} Date;

void initialiseDate(Date *d){
	printf("Saisir le jour : ");
	scanf("%i", &(d->jour));
	printf("Saisir le mois : ");
	scanf("%i", (int *)&(d->mois));
	printf("Saisir l'année : ");
	scanf("%i", &(d->annee)); 
}

void afficheDate(Date *d){
	printf("La date (jj/mm/aaaa) est : %i/%i/%i", d->jour, d->mois, d->annee);
}

Date creerDateParCopie(){
	Date d;
	initialiseDate(&d);
	return(d);
}

Date *newDate(){
	Date *d;
	d=malloc(sizeof(Date));
	initialiseDate(d);
	return(d);
}

bool estBissextile(unsigned int annee){
	if (annee%400==0){
		return true;
	}
	else if (annee%4==0){
		if (annee%100==0){
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}
}

unsigned int nbreJours(Mois mois, unsigned int annee){
	switch(mois){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			if (estBissextile(annee)){
				return 29;
			}
			else{
				return 28;
			}
			break;
		default:
			return 0;
	}
}

int main(void){
	return 0;
	}

