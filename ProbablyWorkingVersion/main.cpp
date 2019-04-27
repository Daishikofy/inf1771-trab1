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
	

	clock_t t;

	srand(3);

	t = clock();
	Solution* simulated = SimulatedAnnealing(clients, capacity, 5000, 500, 0.4);

	t = clock() - t;
	float time = (float)t/CLOCKS_PER_SEC;

	simulated->PrintSolution();

	printf("Tick: %d - Time: %3.5f\n",t,time);

	return 0;
}


