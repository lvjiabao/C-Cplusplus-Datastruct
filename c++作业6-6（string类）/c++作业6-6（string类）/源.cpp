#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
class string1
{
public:
	string1(char*str = "")
	{
		if (NULL == str)
		{
			p = new char[1];
			*p = '\0';
		}
		else
		{
			p = new char[strlen(str) + 1];
			strcpy(p, str);
		}

	}
	~string1()
	{
		if (p != NULL)
		{
			delete[]p;
			p = NULL;
		}
	}

	string1(const string1&s)
	{
		p = new char[strlen(s.p) + 1];
		strcpy(p, s.p);
	}
	string1&operator=(const string1&s)
	{
		if (this != &s)
		{
			char*pt = new char[strlen(s.p) + 1];
			strcpy(pt, s.p);
			delete[]p;
			p = pt;
		}
		return *this;
	}

	bool operator>(const string1&s);
	bool operator>=(const string1&s);
	bool operator<(const string1&s);
	bool operator<=(const string1&s);
	bool operator==(const string1&s);
	bool operator!=(const string1&s);

	size_t size()const;
	char&operator[](size_t size);
	const char&operator[](size_t size)const;
	bool Strstr(const char*p);
	size_t Copy(char* p, size_t pos, size_t count);
private:
	int mystrcmp(const string1&s);
	char*p;
};

int string1::mystrcmp(const string1&s)
{
	char*pt = p;
	const char*sp = s.p;
	while (*pt&&*sp)
	{
		if (*pt > *sp)
			return 1;
		else if (*pt<*sp)
			return -1;
		else
		{
			pt++;
			sp++;
		}
	}
	if (*pt == 0 && *sp != 0)
		return -1;
	else if (*pt != 0 && *sp == 0)
		return 1;
	else
		return 0;
}


bool string1::operator>(const string1&s)
{
	if (mystrcmp(s.p)>0)
		return true;
	return false;
}

bool string1::operator>=(const string1&s)
{
	if (mystrcmp(s.p) >= 0)
		return true;
	return false;
}

bool string1::operator<(const string1&s)
{
	if (mystrcmp(s.p)<0)
		return true;
	return false;
}

bool string1::operator<=(const string1&s)
{
	if (mystrcmp(s.p) <= 0)
		return true;
	return false;
}

bool string1::operator==(const string1&s)
{
	if (mystrcmp(s.p) == 0)
		return true;
	return false;
}

bool string1::operator!=(const string1&s)
{
	if (mystrcmp(s.p) == 0)
		return false;
	return true;
}

size_t string1::size()const
{
	char*pt = p;
	while (*pt)
		pt++;
	return pt - p;
}

char& string1::operator[](size_t size)
{
	if (size <= this->size())
		return p[size];
	else
	{
		cout << "out of range\n";
		exit(EXIT_FAILURE);
	}
}

const char& string1::operator[](size_t size)const//俩[]必须一起重载
{
	if (size <= this->size())
		return p[size];
	else
	{
		cout << "out of range\n";
		exit(EXIT_FAILURE);
	}
}

bool string1::Strstr(const char*pointer)
{
	char*pleft = p;
	const char*pright = pointer;
	char*start = NULL;
	while (*pleft != 0)
	{
		start = pleft;
		while (*pleft == *pright&&*pleft&&*pright)
		{
			pleft++;
			pright++;
		}
		if (*pright == 0)
			return true;
		pright = pointer;
		pleft = start + 1;
	}
	return false;
}

size_t string1::Copy(char* pointer, size_t pos, size_t count)
{
	assert(p);
	char*pt = p+pos;
	int _count = count;
	while (count&&(*pointer++=*pt++))
	{
		count--;
	}
	return _count - count;
}



class string2
	{
	public:
		string2(char*pt = "")
		{
			if (NULL == pt)
			{
				p = new char[1];
				*p = '\0';
			}
			else
			{
				p = new char[strlen(pt) + 1];
				strcpy(p, pt);
			}
		}
		~string2()
		{
			if (NULL != p)
			{
				delete[]p;
				p = NULL;
			}
		}
		string2(const string2&s) :p(NULL)
		{
			string2 temp(s.p);
			std::swap(p, temp.p);
		}
		string2&operator=(const string2&s)
		{
			if (&s != this)
			{
				string2 temp(s.p);
				std::swap(p, temp.p);
			}
			return *this;
		}
		/*string2&operator=(string2 s)
		{
			std::swap(p, s.p);
			return *this;
		}*/
	private:
		char*p;
	};





class string3
{
public:
	string3(char*str = "") :pcount(new int(1))
	{
		if (NULL == str)
		{
			p = new char[1];
			*p = '\0';
		}
		else
		{
			p = new char[strlen(str) + 1];
			strcpy(p, str);
		}
	}
	~string3()
	{
		--(*pcount);
		if (p != NULL&&*pcount==0)
		{
			delete pcount;
			pcount = NULL;
			delete[]p;
			p = NULL;
		}
	}
	string3(const string3&s)
	{
		p = s.p;
		++(*s.pcount);
		pcount = s.pcount;
	}
	string3&operator=(const string3&s)
	{
		if (pcount != s.pcount)
		{
			--(*pcount);
			if (0 == *pcount)
			{
				delete[]p;
				delete pcount;
			}
			p = s.p;
			++(*s.pcount);
			pcount = s.pcount;
		}
		return *this;
	}
private:
	char*p;
	int* pcount;
};



class string4
{
public:
	string4(char*str = "")
	{
		if (NULL == str)
		{
			p = new char[1+4];
			Getres() = 1;
			*(p+4) = '\0';
		}
		else
		{
			p = new char[strlen(str) + 1+4];
			Getres() = 1;
			strcpy(p + 4, str);
		}
	}
	~string4()
	{
		--(Getres());
		if (p + 4 != NULL&&Getres()== 0)
		{
			delete[]p;
			p = NULL;
		}
	}
	string4(const string4&s)
	{
		p = s.p;
		++(Getres());
	}
	string4&operator=(const string4&s)
	{
		if (this!=&s)
		{
			--(Getres());
			if (0 == Getres())
			{
				delete[]p;
			}
			p = s.p;
			++(Getres());
		}
		return *this;
	}
private:
	int&Getres()
	{
		return *((int*)p);
	}
	char*p;
};

int main()
{
	string1 s1("1234");
	cout << s1.size();
	return 0;
}