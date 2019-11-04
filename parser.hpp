//parser.hpp
#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdio.h>

class Parser
{
public:
	Parser() = default;
	~Parser() = default;
	std::vector<std::string> delim_tokeniz(std::string str, char delim);
	void print();
private:
	std::size_t m_id;
	std::vector<std::string> tokens;
};
#endif
