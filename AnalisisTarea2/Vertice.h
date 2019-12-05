#pragma once

#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>

#include "Arista.h"
using namespace std;

class Arista;
class Graph;

class Vertice {
private:
	friend class Arista;
	friend class Graph;
public:
	vector<Arista*> Aristas;
	string key;
	int number;
	Vertice();
	Vertice(std::string, int);
	~Vertice();
	std::vector<Vertice *> getAdjacents();
};

#endif 
