#include "bf.h"

using std::min;
using std::vector;

double CalculateWeight(Graph& gr, vector <int> vertices)
{
	int numberEdges = vertices.size() - 1;
	double weight;
	// if graph has 2 vertices
	if (numberEdges == 1) {
		weight = 2 * gr.GetWeight(0, numberEdges);
	}
	else {
		weight = gr.GetWeight(0, numberEdges - 1);
		for (int i = 0; i < numberEdges - 1; i++) {
			weight += gr.GetWeight(i, i + 1);
		}
	}
	return weight;
}

double MinWeightBF(Graph &gr)
{
	int size = gr.GetVerticesCount();
	vector<int> vertices;
	for (int i = 0; i < size; i++) {
		vertices.push_back(i);
	}
	double minWeight = DBL_MAX;

	do {
		double tmpWeight;
		tmpWeight = CalculateWeight(gr, vertices);
		minWeight = min(minWeight, tmpWeight);
	} while (std::next_permutation(vertices.begin(), vertices.end()));
	return minWeight;
}