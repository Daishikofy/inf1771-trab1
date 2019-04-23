#include "Solution.h"
#include <iostream>



void Solution::CreateSolution(int nTrucks, Client& centralDepot)
{
	nTruck = nTrucks;
  for (int i = 0; i < nTrucks; i++)
  {
	
    RouteArray* routeArray = new RouteArray;
	routeArray->AddRoute(centralDepot);

	Truck* truck = new Truck (*routeArray);
	std::cout << "route array size: " << truck->routeArray.routeArray.size() << "\n"; 
	truck->totalDemand = 0;

    solution.push_back(*truck);
	std::cout << "route array truck size: " << solution[i].routeArray.routeArray.size() << "\n";
  }

  return;
}


void Solution::FillSolution (std::vector<Client>& clients, int capacity)
{
  
  //Enchendo em largura
  for (int i = 1, truck = 0; i < clients.size(); truck ++)
  {
	std::cout << "route array : " << i << " truck " << truck << "\n";
    truck = truck % nTruck; //Se Truck > nTruck, Truck = Truck - nTruck
	int auxTotalDemand = clients[i].demand + solution[truck].totalDemand;
	std::cout << "total demand " << auxTotalDemand << "\n";
    if ( auxTotalDemand <= capacity)
	{
		solution[truck].routeArray.AddRoute(clients[i]);
		solution[truck].totalDemand = auxTotalDemand;
		i++;
	}
  }
/*
	//Enchendo em altura
	int truck;
	for (int i = 1, truck = 0; i < clients.size() ; i ++)
  {
	std::cout << "route array : " << i << " truck " << truck << "\n";
	truck = truck % nTruck; //Se Truck > nTruck, Truck = Truck - nTruck
	int auxTotalDemand = clients[i].demand + solution[truck].totalDemand;
	int diff = auxTotalDemand - capacity;
	std::cout << "difference " << diff  << "\n";
    if ( auxTotalDemand <= capacity)
	{
		solution[truck].routeArray.AddRoute(clients[i]);
		solution[truck].totalDemand = auxTotalDemand;	
	}
	else
	{
		truck++;
		i--;
	}
  }*/
}

void Solution::PrintSolution ()
{
	for (int i = 0 ; i < solution.size(); i++)
	{
		std::cout << "CAMION N " << i << "\n";
		solution[i].routeArray.PrintRoute();
	}
}