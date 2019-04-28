#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <stdio.h>

#include "Route.h"
#include "Solution.h"
#include "DataArray.h"
#include "SimulatedAnnealing.h"
#include "LocalSearch.h"

using namespace std;

int main ()
{
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray * dataArray = new DataArray();

	dataArray->ReadFile(clients, capacity, nTrucks, "text.txt");
	srand(2);
	/*
	std::vector<Client> aux;
	for(int i = 0 ; i < 25; i++)
	{
		aux.push_back(clients[i]);
	}
	Solution* solaux = new Solution();
	solaux->CreateSolution(aux, 100);
	solaux->PrintSolution();
	std::cout << "\n\n";
	solaux->InnerSwap();
	solaux->PrintSolution();
	*/

	clock_t t;
	// t = clock();
	// Solution* simulated = SimulatedAnnealing(clients, capacity, 1000, 1000, 0.4);
	// t = clock() - t;

	// float time = (float)t/CLOCKS_PER_SEC;
	// simulated->PrintSolution();
	// printf("Tick: %d - Time: %3.5f s\n",t,time);

	t = clock();
	//Solution* local = SimulatedAnnealing(clients, capacity, 5000, 1000, 0.4);
	Solution* local = runLocalSearch(clients, capacity, 50000);
	t = clock() - t;

	float time = (float)t/CLOCKS_PER_SEC;
	local->PrintSolution();
	printf("Tick: %d - Time: %3.5f s\n",t,time);
	
	localSearch->PrintSolution();

	printf("Tick: %d - Time: %3.5f\n", t, time);


	return 0;
}
