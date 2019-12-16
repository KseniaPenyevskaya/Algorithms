#include "graph.h"

using std::vector;
using std::set;
using std::pair;
using std::make_pair;

GraphsEdge::GraphsEdge() : vert(-1), weight(-1.0) {};
GraphsEdge::GraphsEdge(int vert, double weight) : vert(vert), weight(weight) {};
Graph::Graph(int N) : countVertices(N), pairVertices(N) {}

void Graph::AddEdge(int vert1, int vert2, double weight) {
	pairVertices[vert1].push_back(GraphsEdge(vert2, weight));
	pairVertices[vert2].push_back(GraphsEdge(vert1, weight));
}

int Graph::GetVerticesCount() {
	return countVertices;
}

vector <GraphsEdge>  Graph::GetNextVertices(int vert) {
	return pairVertices[vert];
}

double Graph::GetWeight(int vert1, int vert2) {
	double w = -1.0;
	for (GraphsEdge ed : GetNextVertices(vert1)) {
		if (ed.vert == vert2) w = ed.weight;
	}
	//assert(w == -1.0);
	return w;
}

bool isLess(int a, int b) {
	return a < b;
}