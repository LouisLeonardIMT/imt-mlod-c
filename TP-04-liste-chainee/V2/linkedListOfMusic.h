#include "linkedList.h"


#pragma once

#include <stdbool.h>


typedef struct {
	char* Name;
	char* Artist;
	char* Album;
	char* Genre;
	unsigned int DiscNumb;
	unsigned int TrackNumb;
	unsigned int Year;
	} Music;
	
void afficheElement(Element e);

void detruireElement(Element e);

bool equalsElement(Element e1, Element e2);
