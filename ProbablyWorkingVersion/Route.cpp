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


Route* RouteArray::RemoveRoute (int index)
{
	int nextClient;
	if (index == routeArray.size()-1)
		nextClient = 0;
	else
		nextClient = index + 1;

	int weightAux = RouteArray::RouteWeight (routeArray[index - 1].client, routeArray[nextClient].client);
	routeArray[index - 1].weight = weightAux;
	
	//Remover o route
	Route* route = new Route (routeArray[index].client);

	std::cout << "client recuperado: " << &route->client << "\n";			
	routeArray.erase((routeArray.begin() + index));
	
	std::cout << "client recuperado depois de erase: " << &route->client << "\n";	
	RouteArray::UpdateTotalWeight();

	return route;
}//End of function RemoveRoute



void RouteArray::InsertRoute (int index, Route* route)
{
	routeArray.insert(routeArray.begin() + index, *route);
	
	int nextClient;
	if (index == routeArray.size()-1)
		nextClient = 0;
	else
		nextClient = index + 1;
		
	routeArray[index-1].weight = RouteArray::RouteWeight (routeArray[index-1].client , routeArray[index].client);
	routeArray[index].weight = RouteArray::RouteWeight (routeArray[index].client , routeArray[nextClient].client);
	
	RouteArray::UpdateTotalWeight();
}//End of function InsertRoute


int RouteArray::RouteWeight (Client& A, Client& B)
{
	int aux = std::pow((double)(A.x - B.x), 2) + std::pow((double)A.y - B.y, 2);
    int weight = (int) std::sqrt((double)aux);
    return weight;

}//End of function RouteWeight

int RouteArray::GetTotalWeight ()
{
	return totalWeight;
}//End of function GetTotalWeight

void RouteArray::UpdateTotalWeight()
{
	totalWeight = 0;
	for (int i = 0; i < routeArray.size(); i++)
	{
		totalWeight += routeArray[i].weight;
	}
}//End of function UpdateTotalWeight

void RouteArray::PrintRoute ()
{
	for (int i = 0; i < routeArray.size(); i ++)
		std::cout << i << ": " << routeArray[i].client.id << " - " << routeArray[i].weight <<  " km\n";
}//End of funtion PrintRoute

