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
	
	std::vector<Client> aux = vector<Client>();
	
	aux.push_back(clients[0]);
	aux.push_back(clients[1]);
	aux.push_back(clients[2]);
	aux.push_back(clients[3]);
	aux.push_back(clients[4]);
	
	Solution solaux;
	solaux.CreateSolution(aux, 100);
	solaux.PrintSolution();
	solaux.CreateNeighbor(2, aux[0]);
	solaux.PrintSolution();
	
	for(int i = 0; i < aux.size(); i++)
		std::cout << aux[i].id << "\n";

	//Solution * simulated = SimulatedAnnealing(clients, 100);

	//simulated->PrintSolution();



	return 0;
}


