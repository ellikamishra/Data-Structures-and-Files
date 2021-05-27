//============================================================================
// Name        : kruskal.cpp
// Author      : ellika
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//problem statement:Represent any real world graph in adjacency list/matrics and 
//                  find minimum spanning tree by applying kruskals.
//============================================================================

#include <iostream>

using namespace std;
struct graphEdge
	{
		graphEdge *nextEdge;//edge pointer for next edge in edge list
		struct graphVertex *destination; //pointing to the next vertex from main list to access all info
        int w;
        bool intree=0,selected=0;
	};
	struct graphVertex
	{
		char data;

		bool intree=0,selected=0;
		graphEdge *nextEdgePointer;  //points to the edge node in edge list
		graphVertex *nextVertexPointer; //points to next vertex in main list
	};
	struct graphHead
	{
		int count;
		graphVertex *firstVertex; //points to first veretx in main and incremented to add in main
	};

class Kruskal{

    graphHead *G;

    public:

    void createGraph();
	graphVertex* getVertex(char);
	void insertVertex(char);
    void insertEdge(char, char,int);
	void displayGraph();
	void display();
    void mst();
    void displaymst();
    int cycle(graphVertex*,graphVertex*);
};

void Kruskal::createGraph()
{   char data1,data2;
    int ch=1,k,n;
    graphVertex *T;graphVertex *T1;
	G=new graphHead;T=new graphVertex;
    T1=new graphVertex;
	G->count=0;
	cout<<"Enter no. of vertices"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	 cout<<"Enter data:"<<endl;
	 cin>>data1;
	if(G->count==0)
		{G->firstVertex=getVertex(data1);
		T=G->firstVertex;
		}
	else{
		T1=T;
		T=getVertex(data1);
		T1->nextVertexPointer=T;
	}

    }
	T=G->firstVertex;T1=T;

  do
    {cout<<"Enter edges:"<<endl;
    cin>>data1;
    cin>>data2;
    cout<<"Enter weight:"<<endl;
    cin>>k;
    insertEdge(data1,data2,k);
    cout<<"Enter 1 to continue,0 to stop"<<endl;
     cin>>ch;


    }while(ch!=0);


}
graphVertex* Kruskal:: getVertex(char data1)
{
	graphVertex *newptr;
	//allocate the memory for newptr
    newptr=new graphVertex;
    newptr->data=data1;
    newptr->nextEdgePointer=NULL;
    newptr->nextVertexPointer=NULL;

	G->count=G->count+1;

	return newptr;
}

void Kruskal::insertEdge(char startVertex, char endVertex,int w1)
{  graphEdge *newedge=new graphEdge;
   graphEdge *newedge1=new graphEdge;
   graphVertex *fromPtr=G->firstVertex;
   graphVertex *toPtr=G->firstVertex;
   while(fromPtr->data!=startVertex&&fromPtr!=NULL)
    { fromPtr=fromPtr->nextVertexPointer;

    }
//    if((fromPtr==NULL)||(startVertex!=fromPtr->name))
//      {return -1;}
    while(toPtr->data!=endVertex&&toPtr!=NULL)
    { toPtr=toPtr->nextVertexPointer;

    }
//    if((toPtr=NULL)||(endVertex!=toPtr->name))
//      {return -1;}

    newedge->destination=toPtr;
    if(fromPtr->nextEdgePointer==NULL)
    {fromPtr->nextEdgePointer=newedge;
     newedge->nextEdge=NULL;

    }

    graphEdge *pred=NULL;
    graphEdge *temp=fromPtr->nextEdgePointer;
    while(temp!=NULL)
    { pred=temp;
      temp=temp->nextEdge;
    }
    if(fromPtr->nextEdgePointer==NULL)
       {fromPtr->nextEdgePointer=newedge;
        newedge->nextEdge=NULL;

       }
    if(pred==NULL)
    {fromPtr->nextEdgePointer=newedge;}

    else
    {pred->nextEdge=newedge;}

    newedge->nextEdge=temp;
    newedge->destination=toPtr;
    newedge->w=w1;

    graphEdge *pred1=NULL;
    graphEdge *temp1=toPtr->nextEdgePointer;
    while(temp1!=NULL)
    { pred1=temp1;
      temp1=temp1->nextEdge;
    }
    if(toPtr->nextEdgePointer==NULL)
        {toPtr->nextEdgePointer=newedge;
         newedge->nextEdge=NULL;

        }
    if(pred1==NULL)
    {toPtr->nextEdgePointer=newedge1;}

    else
    {pred1->nextEdge=newedge1;}

    newedge1->nextEdge=temp1;
    newedge1->destination=fromPtr;
    newedge1->w=w1;


}
void Kruskal::insertVertex(char data1)
{
	graphVertex *newPtr=NULL,*locPtr=NULL;
	int ch;
	newPtr=getVertex(data1);
	//Insert the new user/vertex in the network/graph. Here we have just taken name (string). U can get complete details (struct object).
	locPtr=G->firstVertex;
	while(locPtr->nextVertexPointer!=NULL)
	{
		locPtr=locPtr->nextVertexPointer;
	}
	locPtr->nextVertexPointer=newPtr;

	G->count++;
}
void Kruskal::display(){

    displayGraph();
    mst();
    displaymst();

}
void Kruskal::displayGraph()
{
	graphVertex *vertexPtr;
	graphEdge *edgePtr;
	//display the graph in adjacency list form
    vertexPtr=G->firstVertex;
    while(vertexPtr!=NULL)
    { cout<<vertexPtr->data<<":"<<endl;
      edgePtr=vertexPtr->nextEdgePointer;
      while(edgePtr!=NULL)
      {
          cout<<edgePtr->destination->data<<"("<<edgePtr->w<<")"<<endl;
          edgePtr=edgePtr->nextEdge;
      }
      vertexPtr=vertexPtr->nextVertexPointer;
    }
}

void Kruskal::mst(){

 graphVertex *v=G->firstVertex;
 graphVertex *p=v;
 graphEdge *e=v->nextEdgePointer;
 graphEdge *e1=NULL;
 graphEdge *minedge=NULL;
 graphVertex *v1=v->nextVertexPointer;

 int min,cost=0,count=G->count;
    v->intree=1;
    while(count-1!=0)
  {  v=G->firstVertex;
     min=999;
      while(v!=NULL)
    {  e=v->nextEdgePointer;

	  while(e!=NULL)
        { if((e->intree==0&&e->selected==0)&&(e->w<min))

            {
                min=e->w;
                minedge=e;
                p=v;
            }
            e=e->nextEdge;
        }

        v=v->nextVertexPointer;

    }


    count--;
    cout<<"Min-edge:"<<p->data<<"-"<<minedge->destination->data<<endl;
     if(minedge->destination->intree==0||p->intree==0)
     { minedge->intree=1;
       minedge->selected=1;
       minedge->destination->intree=1;

       e1=minedge->destination->nextEdgePointer;

       while(e1->w!=minedge->w)
       {e1=e1->nextEdge;}
        e1->intree=0;
        e1->selected=1;

     }

     else{
    	 if(cycle(p,minedge->destination))
        {
    	  minedge->intree=1;minedge->selected=1;
    	  minedge->destination->intree=1;
    	  e1=minedge->destination->nextEdgePointer;

    	     while(e1->w!=minedge->w)
    	     {e1=e1->nextEdge;}
    	      e1->intree=0;
    	      e1->selected=1;
        }
    else{
    	minedge->selected=1;
    	e1=minedge->destination->nextEdgePointer;

        while(e1->w!=minedge->w)
        {e1=e1->nextEdge;}
         e1->intree=0;
         e1->selected=1;
    	}
     }
   cout<<"---------------------------------------"<<endl;
   cout<<"Min-edge weight:"<<minedge->w<<endl;
   cost+=minedge->w;
   cout<<"Cost:"<<cost<<endl;
   cout<<"---------------------------------------"<<endl;
  // e=v->nextEdgePointer;
}
   cout<<"Final Cost:"<<cost<<endl;
}
int Kruskal::cycle(graphVertex* v1,graphVertex *v2)
{ graphEdge* e1=v1->nextEdgePointer;
  int i=1;
  v1->selected=1;
  if(v1==v2)
  {return 0;}

  else{
	  while(e1!=NULL)
	  {  if(e1->intree==1&&e1->destination->selected==0)
	  	  { i+=cycle(e1->destination,v2);}
	  	  e1=e1->nextEdge;
	  }
	  return i;
  }
}
void Kruskal::displaymst(){
    graphVertex *v=G->firstVertex;
    graphEdge *e=v->nextEdgePointer;
    cout<<"Minimum Spanning Tree is:"<<endl;
    while(v!=NULL)
    { 
        while(e!=NULL)
        {
            if(e->intree==1&&e->selected==1)
            {   cout<<v->data<<"->"<<e->destination->data<<endl;
               
            }
            e=e->nextEdge;
        }
        v=v->nextVertexPointer;
        
    }
}
int main()
{
    Kruskal k;
    k.createGraph();
    k.display();
    return 0;
}
/*
/*
Enter no. of vertices                                                                                                           
4                                                                                                                               
Enter data:                                                                                                                     
a                                                                                                                               
Enter data:                                                                                                                     
b                                                                                                                               
Enter data:                                                                                                                     
c                                                                                                                               
Enter data:                                                                                                                     
d                                                                                                                               
Enter edges:                                                                                                                    
a                                                                                                                               
b                                                                                                                               
Enter weight:                                                                                                                   
2                                                                                                                               
Enter 1 to continue,0 to stop                                                                                                   
1                                                                                                                               
Enter edges:                                                                                                                    
a                                                                                                                               
c                                                                                                                               
Enter weight:                                                                                                                   
1                                                                                                                               
Enter 1 to continue,0 to stop                                                                                                   
1  
Enter edges:                                                                                                                    
a                                                                                                                               
d                                                                                                                               
Enter weight:                                                                                                                   
3                                                                                                                               
Enter 1 to continue,0 to stop                                                                                                   
1                                                                                                                               
Enter edges:                                                                                                                    
b                                                                                                                               
d                                                                                                                               
Enter weight:                                                                                                                   
4                                                                                                                               
Enter 1 to continue,0 to stop                                                                                                   
1                                                                                                                               
Enter edges:                                                                                                                    
c                                                                                                                               
d                                                                                                                               
Enter weight:                                                                                                                   
5                                                                                                                               
Enter 1 to continue,0 to stop                                                                                                   
0                                                                                                                               
a:                                                                                                                              
b(2)                                                                                                                            
c(1)   
d(3)                                                                                                                            
b:                                                                                                                              
a(2)                                                                                                                            
d(4)                                                                                                                            
c:                                                                                                                              
a(1)                                                                                                                            
d(5)                                                                                                                            
d:                                                                                                                              
a(3)                                                                                                                            
b(4)                                                                                                                            
c(5)                                                                                                                            
Min-edge:a-c                                                                                                                    
---------------------------------------                                                                                         
Min-edge weight:1                                                                                                               
Cost:1                                                                                                                          
---------------------------------------                                                                                         
Min-edge:a-b                                                                                                                    
---------------------------------------                                                                                         
Min-edge weight:2                                                                                                               
Cost:3                                                                                                                          
---------------------------------------                                                                                         
Min-edge:a-d                                                                                                                    
---------------------------------------                                                                                         
Min-edge weight:3
Cost:6                                                                                                                          
---------------------------------------                                                                                         
Final Cost:6                                                                                                                    
Minimum Spanning Tree is:                                                                                                       
a->b                                                                                                                            
a->c                                                                                                                            
a->d   









*/
