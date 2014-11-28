#ifndef INCLUDED_GRAPH_H
#define INCLUDED_GRAPH_H

#include <vector>

class Person;

class Graph{
public:
		Graph();
		~Graph();

		void push_person(Person* one);

		Person* GetBestFriend(Person* one);
private:
		std::vector<Person*> people_;
};

#endif