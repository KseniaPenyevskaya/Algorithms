#include <iostream>
#include <vector>

#include "graph.h"
#include "dots.h"
#include "mst.h"
#include "bf.h"
#include "statistic.h"

using std::vector;

int main() {
	int numberExperiments = 100;
	int maxNumberVertices = 10;
	vector <int> numberVertices;

	for (int i = 3; i <= 10; i++) {
		numberVertices.push_back(i);
	}

	vector <double> qual;
	vector <double> bfWeight;
	vector <double> mstWeight;
	
	for (int numbVert : numberVertices) {
		qual.clear();
		bfWeight.clear();
		mstWeight.clear();
		for (int i = 0; i < numberExperiments; i++) {
			Graph myGr(numbVert);
			createDots(myGr);
			bfWeight.push_back(MinWeightBF(myGr));
			mstWeight.push_back(getMinimumSpanningTreeWeight(myGr));
		}
		qual = GetQuality(bfWeight, mstWeight);

		outputFile(numbVert, GetMean(qual), GetStandardDeviation(qual), GetMean(bfWeight), GetMean(mstWeight));
	}
}
