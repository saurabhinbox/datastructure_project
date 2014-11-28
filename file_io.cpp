#pragma warning(disable:4996)

#include "file_io.h"
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

const char* ReadFile(const char* file_path){
		string ret;
		ifstream file(file_path, ios::in);

		if (file){
				stringstream buffer;

				buffer << file.rdbuf();

				file.close();

				ret = buffer.str();
		}
		else{
				//file read fail
		}

		int ret_len = ret.size() + 1;
		char* ret_c = (char*)malloc(sizeof(char) * ret_len);
		strncpy(ret_c, ret.c_str(), ret_len);
		return ret_c;
}

void WriteFile(const char* file_path, const char* input){
		string temp(input);
		ofstream file(file_path, ios::out);

		if (file){
				file << input;
				file.close();
		}
		else{
				//file write fail
		}
}
