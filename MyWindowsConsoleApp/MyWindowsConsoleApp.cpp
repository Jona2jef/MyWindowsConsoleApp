#include <iostream>
#include "pstring.h"

using namespace std;

int main()
{
	Pstring ps = "Hello wor";
	const char* msg = ps + "ld. Jolly rancher blah blah blah the length of this string exceeds 80 fossure!!! BUt God alone knows what I'm doing right now";

	cout << msg << endl;
}