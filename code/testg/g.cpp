#include<iostream>
using namespace std;
int main(){
	int foo=10,bar=15;
	__asm__ __volatile__(
		"addl %%ebx,%%eax"
		:"=a"(foo)
		:"a"(foo),"b"(bar)
	);
	cout<<foo<<endl;
	return 0;
}

