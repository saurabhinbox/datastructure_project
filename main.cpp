#include "file_io.h"
#include "parser.h"
#include <iostream>

using namespace std;

namespace{

		void initialize(){
				// TODO :: objects allocation.
				
		
		}

		void start_display(){
				// TODO :: program start window.
		}
		
		void end_display(){
				// TODO :: program end window.
		}

		void execution(){
				//TODO :: main algorithm start.
		}

}

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