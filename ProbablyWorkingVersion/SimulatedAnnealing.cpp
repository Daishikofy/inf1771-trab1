#include <iostream>
#include "cmath"
#include "Route.h"
#include "DataArray.h"
#include "Solution.h"
#include "SimulatedAnnealing.h"


Solution* SimulatedAnnealing (std::vector<Client>& clients, int capacity, int condEnd, int maxTemperature, float coolingFactor)
{
  float temperature;
 
  Solution* solution = new Solution();
  Solution* bestSolution = new Solution();
  solution->CreateSolution(clients, capacity);
  bestSolution = solution;

  int i = 0;
  int noBestCombo = 0;
  bool best;

  while (noBestCombo < condEnd )
  {
	  i++;
	  temperature = maxTemperature;
	  best = false;
	  while (temperature > 1)
	  {
		Solution* newSolution = solution->Duplicate(); // era new Solution(), mas estava bugando, mudei para bestSolution 
		newSolution->CreateNeighbor(clients[0]); 
		int diffWeight = newSolution->totalWeight - solution->totalWeight;
	  
		if (diffWeight > 0)
		{
		  solution = newSolution;
	 
		  if (newSolution->totalWeight < bestSolution->totalWeight) 
		  {
			//std::cout << std::string(i, '|'); //Barra de carregamento
      		bestSolution = newSolution;
			best = true;
			noBestCombo = 0;
		  }
		}
		else
		{
		   float pBoltzman = exp((float) diffWeight/ temperature);
		   if (pBoltzman <= (float) rand()/RAND_MAX) 
		   {
			   solution = newSolution;
		   }
		}
		temperature = coolingFactor * temperature;
	  }
	  if (!best)
			noBestCombo ++;
  }
  return bestSolution;
}
