#include "stdafx.h"
#include "Arista.h"

Arista::Arista() {

}

Arista::Arista(Vertice *origin, Vertice *destiny, int weight) {
	this->origin = origin;
	this->destiny = destiny;
	this->weight = weight;
}

Arista::~Arista() {

}