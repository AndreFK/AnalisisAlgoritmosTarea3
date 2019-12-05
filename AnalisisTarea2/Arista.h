#pragma once

#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"

class Vertice;

class Arista {
private:
	friend class Vertice;
	friend class Graph;
public:
	Vertice * origin;
	Vertice* destiny;
	int weight;
	Arista();
	Arista(Vertice*, Vertice*, int);
	~Arista();
};


#endif 
