#pragma warning(disable:4996)

#include "parser.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

struct TagParser{
		char* delimeter;
		char* ignore;
};


namespace{
		bool is_delimeter_char(const char* delimeter, char c){
				unsigned int delimeter_len = strlen(delimeter);
				for (unsigned int i = 0; i < delimeter_len; i++){
						if (c == delimeter[i]){
								return true;
						}
				}
				return false;
		}

		bool is_ignore_char(const char* ignore, char c){
				unsigned int ignore_len = strlen(ignore);
				for (unsigned int i = 0; i < ignore_len; i++){
						if (c == ignore[i]){
								return true;
						}
				}
				return false;
		}

}//namespace


//TODO :: dangerous -> parameter char need to restrict string type.
Parser Parser_New(const char* delimeter, const char* ignore){
		Parser ret = (Parser)malloc(sizeof(TagParser));
		
		int delimeter_len = strlen(delimeter) + 1;
		ret->delimeter = (char*)malloc(sizeof(char) * delimeter_len);
		if (NULL != ret->delimeter){
				strncpy(ret->delimeter, delimeter, delimeter_len);
		}

		int ignore_len = strlen(ignore) + 1;
		ret->ignore = (char*)malloc(sizeof(char) * ignore_len);
		if (NULL != ret->ignore){
				strncpy(ret->ignore, ignore, ignore_len);
		}
		return ret;
}

vector<string> Parser_Parsing(Parser ps, const char* chunck){
		vector<string> ret;

		string token;
		int chunck_len = strlen(chunck);
		for (int i = 0; i < chunck_len; i++){
				char c = chunck[i];
				if (is_delimeter_char(ps->delimeter, c)){
						if (token.empty() == false){
								ret.push_back(token);
								token.clear();
						}
				}else if (is_ignore_char(ps->ignore, c)){
						continue;
				}
				else{
						token += c;
				}
		}
		
		if (token.empty() == false){
				ret.push_back(token);
				token.clear();
		}
		return ret;
}

void Parser_Delete(Parser ps){
		//TODO :: if needed...		
}
