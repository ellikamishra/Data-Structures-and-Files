#include<bits/stdc++.h>

using namespace std;


//edge is struct to store edges
typedef struct edge{
    
    int src,dest,cost;
}edge;

//class graph with vector of edges
class Graph{
    int n=0;
    vector<edge>edges;

    public:
    Graph(){
        n=0;
    }

    Graph(int size){
        n=size;
        
    }

    void addEdge(int source,int dest,int cost){             //add edges 
        
        edge newEdge;
        
        newEdge.src=source;
        newEdge.dest=dest;
        newEdge.cost=cost;
        edges.push_back(newEdge);
    }

    void Display(){                                         //display using vector of edges
        cout<<"From\tTo\tWeight\n";
        for(auto it:edges)
            cout<<it.src<<"\t-\t"<<it.dest<<"\t-\t"<<it.cost<<"\n";

    }

    friend void Shortest(Graph g,vector<int>&distance,int source);
};

void Shortest(Graph g,vector<int>&distance,int source){         //Shortest path friend function
    distance[source]=0;
    
    int flag=1;                                                  //define path to track parent
    int size=g.n;
    vector<int>path(size,-1);
    for(int i=0;i<=size-1;i++){                                    //iterate through edges no. of nodes-1 times
        for(int j=0;j<g.edges.size();j++){
            int u=g.edges[j].src;
            int v=g.edges[j].dest;
            int w=g.edges[j].cost;
            if(distance[u]!=1000&& distance[u]+w<distance[v]) {         //update distance vector with min distances and path too
                distance[v]=distance[u]+w;
                
                path[v]=u;
            }
        }

    }
    for(int j=0;j<g.edges.size();j++){                                  //if another min path found then negative cycle exits
            int u=g.edges[j].src;
            int v=g.edges[j].dest;
            int w=g.edges[j].cost;
            if(distance[u]!=1000&& distance[u]+w<distance[v]) {
                cout<<"Negative cycle!";
                flag=0;
                break;
            }
        }

    if(flag){                                                           //else print path and distance respectively for each node dtarting from 0
    
        vector<int>totpath;
        for(int j=size-1;j>=0;j--){
            for(int i=path[j];i!=-1;i=path[i]) {
                totpath.push_back(i);
            }   
            reverse(totpath.begin(),totpath.end());
            cout<<"\nNode "<<j<<" Path";
            for(auto it:totpath) cout<<it<<"\t";
            totpath.clear();
            cout<<"\nDistance from source\t"<<distance[j];

        }
        
    }
    

}

int main(){
    int dest,weight,n,k,source;
    
    cout<<"\nEnter no. of nodes\n";                                 //input number of nodes
    cin>>n;
    vector<vector<int>>graph(n+1,vector<int>(n+1,0));               //create 2D to print 
    Graph g(n);
    
    vector<int>distance(n,1000),path;
    for(int i=0;i<n;i++){
        cout<<"Enter 1 to add edge from node "<<i<<",0 to exit"<<"\n";      //take input
        cin>>k;
        while(k){
        
        cout<<"\nEnter dest and weight\n";
        cin>>dest>>weight;
        g.addEdge(i,dest,weight);
        graph[i+1][dest+1]=weight;
        cout<<"Enter 1 to add edge from node "<<i<<",0 to exit"<<"\n";
        cin>>k;
        }
    }
    g.Display();
    cout<<"\nGraph in matrix\n";        //print graph
    for(int i=0;i<n+1;i++)
    {
        graph[0][i]=i;
        graph[i][0]=i;
    }
    for(int i=0;i<n+1;i++){

        for(int j=0;j<n+1;j++){

            cout<<graph[i][j]<<'\t';
            if(j==0) cout<<"->";
	 
        }
        cout<<"\n";
    }
    cout<<"\nEnter source vertex";              //enter source and call Shortest path
    cin>>source;
    Shortest(g,distance,source);


}


/*
TESTCASE1:
Enter no. of nodes
7
Enter 1 to add edge from node 0,0 to exit
1

Enter dest and weight
1
6
Enter 1 to add edge from node 0,0 to exit
1

Enter dest and weight
2
5
Enter 1 to add edge from node 0,0 to exit
1

Enter dest and weight
3
5
Enter 1 to add edge from node 0,0 to exit
0
Enter 1 to add edge from node 1,0 to exit
1

Enter dest and weight
4
-1
Enter 1 to add edge from node 1,0 to exit
0
Enter 1 to add edge from node 2,0 to exit
1

Enter dest and weight
1
-2
Enter 1 to add edge from node 2,0 to exit
1

Enter dest and weight
4
1
Enter 1 to add edge from node 2,0 to exit
0
Enter 1 to add edge from node 3,0 to exit
1

Enter dest and weight
2
-2
Enter 1 to add edge from node 3,0 to exit
1

Enter dest and weight
5
-1
Enter 1 to add edge from node 3,0 to exit
0
Enter 1 to add edge from node 4,0 to exit
1

Enter dest and weight
6
3
Enter 1 to add edge from node 4,0 to exit
0
Enter 1 to add edge from node 5,0 to exit
1

Enter dest and weight
6
3
Enter 1 to add edge from node 5,0 to exit
0
Enter 1 to add edge from node 6,0 to exit
0
From    To      Weight
0       -       1       -       6
0       -       2       -       5
0       -       3       -       5
1       -       4       -       -1
2       -       1       -       -2
2       -       4       -       1
3       -       2       -       -2
3       -       5       -       -1
4       -       6       -       3
5       -       6       -       3

Graph in matrix
0       ->1     2       3       4       5       6       7
1       ->0     6       5       5       0       0       0
2       ->0     0       0       0       -1      0       0
3       ->0     -2      0       0       1       0       0
4       ->0     0       -2      0       0       -1      0
5       ->0     0       0       0       0       0       3
6       ->0     0       0       0       0       0       3
7       ->0     0       0       0       0       0       0

Enter source vertex0

Node 6 Path0    3       2       1       4
Distance from source    3
Node 5 Path0    3
Distance from source    4
Node 4 Path0    3       2       1
Distance from source    0
Node 3 Path0
Distance from source    5
Node 2 Path0    3
Distance from source    3
Node 1 Path0    3       2
Distance from source    1
Node 0 Path

-------------------------------------------------------------------------------------------------
TESTCASE 2

Enter no. of nodes
4
Enter 1 to add edge from node 0,0 to exit
1

Enter dest and weight
1
5
Enter 1 to add edge from node 0,0 to exit
1

Enter dest and weight
2
4
Enter 1 to add edge from node 0,0 to exit
0
Enter 1 to add edge from node 1,0 to exit
1

Enter dest and weight
3
3
Enter 1 to add edge from node 1,0 to exit
0
Enter 1 to add edge from node 2,0 to exit
1

Enter dest and weight
1
-6
Enter 1 to add edge from node 2,0 to exit
0
Enter 1 to add edge from node 3,0 to exit
2

Enter dest and weight
2
2
Enter 1 to add edge from node 3,0 to exit
0
From    To      Weight
0       -       1       -       5
0       -       2       -       4
1       -       3       -       3
2       -       1       -       -6
3       -       2       -       2

Graph in matrix
0       ->1     2       3       4
1       ->0     5       4       0
2       ->0     0       0       3
3       ->0     -6      0       0
4       ->0     0       2       0

Enter source vertex0
Negative Cycle!
-------------------------------------------------------------------------------------------------

*/