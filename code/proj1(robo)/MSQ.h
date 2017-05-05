#include <iostream>
#include <string>
#include <mysql.h>
#include <cstdlib>
using namespace std;

typedef struct StLep{
	string* s;
	int* ar;
}StLep;

class MSQ
{
private:
	int res;	//check selection success or not
	MYSQL my_connection;
	MYSQL_RES* res_ptr;
	MYSQL_ROW sqlrow;
	string sentence;				//initial seletion sentence
	string* storage;			//consequent
public:
	MSQ();		//initating and connecting to mysql
	~MSQ(){mysql_close(&my_connection);};	
	StLep search(string* name, int& length);	//searching inputed string array with the end of "end"
};

MSQ::MSQ()
{
	storage = new string[100];
	if(storage == NULL)
	{
		cout<<"Please enter again"<<endl;
		exit(1);
	}

	sentence ="SELECT Coding FROM library WHERE S = ";
	mysql_init(&my_connection);
	if (mysql_real_connect(&my_connection, "localhost", 
									"rick", "zhiyuan961202", "rick", 0, NULL, 0))
	{
		cout<<"Connect is success!"<<endl;
	}
	else
	{
		cout<<"Connect is failure!"<<endl;
		if (mysql_errno(&my_connection))
		{
			cout<<"Connection error "<<mysql_errno(&my_connection)<<": "
									<<mysql_error(&my_connection)<<endl;
		}
	}
}

StLep MSQ::search(string* name, int& length)
{
	string s;	//tempt string used to construct selecting sentence
	int k = 0;
	int l = 0;

	int rm[length];//temp
	for (int i = 0; i < length; ++i)
	{
		rm[i] = -1;
	}

	for(int i = 0; i < length ;i++)
	{
		s = sentence + "'" + name[i] + "'";
		res = mysql_query(&my_connection, s.c_str());
		if (res)
		{
			cout<<"SELECT error("<<s<<"): "<<mysql_error(&my_connection)<<endl;
		}
		else
		{
			res_ptr = mysql_store_result(&my_connection);
			if (res_ptr)
			{
				sqlrow = mysql_fetch_row(res_ptr);
				if(!sqlrow)
				{
					cout<<"                   "<<name[i]<<" are all loaned!"<<endl;

					rm[k] = i;//temp

					k++;
				}
				while(sqlrow)
				{
					storage[l] = sqlrow[0];
					l++;
					break;
				}
				if (mysql_errno(&my_connection))
				{
					cout<<"SELECT error: "<<mysql_error(&my_connection)<<endl;
				}
				mysql_free_result(res_ptr);
			}
		}
	}

	while(k){
		length--;
		k--;
	}

	StLep re;
	re.s = storage;
	re.ar = rm;

	return re;
}