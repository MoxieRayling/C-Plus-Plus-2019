#include <iostream>
#include<map>

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
	std::map<std::string, unsigned int> phrases{{"",0}};
	char input;
	std::string test = "";
	while(std::cin.get(input))
	{
		if(phrases.find(test)!=phrases.end()||test ==""){
			test += input;
		}
		else{
			std::cout<< std::to_string(phrases.find(test.substr(0,test.size()-1))->second) + escapeChar(test.back()) <<std::endl;
			phrases.insert(std::pair<std::string,unsigned int>(test,phrases.size()));
			test = input;
		}
	}
	std::cout<< std::to_string(phrases.find(test.substr(0,test.size()-1))->second) + escapeChar(test.back())<<std::endl;
}