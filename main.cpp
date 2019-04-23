#include <vector>
#include <string>
#include <iostream>

#include "Route.h"
#include "Solution.h"
#include "DataArray.h"


int main ()
{
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray dataArray;

	dataArray.ReadFile(clients, capacity, nTrucks, "text.txt");

	Solution* solution = new Solution;
	 
	solution->FillSolution(clients,capacity);
	solution->PrintSolution();
	
	return 0;
}


