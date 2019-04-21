#include <cmath>
#include <iostream>
#include "Route.h"

void RouteArray::AddRoute (Client& client)
{
	Route* route = new Route (client);
	
	if (routeArray.size() == 0)	
	{
		route->weight = 0;
		totalDemand = client.demand;
	}
	else
	{
		totalDemand += client.demand;
		int lastElement = routeArray.size() - 1;
		routeArray[lastElement].weight = RouteArray::RouteWeight (routeArray[lastElement].client, client);
		route->weight = RouteArray::RouteWeight (client, routeArray[0].client);
	}
    routeArray.push_back(*route);
}//End of function AddRoute

int RouteArray::RouteWeight (Client& A, Client& B)
{
	int aux = std::pow((double)(A.x - B.x), 2) + std::pow((double)A.y - B.y, 2);
    int weight = std::sqrt((double)aux);
    return weight;
}//End of function RouteWeight

int RouteArray::GetTotalDemand ()
{
	return totalDemand;
}

void RouteArray::PrintRoute (Route& route)
{
	std::cout << route.client.demand << " " << route.weight << "\n";
}//End of funtion PrintRoute

