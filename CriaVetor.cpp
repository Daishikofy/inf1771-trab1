#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>

#define PATH "text.txt"

using namespace std;


struct Client{
	int id;
	int x;
	int y;
	int demand;
};

vector<Client> ReadFile(string filePath, int& capacity);
Client fillClient (string line);
void printClient (Client client);

int main ()
{
	vector<Client> clients;
	int capacity;
	
	clients = ReadFile("text.txt", capacity);
	
	cout << capacity << endl;
	/*
	for (int i = 0; i<clients.size(); i++)
	{
		printClient(clients[i]);
	}*/
	
	return 0;
}

vector<Client> ReadFile(string filePath, int& capacity)
{
	
	string line;
	bool NODE_COORD_SECTION = false, DEMAND_SECTION = false;
	int tam;
	int i = 0;
	vector<Client> clients;
	
	ifstream file (filePath);
	
	if (! file.is_open ())
	{
		cout << "Couldn't open de file\n";
		return clients;
	}
	
	while ( getline (file, line))
	{
		
		if (line.find("DIMENSION") != string::npos)
		{
			tam = stoi( line.substr(13,15) );
			cout << "CRIE UM VETOR DE " << tam << " DIMENSOES" << endl;
		}
		
		else if (line.find("CAPACITY") != string::npos)
		{
			capacity = stoi( line.substr(12,15) );
			cout << "CAMINHAO TEM CAPACIDADE DE " << capacity << endl;
		}
		
		else if (line.find("NODE_COORD_SECTION") != string::npos)
		{
			NODE_COORD_SECTION = true;
		}
		
		else if (NODE_COORD_SECTION)
		{
			cout << i << " ARMAZENA COORDENADAS" << endl;
			clients.push_back( fillClient(line) );

			i++;
			if (i>=tam)
			{
				NODE_COORD_SECTION = false;
				i = 0;
			}
		}
		
		else if (line.find("DEMAND_SECTION") != string::npos)
		{
			DEMAND_SECTION = true;
		}
		
		else if ( DEMAND_SECTION )
		{		
			cout << i <<" ARMAZENA CAPACIDADE" << endl;
			
			stringstream lineStream(line);
			lineStream >> clients[i].id >> clients[i].demand;
			
			printClient(clients[i]);
					
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
}

Client fillClient (string line)
{
	Client client;
	stringstream lineStream(line);

	lineStream >> client.id >> client.x >> client.y;
	
	return client;
}

void printClient (Client client)
{
	cout << client.id << " " << client.x << " " << client.y << " " << client.demand << endl;
}


