#include <iostream>
#include "Route.h"
#include "LocalSearch.h"


Solution * HillClimbing(std::vector<Client>& clients, int capacity, int nNeighbors)
{
	int method = 0;
	
	//Criar uma solução corrente
	Solution* currentSolution = new Solution();
	currentSolution->CreateSolution(clients, capacity);
	Solution* bestSolution = currentSolution;
	bool best = true;

	while (best)
	{
		std::vector<Solution*> neighborhood;
		//Gerar um espaço de soluçoes
		for (int i = 0; i < nNeighbors; i++)
		{ 
			Solution* newSolution = currentSolution->Duplicate();
			newSolution->CreateNeighbor(clients[0], method);	
			neighborhood.push_back(newSolution);
		}

		//Percorer este espaco de solucoes
		//Comparar cada solucao com a solucao atual
		//Sempre que obter uma solucao melhor, guardar ela
		best = false;
		for (int i = 0; i < neighborhood.size(); i++)
		{
			if (neighborhood[i]->totalWeight <= bestSolution->totalWeight)
			{
				best = true;
				bestSolution = neighborhood[i];
			}
			else				
				delete neighborhood[i];
		} 
		//Usar a solucao melhor como solucao atual
		currentSolution = bestSolution;
	}
	return currentSolution;
}//End of function HillClimbing
