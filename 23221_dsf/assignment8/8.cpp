/*============================================================================
 	Title   : Dijikstra's
 	Name    : Ellika
 	Roll No : 23257
 	Batch   : F-10
	Problem Statement   :
	Represent a given graph using adjacency matrix /adjacency list and find the
shortest path using Dijkstra's algorithm (single source all destination).
============================================================================*/
#include <iostream>

using namespace std;

class Short{
    int graph[10][10];
    int n;
    
    public:
    int minval(int distance[],bool set[]);
    void create();
    void path();
    
};

void Short::create(){
 int ch,v,u,w;
 cout<<"Enter the no. of vertices:"<<endl;
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
 cout<<"Enter edges (1-"<<n<<")"<<endl;
 do{
     cout<<"First vertex:"<<endl;
     cin>>u;
     cout<<"Second vertex:"<<endl;
     cin>>v;
     cout<<"Enter weight"<<endl;
     cin>>w;
     graph[u][v]=w;
     graph[v][u]=w;
     cout<<"Enter 1 to contiunue,0 to stop"<<endl;
     cin>>ch;
     
 }while(ch!=0);
 
 cout<<"Graph is:"<<endl;
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
int Short::minval(int distance[],bool set[]){
	
	
	
	
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
void Short::path(){
    int v,u,min,index=1,k=n,cost=0;
  int   distance[10];
  int  short_path[10];
  bool set[10];
    cout<<"Enter starting vertex(1-"<<n<<")"<<endl;
    cin>>v;
    distance[0]=100;
    for(int i=1;i<n+1;i++)
    {  if(graph[i][v]!=0)
      { distance[i]=graph[i][v];}
      else
      {distance[i]=100;}
      set[i]=0;
    }
    distance[v]=0;
    set[v]=1;
    short_path[0]=v;
    
     
    for(int c=0;c<n-1;c++)
    {int u=minval(distance,set);
     set[u]=1;
     short_path[index]=u;index++;
     cost+=distance[u];
	for(int i=1;i<n+1;i++)
    {
        if(!set[i]&&(distance[i]>(distance[u]+graph[u][i]))&& graph[u][i] && distance[u] !=100)
        {
            distance[i]=distance[u]+graph[u][i];
        }
    }
    }
    
    for(int i=1;i<n+1;i++)
    {
        cout<<"Distance of("<<i<<")from source:"<<distance[i]<<endl;
    }
    cout<<"Shortest path"<<endl;
    for(int i=0;i<n;i++)
    {  
	    if(i==n-1)
        {cout<<short_path[i];}
        else
        {cout<<short_path[i]<<"->";}
    }
 cout<<"\nCost"<<cost<<endl;   
}





int main()
{
    Short s;
    s.create();
    s.path();
    return 0;
}
/*
Enter the no. of vertices:
5
Enter edges (1-5)
First vertex:
1
Second vertex:
2
Enter weight
3
Enter 1 to contiunue,0 to stop
1
First vertex:
1
Second vertex:
3
Enter weight
1
Enter 1 to contiunue,0 to stop
1
First vertex:
2
Second vertex:
3
Enter weight
7
Enter 1 to contiunue,0 to stop
1
First vertex:
2
Second vertex:
4
Enter weight
5
Enter 1 to contiunue,0 to stop
1
First vertex:
2
Second vertex:
5
Enter weight
1
Enter 1 to contiunue,0 to stop
1
First vertex:
3
Second vertex:
4
Enter weight
2
Enter 1 to contiunue,0 to stop
1
First vertex:
4
Second vertex:
5
Enter weight
7
Enter 1 to contiunue,0 to stop
0
Graph is:
0->12345
1->03100
2->30751
3->17020
4->05207
5->01070
Enter starting vertex(1-5)
3
Distance of(1)from source:1
Distance of(2)from source:4
Distance of(3)from source:0
Distance of(4)from source:2
Distance of(5)from source:5
Shortest path
3->1->4->2->5
Cost12

--------------------------------
Process exited after 40.88 seconds with return value 0
Press any key to continue . . .









*/

