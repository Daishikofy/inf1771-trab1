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
			if(!insertOtherRoute)
			{
				InicializeSolution(clients[0]);
				truck++;
				bool succesInsert = InsertClient (clients[i], capacity, truck);
				if (!succesInsert)
					std::cout << "Demanda do client " << clients[i].id << " maior do que a capacidade total de um caminhao\n";
			}
		}
	} 

	for (int i = 0; i < solution.size(); i++)
	{
		solution[i].routeWeight = solution[i].routeArray->GetTotalWeight();
	}
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
			return true;
	}
	return false;
}

void Solution::CreateNeighbor (Client& centralDepot)
{

	Solution::MoveRoute(centralDepot);
	
}//End of function CreateNeighbor


void Solution::MoveRoute(Client& centralDepot)
{
	
	int indexRoute = rand() % solution.size(); 	
	int indexClient = rand() % solution[indexRoute].routeArray->routeArray.size();
	if (indexClient == 0)
		indexClient++;
		
	//Escolhe uma rota aleatoria e remove um cliente aleatorio desta rota
	/*if (solution[indexRoute].routeArray->routeArray.size() < 2);
		indexRoute++;*/
		
	Route* routeAux = solution[indexRoute].routeArray->RemoveRoute(indexClient);
	solution[indexRoute].totalDemand -= routeAux->client->demand;
	
	if (solution[indexRoute].routeArray->routeArray.size() < 2);//Caso uma roa estaja vazia, remover ela.
    	solution.erase(solution.begin() + indexRoute);
    	
	std::cout << "Remocao effetiva\n";
	
	//Escolhe uma rota aleatoria
	int indexNewRoute = rand() % (solution.size() + 2);
	
	if (indexNewRoute >= solution.size())
	{
		Solution::InicializeSolution(centralDepot);
		indexNewRoute = solution.size() - 1;
	}
	//verifica que o clinete pode ser inserido nesta rota
	
	while(! Solution::IsInsertionValid(routeAux->client->demand, indexNewRoute, _capacity))
	{
		indexNewRoute = rand() % (solution.size() + 2);
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
	std::cout << "Insercao effetiva\n";
	
}//End of function MoveRoute

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
}


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
	int soma = 0;
	for (int i = 0 ; i < solution.size(); i++)
	{
		int n = i + 1;
		std::cout << "CAMION N " << n << " - " << solution[i].routeArray->GetTotalWeight() << " km\n";
		solution[i].routeArray->PrintRoute();
		soma += solution[i].routeArray->GetTotalWeight();
	}
	std::cout << "Distancia total: " << soma << " km\n";
}

