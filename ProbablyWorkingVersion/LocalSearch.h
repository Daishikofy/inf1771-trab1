#pragma once
#include <vector>
#include "DataArray.h"
#include "Solution.h"
#include "Route.h"

/*
* Recebe um vetor de clientes
* A capacidade maxima de um caminhao
* O tamanho da vizinhan�a a ser explorada
*
* Realiza um busca Local
*
* Retorna a melhor solu��o achada
*/
Solution* HillClimbing(std::vector<Client>& clients, int capacity, int nNeighbors);
