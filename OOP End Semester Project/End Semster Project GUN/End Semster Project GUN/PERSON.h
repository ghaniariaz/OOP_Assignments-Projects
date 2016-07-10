//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		                                 PERSON CLASS         	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>


using namespace std;


class Person
{	
	friend class Ticket;
protected:
	
	char name[20];
	char gender[10];
	char nationality[20];
	char cnic[20];
	int age;

public:
	

		Person(){
		strcpy(name,"Default");
		age=19;
		strcpy(gender,"Male");
		strcpy(nationality,"Pakistani");
				}


	void setdata()
	{	
		
		cout<<"PLEASE ENTER YOUR FULL NAME"<<endl<<endl;
		//////////////////////////////////////////////////
		// Name Exception
		/////////////////////////////////////////////////
		for(int i=0;i<1;i++)
		{
			try{
				cin.ignore();
				gets(name);
				throw 1;
				}
			catch(int a)
				{
					if(isdigit(name[0]))
					{
						i--;
						cout<<"\n";
						cout<<"RETRY AS  U HAVE ENTERNED THE WRONG INPUT"<<endl;
					}
				}
		}
		re:
		cout<<endl<<"PLEASE ENTER YOUR AGE"<<endl<<endl;
		cin>>age;

	

		cout<<endl<<"PLEASE ENTER YOUR GENDER"<<endl<<endl;
		//////////////////////////////////////////////////
		// Sex Exception
		/////////////////////////////////////////////////
		for(int i=0;i<1;i++)
		{
			try{
				cin.ignore();
				gets(gender);
				throw 1;
			   }
			catch(int a)
			{
				if(isdigit(gender[0]))
				{
					i--;
					cout<<"\n";
					cout<<"RETRY AS  U HAVE ENTERNED THE WRONG INPUT"<<endl;
				}
			}
		}

		n:
		cout<<endl<<"PLEASE ENTER YOUR CNIC NUMBER (EG: 11111-1111111-1)"<<endl<<endl;
		gets(cnic);

		for(int n=0 ; n<strlen(cnic);n++)
		{
		if (isalpha(cnic[n]))
		{
		cout<<"NIC Cannot Have An Alphabet , Please Type Again"<<endl;
		goto n;
		}
		
		}
		
		cout<<endl<<"PLEASE ENTER YOUR NATIONALITY"<<endl<<endl;
		//////////////////////////////////////////////////
		// Nationality Exception
		/////////////////////////////////////////////////
		for(int i=0;i<1;i++)
		{
				try{
				gets(nationality);
				throw 'a';
				}
				catch(char a)
				{
					if(isdigit(nationality[0]))
					{
					i--;
					cout<<"\n";
					cout<<"RETRY AS YOU HAVE ENTERNED THE WRONG INPUT"<<endl;
					}
				}
		}
		
		
	}

	void get_data()
	{	
		cout<<"\n";
		char a[]={"\t\t\t\t PERSONAL DATA\n\t\t\t\t ~~~~~~~~~~~~~\n"};
		sleep(a,40);
		cout<<"NAME		: "<<name;                                        Sleep(35);
		cout<<"\nGENDER		: "<<gender;                                     Sleep(35);
		cout<<"\nAGE		: "<<age;                                     Sleep(35);
		cout<<"\nNIC NO.		: "<<cnic;                                Sleep(35);
		cout<<"\nNATIONALITY	: "<<nationality<<"\n\n";                 Sleep(35);
	}


};
