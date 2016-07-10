#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student
{
public:
	char name[15];
	int ID;
	char dept[10];

	void setdata()
	{
		cout<<"Enter Name: "<<endl; 
		cin>>name;
		cout<<"Enter ID: "<<endl; 
		cin>>ID;
		cout<<"Enter Department: "<<endl; 
		cin>>dept;
	}

	void displaydata()
	{
		cout<<endl;
		cout<<"Name of Student: "<<name<<endl;
		cout<<"ID of the student: "<<ID<<endl;
		cout<< "Department:"<<dept<<endl;
		cout<<endl<<endl;
	}

	void WriteInFile(ofstream &out)
	{
		out<<name<<endl;
		out<<ID<<endl;
		out<<dept<<endl;
		
	}
	void ReadFromFile(ifstream &in)
	{
	    in>>name>>ID>>dept;
	}

		
};
int main()
{
	
	
	Student s1, s2, s3, s4;
	ofstream outfile("STUDENT DATA");
	if (outfile.is_open())
	{
		s1.setdata();
		s1.WriteInFile(outfile);
		s2.setdata();
		s2.WriteInFile(outfile);
		s3.setdata();
		s3.WriteInFile(outfile);
		s4.setdata();
		s4.WriteInFile(outfile);
		outfile.close();
	}
	else
		cout<<"Unable to open file"<<endl;
	
 
ifstream infile ("STUDENT DATA");
    if (infile.is_open())
    {
     
	    s1.ReadFromFile(infile);        
		s1.displaydata();
		s2.ReadFromFile(infile);        
		s2.displaydata();
		s3.ReadFromFile(infile);        
		s3.displaydata();
		s4.ReadFromFile(infile);        
		s4.displaydata();
        infile.close();
	}
  else cout << "Unable to open file";

return 0;
}


