#pragma once
#include <string>

using namespace std;

/*
*
* Non protected string - buffer overflow possible with these types
*/
class String
{
protected:
	static const unsigned int MAX = 80; // maximum limit for all strings
	// be it protected or non-protected
	char str[MAX];
public:
	String()
	{
		strcpy_s(str, "");
	}

	String(char s[])
	{
		strcpy_s(str, s);
	}

	String(const char* s)
	{
		strcpy_s(str, s);
	}

	String(string s)
	{
		const char* x = s.c_str();
		strcpy_s(str, x);
	}

	void operator= (char s[])
	{
		strcpy_s(str, s);
	}

	void operator= (const char* s)
	{
		strcpy_s(str, s);
	}

	String operator += (const char* s)
	{
		String temp;
		strcpy_s(temp.str, str);
		strcat_s(temp.str, s);
		return temp;
	}

	operator char* ()
	{
		return str;
	}
};

/**
* Safer strings can be created with this class
**/
class Pstring : public String
{
	char str[MAX];
public:

	Pstring()
	{
		strcpy_s(str, "");
	}

	Pstring(const char* s)
	{
		int len = sizeof(s);
		// if there is string overflow
		if (len < MAX - 1)
		{
			for (int i = 0; i < MAX - 1; i++)
			{
				str[i] = s[i];
			}
			str[MAX - 1] = '\0'; // last character is always null
		}
		else // else copy the entire string
			strcpy_s(str, s);
	}

	// overloaded the += operator for concatenation
	char* operator + (const char* s)
	{
		// s is the string you want to concanetant
		// MAX is the maximum limit i.e. 80 chars and not more
		char foo[MAX]; // create a temporary string
		// continue filling up foo as long as the number of characters filled is 78
		// 79th character is the NULL character
		unsigned int i, j; // i is the common counter, while j is the counter for s
		for (i = 0, j = 0; i < MAX - 1; i++) {
			// first fill up foo with characters of str
			if (i <= strlen(str)) // if position is less than length of str
				foo[i] = str[i]; // keep filling up chars of str
			else {// else, position of the caret has exceeded the length of str
				foo[i] = s[j]; // so start filling foo with characters of s
				j++; // start incrementing j
			}
		}
		foo[MAX - 1] = '\0';
		return foo;
	}

	void operator = (const char* s)
	{
		strcpy_s(str, Pstring(s).str);
	}

	operator const char* ()
	{
		return str;
	}
};
