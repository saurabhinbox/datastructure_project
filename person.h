#ifndef INCLUDED_PERSON_H
#define INCLUDED_PERSON_H

#include <vector>

class Feature;

class Person{
public:
		Person();
		Person(const char* name);
		~Person();
		
		void SetFriend(Person* my_friend);
		std::vector<int> getCostVector();

		bool operator==(const Person& rhs);
private:
		char* person_name_;
		std::vector<Person*> my_friends_;
		std::vector<Feature*> features_;
};

#endif