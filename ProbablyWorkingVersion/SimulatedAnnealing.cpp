#include "Route.h"
#include "DataArray.h"
#include "Solution.h"
#include "cmath"
#include "ctime"
#include "SimulatedAnnealing.h"
#include <iostream>
#define COND_END 10


Solution* SimulatedAnnealing (std::vector<Client>& clients, int capacity)
{
  int temperature = 10;
  int coolingFactor = 0.5;
 
  Solution* solution = new Solution();
  Solution* bestSolution = new Solution();
    
  solution->CreateSolution(clients, capacity);
  bestSolution = solution;


  for (int i = 0; i < COND_END; i++)
  {
	Solution* newSolution = solution->Duplicate(); // era new Solution(), mas estava bugando, mudei para bestSolution 
    std::cout << "\n\nANTES DE MEXER: \n\n";
    solution->PrintSolution();
    
    newSolution->CreateNeighbor(clients[0]);
	solution->CreateNeighbor(clients[0]);
	std::cout << "\n\nNEW SOLUTION: \n\n";
	newSolution->PrintSolution();
	std::cout << "\n\nCURRENT SOLUTION: \n\n";
	solution->PrintSolution();
	
    int diffWeight = newSolution->totalWeight - solution->totalWeight;
	  
    if (diffWeight > 0)
    {
      solution = newSolution;
	 
      if (newSolution->totalWeight < bestSolution->totalWeight) {
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
  return bestSolution;
}
