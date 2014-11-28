#ifndef INCLUDED_WORD_H
#define INCLUDED_WORD_H

class Word{
public:
		Word();
		Word(char* word_name);
		Word(const Word& copy);
		~Word();

		void IncreaseCount();
		void SetWordName(const char* word_name);

		int GetCount();

		Word operator=(const Word& rhs);

private:
		char* word_name_;
		int count_;
};

#endif