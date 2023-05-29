#include<iostream>
using namespace std;
#define MAX 10

class Heap
{
	private:
		int Marks[MAX];
		int n;
	
	public:
		Heap();
		void insert(int num);
		void makeheap();
		void heapsort();
		void display();
		void display_max_min_marks();
};

Heap::Heap()
{
	n=0;
	for(int i=0;i<MAX;i++)
	{
		Marks[i]=0;
	}
}

void Heap::insert(int num)
{
	if(n<MAX)
	{
		Marks[n]=num;
		n++;
	}
	else
	{
		cout<<"\n Array is Full";
	}
}

void Heap::makeheap()
{
	for(int i=1;i<n;i++)
	{
		int val=Marks[i];
		int j=i;
		int f=(j-1)/2;
		while (j>0 && Marks[f]<val)
		{
			Marks[j]=Marks[f];
			j=f;
			f=(j-1)/2;
		}
		Marks[j]=val;
	}
}

void Heap::heapsort()
{
	for(int i=n-1;i>0;i--)
	{
		int temp=Marks[i];
		Marks[i]=Marks[0];
		int k=0;
		int j;
		if(i==1)
		{
			j=-1;
		}
		else
		{
			j=1;
		}
		if(i>2 && Marks[2]>Marks[1])
		{
			j=2;
		}
		while(j>=0 && temp<Marks[j])
		{
			Marks[k]=Marks[j];
			k=j;
			j=2*k+1;
			if(j+1<=i-1&&Marks[j]<Marks[j+1])
			{
				j++;
			}
			if(j>i-1)
			{
				j=-1;
			}
		}
		Marks[k]=temp;
	}
}

void Heap::display()
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<Marks[i];
	}
	cout<<"\n";
}

void Heap::display_max_min_marks()
{
	cout<<"\n The Maximum marks = "<<Marks[n-1];
	cout<<"\n The Minimum marks = "<<Marks[0];
	cout<<"\n";
}

int main()
{
	Heap obj;
	obj.insert(55);
	obj.insert(48);
	obj.insert(89);
	obj.insert(91);
	obj.insert(75);
	obj.insert(63);
	obj.insert(45);
	obj.insert(78);
	
	cout<<"\n Following Marks are obtained by Students : "<<endl;
	obj.display();
	obj.makeheap();
	
	cout<<"\n\n Heapified..."<<endl;
	
	obj.heapsort();
	obj.display_max_min_marks();
}
