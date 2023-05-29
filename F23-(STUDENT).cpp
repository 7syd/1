#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;
#include<stdlib.h>

class STUDENT_CLASS
{
	typedef struct STUDENT
	{
		char name[10];
		int roll_no;
		int division;
		char address[50];
	}Rec;
	
	Rec Records;
	public:
		void Create();
		void Display();
		void Update();
		void Delete();
		void Append();
		int Search();
};

void STUDENT_CLASS :: Create()
{
	char ch='y';
	fstream seqfile;
	seqfile.open("STUDENT.dat",ios::out|ios::binary);
	do
	{
		cout<<"\n Enter Name : ";
		cin>>Records.name;
		cout<<"\n Enter Roll No : ";
		cin>>Records.roll_no;
		cout<<"\n Enter Division : ";
		cin>>Records.division;
		cout<<"\n Enter Address : ";
		cin>>Records.address;
		
		seqfile.write((char*)&Records,sizeof(Records));
		cout<<"\n Do you want to add more Records?: ";
		cin>>ch;
	}while(ch=='y');
	
	seqfile.close();
}

void STUDENT_CLASS::Display()
{
	fstream seqfile;
	int n;
	seqfile.open("STUDENT.dat",ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	cout<<"\n The Contents of File Are : "<<endl;
	
	while(seqfile.read((char*)&Records,sizeof(Records)))
	{
		if(Records.roll_no!=-1)
		{
			cout<<"\n NAME : "<<Records.name;
			cout<<"\n ROLL NO : "<<Records.roll_no;
			cout<<"\n DIVISION : "<<Records.division;
			cout<<"\n ADDRESS : "<<Records.address;
			cout<<"\n";
		}
	}
	
	int last_rec=seqfile.tellg();
	n=last_rec/(sizeof(Rec));
	seqfile.close();
}

void STUDENT_CLASS::Update()
{
	int pos;
	cout<<"\n For Updation,";
	fstream seqfile;
	seqfile.open("STUDENT.dat",ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	pos=Search();
	if(pos==-1)
	{
		cout<<"\n The Record is Not Present In The File";
		return;
	}
	
	int offset=pos*sizeof(Rec);
	seqfile.seekp(offset);
	cout<<"\n Enter The Values For Updation...";
	cout<<"\n Name : ";
	cin>>Records.name;
	cout<<"\n Roll No : ";
	cin>>Records.roll_no;
	cout<<"\n Division : ";
	cin>>Records.division;
	cout<<"\n Address : ";
	cin>>Records.address;
	
	seqfile.write((char*)&Records,sizeof(Records))<<flush;
	seqfile.seekg(0);
	seqfile.close();
	cout<<"\n The Record is Updated!!!";
	
}

void STUDENT_CLASS::Delete()
{
	int pos;
	cout<<"\n For Deletion,";
	fstream seqfile;
	seqfile.open("STUDENT.dat",ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	pos=Search();
	if(pos==-1)
	{
		cout<<"\n The Record is Not Present In The File";
		return;
	}
	
	int offset=pos*sizeof(Rec);
	seqfile.seekp(offset);
	strcpy(Records.name,"");
	Records.roll_no=-1;
	Records.division=-1;
	strcpy(Records.address,"");
	seqfile.write((char*)&Records,sizeof(Records))<<flush;
	seqfile.seekg(0);
	seqfile.close();
	cout<<"\n The Record is Deleted!!!";
}


void STUDENT_CLASS::Append()
{
	fstream seqfile;
	seqfile.open("STUDENT.dat",ios::ate|ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	int i=0;
	while(seqfile.read((char*)&Records,sizeof(Records)))
	{
		i++;
	}
	seqfile.clear();
	cout<<"\n Enter The Record For Appending : ";
	cout<<"\n Name : ";
	cin>>Records.name;
	cout<<"\n Roll No : ";
	cin>>Records.roll_no;
	cout<<"\n Division : ";
	cin>>Records.division;
	cout<<"\n Address : ";
	cin>>Records.address;
	
	seqfile.write((char*)&Records,sizeof(Records));
	seqfile.close();
	cout<<"\n The Record is Appendix!!!";
}


int STUDENT_CLASS::Search()
{
	fstream seqfile;
	int id,pos;
	cout<<"\n Enter The Roll No for Searching The Record";
	cin>>id;
	seqfile.open("STUDENT.dat",ios::ate|ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	pos=-1;
	int i=0;
	while(seqfile.read((char*)&Records,sizeof(Records)))
	{
		if(id==Records.roll_no)
		{
			pos=i;
			break;
		}
		i++;
	}
	return pos;
	
}


int main()
{
	STUDENT_CLASS List;
	char ans='y';
	int choice,key;
	
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
			case 6 : key=List.Search();
					if(key<0)
					{
						cout<<"\n Record is Not Present in the file";
					}
					else
					{
						cout<<"\n Record is Present in the file";
					}
					 break;
			case 7 : exit(0);
		}
		cout<<"\n\t Do You want to go back to Main Menu?";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
