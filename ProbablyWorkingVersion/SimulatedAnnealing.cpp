#include "Route.h"
#include "DataArray.h"
#include "Solution.h"
#include "cmath"
#include "ctime"
#include "SimulatedAnnealing.h"
#include <iostream>
#define COND_END 10
#define TEMP 1000


Solution* SimulatedAnnealing (std::vector<Client>& clients, int capacity)
{
  int temperature = TEMP;
  int coolingFactor = 0.95;
 
  Solution* solution = new Solution();
  Solution* bestSolution = new Solution();
    
  solution->CreateSolution(clients, capacity);
  bestSolution = solution->Duplicate();
  solution->PrintSolution();
  
  for (int i = 0; i < COND_END; i++)
  {
	  temperature = TEMP;
	  while (temperature > 0.5)
	  {
		Solution* newSolution = solution->Duplicate(); // era new Solution(), mas estava bugando, mudei para bestSolution 
		std::cout << i << "\n";
		newSolution->CreateNeighbor(clients[0]);
	
		int diffWeight = newSolution->totalWeight - solution->totalWeight;
	  
		if (diffWeight > 0)
		{
		  solution = newSolution;
	 
		  if (newSolution->totalWeight < bestSolution->totalWeight) {
			  std::cout << "oi" << "\n";
      		bestSolution = newSolution;
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
  }
  bestSolution->PrintSolution();
  return bestSolution;
}
