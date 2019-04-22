#include <vector>
#include <string>
#include <iostream>

#include "Route.h"

using namespace std;

int main ()
{
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray * dataArray = new DataArray();

	dataArray->ReadFile(clients, capacity, nTrucks, "text.txt");

	std::cout << capacity << "\n";
	std::cout << nTrucks << "\n";
	
	for (int i = 0; i < clients.size(); i++)
	{
		dataArray->PrintClient(clients[i]);
	}
	
	RouteArray route;

	route.AddRoute(clients[0]);
	route.AddRoute(clients[1]);
	route.AddRoute(clients[2]);

	int t = route.GetTotalDemand();

	std::cout << t << "\n";

	cout << "Tamanho da Rota: " << clients.size() << endl;
	return 0;
}


