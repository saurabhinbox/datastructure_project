#include "file_io.h"
#include "parser.h"
#include <iostream>

using namespace std;

int main(){
		const char* chunck = ReadFile("data/friend_relation/±Ë¿±»Ø.txt");
		
		char* delimeter = "/ ";
		char* ignore = "!@#$";
		Parser obj = Parser_New(delimeter, ignore);
		vector<string> tokens = Parser_Parsing(obj, chunck);

		string out_chunck;
		for (auto ptr : tokens){
				cout << ptr << endl;
				out_chunck += ptr;
				out_chunck += "/";
		}
		
		WriteFile("data/friend_relation/test_out.txt", out_chunck.c_str());

		return 1;
}