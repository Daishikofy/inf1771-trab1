#include "Solution.h"
#include <iostream>



void Solution::InicializeSolution(Client& centralDepot)
{
    RouteArray* routeArray = new RouteArray;
	routeArray->AddRoute(&centralDepot);

	Truck* truck = new Truck (routeArray);
	truck->totalDemand = 0;
	truck->routeWeight = 0;
    solution.push_back(*truck);

  return;
}//End of function InicializeSolution


void Solution::CreateSolution (std::vector<Client>& clients, int capacity)
{
	InicializeSolution(clients[0]);
	int truck = 0;
	_capacity = capacity;

	for (int i = 1; i < clients.size() ; i ++)
	{
		
		bool succesInsert = InsertClient (clients[i], capacity, truck);
		if (!succesInsert)
		{
			
			bool insertOtherRoute = TestAllRoutes(clients[i], capacity);
			if (!insertOtherRoute)
			{
				InicializeSolution(clients[0]);
				truck++;
				bool succesInsert = InsertClient (clients[i], capacity, truck);
				if (!succesInsert)
				{
					std::cout << "Demanda do client " << clients[i].id << " maior do que a capacidade total de um caminhao\n";
					return;
				}
			}
		}
	} 

	Solution::UpdateTotalWeight();
}// End of function CreateSolution


bool Solution::InsertClient(Client& client, int capacity, int indexTruck)
{
	int auxTotalDemand = client.demand + solution[indexTruck].totalDemand;
    if ( auxTotalDemand <= capacity)
	{
		solution[indexTruck].routeArray->AddRoute(&client);
		solution[indexTruck].totalDemand = auxTotalDemand;
		return true;
	}
	return false;
}//End of function InsertClient


bool Solution::TestAllRoutes(Client& client, int capacity)
{
	for (int i = 0; i < solution.size(); i++)
	{
		if ( Solution::IsInsertionValid(client.demand, i, capacity))
		{
			InsertClient (client, capacity, i);
			return true;
		}
	}
	return false;
}//End of function TestAllRoutes


void Solution::CreateNeighbor (Client& centralDepot, int method)
{
	if (method)
		Solution::MoveRoute(centralDepot);
	else
		Solution::InnerSwap();
	
}//End of function CreateNeighbor

Solution* Solution::Duplicate()
{
	Solution* newSolution = new Solution ();

	for (int i = 0 ; i < solution.size(); i++)
	{
		Truck newTruck(solution[i].routeArray->Duplicate());
		newTruck.routeWeight = solution[i].routeWeight;
		newTruck.totalDemand = solution[i].totalDemand;
		newSolution->solution.push_back(newTruck);
	}

	newSolution->totalWeight = totalWeight;
	newSolution->_capacity = _capacity;

	return newSolution;
}//End of function Duplicate


bool Solution::IsInsertionValid(int clientDemand, int index, int capacity)
{
	int auxTotalDemand = clientDemand + solution[index].totalDemand;
	if ( auxTotalDemand <= _capacity )
		return true;
	return false;
}// End of function IsInsertionvalid


void Solution::UpdateTotalWeight()
{
	totalWeight = 0;
	for (int i = 0 ; i < solution.size(); i++)
	{
		totalWeight += solution[i].routeArray->GetTotalWeight();
	}
}// End of function UpdateTotalWeight


void Solution::PrintSolution ()
{
	for (int i = 0 ; i < solution.size(); i++)
	{
		int n = i + 1;
		std::cout << "\nCAMION N " << n << " - " << solution[i].routeArray->GetTotalWeight() << " km\n";
		solution[i].routeArray->PrintRoute();
	}

}// End of function PrintSolution


/*** FUNCOES DE VIZINHANCA ***/

void Solution::MoveRoute(Client& centralDepot)
{
	int indexRoute = rand() % solution.size(); 	
	int indexClient = rand() % solution[indexRoute].routeArray->routeArray.size();
	if (indexClient == 0)
		indexClient++;

	Route* routeAux = solution[indexRoute].routeArray->RemoveRoute(indexClient);
	solution[indexRoute].totalDemand -= routeAux->client->demand;

	int routeSize = solution[indexRoute].routeArray->routeArray.size();
	if (routeSize <= 1)//Caso a rota estiver vazia, remover ela.
		solution.erase(solution.begin() + indexRoute);
	
	//Escolhe uma rota aleatoria
	int indexNewRoute = rand() % (solution.size() + 2);
	
	if (indexNewRoute >= solution.size())
	{
		Solution::InicializeSolution(centralDepot);
		indexNewRoute = solution.size() - 1;
	}

	//verifica que o cliente pode ser inserido nesta rota
	while(! Solution::IsInsertionValid(routeAux->client->demand, indexNewRoute, _capacity))
	{
		indexNewRoute = rand() % (solution.size() + 2);

		if (indexNewRoute >= solution.size())
		{
			Solution::InicializeSolution(centralDepot);
			indexNewRoute = solution.size() - 1;
		}
	}

	//escolhe um indexo cliente aleatorio
	indexClient = rand() % solution[indexNewRoute].routeArray->routeArray.size();
	
	if (indexClient == 0)
		indexClient++;
	//Insere o cliente aleatoriamente nesta rota
	solution[indexNewRoute].routeArray->InsertRoute(indexClient, routeAux);
	solution[indexNewRoute].totalDemand += routeAux->client->demand;
	//Equilibra os pesos
	UpdateTotalWeight();	
	
}//End of function MoveRoute



void Solution::InnerSwap ()
{
	//Escolhe uma rota aleatoria
	int indexRoute = rand() % solution.size(); 

	//Se a rota tiver pelo menos dois clientes
	while(solution[indexRoute].routeArray->routeArray.size() < 3)
		indexRoute = rand() % solution.size(); 

	//Escolhe um cliente aleatorio differente de 0
	int indexClientA = rand() % solution[indexRoute].routeArray->routeArray.size();
	if (indexClientA == 0)
		indexClientA++;
	
	//Escolhe um segundo cliente differente do primeiro e de 0
	int indexClientB = rand() % solution[indexRoute].routeArray->routeArray.size();
	while (indexClientB == 0 || indexClientB == indexClientA)
		indexClientB = rand() % solution[indexRoute].routeArray->routeArray.size();
	
	//Troca os dois clientes de lugar
	solution[indexRoute].routeArray->SwapRoute(indexClientA, indexClientB);

	Solution::UpdateTotalWeight();
	
}//End of function InnerSwap