#include <iostream>
#include <fstream>
std::string escapeChar(char ch){
	switch(ch){
		case '\t': return "\\t";
		case ' ': return "\\s";
		case '\n': return "\\n";
		case '\r': return "\\r";
		case '\\': return "\\\\";
	}
	if(isdigit(ch)) return "\\"+std::string(1,ch);

	return std::string(1,ch);
}
int main() {
std::string str = "";
	std::getline()  "";
	while(std::cin>>str)
	std::cout<<str;
	return 0;
}

