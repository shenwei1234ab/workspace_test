#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include <assert.h>
#include<iostream>
using namespace std;

class CString
{
public:
	const char *C_Str()const
	{
		return m_data;
	}
	CString(const char *str=NULL)
	{
		if(str == NULL)
		{
			m_data = new char[1];
			*m_data = '\0';
		}
		else
		{
			int len = strlen(str);
			m_data = new char [len +1];
			strcpy(m_data,str);
		}
	}


	CString(const CString &other)
	{
		int len = strlen(other.m_data);
		m_data = new char[len+1];
		strcpy(m_data,other.m_data);
	}


	~CString()
	{
		delete []m_data;
	}


	CString & operator =(const CString &rhs)
	{
		if(&rhs == this)
		{
			return *this;
		}
		delete []m_data;
		int len = strlen(rhs.m_data);
		m_data = new char[len+1];
		strcpy(m_data,rhs.m_data);
		return *this;
	}

	CString  operator+(const CString &rhs)
	{
		int len = strlen(m_data)+strlen(rhs.m_data)+1;
		char *pNewStr = new char[len];
		snprintf(pNewStr,len,"%s%s",m_data,rhs.m_data);
		CString ret(pNewStr);
		return ret;
	}


private:
	char *m_data;

private:

};
