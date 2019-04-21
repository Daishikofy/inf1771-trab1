#pragma once
#include <vector>
#include <string>

struct Client
{
	int id;
	int x;
	int y;
	int demand;

};

class DataArray 
{
public:

	/**
	*	clients: vetor de clients, o primeiro client eh  deposito. 
	*	capacity: capacidade de transporte de um caminhao
	*	nTrucks: numero de rotas 
	*   filePath: caminho ate o txt contendo os dados. A formatacao do txt deve ser especifica 
	**/
	void ReadFile (std::vector<Client>& clients, int& capacity, int& nTucks, std::string filePath );
	
private:
	Client FillClient (std::string line);
	void PrintClient (Client client);
}; 
