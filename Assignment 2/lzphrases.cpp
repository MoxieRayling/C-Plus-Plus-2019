#include <iostream>
#include <set>

std::string escapeChar(char ch)
{
	switch(ch)
	{
		case '\t': return "\\t";
		case ' ': return "\\s";
		case '\n': return "\\n";
		case '\r': return "\\r";
		case '\\': return "\\\\";
	}
	if(isdigit(ch)) return "\\"+std::string(1,ch);
	return std::string(1,ch);
}

std::string escapeString(const std::string& s){
	std::string result;
	for(const char& ch : s)
	{
		result += escapeChar(ch);
	}
	return result;
}

int main() 
{
	std::set<std::string> phrases;
	char input;
	std::string test = "";
	while(std::cin.get(input))
	{
		if(phrases.find(test)!=phrases.end()||test ==""){
			test += input;
		}
		else{
			std::cout<<escapeString(test) << std::endl;
			phrases.insert(test);
			test = input;
		}
	}
	std::cout<<escapeString(test) <<std::endl;
}