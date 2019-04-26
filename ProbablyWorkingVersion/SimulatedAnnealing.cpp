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
  //std::cout << "oi1";
  Solution* solution = new Solution();
  Solution* bestSolution = new Solution();
    
  //std::cout << "oi2";
  solution->CreateSolution(clients, capacity);
  //  std::cout << "oi3";
  bestSolution = solution;
 //  std::cout << "oi4";
  for (int i = 0; i < COND_END; i++)
  {
    Solution* newSolution = bestSolution; // era new Solution(), mas estava bugando, mudei para bestSolution
	   //std::cout << "oi5";
    newSolution->CreateNeighbor((int) time(NULL));
	  // std::cout << "oi6";
    int diffWeight = newSolution->totalWeight - solution->totalWeight;
	  // std::cout << "oi7";
    if (diffWeight > 0)
    {
      solution = newSolution;
	  //std::cout << "oi1";
      if (newSolution->totalWeight < bestSolution->totalWeight) {
      	bestSolution = newSolution;
		break;
	  }
    }
    else
    {
       float pBoltzman = exp((float) diffWeight/ temperature);
       if (pBoltzman <= (float) rand()/RAND_MAX) {
		   solution = newSolution;
	   }
    }
	   std::cout << "oi6";
  }
  return bestSolution;
}
