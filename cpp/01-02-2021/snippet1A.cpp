#include <iostream>
#include <string>

using namespace std;

int main()
{
	string text = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean m";
	text.erase(134, 1);
	
	return 0;
}