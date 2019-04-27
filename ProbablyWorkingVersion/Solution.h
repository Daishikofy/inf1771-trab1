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
	std::vector<Truck> solution;
    int totalWeight;
    int _capacity;
    
	void CreateSolution (std::vector<Client>& clients, int capacity);
	void CreateNeighbor (Client& centralDepot);
	Solution* Duplicate();
	void PrintSolution ();
private:
	bool InsertClient(Client& client, int capacity, int indexTruck);
	void InicializeSolution(Client& centralDepot);
	bool TestAllRoutes(Client& client, int capacity);
	void MoveRoute(Client& centralDepot);
	std::vector<Truck> DuplicateTrucks();
	bool IsInsertionValid(int clientDemand, int index, int capacity);
	void UpdateTotalWeight();
};
