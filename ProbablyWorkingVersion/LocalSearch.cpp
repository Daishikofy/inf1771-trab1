#include "LocalSearch.h"


Solution* runLocalSearch(std::vector<Client>& clients, int capacity, int nRepeticoes)
{
	Solution* solution = new Solution();
	Solution* bestSolution = new Solution();

	solution->CreateSolution(clients, capacity);
	bestSolution = solution;

	int noBestCombo = 0;
	bool best;

	for (int i = 0; i < nRepeticoes; i++)
	{
		best = false;
		Solution* newSolution = solution->Duplicate();

		newSolution->CreateNeighbor(clients[0], i%2);
	
		if (newSolution->totalWeight - solution->totalWeight < 0)
		{
			solution = newSolution;

			if (newSolution->totalWeight < bestSolution->totalWeight)
			{
				bestSolution = newSolution;
				best = true;
				noBestCombo = 0;
			}
		}
		if (!best)
			noBestCombo ++;
	}
	return bestSolution;
}



