#include<bits/stdc++.h>

using namespace std;
typedef struct node{
    int dest;
    int weight;
}node;

class Graph{

    int n;
    vector<node> *edgeList;

    public:
    Graph(){
        n=0;
    }

    Graph(int count){
        n=count;
        edgeList= new vector<node>[n];
    }

    
    void create(int source,int dest,int weight){
        node newNode;
        newNode.dest=dest;
        newNode.weight=weight;
        edgeList[source].push_back(newNode);
    }

    void display(){
        cout<<"From\tTo\tWeight\n";
        for(int i=0;i<n;i++){
            for(auto it:edgeList[i]){
                if(i<it.dest)
                    cout<<i+1<<"-"<<it.dest+1<<"-"<<it.weight<<"\n";
            }
        }
    }

    int minNode(int start){
        vector<node>::iterator it;
        node mindist=*edgeList[start].begin();
    for(it=edgeList[start].begin();it!=edgeList[start].end();it++){
        if(it->weight<mindist.weight)
            mindist=*it;
    }
    cout<<it-edgeList[start].begin()<<"\n";
    return it-edgeList[start].begin();
    }

    friend void Shortest(Graph g, vector<int> &distance,vector<int> &prev,int start);
};


void Shortest(Graph g,vector<int> &distance,vector<int> &prev,int start){

    int n=g.n;

    // for(int i=0;i<n;i++){
    //     distance[i]=1000;
    //     prev[i]=-1;
    // }
    distance[start]=0;
    while(n--){
        for(auto it=g.edgeList[start].begin();it!=g.edgeList[start].end();it++)
                {
                    if((distance[start]+(it->weight))<distance[it->dest]){
                        distance[it->dest]=distance[start]+(it->weight);
                        prev[it->dest]=start;
                    }
                }
        start=g.minNode(start);
    }
    


}

int main(){
    int n,k=1,dest,weight,start;
    vector<int>distance(n,10000);
    vector<int>prev(n,-1);
    cout<<"\nEnter no. of nodes\n";
    cin>>n;
    Graph g(n);

    for(int i=0;i<n;i++){
        cout<<"Enter 1 to add edge from node"<<i<<",0 to exit"<<"\n";
        cin>>k;
        while(k){
        
        cout<<"\nEnter dest and weight\n";
        cin>>dest>>weight;
        g.create(i,dest,weight);
        g.create(dest,i,weight);
        cout<<"Enter 1 to add edge from node"<<i<<",0 to exit"<<"\n";
        cin>>k;
        }
    }
    g.display();
    
    
    cout<<"\nEnter start node index\n";
    cin>>start;
    Shortest(g,distance,prev,start);
    for(int i = 0; i<n; i++)
      if(i != start)
         cout<<start+1<<" to "<<i+1<<", Cost: "<<distance[i]<<" Previous: "<<prev[i]<<endl;
    return 0;
}

/*


Enter no. of nodes
4
Enter 1 to add edge from node00 to exit
1

Enter dest and weight
1 5
Enter 1 to add edge from node00 to exit
1

Enter dest and weight
2 8
Enter 1 to add edge from node00 to exit
0
Enter 1 to add edge from node10 to exit
1

Enter dest and weight
2 9
Enter 1 to add edge from node10 to exit
1

Enter dest and weight
3 2
Enter 1 to add edge from node10 to exit
0
Enter 1 to add edge from node20 to exit
1

Enter dest and weight
3 6
Enter 1 to add edge from node20 to exit
0
Enter 1 to add edge from node30 to exit
0
From    To      Weight
1-2-5
1-3-8
2-3-9
2-4-2
3-4-6

Enter start node index
1
3
2
3
2
1 to 0, Cost: 5 Previous: 1
1 to 2, Cost: 8 Previous: 3
1 to 3, Cost: 2 Previous: 1
*/