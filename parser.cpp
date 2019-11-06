//parser.cpp

#include "inc/parser.hpp"

void Parser::print()
{
	for(auto i = tokens.begin(); i != tokens.end(); ++i)
		std::cout << *i << "\n";
}

std::vector<std::string> Parser::delim_tokeniz(std::string str, char delim)
{
	std::stringstream ss(str);	
	std::string temp;

	while(std::getline(ss, temp, delim))
	{
		tokens.push_back(temp);
	}

	return tokens;
}
