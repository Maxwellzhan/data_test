#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Priority.h"
using namespace std;

#ifndef   _aaa_   
#define   _aaa_  
typedef struct info{
	int x;
	int y;
	int z;
}info;
#endif

template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
} 

int* stn(string* s, int len)
{
	int* stor;
	stor = new int[len];
	if (stor == NULL)
	{
		cout<<"Please try again!"<<endl;
		exit(1);
	}
	for (int i = 0; i < len; ++i)
		stor[i] = stringToNum<int>(s[i]);
	return stor;
}

info* obt(int* s, int len)
{
	info* decod;
	decod = new info[len];
	if (decod == NULL)
	{
		cout<<"Please try again!"<<endl;
		exit(1);
	}
	for (int i = 0; i < len; ++i)
	{
		decod[i].x = (s[i]>>8)&7;
		decod[i].y = (s[i]>>6)&3;
		decod[i].z = (s[i]>>4)&3;
	}
	return decod;
}

//transition coding to commanding
info* trans(info* decod, int len, int* movx, int* movy, int* movz)
{
	info* st;
	st = new info[len];
	if (st == NULL)
	{
		cout<<"Please try again!"<<endl;
		exit(1);
	}
	for (int i = 0; i < len; ++i)
	{
		st[i].x = movx[decod[i].x];
		st[i].y = movy[decod[i].y];
		st[i].z = movz[decod[i].z];
	}
	return st;
}

//search x in st[i]
info search(info* st, int len, int x)
{
	info l;	
	for (int i = 0; i < len; ++i)
	{
		if(st[i].x == x)
		{
			l = st[i];
			st[i].x = 0;
			break;
		}
	}
	return l;
}

//sorting movx by using priority queue
info* Sort(info* st, int len)
{
	info* sor;
	sor = new info[len];
	if (st == NULL)
	{
		cout<<"Please try again!"<<endl;
		exit(1);
	}
	int temp1;
	info temp2;
	MaxPQ<int> storage;
	for (int i = 0; i < len; ++i)
		storage.push(st[i].x);
	for (int i = 0; i < len; ++i)
	{	temp1 = storage.pop();
		temp2 = search(st, len, temp1);
		sor[i].x = temp2.x;
		sor[i].y = temp2.y;
		sor[i].z = temp2.z;
	}
	return sor;
}