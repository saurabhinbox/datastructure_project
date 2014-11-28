#include "graph.h"
#include "closeness_checker.h"
#include "person.h"

using namespace std;

Graph::Graph(){
}
Graph::~Graph(){
}

void Graph::push_person(Person* one){
		people_.push_back(one);
}

Person* Graph::GetBestFriend(Person* one){
		vector<vector<int>> next_layer;
		vector<int> target_vector = one->getCostVector();

		int search_count = 0;
		const int people_size = people_.size();
		while (people_size > search_count){
				//get next layer.
				//update search count.
				//evaluation(target_vector, next_layer);
				//get best.
		}
		//return best
}
