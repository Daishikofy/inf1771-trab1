#include <vector>
#include <string>
#include <iostream>
#include "DataArray.h"

int main ()
{
	std::vector<Client> clients;
	int capacity, nTrucks;
	DataArray dataArray;

	clients = dataArray.ReadFile(clients, capacity, nTruks, "text.txt");

	std::cout << capacity << "\n";
	/*
	for (int i = 0; i<clients.size(); i++)
	{
		DataArray::PrintClient(clients[i]);
	}*/
	
	return 0;
}


