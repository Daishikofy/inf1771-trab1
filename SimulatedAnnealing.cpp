#define COND_END 10

Solution& SimulatedAnnealing (Clients& clients, int capacity)
{
  int temperature = 10;
  
  Solution* solution = new solution;
  Solution* bestSolution = new solution;
  solution->CreateSolution(clients, capacity);
  bestSolution = solution;

  for (int i = 0; i < COND_END; i++)
  {
    Solution* newSolution = new solution;
    newSolution->CreateNeighborSolution(seed);
    int diffWeight = newSolution->totalWeight - solution->totalWeight;

    if (diffWeight > 0)
    {
      solution = newSolution;
      if (newSolution->totalWeight < bestSolution->totalWeight)
      	bestSolution = newSolution;
    }
    else
    {
       int pBoltzman = exp(diffWeight/temperature);
       if (pBoltzman <= (float) rand()/RAND_MAX)
       		solution = newSolution;
    }
  }
  return bestSolution;
}
