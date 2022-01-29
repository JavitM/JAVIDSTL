#include <iostream>
#include <string.h>
#include <vector>
#include "array.h"
#include "vector.h"
#include "list.h"
#include "stackarray.h"
#include "queuearray.h"
#include "tree.h"
#include "string.h"
#include "sort.h"


class Account
{
public:
	Account(const String& str)
	{
		AccountName = str;
		AccountID = 164268347;
	}


	String AccountName;
	int AccountID;
};

void PrintString(const String& str)
{
	std::cout << str << "\n";
}



int main()
{
	JAVIDSTL::Vector<String> vec;
	String str = "Javid";
	vec.PushBack(str); 
	String str1 = "Mete";
	vec.PushBack(str1);
	String str2 = "AA";
	vec.PushBack(str2);



	for (int i = 0; i < 3; i++)
	{
		PrintString(vec[i]);
	}

	str1 = str2;

	//std::vector<std::string> v;
	//std::string str3 = "dsds";
	//v.push_back(str3);
}
