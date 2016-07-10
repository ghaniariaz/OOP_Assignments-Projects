////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               TICKET CLASS
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "TRAIN.h"
#include "TRAVELLER.h"

using namespace std;


class Ticket : public train,public  Traveller
{
public:
		
	float final_cost;
	char tstatus[20];
	

	void setdata()
	{
		strcpy(tstatus,"RESERVED");
		////////////////////////////////////////////
		ifstream is;
		is.open("E://id.txt");
		is>>cid;
		is.close();
		////////////////////////////////////////////
		char a[]={"                  YOUR CUSTOMER ID IS = "};
		sleep(a,50);
		cout<<cid<<endl<<endl;
		route::setdata();
		
		
		system("cls");
		
		train::setdata();
		system("cls");
	Person::setdata();
		system("cls");
		Traveller::setdata();
		final_cost=cost+luggage_cost-((.01*age_discount)*cost)-((.01*status_discount)*cost);
		cout<<endl<<"YOU HAVE SUCCESSFULLY RESERVED A SEAT "<<endl<<endl;
		cout<<endl<<"IN ORDER TO VIEW RECIEPT PROCEED TO MENU AND THEN PRESS 3."<<endl<<endl;
		system("pause");
		system("cls");
	}

	friend void operator << (ostream &print , Ticket t)	
	{
		char a[]={"\n\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n   ~~~~~~~~~~~~~~~   RAILWAY TRAVELLING SERVICES    ~~~~~~~~~~~~~~~~~~~~\n   ~~~~~~~~~~~~~~~                                  ~~~~~~~~~~~~~~~~~~~~\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"};
		sleep(a,10);
		
		t.Person::get_data();
		t.Traveller::get_data();
		t.route::get_data();
		t.train::get_data();
		print<<"STATUS\t\t:"<<t.tstatus<<endl;
		print<<"--------------------------------------------------------------------\n";
		print<<"\t\t  THE FINAL COST OF TICKET IS	:::	"<<t.final_cost<<" Rs.\n\n\n\n\n";
	}

	void updatedata()
	{
		strcpy(tstatus,"CANCELED");
		this->final_cost=0;
	}

	int accountmannage()
	{
		finalcost=finalcost+this->final_cost;
		return finalcost;
	}

	void storein(ofstream &os)
	{
	os.write((char*)this,sizeof(*this));
	}

	void storefrom(ifstream &is)
	{
	is.read((char*)this,sizeof(*this));
	}
};