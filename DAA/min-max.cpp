/*
    4 5 6 3 8 1

    1 3 4 5 6 8 

    4 5 6 1 8 3

    maxe
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{

    vector<int>input={2,5,9,1,3};
    vector<int>res;
    int maxe=input[0];
    int mine=input[0];
    for(int i=0;i<input.size();i++)    //input.size()+1 times
    {
        if(input[i]>maxe)              //input.size()
        {
            maxe=input[i];            // n
        }

        if(mine>input[i])               //input.size()
        {
             mine=input[i];             //n
        }
    }

    cout<<"Max:"<<maxe<<"\n";
    cout<<"Min:"<<mine<<"\n";
    
}

/*

O(n) 

*/