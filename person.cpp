#include "person.h"
#include "feature.h"

using namespace std;

namespace{
		char* copy_string(const char* src){
				int input_len = strlen(src) + 1;
				char* ret = (char*)malloc(sizeof(char)* input_len);
				strncpy(ret, src, input_len);
				return ret;
		}
}//namespace

Person::Person() : person_name_(nullptr){
}
Person::Person(const char* name){
		person_name_ = copy_string(name);
}
Person::~Person(){
		if (nullptr != person_name_){
				free(person_name_);
				person_name_ = 0;
		}
}

void Person::SetFriend(Person* my_friend){
		my_friends_.push_back(my_friend);
}

vector<int> Person::getCostVector(){
		vector<int> ret;
		for (auto ptr : features_){
				ret.push_back(ptr->GetScore());
		}
		return ret;
}

bool Person::operator==(const Person& rhs){
		if (0 == strcmp(person_name_, rhs.person_name_)){
				return true;
		}
		return false;
}