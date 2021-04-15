#include "pstring.h"
#include <iostream>

using namespace std;

int main()
{
	Pstring msg;
	char s[] = "This message will surely exceed the width of the screen which is what the max size constant represents";
	msg = s;
	cout << msg << endl;
	cout << strlen(msg) << endl;
}
