// AnalisisTarea2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iostream> 
#include <string>
#include <time.h>

#include "Grafo.h"
#include "Arista.h"
#include "Vertice.h"

using namespace std;

int main()
{
	unsigned to, t1;
	to = clock();
	int opc = 0;
	
	
	while (opc != 3) {
		cin >> opc;

		if (opc == 1) {
			int val;
			int cal;
			Grafo g(false);

			cin >> val >> cal;

			string s = to_string(val);
			string s1 = to_string(cal);
			char u = s.at(0) - '0';
			char v = s1.at(0) - '0';
			int us = (int)u;
			int vs = (int)v;

			for (int i = 1; i <= us; i++) {
				g.addVertice(to_string(i));
			}

			for (int i = 0; i < vs; i++) {
				int arista;
				int arista1;
				cin >> arista >> arista1;
				string a = to_string(arista);
				string a1 = to_string(arista1);
				char uu = a.at(0) - '0';
				char vv = a1.at(0) - '0';
				int uuu = (int)uu;
				int vvv = (int)vv;
				string origen = to_string(uuu);				
				string destino = to_string(vvv);
				g.addArista(origen, destino, 0);

			}

			int val1;
			int val2;
			cin >> val1;
			cin >> val2;
			string p = to_string(val1);
			string p1 = to_string(val2);
			char o = p.at(0) - '0';
			char d = p1.at(0) - '0';
			int ori = (int)o;
			int dest = (int)d;
			string origen = to_string(ori);
			string destino = to_string(dest);
			if (g.pathUV(origen, destino)) {
				cout << 1 << endl;
			}
			else {
				cout << 0;
			}
		
		}
		else if (opc == 2){
			int val;
			int cal;
			Grafo g1(true);

			cin >> val >> cal;

			string s = to_string(val);
			string s1 = to_string(cal);
			char u = s.at(0) - '0';
			char v = s1.at(0) - '0';
			int us = (int)u;
			int vs = (int)v;

			for (int i = 1; i <= us; i++) {
				g1.addVertice(to_string(i));
			}

			for (int i = 0; i < vs; i++) {
				int arista;
				int arista1;
				cin >> arista >> arista1;
				string a = to_string(arista);
				string a1 = to_string(arista1);
				char uu = a.at(0) - '0';
				char vv = a1.at(0) - '0';
				int uuu = (int)uu;
				int vvv = (int)vv;
				string origen = to_string(uuu);
				string destino = to_string(vvv);
				g1.addArista(origen, destino, 0);

			}

			if (g1.cycle()) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
	}/*
			t1 = clock();
			double time = (double(t1 - to) / CLOCKS_PER_SEC);
			cout << time << endl;
			system("pause");*/
    return 0;
}

