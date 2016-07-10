////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    TRAIN CLASS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "ROUTE.h"


using namespace std;


class train : public route
{
protected:

	char section[15];
	float rpk; //rate per Km
	float cost;
	char trainss[20];
	int seatno;

	
public:

		train(){		
			strcpy(section,"default");
			rpk=0;
			cost=distance*rpk;	
		}

	
	void setdata()
	{
		label: 
			cout<<"The trains available are:"<<endl<<endl;
			cout<<"1.KHYBER MAIL"<<endl;
			Sleep(30);
			cout<<"2.TEZGAM"<<endl;
			Sleep(30);
			cout<<"3.AWAM EXPRESS"<<endl<<endl;
			Sleep(30);
			char choose[]={"Please choose one of the following to check availability of seats:\n"};
			sleep(choose,30);
			int ddchoice;
			cin>>ddchoice;
			
			switch(ddchoice)
			{
				case 1:
				{		
					availability=rand()%100;
					if(availability<=100)
					{ 
						cout<<"Seat is available"<<endl;

						///////////////////////////////////
						ifstream is;
						is.open("E://kseat.txt");
						is>>seatno;
						is.close();
						//////////////////////////////////

						cout<<"The Seat Number Allocated To You : "<<seatno<<endl;
						cout<<"If you want to change your seat,\n please talk directly to the customer representitive"<<endl;
						strcpy (trainss , "KHYBER MAIL"    ) ;
						system("pause");

	///////////////////////////////////
	ofstream os;
	os.open("E://kseat.txt");
	++seatno;
	os<<seatno;
	os.close();
	/////////////////////////////////

						break;
					}
					else if(availability>100){
						cout<<"We are very sorry, no seats available on this train"<<endl;
						cout<<"Please select another train"<<endl<<endl;
						goto label; 
					}
				}
				
				case 2:
				{		
					availability=rand()%100;
					if(availability<=60)
					{ 
						cout<<"Seat is available"<<endl; 
						
						///////////////////////////////////
						ifstream is;
						is.open("E://tseat.txt");
						is>>seatno;
						is.close();
						//////////////////////////////////

						cout<<"The Seat Number Allocated To You : "<<seatno<<endl;
						cout<<"If you want to change your seat,\n please talk directly to the customer representitive"<<endl;
						strcpy (trainss , "TEZGAM"   ) ;

						/////////////////////////////////
						ofstream os;
						os.open("E://tseat.txt");
						++seatno;
						os<<seatno;
						os.close();
						///////////////////////////////

						system("pause");
						break;
					}
					else if(availability>60){
						cout<<"We are very sorry, no seats available on this train"<<endl;
						cout<<"Please select another train"<<endl<<endl;
						goto label; 
					}
				}
				
				case 3:
				{		
					availability=rand()%100;
					if(availability<=0)
					{ 
						cout<<"Seat is available"<<endl;
						cout<<"The Seat Number Allocated To You : "<<seatno<<endl;
						cout<<"If you want to change your seat,\n please talk directly to the customer representitive"<<endl;
						strcpy (trainss , "AWAM EXPRESS" ) ; 
						system("pause");
						break;
					}
				else if(availability>0){
					cout<<"We are very sorry, no seats available on this train"<<endl;
					cout<<"Please select another train"<<endl<<endl;
					goto label; 
					}
				}
			}

		system("cls");
				
		rec:
		cout<<endl<<endl<<"\t\tCHOOSE YOUR DESIRE CLASS "<<endl<<endl;
        cout<<"1. ECONOMY CLASS"<<endl;
		cout<<"2. AC CLASS"<<endl;
		cout<<"3. LUXURY CLASS"<<endl;
		
		cout<<endl<<"ENTER YOUR CHOICE"<<endl<<endl;
		int choice2;
		cin>>choice2;

		if(choice2>=4)
		{
		system("cls");
		cout<<"RETRY FOR YOU HAVE GIVEN WRONG INPUT"<<endl;
		goto rec;
		}

		switch(choice2)
		{
			case 1:
			{		
				strcpy(section,"ECONOMY");
				rpk=1;
				cost=distance*rpk;
	            break;
			}
			case 2:
			{
				strcpy(section,"AC");
				rpk=1.5;
				cost=distance*rpk;
				break;
			}
			case 3:
			{
				strcpy(section,"LUXURY");
				rpk=2;
				cost=distance*rpk;
				break;
			}
		}	
	system("cls");
	}

	void get_data()
	{

		cout<<"\nTRAIN		: "<<trainss;			Sleep(35);
		cout<<"\nSEAT NUMBER     : "<<(seatno-1);       Sleep(35);
		cout<<"\nCLASS	        : "<<section;          Sleep(35);
		cout<<"\nRATE/KM		: "<<rpk<<"\n\n";  Sleep(35);

	
	}
};