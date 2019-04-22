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

	void CreateSolution(int nTrucks, Client& centralDepot);
	void FillSolution (std::vector<Client> clients, int capacity);
	void PrintSolution ();
private:

};