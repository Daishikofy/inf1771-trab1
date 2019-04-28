#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <stdio.h>

#include "Route.h"
#include "Solution.h"
#include "DataArray.h"
#include "SimulatedAnnealing.h"
#include "LocalSearch.h"

using namespace std;

int main ()
{
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray * dataArray = new DataArray();
	dataArray->ReadFile(clients, capacity, nTrucks, "text.txt");


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
		/*Parte a comentar caso for testar a busca local*/
		/*std::cout << "\nTemperature: ";
		std::cin >> temp;
		std::cout << "Cooling Factor ]0,1[ : ";
		std::cin >> a;
		std::cout << "COND_END (Repetitions with no improvment): ";
		std::cin >> condEnd;
		*/
		/*Parte a descomentar caso for testar a busca local*/
		
		std::cout << "\nNumber of solutions to explore: ";
		std::cin >> size;
		


		t = clock();
		//Solution* solution = SimulatedAnnealing(clients, capacity, temp, condEnd, a);
		Solution* solution = HillClimbing(clients, capacity, size);
		t = clock() - t;

		float time = (float)t/CLOCKS_PER_SEC;
		std::cout << "\nDistancia total: " << solution->totalWeight << " km\n";
		printf("Tick: %d - Time: %3.5f s\n",t,time);

		char choice1;
		std::cout << "\nDeseja imprimir a solucao? (s/n): ";
		std::cin >> choice1;

		if (choice1 == 's')
			solution->PrintSolution();

		std::cout << "Deseja testar com outros parametros? (s/n): ";
		std::cin >> choice2;
	}

	return 0;
}
