#pragma once

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <queue>
#include "Vertice.h"
#include "Arista.h"

using namespace std;

class Grafo {
private:
	vector<Vertice*> vertices;
	int VerticeAmount;
	bool directed;
	friend class Vertice;
	friend class Arista;
public:
	Grafo(bool);
	void addVertice(string);
	void addArista(string, string, int);

	/*void Dijkstra(string);
	void Dijkstra(Vertice *);
	Grafo *copyGrafo();*/

	void DFS();
	void DFSVisit(Vertice *, bool[]);
	
	//Encontrar camino entre U y V
	bool pathUV(string uName, string vName);
	void pathVisitUV(Vertice *v, bool visited[], string uName,
		string vName, bool *foundU, bool *foundV);
	
	//Determinar si existen ciclos
	bool cycle();
	void cycleVisit(Vertice *v, bool visited[], bool *cyclic, string key);

	/*int weight(Vertice *, Vertice *);
	queue<Arista *> sortedEdges(Vertice*);*/
};


#endif 

