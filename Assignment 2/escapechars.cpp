#include <iostream>

std::string escapeChar(char ch)
{
	switch(ch)
	{
		case '\t': return "\\t";
		case ' ' : return "\\s";
		case '\n': return "\\n";
		case '\r': return "\\r";
		case '\\': return "\\\\";
	}
	if(isdigit(ch)) return "\\"+std::string(1,ch);
	return std::string(1,ch);
}

int main() 
{
	char ch = ' ';
	while(std::cin.get(ch))
	{
    	std::cout<<escapeChar(ch);
	}
}

