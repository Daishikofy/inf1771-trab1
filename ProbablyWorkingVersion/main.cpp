#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <stdio.h>

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
	srand(3);
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
	t = clock();
	Solution* simulated = SimulatedAnnealing(clients, capacity, 1000, 1000, 0.4);
	t = clock() - t;

	float time = (float)t/CLOCKS_PER_SEC;
	simulated->PrintSolution();
	printf("Tick: %d - Time: %3.5f s\n",t,time);
	
	return 0;
}


