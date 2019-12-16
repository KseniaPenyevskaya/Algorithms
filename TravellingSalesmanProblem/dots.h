#pragma once
/*
Cлучайный набор точек, нормально распределенный на плоскости с дисперсией 1. 
Нормально распределенный набор точек получайте с помощью преобразования Бокса-Мюллера.
*/
#include "graph.h"

#include <vector>
#include <cmath>
#include <ctime>

void createDots(Graph& graph);