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
	int nTruck;
    int totalWeight;
	void InicializeSolution(Client& centralDepot);
	void CreateSolution (std::vector<Client>& clients, int capacity);
	bool InsertClient(Client& client, int capacity, int indexTruck);
	bool TestAllRoutes(Client& client, int capacity);
	void CreateNeighbor (int seed);
	void PrintSolution ();
private:

};
