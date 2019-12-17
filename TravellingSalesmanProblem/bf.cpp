#include "bf.h"

using std::min;
using std::vector;

double CalculateWeight(Graph& gr, vector <int>& vertices)
{
	int numberEdges = vertices.size() - 1; //2
	double weight;
	// if graph has 2 vertices
	if (numberEdges == 1) {
		weight = 2 * gr.GetWeight(vertices[0], vertices[numberEdges]);
	}
	else {
		weight = gr.GetWeight(vertices[0], vertices[numberEdges - 1]);
		for (int i = 0; i < numberEdges; i++) {
			weight += gr.GetWeight(vertices[i], vertices[i + 1]);
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
		//std::cout << minWeight << std::endl;
	} while (std::next_permutation(vertices.begin(), vertices.end()));
	//std::cout << "minWeight is:" << minWeight;
	return minWeight;
}