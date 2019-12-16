#include "mst.h"

using std::pair;
using std::make_pair;
using std::set;
using std::vector;

double getMinimumSpanningTreeWeight(Graph& gr) {

	int verticesCount = gr.GetVerticesCount();

	vector <double> minWeightFromVert(verticesCount, DBL_MAX);
	vector <bool> addedVertState(verticesCount, false);
	vector <int> minSpTreeVert;

	set <pair<double, int> > vertSet;
	vertSet.insert(make_pair(0, 0));
	minWeightFromVert[0] = 0.0;

	double totalWeight = 0.0;
	double weight;
	int vert;
	double nWeight;
	int nVert;
	while (minSpTreeVert.size() < verticesCount) {
		weight = vertSet.begin()->first;
		vert = vertSet.begin()->second;
		totalWeight += weight;
		minSpTreeVert.push_back(vert);
		addedVertState[vert] = true;
		vertSet.erase(vertSet.begin());
		for (GraphsEdge nextVert : gr.GetNextVertices(vert)) {
			nVert = nextVert.vert;
			if (!addedVertState[nVert]) {
				nWeight = nextVert.weight;
				if (nWeight < minWeightFromVert[nVert]) {
					vertSet.erase(make_pair(minWeightFromVert[nVert], nVert));
					minWeightFromVert[nVert] = nWeight;
					vertSet.insert(make_pair(nWeight, nVert));
				}
			}
		}
	}
	return totalWeight;
}