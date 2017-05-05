#include <iostream>
#include <cstdlib>
using namespace std;

class Bit
{
private:
	int bitsize;
	int current;
	int* bit;
public:
	Bit(int b = 11);
	~Bit(){delete[] bit;};
	void insert(int ele);
	void show();
};

Bit::Bit(int b)
{
	bitsize = b;
	current = 0;
	bit = new int[bitsize+1];
	if(bit == NULL)
	{
		cout<<"Please enter again"<<endl;
		exit(1);
	}
	for (int i = 0; i < bitsize; ++i)
	{
		bit[i] = 0;
	}
}

void Bit::insert(int ele)
{
	if (current > bitsize)
	{
		cout<<"error!"<<endl;
		exit(1);
	}
	current ++;
	bit[bitsize - current +1] = ele;
}

void Bit::show()
{
	for (int i = 1; i <= bitsize; ++i)
	{
		cout<<bit[i];
	}
	cout<<endl;
	current = 0;
}