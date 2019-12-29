#include <iostream>
#include <vector>

#include "graph.h"
#include "dots.h"
#include "mst.h"
#include "bf.h"
#include "statistic.h"

using std::vector;

int main() {
	srand(time(0));
	int numberExperiments = 100;
	int maxNumberVertices = 10;

	vector <int> numberVertices;

	for (int i = 2; i <= maxNumberVertices; i++) {
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
			mstWeight.push_back(apprMinWeight(myGr));
		}
		qual = GetQuality(bfWeight, mstWeight);

		outputFile(numbVert, GetMean(qual), GetStandardDeviation(qual), GetMean(bfWeight), GetMean(mstWeight));
	}
	
}
