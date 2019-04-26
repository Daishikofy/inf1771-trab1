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
	
	for(int i = 0; i<15; i++)
	{
	aux.push_back(clients[i]);
	}
	
	
	Solution solaux;
	solaux.CreateSolution(clients, capacity);
	solaux.PrintSolution();
	
	srand(1);
	
	for(int i = 0; i < 3; i++)
	{
		solaux.CreateNeighbor(aux[0]);
		std::cout << " \n\n" << "SOLUTION N " << i + 1 << " \n\n";
		solaux.PrintSolution();	
	}

	//Solution * simulated = SimulatedAnnealing(clients, 100);

	//simulated->PrintSolution();



	return 0;
}


