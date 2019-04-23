#pragma once
#include <vector>
#include "Route.h"

struct Truck
{
  int totalDemand;
  RouteArray& routeArray;

  Truck(RouteArray& routeArray) : routeArray(routeArray) { }
};

class Solution {
public:
	std::vector<Truck> solution;
	int nTruck;

	void CreateSolution(Client& centralDepot);
	void FillSolution (std::vector<Client>& clients, int capacity);
	int Solution::InsertClient(Client& client, int capacity, int indexTruck);
	int TestAllRoutes(Client& client, int capacity);
	void PrintSolution ();
private:

};