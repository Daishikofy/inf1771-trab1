#include "Solution.h"
#include <iostream>



void Solution::CreateSolution(int nTrucks, Client& centralDepot)
{
	nTruck = nTrucks;
  for (int i = 0; i < nTrucks; i++)
  {
	Truck truck;
    RouteArray routeArray;
   // routeArray.AddRoute(centralDepot);

    truck.routeArray = &routeArray;
	truck.routeArray->AddRoute(centralDepot);
	std::cout << "route array size: " << truck.routeArray->routeArray.size() << "\n"; 
	truck.totalDemand = 0;

    solution.push_back(truck);
	std::cout << "route array truck size: " << solution[i].routeArray->routeArray.size() << "\n";
  }

  return;
}


void Solution::FillSolution (std::vector<Client> clients, int capacity)
{
  int truck = 0;

  for (int i = 1, truck = 0; i < clients.size(); truck ++)
  {
	  std::cout << "route array size fill: " << solution[truck].routeArray->routeArray.size() << "\n";
    truck = truck % nTruck; //Se Truck > nTruck, Truck = Truck - nTruck
	int auxTotalDemand = clients[i].demand + solution[truck].totalDemand;
    if ( auxTotalDemand <= capacity)
	{
		solution[truck].routeArray->AddRoute(clients[i]);
		solution[truck].totalDemand = auxTotalDemand;
		i++;
	}
  }
}

void Solution::PrintSolution ()
{
	for (int i = 0 ; i < solution.size(); i++)
	{
		std::cout << "CAMION N " << i << "\n";
		solution[i].routeArray->PrintRoute();
	}
}