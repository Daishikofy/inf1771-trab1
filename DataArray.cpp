#include <iostream>
#include <fstream>
#include <sstream>
#include "DataArray.h"



void DataArray::ReadFile (std::vector<Client>& clients, int& capacity, int& nTrucks, std::string filePath )
{
	std::string line;
	bool NODE_COORD_SECTION = false, DEMAND_SECTION = false, isFirst = true;
	int tam;
	int i = 0;

	std::ifstream file (filePath);

	if (! file.is_open ())
	{
		std::cout << "Couldn't open de file\n";
		return;
	}

	while ( getline (file, line))
	{
		if (isFirst) 
		{//Recupera numero de caminhoes
			int index = line.find("k") + 1;
			nTrucks = std::stoi( line.substr(index,line.size()) );
			isFirst = false;
		}

		else if (line.find("DIMENSION") != std::string::npos)
		{//Recupera numero de cliente + deposito
			int index = line.find(":") + 1;
			tam = std::stoi( line.substr(index,line.size()) );
		}

		else if (line.find("CAPACITY") != std::string::npos)
		{//Recupera capacidade do caminhao
			int index = line.find(":") + 1;
			capacity = stoi( line.substr(index,line.size()) );
		}

		else if (line.find("NODE_COORD_SECTION") != std::string::npos)
		{
			NODE_COORD_SECTION = true;
		}

		else if (NODE_COORD_SECTION)
		{//Armazena as coordenadas dos clientes
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
		{//Armazena a demenda dos clientes
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
