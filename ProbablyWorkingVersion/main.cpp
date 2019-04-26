#include <vector>
#include <string>
#include <iostream>

#include "Route.h"
#include "Solution.h"
#include "DataArray.h"
#include "SimulatedAnnealing.h"

using namespace std;

int main ()
{
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray * dataArray = new DataArray();

	dataArray->ReadFile(clients, capacity, nTrucks, "text.txt");

	/*Solution* solution = new Solution;
	 
	solution->CreateSolution(clients,capacity);
	solution->PrintSolution();*/
	
	std::vector<Client> aux = vector<Client>();
	
	aux.push_back(clients[0]);
	aux.push_back(clients[1]);
	aux.push_back(clients[2]);
	aux.push_back(clients[3]);
	aux.push_back(clients[4]);
	
	Solution* solaux = new Solution();
	solaux->CreateSolution(aux, 100);
	solaux->PrintSolution();
	Route* client = solaux->solution[1].routeArray.RemoveRoute(1);
	std::cout << client->client.id << "\n";
	solaux->PrintSolution();
	solaux->solution[1].routeArray.InsertRoute(1, client);
	solaux->PrintSolution();

	//Solution * simulated = SimulatedAnnealing(clients, 100);

	//simulated->PrintSolution();



	return 0;
}


