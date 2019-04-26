#pragma once
#include <vector>
#include "Route.h"

struct Truck
{
  int totalDemand;
  int routeWeight;
  RouteArray& routeArray;

  Truck(RouteArray& routeArray) : routeArray(routeArray) { }
};

class Solution {
public:
	std::vector<Truck> solution;
    int totalWeight;
	void CreateSolution (std::vector<Client>& clients, int capacity);
	
	void CreateNeighbor (int seed, Client& centralDepot);
	void PrintSolution ();
private:
	bool InsertClient(Client& client, int capacity, int indexTruck);
	void InicializeSolution(Client& centralDepot);
	bool TestAllRoutes(Client& client, int capacity);
	void MoveRoute(int seed, Client& centralDepot);
};
