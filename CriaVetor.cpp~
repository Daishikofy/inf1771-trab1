#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <sstream>

#define PATH "text.txt"

using namespace std;


typedef  struct client{
	int id;
	int x;
	int y;
	int demand;
}Client;

void ReadFile(string filePath);
Client fillClient (string line);
void printClient (Client client);

int main ()
{
	ReadFile("text.txt");
	return 0;
}

void ReadFile(string filePath)
{
	
	string line;
	bool NODE_COORD_SECTION, DEMAND_SECTION;
	int tam;
	int i = 0;
	vector<Client> clients;
	
	ifstream file (PATH);
	
	if (! file.is_open ())
	{
		cout << "Couldn't open de file\n";
		return;
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
			int p = stoi( line.substr(13,15) );
			cout << "CAMINHAO TEM CAPACIDADE DE " << p << endl;
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
			
			//stringstream lineStream(line);
			
			
			i++;
			if (i>=tam)
			{
				DEMAND_SECTION = false;
				i = 0;
			}
		}
	}
	
	
	file.close();	
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
	cout << client.id << " " << client.x << " " << client.id << endl;
}


