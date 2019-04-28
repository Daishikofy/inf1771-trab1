#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cstring>

#include "Route.h"
#include "Solution.h"
#include "DataArray.h"
#include "SimulatedAnnealing.h"
#include "LocalSearch.h"

using namespace std;

int main (int argc, char * argv[])
{
	if (argc != 3)
	{
		std::cout << "Uso: ./executavel <arquivoDeInstancias.txt> <heuristica> \nOnde heuristica pode ser SA (Simulated Annealing) ou HC (Hill Climbing)\n\n";

		return 0;
	}
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray * dataArray = new DataArray();
	dataArray->ReadFile(clients, capacity, nTrucks, argv[1]);

	Solution * answer = new Solution();

	clock_t t;

	srand(1); //Pode testar outros valores para tentar acha o melor resultado

	//VARIAVEIS PARA SIMULATED ANNEALING
	int temp, condEnd;
	float a;
	//VARIAVEIS PARA BUSCA LOCAL
	int size;

	char choice2 = 's';

	while(choice2 == 's')
	{
		if (strcmp(argv[2], "SA" ) == 0)
		{
			std::cout << "\nTemperature: ";
			std::cin >> temp;
			std::cout << "Cooling Factor ]0,1[ : ";
			std::cin >> a;
			std::cout << "COND_END (Repetitions with no improvment): ";
			std::cin >> condEnd;
			t = clock();

			Solution* solution = SimulatedAnnealing(clients, capacity, temp, condEnd, a);
			
			t = clock() - t;

			float time = (float)t / CLOCKS_PER_SEC;


			std::cout << "\nDistancia total: " << solution->totalWeight << " km\n";
			printf("Tick: %d - Time: %3.5f s\n", t, time);

			answer = solution;
		}
		
		else if (strcmp(argv[2], "HC") == 0)
		{
			std::cout << "\nNumber of solutions to explore: ";
			
			std::cin >> size;

			t = clock();

			Solution* solution = HillClimbing(clients, capacity, size);
			
			t = clock() - t;

			float time = (float)t / CLOCKS_PER_SEC;
	
			std::cout << "\nDistancia total: " << solution->totalWeight << " km\n";
			
			printf("Tick: %d - Time: %3.5f s\n", t, time);
			
			answer = solution;
		}	

		char choice1;
		std::cout << "\nDeseja imprimir a solucao? (s/n): ";
		std::cin >> choice1;

		if (choice1 == 's')
			answer->PrintSolution();

		std::cout << "Deseja testar com outros parametros? (s/n): ";
		std::cin >> choice2;
	}

	return 0;
}
