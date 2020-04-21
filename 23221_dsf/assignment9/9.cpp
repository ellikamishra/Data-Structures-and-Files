/*============================================================================
 	Title   : Hashing
 	Name    : Ellika
 	Roll No : 23221
 	Batch   : F-10
	Problem Statement   :
	Store data of students with telephone no and name in the structure using
	hashing function for telephone number and implement chaining with and without
	replacement.
============================================================================*/

#include<iostream>
using namespace std;
#define max 10

struct student{
 char name[20];
 long tel;	
	
};

struct ht{
	
	
	student stud;
	int flag;
	int chain;
	
};
class lp_withoutreplace{
	
	ht records[max];
	
	public:
	void init();
    void insert(student key);
    void display();
    int search(long tel);
	
};
class lp_withreplace{
	
	ht records[max];
	
	public:
    void init();
    void insert(student key);
    void display();
    int search(long tel);
	
};
void lp_withoutreplace::init(){
	for(int i=0;i<max;i++)
	{
	records[i].flag=0;
	records[i].chain=-1;
//	records[i].stud.name='\0';
//	records[i].stud.tel=1;
		
	}
	
}
void lp_withreplace::init(){
	
	
	for(int i=0;i<max;i++)
	{
	records[i].flag=0;
	records[i].chain=-1;
//	records[i].stud.name='\0';
//	records[i].stud.tel=1;
		
	}
}
void lp_withoutreplace::insert(student key)
{
	int loc,i,j;
	i=0;
	loc=key.tel%max;
	j=loc;
	while(i<max&&records[j].flag==1)
	{
		if(records[j].stud.tel%max==key.tel%max)
		{break;
		}
	   j=(j+1)%max;
       i=i+1;	
    }
    if(i==max)
     {cout<<"Table is full"<<endl;
     return;
	 }
	while(records[j].chain!=-1)
	{j=records[j].chain;}
	
	loc=j;
	while(records[loc].flag&&i<max)
	{loc=(loc+1)%max;
	 i=i+1;
	}
	
	if(i==max)
	{cout<<"Table is full"<<endl;
	 return;
	 } 
	records[loc].stud=key;
	records[loc].flag=1;
	if(j!=loc)
	{records[j].chain=loc;
	}
}
void lp_withreplace::insert(student key){
	
	int loc,i,j;
	loc=(key.tel)%max;
	i=0;
	cout<<loc<<endl;
	if(records[loc].flag==0)
	{
		records[loc].stud=key;
		records[loc].flag=1;
		return;
	}
	
	i=0;
	j=loc;
	while(i<max&&records[j].flag==1)
	{
		j=(j+i)%max;
		i=i+1;
	}
	
	if(i==max)
	{
		cout<<"Table is Full"<<endl;
		return;
	}
	
	if((records[loc].stud.tel)%max!=loc)
	{
		i=records[loc].stud.tel%max;
		while(records[i].chain!=loc)
		{
			i=records[i].chain;
		}
		records[i].chain=records[loc].chain;
		while(records[i].chain!=-1)
		{
			i=records[i].chain;
		}
		
		records[i].chain=j;
		
		records[j].stud=records[loc].stud;
		records[j].flag=1;
		records[j].chain=-1;
		
		records[loc].stud=key;
	    records[loc].flag=1;
	    records[loc].chain=-1;
	    
	    return;
	}
	
	if((records[loc].stud.tel)%max==loc)
	{
		records[j].stud=key;
		records[j].flag=1;
		records[j].chain=-1;
		i=loc;
		while(records[i].chain!=-1)
		{i=records[i].chain;
		}
		records[i].chain=j;
		
		
	}
    
}
void lp_withoutreplace::display(){
	
	cout<<"Index \t Name \t Tel No \t Flag \t Chain"<<endl;

	for(int i=0;i<max;i++)
		cout<<i<<"\t"<<records[i].stud.name<<"\t"<<records[i].stud.tel<<"\t"<<records[i].flag<<"\t"<<records[i].chain<<endl;
	
	
}
void lp_withreplace::display(){
	
cout<<"Index \t Name \t Tel No \t Flag \t Chain"<<endl;

	for(int i=0;i<max;i++)
		cout<<i<<"\t"<<records[i].stud.name<<"\t"<<records[i].stud.tel<<"\t"<<records[i].flag<<"\t"<<records[i].chain<<endl;
	
}
int lp_withoutreplace::search(long tel)
{
	int i,loc;
	i=0;
	loc=tel%max;
while(i<max&&records[loc].flag==1&&(records[loc].stud.tel%max)!=loc)
	{
		i=i+1;
		loc=(loc+1)%max;
	}
	if(records[loc].flag!=1||i==max)
	
	{ return -1;
		
	}
	else{
		
		while(loc!=-1)
		{
			if(records[loc].stud.tel==tel)
			{
				return loc;
			}
			else
			{
				loc=records[loc].chain;
			}
			
		}
	}
	
	return -1;
}
int lp_withreplace::search(long tel)
{
	int i,loc;
	i=0;
	loc=tel%max;
	while(i<max&&records[loc].flag==1&&(records[loc].stud.tel%max)!=loc)
	{
		i=i+1;
		loc=(loc+1)%max;
	}
	
	if(records[loc].flag!=1||i==max)
	
	{ return -1;
		
	}
	
	else{
		
		while(loc!=-1)
		{
			if(records[loc].stud.tel==tel)
			{
				return loc;
			}
			else
			{
				loc=records[loc].chain;
			}
			
		}
	}
	
	return -1;
}


int main()
{   lp_withreplace lp1;
    lp_withoutreplace lp2;
    student s1;
    long k;
	int ch,ch1,f;
	do
	{cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Linear Probing with Replacement\n";
		cout<<"2. Linear Probing without Replacement\n";
		cout<<"3. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";
    switch(ch)
    {
    	case 1:lp1.init();
		     do{
    		cout<<"----------------------------\n";
				cout<<"Select the Options\n";
				cout<<"----------------------------\n";
				cout<<"1. Insert a Value\n";
				cout<<"2. Search for a Value\n";
				cout<<"3. Display Table\n";
				cin>>ch1;
			switch(ch1){
				
				case 1:
				       cout<<"Enter name"<<endl;
				       cin.ignore();
				       cin.getline(s1.name,20);
				       cout<<"Enter no."<<endl;
				       cin>>s1.tel;
				       lp1.insert(s1);
				       break;
				case 2:   cout<<"Enter search value"<<endl;
				          cin>>k;
						 f= lp1.search(k);    
						 if(f==-1)
						 {
						 	cout<<"Element not found"<<endl;
						 	break;
						 }
						 cout<<"Found at position"<<f<<endl;
				         break;
				case 3:          
				     lp1.display();
				     break;
			}	
			
		}while(ch1!=0);
	
        break;
     
case 2:   lp2.init();
          do{
    		cout<<"----------------------------\n";
				cout<<"Select the Options\n";
				cout<<"----------------------------\n";
				cout<<"1. Insert a Value\n";
				cout<<"2. Search for a Value\n";
				cout<<"3. Display Table\n";
				cin>>ch1;
			switch(ch1){
				
				case 1:
				       cout<<"Enter name"<<endl;
				       cin.ignore();
				       cin.getline(s1.name,20);
				       cout<<"Enter no."<<endl;
				       cin>>s1.tel;
				       lp2.insert(s1);
				       break;
				case 2:   cout<<"Enter search value"<<endl;
				          cin>>k;
						 f= lp2.search(k);    
						 if(f==-1)
						 {
						 	cout<<"Element not found"<<endl;
						 	break;
						 }
						 cout<<"Found at position"<<f<<endl;
				         break;
				case 3:          
				     lp2.display();
				     break;
			}	
			
		}while(ch1!=0);
	
     break;
}
}while(ch!=0);
	
return 0;	
	
}


/*

----------------------------
Select the Options
----------------------------
1. Linear Probing with Replacement
2. Linear Probing without Replacement
3. Exit

Your Choice: 2
----------------------------

----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
wer
Enter no.
1234
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
fgh
Enter no.
456
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
dfgh
Enter no.
678
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
cvb
Enter no.
890
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
wsdf
Enter no.
324
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
dfg
Enter no.
567
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
bnm
Enter no.
675
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
sdf
Enter no.
651
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
hjk
Enter no.
987
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
dsa
Enter no.
231
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
456
Enter no.
345
Table is full
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
rty
Enter no.
3456
Table is full
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
dfg
Enter no.
345
Table is full
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
2
Enter search value
987
Found at position2
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
3
Index    Name    Tel No          Flag    Chain
0       cvb     890     1       -1
1       sdf     651     1       3
2       hjk     987     1       -1
3       dsa     231     1       -1
4       wer     1234    1       5
5       wsdf    324     1       -1
6       fgh     456     1       -1
7       dfg     567     1       2
8       dfgh    678     1       -1
9       bnm     675     1       -1
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
0
----------------------------
Select the Options
----------------------------
1. Linear Probing with Replacement
2. Linear Probing without Replacement
3. Exit

Your Choice: 1
----------------------------

----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
yui
Enter no.
789
9
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
ygh
Enter no.
765
5
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
ert
Enter no.
543
3
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
pol
Enter no.
763
3
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
rdf
Enter no.
086
6
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
sdf
Enter no.
234
4
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
sds
Enter no.
345
5
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
rty
Enter no.
432
2
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
scv
Enter no.
567
7
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
hjk
Enter no.
234
4
Table is Full
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
1
Enter name
hjk
Enter no.
987
7
Table is Full
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
2
Enter search value
987
Element not found
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
2
Enter search value
432
Found at position2
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
3
Index    Name    Tel No          Flag    Chain
0       pol     763     1       -1
1                     0       0       -1
2       rty     432     1       -1
3       ert     543     1       0
4       sdf     234     1       -1
5       ygh     765     1       8
6       rdf     86      1       -1
7       scv     567     1       -1
8       sds     345     1       -1
9       yui     789     1       -1
----------------------------
Select the Options
----------------------------
1. Insert a Value
2. Search for a Value
3. Display Table
0
----------------------------
Select the Options
----------------------------
1. Linear Probing with Replacement
2. Linear Probing with Replacement
3. Exit

Your Choice: 0
----------------------------


--------------------------------
Process exited after 245.6 seconds with return value 0
Press any key to continue . . .



















*/
