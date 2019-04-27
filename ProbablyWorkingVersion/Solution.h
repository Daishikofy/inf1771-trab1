#pragma once
#include <vector>
#include "Route.h"

struct Truck
{
  int totalDemand;
  int routeWeight;
  RouteArray* routeArray;

  Truck(RouteArray* routeArray) : routeArray(routeArray) { }
  
  void operator=(const Truck& truck)
	{
		totalDemand = truck.totalDemand;
		routeWeight = truck.routeWeight;
		routeArray = truck.routeArray;
	}
};

class Solution {
public:
	std::vector<Truck> solution; //Vetor contendo as rotas dos differentes caminhoes
    int totalWeight; //Distancia total percorrida pelos caminhoes
    
    /*
	* Recebe um vetor de clientes e a capacidade de um caminhao e preenche o vetor de rotas.
	*/
	void CreateSolution (std::vector<Client>& clients, int capacity);

	/*
	* Recebe o deposito e modifica uma solucao atual para a transformar em uma vizinha
	*/
	void CreateNeighbor (Client& centralDepot, int method);

	/*
	* Retorna um ponteirp para uma copia da solução atual
	*/
	Solution* Duplicate();

	/*
	* Descreve a solucao 
	*/
	void PrintSolution ();

	void InnerSwap ();

private:
	int _capacity;

	bool InsertClient(Client& client, int capacity, int indexTruck);
	void InicializeSolution(Client& centralDepot);
	bool TestAllRoutes(Client& client, int capacity);
	std::vector<Truck> DuplicateTrucks();
	bool IsInsertionValid(int clientDemand, int index, int capacity);
	void UpdateTotalWeight();

	void MoveRoute(Client& centralDepot);
	
};
