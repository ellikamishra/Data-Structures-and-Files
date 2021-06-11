#include<bits/stdc++.h>

using namespace std;

int Knapsack(int W,vector<int>& values,vector<int>&weights){        //Call knapsack function with parameters

    int n=values.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));                  //dp 2D array to store values

    for(int i=1;i<=n;i++){                                          //loop values from W(max capacity of sack) in cols to item weights in row

        for(int j=1;j<=W;j++){
            
            

            if(weights[i-1]<=j){                                     //if weight is lesser than current capacity insert max possible value

                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }

            else dp[i][j]=dp[i-1][j];                               //else do not update
        }
    }
    
    return dp[n][W];
}



int main(){
    int n,W;
    cout<<"\nEnter max capacity of knapsack ";
    cin>>W;
    cout<<"\nEnter no. of items\n";
    cin>>n;
    vector<int>values(n,0);
    vector<int>weights(n,0);

    for(int i=0;i<n;i++){
        cout<<"Enter weight of item "<<i+1<<"\t";
        cin>>weights[i];
        cout<<"Enter value of item "<<i+1<<"\t\n";
        cin>>values[i];
    }

    cout<<"Max value possible for give knapsack: "<<Knapsack(W,values,weights);
    
}



/*
OUTPUT-

Enter max capacity of knapsack 50

Enter no. of items
3
Enter weight of item 1  10
Enter value of item 1
60
Enter weight of item 2  20
Enter value of item 2
100
Enter weight of item 3  30
Enter value of item 3
120
Max value possible for give knapsack: 220


*/