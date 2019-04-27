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

  int noBestCombo = 0;
  bool best;
  int i = 0;
  while (noBestCombo < condEnd )
  {
	  i++;
	  temperature = maxTemperature;
	  best = false;
	  while (temperature > 1)
	  {
		Solution* newSolution = solution->Duplicate(); 
		newSolution->CreateNeighbor(clients[0], i%2); 
		int diffWeight = newSolution->totalWeight - solution->totalWeight;
	  
		if (diffWeight > 0)
		{
		  solution = newSolution;
	 
		  if (newSolution->totalWeight < bestSolution->totalWeight) 
		  {
      		bestSolution = newSolution;
			best = true;
			noBestCombo = 0;
		  }
		}
		else
		{
		   float pBoltzman = exp((float) diffWeight/ temperature);
		   if (pBoltzman <= (float) rand()/RAND_MAX) 	   
			   solution = newSolution;  
		}
		temperature = coolingFactor * temperature;
	  }
	  if (!best)
			noBestCombo ++;
  }
  return bestSolution;
}//End of function Simulated Annealing
