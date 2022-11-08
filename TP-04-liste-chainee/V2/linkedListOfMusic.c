#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement(Element e) {
	printf("%s ",(char*) e);
}

void detruireElement(Element e){}

bool equalsElement(Element e1, Element e2){
	return strcmp(e1,e2)==0;
}

int main(void){
	Liste l,p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete("Bonjour",l);
	l = ajoutTete("Au revoir",l);
	l = ajoutTete("Poyo",l);
	l = ajoutTete("Bonjour",l);
	l = ajoutTete("POYOOO",l);
	l = ajoutTete("Bleh",l);
	l = ajoutTete("Hello",l);
	l = ajoutTete("Poyo",l);
	l = ajoutTete("POYOOO",l);

	afficheListe_i(l);

	ajoutFin_r("Je suis disponible",l);
	afficheListe_i(l);

	ajoutFin_r("Et moi non",l);
	afficheListe_i(l);

	p = cherche_i("Constantinople",l);
	printf("cherche_i(Constantinople) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i("Et moi non",l);
	if(estVide(p))
		printf("cherche_i(Et moi non) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(Et moi non) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r("Constantinople",l);
	printf("cherche_r(Constantinople) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_r("Et moi non",l);
	if(estVide(p))
		printf("cherche_r(Et moi non) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_r(Et moi non) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	printf("retirePremier_i(Bonjour)   : ");
	l = retirePremier_i("Bonjour",l);
	afficheListe_r(l);

	printf("retirePremier_i(Bonjour)   : ");
	l = retirePremier_i("Bonjour",l);
	afficheListe_r(l);

	printf("retirePremier_i(Et moi non) : ");
	l = retirePremier_i("Et moi non",l);
	afficheListe_r(l);

	printf("retirePremier_r(Poyo)   : ");
	l = retirePremier_r("Poyo",l);
	afficheListe_r(l);

	printf("retirePremier_r(Poyo)   : ");
	l = retirePremier_r("Poyo",l);
	afficheListe_r(l);

	printf("retirePremier_r(Je suis disponible)  : ");
	l = retirePremier_r("Je suis disponible",l);
	afficheListe_r(l);

	detruire_r(l);
	

	return EXIT_SUCCESS;
}
