#include "LocalSearch.h"
#define COND_END 200

// calcula quem tem a maior pontuacao entre os sucessores de currentSol

int EvalsValue(Solution * currentSol, int n)
{
	int score = 0;
	int i;
	int minimalCost = 99999;

	for (i = n; i < currentSol->solution.size(); i++)
	{
		if (currentSol->totalWeight < minimalCost)
		{
			std::cout << currentSol->totalWeight << " OOI";
			minimalCost = currentSol->totalWeight;
			score = i;
		}

	}
	return score;
}


Solution * hillClimber(std::vector<Client>& clients, int capacity, int nRepeticoes)
{
	Solution * currentSolution = new Solution();
//	Solution * bestSolution = new Solution();

//	bestSolution->CreateSolution(clients, capacity);
	Solution* bestSolution = currentSolution;

	currentSolution->CreateSolution(clients, capacity);


	//Solution* newSolution = currentSolution->Duplicate();

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

		/*
		//currentSolution->CreateNeighbor(clients[0]);
		newSolution->CreateNeighbor(clients[0]);


		int next = EvalsValue(currentSolution, i);

		bestSolution->CreateNeighbor(clients[next]);

		if (bestSolution->totalWeight >= newSolution->totalWeight)
		{
			bestSolution = newSolution;

			//bestSolution->solution[i].routeArray = currentSolution->solution[i].routeArray;
			break;
		}
		newSolution = bestSolution;
		//currentSolution->CreateNeighbor(clients[i]);
	}
	*/
	return bestSolution;
}


// Guarda o custo necessario para se chegar no no corrente, cuidando do passado
int StoresCost(std::vector<Client>& alreadyVisited, int capacity)
{
	Solution * solution = new Solution();
	solution->CreateSolution(alreadyVisited, capacity);
	int alreadyVisitedClientsCost = solution->totalWeight;

	return alreadyVisitedClientsCost;
}
