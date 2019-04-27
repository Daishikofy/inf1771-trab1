#include "LocalSearch.h"
#define COND_END 9

Solution * runLocalSearch(std::vector<Client> clients, int capacity)
{
	Solution * solution = new Solution();
	Solution * bestSolution = new Solution();

	solution->CreateSolution(clients, capacity);
	bestSolution = solution;

	for (int i = 0; i < COND_END; i++)
	{
		Solution newSolution = *solution;
		std::cout << "Pre Conds.:\n\n";
		solution->PrintSolution();

		solution->CreateNeighbor(clients[i]);
		std::cout << "New Solution:\n\n";
		newSolution.PrintSolution();
			
		std::cout << "Current Solution:\n\n";
		
		solution->PrintSolution();
	
		if (newSolution.totalWeight - solution->totalWeight > 0)
		{
			solution = &newSolution;

			if (newSolution.totalWeight < bestSolution->totalWeight)
			{
				bestSolution = &newSolution;
			}
		}
	}
	int oi;
	std::cin >> oi;
	return bestSolution;
}



