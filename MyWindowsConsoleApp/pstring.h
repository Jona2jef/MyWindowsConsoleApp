#pragma once
#include <string>

using namespace std;

class String
{
protected:
	static const int MAX = 80;
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

	operator char* ()
	{
		return str;
	}
};

class Pstring : public String
{

protected:
	char str[String::MAX];

public:

	Pstring()
	{
		strcpy_s(str, "");
	}

	Pstring(char s[])
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
		else
		{
			strcpy_s(str, s);
		}
	}

	operator char* ()
	{
		return str;
	}
};
