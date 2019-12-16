#include "statistic.h"

using std::vector;

double GetMean(vector <double> arr) {
	double sum = 0.0;
	for (double el : arr) {
		sum += el;
	}
	return sum / arr.size();
}

double GetStandardDeviation(vector <double> arr) {
	double mean = GetMean(arr);
	double stDev = 0.0;
	for (double el : arr) {
		stDev += pow(el - mean, 2.0);
	}
	return stDev;
}

vector <double> GetQuality(vector <double> bf, vector <double> mst) {
	//assert(bf.size() != mst.size());
	vector <double> quality;
	int size = bf.size();
	for (int i = 0; i < size; i++) {
		quality.push_back(2 * mst[i] - bf[i]);
	}
	return quality;
}

double GetQuality(Graph& myGr) {
	createDots(myGr);
	double weightSpTr = getMinimumSpanningTreeWeight(myGr);
	double weightMin = MinWeightBF(myGr);
	double quality = weightSpTr - weightMin;
	return quality;
}

void outputFile(int/*number Of dots*/ n, double mean/*mean error*/, double stDev/*standard deviation*/, double weightBF, double weightMST)
{
	std::ofstream out;
	out.open("output.txt", std::ios_base::app);
	out << n << " vertices" << '\n';
	out << "Mean: " << mean << '\t' << "Standard Deviation: " << stDev << '\n';
	out << "MST:  "<< weightMST <<'\t'<< "BF: " << weightBF << '\t' << "2MST: " << 2*weightMST << '\n';
	out << '\n' << '\n';
}