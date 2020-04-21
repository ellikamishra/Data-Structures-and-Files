/*============================================================================
 	Title   : Prim's Algorithm
 	Name    : Ellika
 	Roll No : 23221
 	Batch   : F-10
	Problem Statement   :
	A business house has several offices in different countries; they want to lease
	phone lines to connect them with each other and the phone company charges
	different rent to connect different pairs of cities. Business house want to
	connect all its offices with a minimum total cost. Solve the problem by
	suggesting appropriate data structures
============================================================================*/
#include <iostream>
using namespace std;

class  Prims{
    int graph[10][10];
    int n;
    
    public:
    void create();
    void path();
    int minval(int [10],bool [10]);
    
};

void Prims::create(){
 int ch,v,u,w;
 cout<<"Enter the no. of cities:"<<endl;
 cin>>n;
 for(int i=0;i<n+1;i++)
 { for(int j=0;j<n+1;j++)
   {
   graph[i][j]=0;    
   }
     
}
for(int i=0;i<n+1;i++)
    {
        graph[0][i]=i;
        graph[i][0]=i;
    }
 
 cout<<"City Codes:\nPune(1)\nMumbai(2)\nBangalore(3)\nChennai(4)\5Surat(5)\n";
 cout<<"Enter edges (1-"<<n<<")"<<endl;
 do{
     cout<<"First city code:"<<endl;
     cin>>u;
     cout<<"Second city code:"<<endl;
     cin>>v;
     cout<<"Enter cost(/100):"<<endl;
     cin>>w;
     graph[u][v]=w;
     graph[v][u]=w;
     cout<<"Enter 1 to contiunue,0 to stop"<<endl;
     cin>>ch;
     
 }while(ch!=0);
 
 cout<<"Graph is(in codes):"<<endl;
   for(int i=0;i<n+1;i++)
 { for(int j=0;j<n+1;j++)
   {
     cout<<graph[i][j];
      if(j==0)
     {cout<<"->";
	 }
   }
    cout<<"\n"; 
}
    
}
int Prims::minval(int distance[10],bool set[10]){
	int min=100,min_index;
	for(int i=1;i<n+1;i++)
	{if(set[i]==false&&distance[i]<min)
	{
		min=distance[i];
		min_index=i;
	}
	
	
	}
	
	return min_index;
	
}
void Prims::path(){
	int cost=0;
    int short_path[10];
    int distance[10];
    bool set[10];
    distance[0]=100;
     for (int i = 1; i <n+1 ; i++)  
       {
		 distance[i]=100; set[i] = false;  }
    
	distance[1]=0;
	short_path[1]=1;
	for(int c=0;c<n-1;c++)
	{int u=minval(distance,set);
	 set[u]=true;
	 cost+=distance[u];
	 for(int i=1;i<n+1;i++)
	{
		if(graph[u][i]&&distance[i]>graph[u][i]&&set[i]==false)
		{
			distance[i]=graph[u][i];
			short_path[i]=u;
		}
	}
	
	
	}
		
	   
	   
	  
	   cout<<"City Codes(from city Pune(1)) \tWeight\n";  
    for (int i = 1; i < n+1; i++)  
        cout<<short_path[i]<<" - "<<i<<"\t \t"<<graph[i][short_path[i]]<<" \n";  
	   
	cout<<"Cost:"<<cost<<endl;   
}



int main()
{
    Prims s;
    s.create();
    s.path();
    return 0;
}

/*
Enter the no. of cities:
5
City Codes:
Pune(1)
Mumbai(2)
Bangalore(3)
Chennai(4)Surat(5)
Enter edges (1-5)
First city code:
1
Second city code:
2
Enter cost(/100):
3
Enter 1 to contiunue,0 to stop
1
First city code:
1
Second city code:
3
Enter cost(/100):
1
Enter 1 to contiunue,0 to stop
1
First city code:
2
Second city code:
3
Enter cost(/100):
7
Enter 1 to contiunue,0 to stop
1
First city code:
2
Second city code:
4
Enter cost(/100):
5
Enter 1 to contiunue,0 to stop
1
First city code:
2
Second city code:
5
Enter cost(/100):
1
Enter 1 to contiunue,0 to stop
1
First city code:
3
Second city code:
4
Enter cost(/100):
2
Enter 1 to contiunue,0 to stop
1
First city code:
4
Second city code:
5
Enter cost(/100):
7
Enter 1 to contiunue,0 to stop
0
Graph is(in codes):
0->12345
1->03100
2->30751
3->17020
4->05207
5->01070
City Codes(from city Pune(1))   Weight
1 - 1           0
1 - 2           3
1 - 3           1
3 - 4           2
2 - 5           1
Cost:6

--------------------------------
Process exited after 39.76 seconds with return value 0
Press any key to continue . . .








*/