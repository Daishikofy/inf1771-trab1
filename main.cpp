#include <vector>
#include <string>
#include <iostream>

#include "Route.h"
#include "Solution.h"
#include "DataArray.h"


int main ()
{
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray dataArray;

	dataArray.ReadFile(clients, capacity, nTrucks, "text.txt");

	std::cout << capacity << "\n";
	std::cout << nTrucks << "\n";
	/*
	for (int i!m = 0; i<clients.size(); i++)
	{
		DataArray::PrintClient(clients[i]);
	}
	RouteArray route;
	RouteArray* routePtr;
	routePtr = &route;
	routePtr->AddRoute(clients[1]);
	routePtr->AddRoute(clients[2]);
	
	route.AddRoute(clients[1]);
	route.AddRoute(clients[2]);
	*/
	

	Solution* solution = new Solution;
	std::vector<Client> aux;

	aux.push_back(clients[0]);
	aux.push_back(clients[1]);
	aux.push_back(clients[2]);
	aux.push_back(clients[3]);
	aux.push_back(clients[4]);

		 
	solution->FillSolution(clients,capacity);

	solution->PrintSolution();
	/*
	//TORCAR  REFERENCIA POR PONTEIRO PARA REFENCIA POR REFERENCIA
	solution.solution[0].routeArray->AddRoute(clients[1]);
	solution.solution[0].routeArray->AddRoute(clients[2]);
	//solution.FillSolution(clients,capacity);
	*/
	
	
	return 0;
}


