#pragma once
#include <vector>
#include <fstream>
#include <cassert>

#include "graph.h"
#include "dots.h"
#include "mst.h"
#include "graph.h"
#include "bf.h"

double GetMean(std::vector <double> arr);
double GetStandardDeviation(std::vector <double> arr);
std::vector <double> GetQuality(std::vector <double> bf, std::vector <double> mst);
void outputFile(int/*number Of dots*/ n, double mean/*mean error*/, double stDev/*standard deviation*/, double weightBF, double weightMST);
