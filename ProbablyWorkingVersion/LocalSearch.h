#pragma once
#include "Solution.h"
#include "Route.h"
#include "DataArray.h"
#include <vector>
#include <iostream>

int EvalsValue(Solution * currentSol, int n);

Solution * hillClimber(std::vector<Client>& clients, int capacity);
