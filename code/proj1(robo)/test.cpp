/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	                                                                                                                                   //    
//	class MSQ(impelement in MSQ.h): connect to database and search the coding of books from library table                              //
//	Type name StLe(define in iout.h): contain string* and int to store search string and its length                                    //
//	Type name StLep(define in MSQ.h): contain string* and int* to store search string and error index to remove string(used in ouput)  //
//	Type name info(define in inout.h): orgnize the struction of books' information(moving Xm, Ym, Zcm)                                 //
//	movx[], movy[] and movz[]: used to decode the distance of books by the code                                                        //
//                                                                                                                                     //
//	Define in datapro.h, the funcions of data processing                                                                               //
//	Function stn(search_info, length): transform the strings to integers by parameters of string point and its length                  //
//	Function obt(string_to_code, length): orgnize the books' information struction by transforming integers to type info               //
//	Function trans(code_init_struct, length, movx, movy, movz): decode the coding (movx, movy, movz)                                   //
//	Function Sort(code_to_init_dist, length): sorting by the value of movx with the priority queue defined in Priority.h               //
//                                                                                                                                     //
//	Define in inout.h, the functions of input and output                                                                               //
//	Function window(): output some essential information and receive the input strings                                                 //
//	Function outcode(string_to_code, input_info, length): output the code of books with bibary formulation                             //
//	Function outseq(code_to_init_dist, length): output the data processing                                                             //
//                                                                                                                                     //      //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "datapro.h"
#include "MSQ.h"
#include "inout.h"
using namespace std;

int main(int argc, char const *argv[])
{
	//intiate parameter setting
	MSQ my_data;
	StLe input_temp;
	StLep info_temp;//temp situation
	string* input_info, *search_info;
	int length, temp;
	int* string_to_code, *remove;

	info* code_init_struct, *code_to_init_dist, *code_conseq;

	int movx[8], movy[4], movz[4];		
	for(int i = 0; i < 8; ++i)
	{
		movx[i] = (i+1)*3;
	}
	for(int i = 0; i < 4; ++i)
	{
		movy[i] = (i+1)*2;
		movz[i] = (i+1)*50;
	}

	input_temp = window();

	cout<<endl;
	cout<<endl;

	input_info = input_temp.s;
	temp = length = input_temp.len;

	//search infomation and process
	info_temp = my_data.search(input_info, length);//temp storing

	search_info = info_temp.s;
	remove = info_temp.ar;

	//modify the input string because of the unsuccessiful searching
	for (int i = 0; i < temp; ++i)
	{
		if(remove[i] == -1)
			break;
		for (int j = remove[i] + 1; j < temp; ++j)
		{
			input_info[j-1] = input_info[j];
		}
	}

	string_to_code = stn(search_info, length);

	code_init_struct = obt(string_to_code, length);

	outcode(string_to_code, input_info, length);
	code_to_init_dist = trans(code_init_struct, length, movx, movy, movz);

	cout<<endl;
	cout<<endl;
	cout<<"                   Unsorted list of books picking is"<<endl;
	outseq(code_to_init_dist, length);

	code_conseq = Sort(code_to_init_dist, length);

	cout<<endl;
	cout<<endl;
	cout<<"                   Sorted list of books picking is"<<endl;
	outseq(code_conseq, length);

	return 0;
}