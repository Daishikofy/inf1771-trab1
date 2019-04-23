#pragma once
#include <vector>
#include "DataArray.h"

struct Route
{
  int weight; //Peso entre este elemento e o prox da lista
  Client& client;
  
  Route(Client& client) : client(client) { }
};

class RouteArray
{
public:
    std::vector<Route> routeArray;
	int GetTotalWeight ();
    void AddRoute (Client& client);
	void PrintRoute ();

private:
	int totalWeight;
	int RouteWeight (Client& A, Client& B);
	
};