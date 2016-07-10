//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		                                          	MAIN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "TICKET.h"



using namespace std;




HANDLE me= GetStdHandle ( STD_OUTPUT_HANDLE) ;

int main()
{
	int n;
	static int a=1;
	set:
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY );
	cout<<endl<<"\t\tWELCOME TO ISLAMABAD RAILWAY STATION\t\t\t"<<endl<<endl;
	cout<<"CHOOSE FROM THE FOLLOWING"<<endl<<endl;
	cout<<"1. FOR RESERVING A SEAT"<<endl;
	cout<<"2. FOR CANCELING A RESERVATION"<<endl;
	cout<<"3. FOR VIEWING YOUR RECIEPT"<<endl;
	cout<<"4. FOR VIEWING ALL THE RECORD"<<endl;
	cout<<"5. FOR VIEWING COST FOR TODAY"<<endl;
	cout<<"6. EXIT"<<endl<<endl;
	cin>>n;

	if(n>=7)
	{
	system("cls");
	cout<<"RETRY FOR YOU HAVE GIVEN WRONG INPUT"<<endl;
	goto set;
	}

	int id;
	switch (n)
	{
	//////////////////////////////////////////////////////////////////////////////////////////////
	//                   Getting Data And Storing It in The File
	//////////////////////////////////////////////////////////////////////////////////////////////

		case 1 :
		{
			system("cls");
			Ticket t;
			ofstream os;
			t.setdata();
			t.accountmannage();
			++cid;
			/////////////////////////////////////
			ofstream id;
			id.open("E://id.txt");
			id<<cid;
			id.close();
			/////////////////////////////////////
			os.open("E://station.dat",ios::binary | ios::app);

			if(os)
			{
				t.storein(os);
			}
			os.close();
		goto set;
		}

//////////////////////////////////////////////////////////////////////////////////////////////
//                  Cancelation Of Seat
//////////////////////////////////////////////////////////////////////////////////////////////

		case 2:
		{
			system("cls");
	
			ifstream is;
			cout<<"PLEASE ENTER YOUR USER ID "<<endl<<endl;
			cin>>id;
			is.open("E://station.dat",ios::binary);
			is.seekg((id-1001)*sizeof(Ticket), ios::beg);
			Ticket temp;
			is.read(reinterpret_cast<char*>(&temp), sizeof(Ticket));
			temp.updatedata();
			is.close();
	
			ofstream os;
			os.open("E://station.dat",ios::binary | ios::_Nocreate);
			os.seekp((id-1001)*sizeof(Ticket), ios::beg);
			os.write(reinterpret_cast<char*>(&temp), sizeof(Ticket));
			os.close();
	
			cout<<"YOU HAVE SUCCESSFULLY CANCELED YOUR RESERVATION"<<endl<<endl;
			system("pause");
			system("cls");
			goto set;
		}


//////////////////////////////////////////////////////////////////////////////////////////////
//                        Retriving Data Of Specific User
//////////////////////////////////////////////////////////////////////////////////////////////
		case 3:
		{
			system("cls");
			cout<<"PLEASE ENTER YOUR Customer ID "<<endl<<endl;
			cin>>id;
	
			ifstream is;
			is.open("E://station.dat",ios::binary);
			is.seekg((id-1001)*sizeof(Ticket), ios::beg);
			Ticket temp;
			temp.storefrom(is);
			cout<<temp;        
			is.close();
			system("pause");
			system("cls");
			goto set;
		}

//////////////////////////////////////////////////////////////////////////////////////////////
//                         Viewing All Data 
//////////////////////////////////////////////////////////////////////////////////////////////
		case 4:
		{
			system("cls");
			int i=0;
			ifstream is;

			is.open("E://station.dat",ios::binary);
	
			Ticket temp;
			
			while (true)
			{
				temp.storefrom(is);
				
				if (is.good())
				{
					++i;
					cout<<"         --------------------------------------------------------"<<endl;
					cout<<"         ________________  CUSTUMER NO. "<<i<<" _______________________"<<endl;
					cout<<"         --------------------------------------------------------"<<endl;
					cout<<temp;
				}	
				else
				{
					is.clear();
					is.close();
					system("pause");
					system("cls");
					goto set;
				}
			}
		}

//////////////////////////////////////////////////////////////////////////////////////////////
//                         COST FOR TODAY
//////////////////////////////////////////////////////////////////////////////////////////////

		case 5:
		{	ofstream os;
			os.open("E://cost.txt");
			cout<<"THE COST OF TODAY IS = "<<finalcost<<endl;
			os<<"Cost for Today is = " << finalcost;
			os.close();
			system("pause");
			goto set;
		}

//////////////////////////////////////////////////////////////////////////////////////////////
//                         EXIT
//////////////////////////////////////////////////////////////////////////////////////////////
		case 6:
		{
			break;
		}
}// EOS
}


