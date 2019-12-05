#include "stdafx.h"
#include "Grafo.h"


using namespace std;

Grafo::Grafo(bool directed) {
	VerticeAmount = 0;
	this->directed = directed;
}

void Grafo::addVertice(string name) {
	vertices.push_back(new Vertice(name, VerticeAmount));
	VerticeAmount++;
}

void Grafo::addArista(string origin, string destiny, int weight) {
	int count = 0;
	int originPosition;
	int destinyPosition;
	Arista *a = new Arista();
	for (int i = 0; i < vertices.size(); i++) {
		if (vertices[i]->key == origin) {
			a->origin = vertices[i];
			originPosition = i;
			count++;
		}
		else if (vertices[i]->key == destiny) {
			a->destiny = vertices[i];
			destinyPosition = i;
			count++;
		}
	}
	if (count < 2) {
		delete a;
		return;
	}
	else {
		a->weight = weight;
		vertices[originPosition]->Aristas.push_back(a);
		if (!directed) {
			Arista *aristaN = new Arista();
			aristaN->origin = vertices[destinyPosition];
			aristaN->destiny = vertices[originPosition];
			vertices[destinyPosition]->Aristas.push_back(aristaN);
		}
	}
}

/*
void Grafo::DFS() {
	bool *visited = new bool[VerticeAmount];
	for (int i = 0; i < VerticeAmount; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < vertices.size(); i++) {
		Vertice *v = vertices[i];
		if (!visited[i]) {
			DFSVisit(v, visited);
		}
	}
}

void Grafo::DFSVisit(Vertice *v, bool visited[]) {
	visited[v->number] = true;
	for (int i = 0; i < v->Aristas.size(); i++) {
		if (!visited[v->Aristas[i]->destiny->number]) {
			DFSVisit(v->Aristas[i]->destiny, visited);
		}
	}
}
*/
bool Grafo::pathUV(string uName, string vName) {
	
	bool *visited = new bool[VerticeAmount];
	
	bool vertexU = false;
	
	bool vertexV = false;
	
	for (int i = 0; i < VerticeAmount; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < vertices.size(); i++) {
		Vertice *v = vertices[i];
		if (v->key == uName) {
			if (!visited[v->number]) {
				pathVisitUV(v, visited, uName, vName, &vertexU, &vertexV);
				if (vertexU && vertexV)
					return true;
				else {
					return false;
				}
			}
		}
	}
	return false;
}

void Grafo::pathVisitUV(Vertice *v, bool visited[], string uName,
	string vName, bool *vertexU, bool *vertexV) {
	visited[v->number] = true;
	
	if (v->key == uName) {
		*vertexU = true;
	}
	
	else if (v->key == vName) {
		*vertexV = true;
	}
	
	for (int i = 0; i < v->Aristas.size(); i++) {
		if (!visited[v->Aristas[i]->destiny->number]) {
			pathVisitUV(v->Aristas[i]->destiny, visited, uName, vName, vertexU, vertexV);
		}
	}
}

bool Grafo::cycle() {
	
	bool *visited = new bool[VerticeAmount];
	
	bool cyclic = false;
	
	for (int i = 0; i < VerticeAmount; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < vertices.size(); i++) {
		Vertice *v = vertices[i];


		for (int i = 0; i < VerticeAmount; i++) {
			visited[i] = false;
		}
		
		
		if (!visited[i]) {
			cycleVisit(v, visited, &cyclic, v->key);
			if (cyclic)
				return true;
		}
	}
	return false;
}

void Grafo::cycleVisit(Vertice *v, bool visited[], bool *cyclic, string key) {
	visited[v->number] = true;
	
	for (int i = 0; i < v->Aristas.size(); i++) {
		
		if (!visited[v->Aristas[i]->destiny->number]) {
			cycleVisit(v->Aristas[i]->destiny, visited, cyclic, key);
		}
	
		else {
			if (v->Aristas[i]->destiny->key == key)
				*cyclic = true;
		}
	}
}