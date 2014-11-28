#include "closeness_checker.h"
#include <math.h>

using namespace std;

namespace{
		
		vector<double> cosine_scoring(vector<int>& target, vector< vector<int> >& feature_vector){
				vector<double> score;

				int target_size = target.size();
				for (auto v : feature_vector){
						int dot_product = 0;
						double target_scalar = 0;
						double v_scalar = 0;
						for (int i = 0; i < target_size; i++){
								dot_product += target.at(i) * v.at(i);
								target_scalar += pow(target.at(i), 2.0);
								v_scalar += pow(v.at(i), 2.0);
						}
						target_scalar = sqrt(target_scalar);
						v_scalar = sqrt(v_scalar);

						score.push_back(acos((double)dot_product/(target_scalar * v_scalar)));
				}
				return score;
		}

		vector<double> euclidian_scoring(vector<int>& target, vector< vector<int> >& feature_vector){
				vector<double> score;
				
				int target_size = target.size();
				for (auto v : feature_vector){
						double distance = 0;
						for (int i = 0; i < target_size; i++){
								distance += pow((target.at(i) - v.at(i)), 2.0);
						}
						distance = sqrt(distance);

						score.push_back(distance);
				}
				return score;
		}

}//namespace

//sum bigger, priority smaller.
vector<double> evaluation(vector<int> target, vector< vector<int> > feature_vector){
		vector<double> total_score;
		vector<double> cosine_score = cosine_scoring(target, feature_vector);
		vector<double> euclidian_score = euclidian_scoring(target, feature_vector);

		//sum scoring.
		int count = 0;
		for (auto y : feature_vector){
				double sum = 0;
				for (auto x : y){
						sum += x;
				}
				sum += cosine_score.at(count);
				sum += euclidian_score.at(count);
				total_score.push_back(sum);
				++count;
		}

		return total_score;
}

