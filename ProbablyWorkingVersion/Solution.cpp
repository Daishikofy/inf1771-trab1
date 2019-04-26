#include "Solution.h"
#include <iostream>



void Solution::InicializeSolution(Client& centralDepot)
{
    RouteArray* routeArray = new RouteArray;
	routeArray->AddRoute(centralDepot);

	Truck* truck = new Truck (*routeArray);
	truck->totalDemand = 0;
	truck->routeWeight = 0;
    solution.push_back(*truck);

  return;
}


void Solution::CreateSolution (std::vector<Client>& clients, int capacity)
{
	InicializeSolution(clients[0]);
	int truck = 0;

	for (int i = 1; i < clients.size() ; i ++)
	{
		bool succesInsert = InsertClient (clients[i], capacity, truck);
		if (!succesInsert)
		{
			bool insertOtherRoute = TestAllRoutes(clients[i], capacity);
			if(!insertOtherRoute)
			{
				InicializeSolution(clients[0]);
				truck++;
				bool succesInsert = InsertClient (clients[i], capacity, truck);
				if (!succesInsert)
					std::cout << "Demanda do client " << clients[i].id << " maior do que a capacidade total de um caminhao\n";
			}
		}
	} 

	for (int i = 0; i < solution.size(); i++)
	{
		solution[i].routeWeight = solution[i].routeArray.GetTotalWeight();
	}
}


bool Solution::InsertClient(Client& client, int capacity, int indexTruck)
{
	int auxTotalDemand = client.demand + solution[indexTruck].totalDemand;
    if ( auxTotalDemand <= capacity)
	{
		solution[indexTruck].routeArray.AddRoute(client);
		solution[indexTruck].totalDemand = auxTotalDemand;
		return true;
	}
	return false;
}

bool Solution::TestAllRoutes(Client& client, int capacity)
{
	for (int i = 0; i < solution.size(); i++)
	{
		int auxTotalDemand = client.demand + solution[i].totalDemand;
		if ( auxTotalDemand <= capacity)
		{
			solution[i].routeArray.AddRoute(client);
			solution[i].totalDemand = auxTotalDemand;
			return true;
		}
	}
	return false;
}

void Solution::CreateNeighbor (int seed, Client& centralDepot)
{
	Client& _centralDepot = centralDepot;
	//Solution::MoveRoute(seed);
	srand(seed);
	
	int indexRoute = rand() % solution.size(); // perigo, se solution estiver vazia, ocorre divisao por zero!!
	int indexClient = rand() % solution[indexRoute].routeArray.routeArray.size();
	if (indexClient == 0)
		indexClient++;
	
	//Escolhe uma rota aleatoria
	//Remove um cliente aleatorio desta rota
	Route* routeAux = solution[indexRoute].routeArray.RemoveRoute(indexClient);
}

void Solution::MoveRoute(int seed)
{/*
	srand(seed);
	
	int indexRoute = rand() % solution.size(); // perigo, se solution estiver vazia, ocorre divisao por zero!!
	int indexClient = rand() % solution[indexRoute].routeArray.routeArray.size();
	if (indexClient == 0)
		indexClient++;
	
	//Escolhe uma rota aleatoria
	//Remove um cliente aleatorio desta rota
	Route* routeAux = solution[indexRoute].routeArray.RemoveRoute(indexClient);
	if (solution[indexRoute].routeArray.routeArray.size() < 2);
	//Caso uma roa estaja vazia, remover ela.
		//solution.erase(solution.begin() + indexRoute);

	
	//Escolhe uma rota aleatoria
	int indexNewRoute = rand() % (solution.size() + 1);
	if (indexNewRoute >= solution.size())
		Solution::InicializeSolution(_centralDepot);
	//Insere o cliente aleatoriamente nesta rota
	indexClient = rand() % solution[indexRoute].routeArray.routeArray.size();
	solution[indexRoute].routeArray.InsertRoute(indexClient, routeAux);
	*/
	
	//Equilibra os pesos
}


void Solution::PrintSolution ()
{
	int soma = 0;
	for (int i = 0 ; i < solution.size(); i++)
	{
		int n = i + 1;
		std::cout << "CAMION N " << n << " - " << solution[i].routeArray.GetTotalWeight() << " km\n";
		solution[i].routeArray.PrintRoute();
		soma += solution[i].routeArray.GetTotalWeight();
	}
	std::cout << "Distancia total: " << soma << " km\n";
}

