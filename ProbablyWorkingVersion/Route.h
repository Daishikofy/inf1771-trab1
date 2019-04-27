#pragma once
#include <vector>
#include "DataArray.h"

struct Route
{
  int weight; //Peso entre este elemento e o prox da lista
  Client* client;
  
  Route(Client* client) : client(client) { }
  
  void operator=(const Route& route)
	{
		weight = route.weight;
		client = route.client;
	}
};

class RouteArray
{
public:
    std::vector<Route> routeArray; //Vetor apontando para os clientes

	/*
	* Retorna a distancia total percorrida neste caminho
	*/
	int GetTotalWeight ();

	/*
	* Recebe um ponteiro para um cliente e o adiciona no caminho corrente
	*/
    void AddRoute (Client* client);

	/*
	* Recebe um indexo e remove o espaco correspondente no vetor de rotas, 
	* equilibrando os peso em seguida e retornando a estrutura guardada neste
	* espaco
	*/
    Route* RemoveRoute (int index);

	/*
	* Recebe um indexo e um ponteiro para uma estrutura
	* Insere essa estrutura no indexo correspondente na rota corrente
	* Equilibra os pesos em seguida
	*/
    void InsertRoute (int index, Route* route);

	void SwapRoute (int indexA, int indexB);

	/*
	* Retorna uma copia da rota corrente
	*/
	RouteArray* Duplicate();

	/*
	* Descreve a rota corrente
	*/
	void PrintRoute ();

private:
	int totalWeight;

	void UpdateSurroundWeight(int index);
	void UpdateTotalWeight();
	int RouteWeight (Client* A, Client* B);	
};
