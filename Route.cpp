#include <cmath>
#include <iostream>
#include "Route.h"

void RouteArray::AddRoute (Client& client)
{
	Route* route = new Route (client);
	
	if (routeArray.size() == 0)	
	{
 		route->weight = 0;
		totalWeight = 0;
	}
	else
	{
		int lastElement = routeArray.size() - 1;
		int weightAux = RouteArray::RouteWeight (routeArray[lastElement].client, client);
		routeArray[lastElement].weight = weightAux;
		route->weight = RouteArray::RouteWeight (client, routeArray[0].client);
		totalWeight += route->weight;
	}

    routeArray.push_back(*route);
}//End of function AddRoute

int RouteArray::RouteWeight (Client& A, Client& B)
{
	int aux = std::pow((double)(A.x - B.x), 2) + std::pow((double)A.y - B.y, 2);
    int weight = std::sqrt((double)aux);
    return weight;

}//End of function RouteWeight

int RouteArray::GetTotalWeight ()
{
	return totalWeight;
}

void RouteArray::PrintRoute ()
{
	for (int i = 0; i < routeArray.size(); i ++)
		std::cout << i << ": " << routeArray[i].client.id << "\n";
}//End of funtion PrintRoute

