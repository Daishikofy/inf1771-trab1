#pragma once
#include <vector>


Solution* SimulatedAnnealing (std::vector<Client>& clients, int capacity, int condEnd, int maxTemperature, float coolingFactor);
