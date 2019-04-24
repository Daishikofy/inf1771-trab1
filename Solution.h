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

	void InicializeSolution(Client& centralDepot);
	void CreateSolution (std::vector<Client>& clients, int capacity);
	int InsertClient(Client& client, int capacity, int indexTruck);
	int TestAllRoutes(Client& client, int capacity);
	void CreateNeighbor (int seed);
	void PrintSolution ();
private:

};
