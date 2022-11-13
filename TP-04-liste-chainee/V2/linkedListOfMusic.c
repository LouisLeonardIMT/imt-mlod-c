#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void afficheElement(Element e) {
	printf("%s - ",((Music*) e)->Name);
	printf("%s - ",((Music*) e)->Artist);
	printf("%s - ",((Music*) e)->Album);
	printf("%s - ",((Music*) e)->Genre);
	printf("%i - ",((Music*) e)->DiscNumb);
	printf("%i - ",((Music*) e)->TrackNumb);
	printf("%i",((Music*) e)->Year);
}

void detruireElement(Element e){
	free (((Music *)e)->Name);
    	free (((Music *)e)->Artist);
    	free (((Music *)e)->Album);
    	free (((Music *)e)->Genre);
    	free ((Music*)e);
}

bool equalsElement(Element e1, Element e2){
	return (strcmp(((Music*)e1)->Name,((Music*)e2)->Name)==0 
		&& strcmp(((Music*)e1)->Artist,((Music*)e2)->Artist)==0
		&& strcmp(((Music*)e1)->Album,((Music*)e2)->Album)==0
		&& strcmp(((Music*)e1)->Genre,((Music*)e2)->Genre)==0
		&& ((Music*)e1)->DiscNumb==((Music*)e2)->DiscNumb
		&& ((Music*)e1)->TrackNumb==((Music*)e2)->TrackNumb
		&& ((Music*)e1)->Year==((Music*)e2)->Year);
}
