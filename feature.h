#ifndef INCLUDED_FEATURE_H
#define INCLUDED_FEATURE_H

#include <vector>

class Word;

class Feature{
public:
		Feature();
		Feature(const Feature& copy);
		~Feature();

		void SetWord(Word* property_word);
		int GetScore();

		Feature operator=(const Feature& rhs);

private:
		int key_;
		std::vector<Word*> words_;
};

#endif