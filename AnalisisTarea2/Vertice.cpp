#include "stdafx.h"
#include "Vertice.h"

using namespace std;

Vertice::Vertice() {
	key = "";
	number = -4;
}

Vertice::Vertice(string key, int number) {
	this->key = key;
	this->number = number;
}

Vertice::~Vertice() {

}

vector<Vertice *> Vertice::getAdjacents() {
	vector<Vertice *> adjacents;
	for (int i = 0; i < Aristas.size(); i++) {
		adjacents.push_back(Aristas[i]->destiny);
	}
	return adjacents;
}