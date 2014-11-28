#ifndef INCLUDED_PARSER_H
#define INCLUDED_PARSER_H

#include <vector>
#include <string>

typedef struct TagParser *Parser;

Parser							Parser_New(const char* delimeter, const char* ignore);
std::vector<std::string>		Parser_Parsing(Parser ps, const char* chunck);
void							Parser_Delete(Parser ps);

#endif