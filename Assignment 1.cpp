#include<iostream>
#include<string>

using namespace std;

class People
{

private:
	string user_NAME, user_ADDRESS, user_MOBILENO;

public:
	People()
	{
		user_NAME="";
		user_ADDRESS="";
		user_MOBILENO="";
	}

	virtual void setData()
	{
		
		cout<<"Enter user_NAME : ";
		cin>>user_NAME;
		cout<<"Enter Mobile Number : ";
		cin>>user_MOBILENO;
		cout<<"Enter user_ADDRESS : ";
		cin>>user_ADDRESS;
	}

	virtual void DispDATA()
	{
		cout<<"user_NAME : "<<user_NAME<<endl;
		cout<<"Mobile Number : "<<user_MOBILENO<<endl;
		cout<<"user_ADDRESS : "<<user_ADDRESS<<endl;
	}
};

class Customer:public People
{

private:
	friend class OBJECT;
	double total;
	string DateofIssue, DateofReturn;
	string GENID;
	double RPD;
	int Total_Days, ended;

public:
	Customer()
	{
		GENID="";
		total=0;
		Total_Days=0;
		DateofIssue="";
		DateofReturn="";
		ended=0;
	}

	void setData()
	{
		People::setData();
		
		cout<<"Enter Generator ID to be Issued : ";
		cin>>GENID;
		cout<<"Enter the Number of Days for which the Generator is Rented : ";
		cin>>Total_Days;
		
		cout<<"Enter Date of Issue (DD/MM/YYYY) : ";
		cin>>DateofIssue;
		cout<<"Enter Date of Return (DD/MM/YYYY) : ";
		cin>>DateofReturn;
	}

	void DispDATA()
	{
		People::DispDATA();
		cout<<"Generator ID: "<<GENID<<endl;
		cout<<"Number of Days : "<<Total_Days<<endl;
		cout<<"Rent per Day of the Generator : "<<RPD<<endl;
		cout<<"Date of Issue : "<<DateofIssue<<endl;
		cout<<"Date of Return : "<<DateofReturn<<endl;
		cout<<"Total Charges : "<<(Total_Days*RPD)<<endl;
	}
};

class Generator
{
private:
	friend class Customer;
	friend class OBJECT;
	int Available;
	string GeneratorID;
	double RentPerDay;

public:
	Generator()
	{
		GeneratorID="";
		RentPerDay=0;
		Available=1;
	}

	void setData()
	{
		
		cout<<"Enter Generator ID : ";
		cin>>GeneratorID;
		cout<<"Enter Rent Per Day of the Generator : ";
		cin>>RentPerDay;
	}

	void DispDATA()
	{
		cout<<"Generator ID : "<<GeneratorID<<endl;
		cout<<"Rent Per Day of the Generator : "<<RentPerDay<<endl;
	}
};


class OBJECT
{
private:
	int i, indicator;
	int counter1, counter2, counter3;
	string genReturnID;
	Generator *generator[10];
	People *people[20];
	Customer *customer[10];

public:
	OBJECT()
	{
		counter1=0;
		counter2=0;
		counter3=0;
		genReturnID="";
		i=0;
		indicator=0;
	}

	void AddGenerator()
	{
		generator[counter1]=new Generator;
		generator[counter1]->setData();
		counter1++;
	}

	

	void RentGenerator()
	{
		customer[counter3]=new Customer;
		customer[counter3]->setData(); 
		
		if(counter1==0)
		{
			cout<<"Sorry. No Generator in Inventory."<<endl;
			return ;
		}
		for (i=0; i<counter1; i++)
		{
			if((customer[counter3]->GENID)==(generator[i]->GeneratorID))
			{
				if(generator[i]->Available==1)
				{
					customer[counter3]->RPD=generator[i]->RentPerDay;
					generator[i]->Available=0;
					counter3++;
					cout<<"Generator Successfully rented out."<<endl;
					return ;					
				}
				else if(generator[i]->Available==0)
				{
					cout<<"Sorry. Generator not available."<<endl;
					delete customer[counter3];
					return ;
				}
				
			}
		}
		if(i=counter1+1)
		{
			cout<<"No Generator with such an ID exists in the Inventory."<<endl;
			delete customer[counter3];
			return ;
		}
	}

	void ReturnGenerator()
	{
		
		cout<<"Enter Generator ID to be returned : ";
		cin>> genReturnID;
		if(counter1==0)
		{
			cout<<"Sorry. No Generator in Inventory."<<endl;
			return ;
		}
		for (i=0; i<counter3; i++)
		{
			if(genReturnID==(customer[i]->GENID))
			{
				if(generator[i]->Available==0)
				{
					generator[i]->Available=1;
					//delete customer[i];
					customer[i]->ended=1;
					cout<<"Generator Successfully returned."<<endl;
					return ;
				}
				else if(generator[i]->Available==1)
				{
					cout<<"Generator has not been allocated to anyone."<<endl;
					return ;
				}
			}
		}
		if(i=counter1+1)
		{
			cout<<"No Generator with such an ID available for return."<<endl;
			return ;
		}
	}

	void ItemsInInventory()
	{
		if(counter1==0)
		{
			cout<<"No Items in the Inventory."<<endl;
			return ;
		}
		for(int i=0; i<counter1; i++)
		{
			generator[i]->DispDATA();
		}
	}

	void GeneratorsRented()
	{
		if(counter3==0)
		{
			cout<<"No Generators are on Rent at the Moment."<<endl;
			return ;
		}
		indicator=1;
		for(int i=0; i<counter3; i++)
		{
			if(customer[i]->ended==0)
			{
				indicator=0;
				customer[i]->DispDATA();
			}
			else if(customer[i]->ended==1)
			{
				continue;
			}
		}
		if(indicator)
		{
			cout<<"No Generators are on Rent at the Moment."<<endl;
		}
	}

	~OBJECT()
	{
		delete[] generator;
		delete[] people;
		delete[] customer;
	}
};


class employees:public People
{

private:
	string employee_ID, employee_Designition; 
	double employee_Salary;

public:
	employees()
	{
		employee_ID="";
		employee_Designition="";
		employee_Salary=0;
	}

	void setData()
	{
		People::setData();
		
		cout<<"Enter Employee ID : ";
		cin>>employee_ID;
		cout<<"Enter Employee employee_Designition : ";
		cin>>employee_Designition;
		cout<<"Enter Employee Salary : ";
		cin>>employee_Salary;
	}

	void DispDATA()
	{
		People::DispDATA();
		cout<<"Emp ID : "<<employee_ID<<endl;
		cout<<"employee_Designition : "<<employee_Designition<<endl;
		cout<<"Salary : "<<employee_Salary<<endl;
	}
};

int main()
{
	int choice=0;
	OBJECT object;
	cout<<endl<<"-***--***--** MENU **--***--***-"<<endl<<endl<<endl;
	while(1)
	{
		
		cout<<"1. Add a Generator \n2. Rent out \n3. Return a Generator\n4. View Items\n5. View all \n6. Exit"<<endl;
		cout<<"\nyour Choice : ";
		cin>>choice;
		cout<<"\n"<<endl;
		switch(choice)
		{
		case 1:
			object.AddGenerator();
			break;

		
		case 2:			
			object.RentGenerator();
			break;

		case 3:
			object.ReturnGenerator();
			break;

		case 4:
			object.ItemsInInventory();
			break;

		case 5:
			object.GeneratorsRented();
			break;

		case 6:
			return(0);

		default:
			cout<<"The option you have selected does not exists in the Menu. Please try again.\n"<<endl;
		}
	}
	return 0;
}
