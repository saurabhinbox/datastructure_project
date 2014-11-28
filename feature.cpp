#include "feature.h"
#include "word.h"
#include <string.h>

namespace{
		
}//namespace

Feature::Feature() : key_(0){
}
Feature::Feature(const Feature& copy) : key_(copy.key_){
		while (words_.empty() == false){
				words_.at(0) = nullptr;
				words_.erase(words_.begin());
		}

		for (auto ptr : copy.words_){
				words_.push_back(ptr);
		}
}
Feature::~Feature(){
		//TODO :: 
}

void Feature::SetWord(Word* property_word){
		words_.push_back(property_word);
}

int Feature::GetScore(){
		int sum = 0;
		for (auto ptr : words_){
				sum += ptr->GetCount();
		}
		return sum;
}

Feature Feature::operator=(const Feature& rhs){
		while (words_.empty() == false){
				words_.at(0) = nullptr;
				words_.erase(words_.begin());
		}

		for (auto ptr : rhs.words_){
				words_.push_back(ptr);
		}

		key_ = rhs.key_;
		return (*this);
}
