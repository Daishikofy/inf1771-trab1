#include <iostream>
#include <fstream>
#include <sstream>
#include "DataArray.h"



std::vector<Client> DataArray::ReadFile (std::string filePath, int& capacity)
{
	std::string line;
	bool NODE_COORD_SECTION = false, DEMAND_SECTION = false;
	int tam;
	int i = 0;
	std::vector<Client> clients;

	std::ifstream file (filePath);

	if (! file.is_open ())
	{
		std::cout << "Couldn't open de file\n";
		return clients;
	}

	while ( getline (file, line))
	{

		if (line.find("DIMENSION") != std::string::npos)
		{
			tam = std::stoi( line.substr(13,15) );
			std::cout << "CRIE UM VETOR DE " << tam << " DIMENSOES" << "\n";
		}

		else if (line.find("CAPACITY") != std::string::npos)
		{
			capacity = stoi( line.substr(12,15) );
			std::cout << "CAMINHAO TEM CAPACIDADE DE " << capacity << "\n";
		}

		else if (line.find("NODE_COORD_SECTION") != std::string::npos)
		{
			NODE_COORD_SECTION = true;
		}

		else if (NODE_COORD_SECTION)
		{
			std::cout << i << " ARMAZENA COORDENADAS" << "\n";
			clients.push_back( FillClient(line) );

			i++;
			if (i>=tam)
			{
				NODE_COORD_SECTION = false;
				i = 0;
			}
		}

		else if (line.find("DEMAND_SECTION") != std::string::npos)
		{
			DEMAND_SECTION = true;
		}

		else if ( DEMAND_SECTION )
		{
			std::cout << i <<" ARMAZENA CAPACIDADE" << "\n";

			std::stringstream lineStream(line);
			lineStream >> clients[i].id >> clients[i].demand;

			DataArray::PrintClient(clients[i]);

			i++;
			if (i>=tam)
			{
				DEMAND_SECTION = false;
				i = 0;
			}
		}
	}

	file.close();
	return clients;
}//End of function ReadFile


Client DataArray::FillClient (std::string line)
{
	Client client;
	std::stringstream lineStream(line);

	lineStream >> client.id >> client.x >> client.y;

	return client;
}//End of function FillClient


void DataArray::PrintClient (Client client)
{
	std::cout << client.id << " " << client.x << " " << client.y << " " << client.demand << "\n";
}//End of function PrintClient
