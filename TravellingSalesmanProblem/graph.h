#pragma once

#include<iostream>
#include<vector>
#include<cassert>
#include<climits>
#include<set>
#include<utility> 

struct GraphsEdge {
	GraphsEdge();
	GraphsEdge(int vert, double weight);
	int vert;
	double weight;
};

class Graph {
public:
	Graph(int countVertices);
	void AddEdge(int x, int y, double weight);
	int GetVerticesCount();
	std::vector <GraphsEdge> GetNextVertices(int vert);
	double GetWeight(int vert1, int vert2);
private:
	int N;
	unsigned int countVertices;
	std::vector <std::vector <GraphsEdge> > pairVertices;
};