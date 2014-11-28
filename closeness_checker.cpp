#include "closeness_checker.h"
#include <math.h>

using namespace std;

namespace{
		
		vector<int> cosine_scoring(vector<int>& target, vector< vector<int> >& feature_vector){
				
		}

		vector<int> euclidian_scoring(vector<int>& target, vector< vector<int> >& feature_vector){
		
		}

}//namespace

vector<int> evaluation(vector<int> target, vector< vector<int> > feature_vector){
		vector<int> total_score;
		
		//sum scoring.
		//initialize total_score vector.
		for (auto y : feature_vector){
				int sum = 0;
				for (auto x : y){
						sum += x;
				}
				total_score.push_back(sum);
		}


}