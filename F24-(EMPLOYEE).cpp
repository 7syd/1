#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;

class EMP_CLASS
{
	typedef struct EMPLOYEE
	{
		char name[10];
		int emp_id;
		int salary;
		char desig[20];
	}Rec;
	
	typedef struct INDEX
	{
		int emp_id;
		int position;
	}Ind_Rec;
	
	Rec Records;
	Ind_Rec Ind_Records;
	public:
		EMP_CLASS();
		void Create();
		void Display();
		void Update();
		void Delete();
		void Append();
		void Search();
};

EMP_CLASS::EMP_CLASS()
{
	strcpy(Records.name,"");
}

void EMP_CLASS :: Create()
{
	int i;
	char ch='y';
	fstream seqfile;
	fstream indexfile;
	i=0;
	indexfile.open("IND.dat",ios::out|ios::binary);
	seqfile.open("EMP.dat",ios::out|ios::binary);
	do
	{
		cout<<"\n Enter Name : ";
		cin>>Records.name;
		cout<<"\n Enter EMP ID : ";
		cin>>Records.emp_id;
		cout<<"\n Enter Salary : ";
		cin>>Records.salary;
		cout<<"\n Enter Designation : ";
		cin>>Records.desig;
		
		seqfile.write((char*)&Records,sizeof(Records))<<flush;
		Ind_Records.emp_id=Records.emp_id;
		Ind_Records.position=i;
		indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
		i++;
		cout<<"\n Do you want to add more Records?: ";
		cin>>ch;
	}while(ch=='y');
	seqfile.close();
	indexfile.close();
}

void EMP_CLASS::Display()
{
	fstream seqfile;
	fstream indexfile;
	int i;
	seqfile.open("EMP.dat",ios::in|ios::out|ios::binary);
	indexfile.open("IND.dat",ios::in|ios::out|ios::binary);
	indexfile.seekg(0,ios::beg);
	seqfile.seekg(0,ios::beg);
	cout<<"\n The Contents of File Are : "<<endl;
	i=0;
	
	while(indexfile.read((char*)&Ind_Records,sizeof(Ind_Records)))
	{
		i=Ind_Records.position*sizeof(Rec);
		seqfile.seekg(i,ios::beg);
		seqfile.read((char*)&Records,sizeof(Records));
		
		if(Records.emp_id!=-1)
		{
			cout<<"\n NAME : "<<Records.name;
			cout<<"\n EMP ID : "<<Records.emp_id;
			cout<<"\n SALARY : "<<Records.salary;
			cout<<"\n DESIGNATION : "<<Records.desig;
			cout<<"\n";
		}
	}
	
	seqfile.close();
	indexfile.close();
}

void EMP_CLASS::Update()
{
	int pos,id;
	char New_name[10];
	char New_desig[10];
	int New_salary;
	cout<<"\n For Updation,";
	cout<<"\n Enter The Emp id for searching : ";
	cin>>id;
	fstream seqfile;
	fstream indexfile;
	seqfile.open("EMP.dat",ios::in|ios::out|ios::binary);
	indexfile.open("IND.dat",ios::in|ios::out|ios::binary);
	indexfile.seekg(0,ios::beg);
	
	pos=-1;
	while(indexfile.read((char*)&Ind_Records,sizeof(Ind_Records)))
	{
		if(id==Ind_Records.emp_id)
		{
			pos=Ind_Records.position;
			break;
		}
	}
	
	if(pos==-1)
	{
		cout<<"\nThe Record is Not Present in The File";
		return;
	}
	
	else
	{
		cout<<"\n Enter The Values For Updation...";
		cout<<"\n Name : ";
		cin>>New_name;
		cout<<"\n Salary : ";
		cin>>New_salary;
		cout<<"\n Designation : ";
		cin>>New_desig;
		
		int offset=pos*sizeof(Rec);
		seqfile.seekp(offset);
		
		strcpy(Records.name,New_name);
		Records.emp_id = id;
		Records.salary = New_salary;
		seqfile.write((char*)&Records,sizeof(Records))<<flush;
		cout<<"\n The Record is Updated!!!";
	}
	
	seqfile.close();
	indexfile.close();
	
	
}

void EMP_CLASS::Delete()
{
	int id,pos;
	cout<<"\n For Deletion,";
	cout<<"\n Enter The Emp id for searching : ";
	cin>>id;
	fstream seqfile;
	fstream indexfile;
	seqfile.open("EMP.dat",ios::in|ios::out|ios::binary);
	indexfile.open("IND.dat",ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	indexfile.seekg(0,ios::beg);
	pos=-1;
	while(indexfile.read((char*)&Ind_Records,sizeof(Ind_Records)))
	{
		if(id==Ind_Records.emp_id)
		{
			pos=Ind_Records.position;
			Ind_Records.emp_id = -1;
			break;
		}
	}
	
	if(pos==-1)
	{
		cout<<"\n The Record is Not Present In The File";
		return;
	}
	
	int offset=pos*sizeof(Rec);
	seqfile.seekp(offset);
	strcpy(Records.name,"");
	Records.emp_id=-1;
	Records.salary=-1;
	strcpy(Records.desig,"");
	seqfile.write((char*)&Records,sizeof(Records))<<flush;
	
	offset = pos*sizeof(Ind_Rec);
	indexfile.seekp(offset);
	Ind_Records.emp_id=-1;
	Ind_Records.position=pos;
	indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
	seqfile.seekg(0);
	indexfile.close();
	seqfile.close();
	cout<<"\n The Record is Deleted!!!";
}


void EMP_CLASS::Append()
{
	fstream seqfile;
	fstream indexfile;
	int pos;
	indexfile.open("IND.dat",ios::in|ios::binary);
	indexfile.seekg(0,ios::end);
	pos = indexfile.tellg()/sizeof(Ind_Records);
	indexfile.close();
	
	indexfile.open("IND.dat",ios::app|ios::binary);
	seqfile.open("EMP.dat",ios::app|ios::binary);
	
	cout<<"\n Enter The Record For Appending : ";
	cout<<"\n Name : ";
	cin>>Records.name;
	cout<<"\n Emp ID : ";
	cin>>Records.emp_id;
	cout<<"\n Salary : ";
	cin>>Records.salary;
	cout<<"\n Designation : ";
	cin>>Records.desig;
	
	seqfile.write((char*)&Records,sizeof(Records));
	Ind_Records.emp_id = Records.emp_id;
	Ind_Records.position = pos;
	indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
	seqfile.close();
	indexfile.close();
	cout<<"\n The Record is Appended!!!";
}


void EMP_CLASS::Search()
{
	fstream seqfile;
	fstream indexfile;
	int id,pos,offset;
	cout<<"\n Enter The Emp ID for Searching The Record";
	cin>>id;
	indexfile.open("IND.dat",ios::in|ios::binary);
	pos=-1;
	while(indexfile.read((char*)&Ind_Records,sizeof(Ind_Records)))
	{
		if(id==Ind_Records.emp_id)
		{
			pos=Ind_Records.position;
			break;
		}
	}
	if(pos==-1)
	{
		cout<<"\n Record is not Present in the file";
		return;
	}
	
	offset=pos*sizeof(Records);
	seqfile.open("EMP.dat",ios::in|ios::binary);
	seqfile.seekg(offset,ios::beg);
	seqfile.read((char*)&Records,sizeof(Records));
	
	if(Records.emp_id==-1)
	{
		cout<<"\n Record is not present in the file";
		return;
	}
	
	else
	{
		cout<<"\n The Record is present in the file and it is...";
		cout<<"\n NAME : "<<Records.name;
		cout<<"\n EMP ID : "<<Records.emp_id;
		cout<<"\n SALARY : "<<Records.salary;
		cout<<"\n DESIGNATION : "<<Records.desig;
	}
	seqfile.close();
	indexfile.close();
	
}


int main()
{
	EMP_CLASS List;
	char ans='y';
	int choice;
	
	do
	{
		cout<<"\n Main Menu "<<endl;
		cout<<"\n 1.Create";
		cout<<"\n 2.Display";
		cout<<"\n 3.Update";
		cout<<"\n 4.Delete";
		cout<<"\n 5.Append";
		cout<<"\n 6.Search";
		cout<<"\n 7.Exit";
		cout<<"\n Enter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1 : List.Create();
					 break;
			case 2 : List.Display();
					 break;
			case 3 : List.Update();
					 break;
			case 4 : List.Delete();
					 break;
			case 5 : List.Append();
					 break;
			case 6 : List.Search();
					 break;
			case 7 : exit(0);
		}
		cout<<"\n\t Do You want to go back to Main Menu?";
		cin>>ans;
	}while(ans=='y');
	return 0;
}





