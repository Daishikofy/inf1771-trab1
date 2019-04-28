#pragma once
#include "Solution.h"
#include "Route.h"
#include "DataArray.h"
#include <vector>
#include <iostream>

Solution * runLocalSearch(std::vector<Client>& clients, int capacity, int nRepeticoes);
