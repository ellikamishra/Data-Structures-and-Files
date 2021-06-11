/*
graph with nodes 


*/ 

#include<bits/stdc++.h>

using namespace std;


typedef struct node{
    int dest;
    int cost;
}node;

class Graph{

    int n;
    public:
    vector<node> *EdgeList;
    Graph(){
        n=0;
    }
    Graph(int n){
        EdgeList= new vector<node>[n];
    }

    void display(){
        
        for(int i=0;i<n;i++){
            for(auto it:EdgeList[i]){

                cout<<it.dest<<"-"<<it.cost<<"\n";
            }
        }
        
    }

    

    void addEdge(int source,int distance,int cost){
        node newNode;
        newNode.dest=distance;
        newNode.cost=cost;

        EdgeList[source].push_back(newNode);

    }
    friend void Shortest(Graph g,int *distance,int *prev,int start);
};
void Shortest(Graph g,int *distance,int *prev,int start){
        int n=g.n;
        for(int i=0;i<n;i++){
            distance[i]=1000;
            prev[i]=-1;
        }
        distance[start]=0;
        prev[start]=0;

        for(int i=0;i<n;i++){
            if(i!=start){
                for(auto it=g.EdgeList[i].begin();it!=g.EdgeList[i].end();it++)
                {
                    if((distance[i]+(it->cost))<distance[it->dest]){
                        distance[it->dest]=distance[i]+(it->cost);
                        prev[it->dest]=i;
                    }
                }
            }
        }

    }
int main(){
    int n=8;
    int dist[n], prev[n];
    int start = 0;
    Graph g(n);
    g.addEdge(0,1,4);
    g.addEdge(0,2,4);
    g.addEdge(1,2,2);
    g.addEdge(2,3,3);
    g.addEdge(2,4,1);
    g.addEdge(2,5,6);
    g.addEdge(3,5,2);
    g.addEdge(4,5,3);
    g.display();
}




/*

vector<vector<int>> generate(int numRows) {
        vector<vector<int>>triangle;
        triangle.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>* row=new vector<int>[i];
            row[0].push_back(1);
            for(int j=1;j<i-1;j++){
                row[j].push_back(triangle[j-1][i-1]+triangle[j][i-1]);
            }
            row[i-1].push_back(1);
            triangle.push_back(*row);
        }
        
        return triangle;
*/