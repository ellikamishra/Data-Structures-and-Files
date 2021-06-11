#include<bits/stdc++.h>
#define Max 1000
using namespace std;

 /*
 Array to store value of columns of queens at position n,starting from 1.
 Queens not placed yet have column value 0 by default
*/
int board[Max]={0}; 

/*
CheckPlace function to find validity of given position
k-row,j-column
*/

bool CheckPlace(int k,int j)
{   
    for(int i=1;i<k;i++)
    {   

        if(board[i]==j)                         //if column values collide invalid
            return false;
        if(abs(board[i]-j)==abs(i-k))           //if diagonal positions invalid
            return false;

    }
    return true;

}
/*

Recursive function with parameters:-
k- queen no.
n-no. of queens

*/

void Solution(int k,int n)            
{   
    for(int i=1;i<n+1;i++)                              //loop for all n columns on board
    {   
        if(CheckPlace(k,i))                             //if valid assign to kth position 
        {   board[k]=i;
            
            
            if(k==n)                                    //if last solution found print
                {   cout<<"\n\nOne Solution:-\n";
                    for(int j=1;j<n+1;j++)
                    {
                        cout<<"Queen no."<<j<<" at columno no."<<board[j]<<"\n";
                    }
                    cout<<"------------------------------------------------------"<<"\n";
                    
                }
            else{
                Solution(k+1,n);                      //continue for rest of the queens
            }
            
         }
         
         
    }
    if(k<n)                                         //print backtracked boards
         {  
            cout<<"Back-Track board"<<"\n";
            cout<<"------------------------------------------------------"<<"\n";
            for(int j=1;j<n+1;j++)
                    
            {
                cout<<"Queen no."<<j<<" at columno no."<<board[j]<<"\n";
            }
            cout<<"------------------------------------------------------"<<"\n";
            
         }

}

int main()
{
    int n;
    cout<<"Enter no. of queens:\n";
    cin>>n;
    while(n<4)                                          //only valid input allowed
    {
        cout<<"Re-enter value of queens!"<<"\n";
        cin>>n;
    }
    Solution(1,n);

    return 0;
}


/**OUTPUT**
 * 
 * Enter no. of queens:
4
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.1
Queen no.2 at columno no.3
Queen no.3 at columno no.0
Queen no.4 at columno no.0
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.1
Queen no.2 at columno no.4
Queen no.3 at columno no.2
Queen no.4 at columno no.0
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.1
Queen no.2 at columno no.4
Queen no.3 at columno no.2
Queen no.4 at columno no.0
------------------------------------------------------


One Solution:-
Queen no.1 at columno no.2
Queen no.2 at columno no.4
Queen no.3 at columno no.1
Queen no.4 at columno no.3
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.2
Queen no.2 at columno no.4
Queen no.3 at columno no.1
Queen no.4 at columno no.3
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.2
Queen no.2 at columno no.4
Queen no.3 at columno no.1
Queen no.4 at columno no.3
------------------------------------------------------


One Solution:-
Queen no.1 at columno no.3
Queen no.2 at columno no.1
Queen no.3 at columno no.4
Queen no.4 at columno no.2
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.3
Queen no.2 at columno no.1
Queen no.3 at columno no.4
Queen no.4 at columno no.2
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.3
Queen no.2 at columno no.1
Queen no.3 at columno no.4
Queen no.4 at columno no.2
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.4
Queen no.2 at columno no.1
Queen no.3 at columno no.3
Queen no.4 at columno no.2
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.4
Queen no.2 at columno no.2
Queen no.3 at columno no.3
Queen no.4 at columno no.2
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.4
Queen no.2 at columno no.2
Queen no.3 at columno no.3
Queen no.4 at columno no.2
------------------------------------------------------
Back-Track board
------------------------------------------------------
Queen no.1 at columno no.4
Queen no.2 at columno no.2
Queen no.3 at columno no.3
Queen no.4 at columno no.2
------------------------------------------------------
**/