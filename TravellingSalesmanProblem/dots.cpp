#include "dots.h"

using std::pair;
using std::vector;
using std::log;
using std::sqrt;
using std::srand;
using std::rand;

typedef pair<double, double> dot;

void createDots(Graph& graph){
	vector<dot> dots;
	for (int i = 0; i < graph.GetVerticesCount(); i++) {
		double z0;
		double z1;

		double x = rand() % 1001 / 1000.0;
		double y = rand() % 1001 / 1000.0 * (1 - x * x);
		double s = x * x + y * y;
		double p = sqrt(-2 * log(s) / s);

		z0 = 50 * x * p;
		z1 = 50 * y * p;
		dots.push_back(dot(z0, z1));

		for (int j = 0; j < i; j++) {
			graph.AddEdge(i, j, sqrt(pow(z0 - dots[j].first, 2.0) + pow(z1 - dots[j].second, 2.0)));
		}
	}
	
}
