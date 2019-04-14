#pragma once
#ifndef Grafo_H
#define Grafo_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//definicao de vertice de um grafo
//todo vertice contem um par com int id e o proprio vertice  
//e uma lista do tipo vector para as adjcacencias

class Vertice {
private:
	typedef pair <int, Vertice*> ptrVertice;
	//id sequencial
	int id; 
	//coordenadas no eixo cartesiano
	int x;
	int y;
	//demanda do cliente
	int demanda;
public:
	vector<ptrVertice> adjacencia;
	Vertice(int id, int x, int y, int demanda);
	int getId();
	int getX();
	int getY();
	int getDemanda();
};

//definicao de um grafo nao generico (especifico para o CVRP)

class Grafo
{
public:
	typedef map<int, Vertice*> VertMap;
	VertMap mapaDeCaminhos;
	void GRF_adicionarVertice(int id, int x, int y, int demanda);
	void GRF_adicionarAresta(int origem, int destino, float custo);
};

#endif // Grafo_H