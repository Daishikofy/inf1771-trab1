#include "Solution.h"
#include <iostream>



void Solution::CreateSolution(Client& centralDepot)
{
    RouteArray* routeArray = new RouteArray;
	routeArray->AddRoute(centralDepot);

	Truck* truck = new Truck (*routeArray);
	truck->totalDemand = 0;
	truck->routeWeight = 0;
    solution.push_back(*truck);

  return;
}


void Solution::FillSolution (std::vector<Client>& clients, int capacity)
{
	CreateSolution(clients[0]);
	int truck = 0;

	for (int i = 1; i < clients.size() ; i ++)
	{
		int succesInsert = InsertClient (clients[i], capacity, truck);
		if (!succesInsert)
		{
			int insertOtherRoute = TestAllRoutes(clients[i], capacity);
			if(!insertOtherRoute)
			{
				CreateSolution(clients[0]);
				truck++;
				int succesInsert = InsertClient (clients[i], capacity, truck);
				if (!succesInsert)
					std::cout << "Demenda do client " << clients[i].id << " maior do que a capacidade total de um caminhao\n";
			}
		}
	} 

	for (int i = 0; i < solution.size(); i++)
	{
		solution[i].routeWeight = solution[i].routeArray.GetTotalWeight();
	}
}


int Solution::InsertClient(Client& client, int capacity, int indexTruck)
{
	int auxTotalDemand = client.demand + solution[indexTruck].totalDemand;
    if ( auxTotalDemand <= capacity)
	{
		solution[indexTruck].routeArray.AddRoute(client);
		solution[indexTruck].totalDemand = auxTotalDemand;
		return 1;
	}
	return 0;
}

int Solution::TestAllRoutes(Client& client, int capacity)
{
	for (int i = 0; i < solution.size(); i++)
	{
		int auxTotalDemand = client.demand + solution[i].totalDemand;
		if ( auxTotalDemand <= capacity)
		{
			solution[i].routeArray.AddRoute(client);
			solution[i].totalDemand = auxTotalDemand;
			return 1;
		}
	}
	return 0;
}


void Solution::PrintSolution ()
{
	for (int i = 0 ; i < solution.size(); i++)
	{
		int n = i + 1;
		std::cout << "CAMION N " << n << " - " << solution[i].routeWeight << " km\n";
		solution[i].routeArray.PrintRoute();
	}
}

