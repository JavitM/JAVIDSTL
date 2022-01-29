// JAVIDSTL. Created By Javid Mamedov.
#pragma once
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class String
{
public:
	String()
	{
		//m_Data = new char[1];
		//m_Data[0] = '\n';
	}

	String(const char* val)
	{
		//delete m_Data;
		m_Size = strlen(val);
		m_Data = new char[strlen(val) + 1];

		memcpy(m_Data, val, m_Size);
		
		m_Data[m_Size] = '\0';


		std::cout << "1 The string passed is: "
			<< m_Data << " |" << std::endl;

	}

	String(const char* val, size_t size)
	{
		delete m_Data;
		m_Data = new char[size + 1];

		memcpy(m_Data, val, size);

		m_Size = size;

		std::cout << "2 The string passed is: "
			<< m_Data << std::endl;
	}

	String(const String& source)
	{
		std::cout << "Copy Constructor The string \n";
		m_Size = source.m_Size;
		m_Data = new char[m_Size + 1];
		memcpy(m_Data, source.m_Data, m_Size);
		m_Data[m_Size] = '\0';
	}

	/* String(String&& source)
	{
		m_Data = source.m_Data;
		source.m_Data = nullptr;
	} */

	String& operator=(String&& source)
	{
		m_Size = source.m_Size;
		char* temp = source.m_Data;
		m_Data = source.m_Data;
		return *this;
	}

	String& operator=(const char* source)
	{
		delete m_Data;
		m_Data = nullptr;
		m_Size = strlen(source);
		m_Data = new char[m_Size + 1];
		memcpy(m_Data, source, m_Size);
		m_Data[m_Size] = '\0';

		return *this;
	}

	String& operator=(String& source)
	{
		char* ptr = m_Data;
		//delete m_Data;
		//::operator delete(m_Data, m_Size * sizeof(char));
		m_Data = nullptr;
		m_Size = source.m_Size;
		m_Data = new char[m_Size + 1];
		memcpy(m_Data, source.m_Data, m_Size);
		m_Data[m_Size] = '\0';
		delete ptr;
		return *this;


		/* ::operator delete(m_Data, m_Size * sizeof(char*));
		m_Data = nullptr;
		m_Size = source.m_Size;
		m_Data = new char[m_Size + 1];
		memcpy(m_Data, source.m_Data, m_Size);
		m_Data[m_Size] = '\0';  
		return *this; */
	}

	String& operator=(const String& source)
	{
		delete m_Data;
		m_Data = nullptr;
		m_Size = source.m_Size;
		m_Data = new char[m_Size + 1];
		memcpy(m_Data, source.m_Data, m_Size);
		m_Data[m_Size] = '\0';

		return *this;
	}

	char& operator[](size_t size)
	{
		return m_Data[size];
	}

	char* GetString()
	{
		return m_Data;
	}

	const char* GetString() const
	{
		return m_Data;
	}

	size_t Size()
	{
		return m_Size;
	}

	const size_t Size() const
	{
		return m_Size;
	}

	~String()
	{
		delete m_Data;
	}
private:
    char* m_Data = nullptr;
	size_t m_Size = 0;
};

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	std::cout << str.GetString();
	return stream;
}
