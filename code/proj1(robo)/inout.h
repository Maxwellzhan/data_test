#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

#ifndef   _aaa_   
#define   _aaa_  
typedef struct info{
	int x;
	int y;
	int z;
}info;
#endif

typedef struct StLe{
	string* s;
	int len;
}StLe;

StLe window()
{
	string* borrow;
	borrow = new string[100];
	if (borrow == NULL)
	{
		cout<<"Please try again!"<<endl;
		exit(1);
	}
	int length = 0;


	cout<<"                   *********************************************************************************"<<endl;
	for (int i = 0; i < 3; ++i)
	{
		cout<<"                   **                                                                             **"<<endl;
	}
	cout<<"                   **                         THE SIMULATION OF iLIBRA 1.0                        **"<<endl;	
	for (int i = 0; i < 2; ++i)
	{
		cout<<"                   **                                                                             **"<<endl;
	}
	cout<<"                   ** The database of this simulation has some books:                             **"<<endl;
	cout<<"                   **          CODING                   NAME                                      **"<<endl;
	cout<<"                   **        51.61/A645=2      Mathematical Analysis(3)                           **"<<endl;
	cout<<"                   **        73.914/C811=2     Introduction to Algorithms(2)                      **"<<endl;
	cout<<"                   **        73.91/S618=2      Introduction to the Theory of Computation(1)       **"<<endl;
	cout<<"                   **        TPO303/P317.3=5   Computer Organization(1)                           **"<<endl;
	cout<<"                   **                                                                             **"<<endl;
	cout<<"                   ** Notation:                                                                   **"<<endl;
	cout<<"                   **          (1)Please input the coding of books in your need,                  **"<<endl;
	cout<<"                   **             use blank to separate and end by \"end\"                          **"<<endl;
	cout<<"                   **          (2)If your input is error or the books searched are                **"<<endl;
	cout<<"                   **             all loaned, it would output \"your book's name are all loaned!\"  **"<<endl;
	for (int i = 0; i < 3; ++i)
	{
		cout<<"                   **                                                                             **"<<endl;
	}
	cout<<"                   *********************************************************************************"<<endl;
	cout<<"                   The books you want to borrow are:"<<endl;
	cout<<"                                 ";
	for (int i = 0;; ++i)
	{
		cin>>borrow[i];
		if(borrow[i] == "end")
			break;
		length++;
	}

	StLe Binfo;
	Binfo.s = borrow;
	Binfo.len = length;
	return Binfo;
}

void outcode(int* codenum, string* borrow, int len)
{
	int n;
	cout<<"                   The books' codes are:"<<endl;
	for (int i = 0; i < len; ++i)
	{
		n = codenum[i];
		int a[11];
		for (int k = 0; k < 11; ++k)
		{
			a[10-k] = n%2;
			n = n/2;
		}
		cout<<"                       "<<borrow[i]<<": ";
		for (int j = 0; j < 11; ++j)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
}

ostream& operator<<(ostream& os, const info& a)
{
	os<<"Moving x: "<<a.x<<"m"<<endl;
	os<<"                           Moving y: "<<a.y<<"m"<<endl;
	os<<"                           Moving z: "<<a.z<<"cm"<<endl;
	return os;
}

void outseq(info* conseq, int len)
{
	cout<<"                   What the distance should be moved is: "<<endl;
	cout<<endl;
	for (int i = 0; i < len; ++i)
	{
		cout<<"                           "<<conseq[i];
		cout<<endl;
	}
}