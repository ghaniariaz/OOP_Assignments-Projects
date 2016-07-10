///////////////////////////////////////////////////////////////////////////////////////////
//                                   ROUTE CLASS
///////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>

using namespace std;


		void sleep(char a[],int n)
		{
		for (int i=0;i<strlen(a);i++)
		{
			cout<<a[i];
			Sleep(n);
		}

		}


static int cid;
int finalcost;

class route
{
protected:
	
	char home[20];
	char destination[20];
	char day[15];
	char timed[20];
	float distance;
	int availability;
	char date[20];

public:
		route(){
		strcpy(home,"ISLAMABAD");
		strcpy(destination,"KARACHI");
		distance=0;
		strcpy(day,"Good Day!");		
		}

	
	void setdata()
	{
		re:
		cout<<"\t\tCHOOSE YOUR TYPE OF TRANSPORT SERVICE" <<endl;
		cout<<endl<<"1.INTRA CITY TRANSPORT "<<endl<<endl;
		cout<<endl<<"2.COUNTRY TO COUNTRY TRANSPORT "<<endl<<endl;
	
		int choice0;
		cin>>choice0;
		
		if(choice0>=3)
		{
		system("cls");
		cout<<"RETRY FOR YOU HAVE GIVEN WRONG INPUT"<<endl;
		goto re;
		}

		switch(choice0)
		{
		//INTRA CITY TRANSPORT PART
		case 1:
		{
			system("cls");
			strcpy(home,"ISLAMABAD");
			
			re1:
			char a[]={"\t\tTHE MENU TO BE DISPLAYED IS AS FOLLOWS\n\n*********************************\n* 1. ISLAMABAD TO LAHORE	*\n* 2. ISLAMABAD TO PESHAWAR	*\n* 3. ISLAMABAD TO MUZAFFARABAD	*\n* 4. ISLAMABAD TO FAISALABAD	*\n* 5. ISLAMABAD TO MULTAN	*\n* 6. ISLAMABAD TO KARACHI	*\n* 7. ISLAMABAD TO QUETTA	*\n*********************************\n"};
			sleep(a,25);
			cout<<endl<<endl<<"PLEASE ENTER YOUR CHOICE"<<endl<<endl;
			int choice1;
			cin>>choice1;

		if(choice1>=8)
		{
		system("cls");
		cout<<"RETRY FOR YOU HAVE GIVEN WRONG INPUT"<<endl;
		goto re1;
		}
			
			switch(choice1)
			{
		
				case 1:
				{
					strcpy(destination,"LAHORE");
					distance=450;
					break;
				}
				case 2:
				{	
					strcpy(destination,"PESHAWAR");
					distance=300;
					break;
				}
				case 3:
				{
					strcpy(destination,"MUZAFARABAD");
					distance=250;
					break;
				}
				case 4:
				{
					strcpy(destination,"FAISALABAD");
					distance=350;			
					break;
				}
				case 5:
				{
					strcpy(destination,"MULTAN");
					distance=540;			
					break;
				}
				case 6:
				{
					strcpy(destination,"KARACHI");
					distance=1050;
					break;
				}
				case 7:
				{
					strcpy(destination,"QUETTA");
					distance=950;
					break;
				}
			}//end of inner switch
				break;
		}
		case 2:
		//COUNTRY TO COUNTRY TRANSPORT PART
		{	
			system("cls");
			strcpy(home,"ISLAMABAD");
			
			re2:
			char a[]={"\nTHE CHOICES ARE AS FOLLOWS\n\n*****************************************\n1.  ISLAMABAD TO CHINA\n2.  ISLAMABAD TO IRAN\n3.  ISLAMABAD TO INDIA\n*****************************************\n"};
			sleep(a,25);
			
			cout<<endl<<"PLEASE ENTER YOUR CHOICE"<<endl<<endl;						
			int choice3;	
			cin>>choice3;

		if(choice3>=4)
		{
		system("cls");
		cout<<"RETRY FOR YOU HAVE GIVEN WRONG INPUT"<<endl;
		goto re2;
		}

		
			switch(choice3)
			{
				case 1:
				{   
					strcpy(destination,"CHINA");
					distance=973;
					break;
				}
				case 2:
				{					
					strcpy(destination,"IRAN");
					distance=1200;
					break;
				}
				case 3:
				{	
					strcpy(destination,"INDIA");
					distance=1000;
					break;
				}
			}//end of inner switch
		break;
		}
	}
		date:
		system("cls");

		re3:
		cout<<endl<<"PLEASE ENTER DATE FOR DEPARTURE (day/month/year) E.G (5/20/2013)"<<endl;
		cin.ignore();
		gets(date);

		for(int i=0;i<strlen(date);i++)
		{
		if(isalpha(date[i]))
		{
		cout<<"Retry, For Your Input cannot Have an alphabet"<<endl;
		goto re3;
		}
		

		}
		/*cout<<endl<<"CHOOSE DAY FOR DEPARTURE"<<endl<<endl;
		cout<<"1. MONDAY"<<endl;
		cout<<"2. TUESDAY"<<endl;
		cout<<"3. WEDNESDAY"<<endl;
		cout<<"4. THURSDAY"<<endl;
		cout<<"5. FRIDAY"<<endl;
		cout<<"6. SATURDAY"<<endl;
		cout<<"7. SUNDAY"<<endl<<endl;

		int dchoice;
		cin>>dchoice;
			
			if      (dchoice==1) { strcpy (day , "MONDAY"    ) ; }
			else if (dchoice==2) { strcpy (day , "TUESDAY"   ) ; }
			else if (dchoice==3) { strcpy (day , "WEDNESDAY" ) ; }
			else if (dchoice==4) { strcpy (day , "THURSDAY"  ) ; }
			else if (dchoice==5) { strcpy (day , "FRIDAY"    ) ; }
			else if (dchoice==6) { strcpy (day , "SATURDAY"  ) ; }
			else if (dchoice==7) { strcpy (day , "SUNDAY"    ) ; }
			else	strcpy(day,"TODAY");
			*/
			system("cls");
			int de;
			re4:
			cout<<"FOR "<<date<<" WE HAVE FOLLOWING TIME OF DEPARTURE"<<endl;
			cout<<"1. 5:30 AM"<<endl<<"2. 8:30 AM"<<endl<<"3. 11:00 AM"<<endl<<"4. 5:30 PM"<<endl<<"5. 8:30 PM"<<endl<<"6. 11:00 PM"<<endl;
			cout<<endl<<"CHOOSE YOUR TIME"<<endl;
			cin>>de;
		
		if(de>=7)
		{
		system("cls");
		cout<<"Retry, as you have given wrong input"<<endl;
		goto re4;
		}

			switch (de)
				{
					case 1: {strcpy(timed,"5:30  AM"); break;}
					case 2: {strcpy(timed,"8:30  AM"); break;}
					case 3: {strcpy(timed,"11:00 AM"); break;}
					case 4: {strcpy(timed,"5:30  PM"); break;}
					case 5: {strcpy(timed,"8:30  PM"); break;}
					case 6: {strcpy(timed,"11:00 PM"); break;}
				}
}
	
	
	void get_data()
	{
		char a[]={"\n\t\t\t\tTRAVELLING DETAILS\n\t\t\t\t~~~~~~~~~~~~~~~~~~\n"};
		sleep(a,40);
		cout<<"\nHOME STATION	: "<<home;                Sleep(35);
		cout<<"\nDESTINATION	: "<<destination;         Sleep(35);
		cout<<"\nDISTANCE	: "<<distance;				  Sleep(35);
		cout<<"\nDEPARTURE DATE  : "<<date;					  Sleep(35);
		cout<<"\nDEPARTURE TIME  : "<<timed;			  Sleep(35);
	}

};