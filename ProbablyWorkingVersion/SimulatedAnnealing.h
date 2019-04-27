#pragma once
#include <vector>

/*
* Recebe um vetor de clientes
* A capacidade maxima de um caminhao
* O numero de repeticoes sem melhoria depois da qual o algoritmo deve parar
* A temperatura maxima no algoritmo
* O fator de resfriamento do algorimo ]0,1[
*
* O algoritmo retorna em seguida a melhor solucao obtida
*/
Solution* SimulatedAnnealing (std::vector<Client>& clients, int capacity, int condEnd, int maxTemperature, float coolingFactor);
