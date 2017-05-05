#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class MaxPQ
{
private:
	T* array;
	int cursize;
	int maxsize;

	void doubleSp();			//double space to addapt requestion
public:
	MaxPQ(T a = 0,int size = 20);
	~MaxPQ(){delete[] array;};
	MaxPQ(const MaxPQ<T>& a);
	void reshape(const T* a, int size);
	bool isEmpty();
	const T& Top();				//return the top of queue
	void push(const T num);
	T pop();
	template<class l> friend ostream& operator<<(ostream& os, const MaxPQ<l>& a);
};

template<class T>
void MaxPQ<T>::doubleSp(){
	T* temp = array;
	maxsize *= 2;
	array = new T[maxsize+1];
	if(array == NULL){
		cout<<"Please try again"<<endl;
		exit(1);
	}
	for(int i = 1; i <= cursize; i++)
		array[i] = temp[i];
	delete[] temp;
}

template<class T>
MaxPQ<T>::MaxPQ(T a, int size){
	maxsize = size;
	cursize = 0;
	array = new T[maxsize+1];
	if(array == NULL){
		cout<<"Please try again"<<endl;
		exit(1);
	}
	array[0] = 0;
	for (int i = 1; i <= maxsize; ++i)
	{
		array[i] = a;
	}
}

template<class T>
MaxPQ<T>::MaxPQ(const MaxPQ<T>& a){
	cursize = a.cursize;
	maxsize = a.maxsize;
	array = new T[maxsize+1];
	if(array == NULL){
		cout<<"Please try again"<<endl;
		exit(1);
	}
	for (int i = 1; i <= cursize; ++i)
		array[i] = a.array[i];
}

template<class T>
bool MaxPQ<T>::isEmpty(){
	if(cursize == 0)
		return 0;
	else
		return 1;
}

template<class T>
const T& MaxPQ<T>::Top(){
	return array[1];
}

template<class T>
void MaxPQ<T>::push(const T num){
	if(cursize == maxsize)
		doubleSp();
	cursize ++;
	int k;
	int i = cursize;
	while(true){
		if(i == 1){k = i;break;}		//at root
		if(num >= array[i/2]){k = i;break;}
		//move top
		array[i] = array[i/2];
		i = i/2;
	}
	array[k] = num;
}

template<class T>
T MaxPQ<T>::pop(){
	if(cursize == 0)
	{cout<<"The queue is Empty!"<<endl;exit(1);}
	T temp1 = array[1];
	T temp2 = array[cursize];

//cout<<"temp1: "<<temp1<<"   temp2: "<<temp2<<endl;

	cursize--;
	int i = 1;
	for (int j = 2; j <= cursize; )
	{
		if (j < cursize)
		{
			if(array[j] > array[j+1])
				j++;
		}
		if(temp2 <= array[j])break;
		array[i] = array[j];
		i = j;
		j *= 2;
	}
	//cout<<"i = "<<i<<endl;
	array[i] = temp2;
	return temp1;
}

template<class T>
void MaxPQ<T>::reshape(const T* a, int size){
	for (int i = 0; i < size; ++i){
		push(a[i]);
	}
}

template<class T>
ostream& operator<<(ostream& os, const MaxPQ<T>& a){
	os<<"The Priority is:"<<endl;
	for (int i = 1; i <= a.cursize; ++i)
	{
		os<<a.array[i]<<endl;
	}
	return os;
}