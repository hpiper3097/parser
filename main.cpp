//c++.com strtok example
//
#include <stdio.h>
#include <string.h>
#include "inc/parser.hpp"
#include "inc/high-res-timer.hpp"

#define ITERATIONS 1000

int main()
{
char str[] = "- This, a sample string.";

auto timer = h_r_Timer();
timer.start();

//for(int i = 0; i < ITERATIONS; i++)
//{
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");

	while(pch != nullptr)
	{
	printf("%s\n",pch);
	pch = strtok(NULL, " ,.-");
	}
	printf("\n");

//}
timer.stop();
auto t1 = timer.time();


std::string str2 = "- This, a sample string.";

timer.start();
//for(auto i = 0; i < ITERATIONS; i++)
//{
	Parser p;
	p.delim_tokeniz(static_cast<std::string>(str2), ' ');
	p.print();
//}
timer.stop();
auto t2 = timer.time();

std::cout << "Splitting the string took strtok " << static_cast<float>(t1/*ITERATIONS*/) << "seconds on average.\n";
std::cout << "Splitting the string took Parser " << static_cast<float>(t2/*ITERATIONS*/) << "seconds on average.\n";

return 0;
}
