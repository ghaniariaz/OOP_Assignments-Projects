/////////////////////////////////////////////////////////////////////////////////////////
//                 TRAVELLER CLASS INHERITS FROM PERSON CLASS
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "PERSON.h"

using namespace std;


class Traveller:public Person
{
protected:
	
	char status[20];
	char luggage_sort[15];
	int luggage_weight;
	int status_discount;
	int age_discount;
	int luggage_cost;
	
public:
	
	Traveller(){
		strcpy(status,"Default Status");
		strcpy(luggage_sort,"default");
		luggage_weight=0;
		status_discount=0;
		age_discount=0;
		luggage_cost=0;
	}


	void setdata()
	{
		cout<<endl<<"\t\tCHOOSE YOUR STATUS FOR AVAILABLE DISCOUNTS\n\n\n";
		cout<<"\t\t1.STUDENT	\n\n\n\t\t2.GOVERNMENT EMPLOYEE	\n\n\n\t\t3.ARMED FORCES PERSONNEL \n\n\n\t\t4.CIVILIAN (NO DISCOUNT)\n\n\n";
		int ch;
	
		for(int i=0;i<1;i++)
		{
			try{
				cin>>ch;
				throw ch;
				}
			catch(...)
				{
					if(ch>=5)
					{
					i--;
					cout<<"RETRY AS  U HAVE ENTERNED THE WRONG INPUT"<<endl;}
		else
		{
			switch(ch)
			{
				case 1:
				{
					strcpy(status,"STUDENT");
					status_discount=20;//20%
					break;
				}
				case 2:
				{
					strcpy(status,"GOVERNMENT EMPLOYEE");
					status_discount=10;			//10%
					break;
				}
				case 3:
				{
					strcpy(status,"ARMED FORCES PERSONAL");				//5%
					status_discount=5;
					break;
				}
				case 4:
				{
					strcpy(status,"CIVILIAN");
					status_discount=0;
				}

			}//end of switch
		}
	}
}

	system("cls");
	cout<<"\n\n\t\tPLEASE ENTER THE LUGGAGE WEIGHT (EG : 100 KG)\n"<<endl<<endl;
	cin>>luggage_weight;
	system("cls");

	cout<<"\n\t\tENTER THE TYPE OF LUGGAGE\n"<<endl;
	cout<<"\t\t1.MACHINERY	\n\n\t\t2.CLOTHING	\n\n\t\t3.EATABLES \n\n\t\t4.NONE \n\n";
	int ch1;
		for(int i=0;i<1;i++){
			try{	
				cin>>ch1;
				throw ch1;
			   }

		catch(...)
		{
			if(ch1==1 || ch==2 || ch==3 || ch==4){
				switch(ch1)
				{
					case 1:
					{		
						strcpy(luggage_sort,"MACHINERY");
						luggage_cost = 30*luggage_weight;
						break;
					}
					case 2:
					{		
						strcpy(luggage_sort,"CLOTHING");
						luggage_cost = 20*luggage_weight;
						break;
					}
					case 3:
					{		
						strcpy(luggage_sort,"EATABLES");
						luggage_cost = 10*luggage_weight;
						break;
					}
					case 4:
					{
						strcpy(luggage_sort,"NONE");
						luggage_cost = 0;
					}
			}//end of switch
		}
			else if (ch>=5)
			{
				i--;
				cout<<"YOU HAVE ENTERNED THE WRONG INPUT ENTER AGAIN"<<endl;
			}
	}
}
		if(age>0 && age<5)age_discount=50;	//50%
		else if(age>5 && age<13)age_discount=25;	//25%
		else if(age>50)age_discount=35;			//35%
		else age_discount=0;		
}

	void get_data()
	{
		char a[]={"\n\t\t\t\tPASSENGER'S DATA\n\t\t\t\t~~~~~~~~~~~~~~~~\n"};
		sleep(a,40);
		cout<<"STATUS		: "<<status;Sleep(35);cout<<"\nLUGGAGE STATUS	: "<<luggage_sort;Sleep(35);cout<<"\nLUGGAGE WEIGHT	: "<<luggage_weight<<"KG";Sleep(35);cout<<"\nSTATUS DISCOUNT	: "<<status_discount;Sleep(35);cout<<"%"<<"\nAGE DISCOUNT	: "<<age_discount;Sleep(35);cout<<"%"<<"\nLUGGAGE COST	: "<<luggage_cost;Sleep(35);cout<<"\n\n";
	}

};
