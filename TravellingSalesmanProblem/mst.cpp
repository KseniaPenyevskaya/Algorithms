#include "mst.h"

using std::pair;
using std::make_pair;
using std::set;
using std::vector;
using std::stack;

Graph getMinimumSpanningTree(Graph& gr) {

	int verticesCount = gr.GetVerticesCount();

	vector <double> minWeightFromVert(verticesCount, DBL_MAX);
	vector <bool> addedVertState(verticesCount, false);
	Graph minSpTree(verticesCount);
	int numberAddedVert = 0;

	set <pair<double, pair<int/*parent*/, int/*vertices*/> > > vertSet;
	vertSet.insert(make_pair(0, make_pair(0,0)));
	minWeightFromVert[0] = 0.0;

	double weight;
	int vert;
	double nWeight;
	int nVert;
	while (numberAddedVert < verticesCount) {
		weight = vertSet.begin()->first;
		vert = vertSet.begin()->second.first;
		nVert = vertSet.begin()->second.second;
		minSpTree.AddEdge(vert, nVert, gr.GetWeight(vert, nVert)); numberAddedVert++;

		addedVertState[vert] = true;
		vertSet.erase(vertSet.begin());
		for (GraphsEdge nextVert : gr.GetNextVertices(vert)) {
			nVert = nextVert.vert;
			if (!addedVertState[nVert]) {
				nWeight = nextVert.weight;
				if (nWeight < minWeightFromVert[nVert]) {
					vertSet.erase(make_pair(minWeightFromVert[nVert], make_pair(vert, nVert)));
					minWeightFromVert[nVert] = nWeight;
					vertSet.insert(make_pair(nWeight, make_pair(vert, nVert)));
				}
			}
		}
	}
	return minSpTree;
}

double apprMinWeight(Graph& gr) {
	int vertCount = gr.GetVerticesCount();
	vector <bool> visited(vertCount, false);
	vector <int> path;
	stack <int> mystack;
	int vert = 0;
	int nVert;

	Graph mst = getMinimumSpanningTree(gr);
	mystack.push(0);

	while (!mystack.empty()) {
		vert = mystack.top();
		mystack.pop();
		path.push_back(vert);
		visited[vert] = true;

		for (GraphsEdge ch : mst.GetNextVertices(vert)) {
			nVert = ch.vert;
			if (!visited[nVert]) mystack.push(nVert);
		}
	}
	path.push_back(path.at(0));
	double weight = 0.;
	for (int i = 0; i < path.size() - 1; i++){
		weight += gr.GetWeight(path[i], path[i + 1]);
	}
	return weight;
}

//double apprWeight() {
//	vector <bool> visited(gr.GetVerticesCount(), false);
//}

/*
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
*/