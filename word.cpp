#include "word.h"
#include <stdlib.h>
#include <string.h>

namespace{
		char* copy_string(const char* src){
				int input_len = strlen(src) + 1;
				char* ret = (char*)malloc(sizeof(char)* input_len);
				strncpy(ret, src, input_len);
				return ret;
		}
}//namespace

Word::Word() : word_name_(NULL), count_(0){

}
Word::Word(char* word_name) : count_(0){
		word_name_ = copy_string(word_name);
}
Word::Word(const Word& copy) : count_(copy.count_){
		word_name_ = copy_string(copy.word_name_);
}
Word::~Word(){
		if (NULL != word_name_){
				free(word_name_);
		}
}

void Word::IncreaseCount(){
		++count_;
}

void Word::SetWordName(const char* word_name){
		word_name_ = copy_string(word_name);
}

int Word::GetCount(){
		return count_;
}

Word Word::operator=(const Word& rhs){
		char* temp = word_name_;
		word_name_ = copy_string(rhs.word_name_);
		free(temp);
		
		count_ = rhs.count_;

		return (*this);
}
