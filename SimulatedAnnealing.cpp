#define COND_END 10

Solution& SimulatedAnnealing (Clients& clients, int capacity)
{
  Solution* solution = new solution;
  Solution* bestSolution = new solution;
  solution->CreateSolution(clients, capacity);
  bestSolution = solution;

  for (int i = 0; i < COND_END; i++)
  {
    Solution* newSolution = new solution;
    newSolution->CreateNeighborSolution(int seed);
    int diffWeight = newSolution->totalWeight - solution->totalWeight;

    if (diffWeight > 0)
    {
      solution = newSolution;
    }
    else
    {
      
       solution = newSolution;
    }
  }
}
