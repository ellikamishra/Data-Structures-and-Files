#include<bits/stdc++.h>

using namespace std;

int visited_all;


int tsp(vector<vector<int>>graph,vector<vector<int>>dp,vector<vector<int>>path,int mask,int pos){           //tsp function with given parameters, changing pos values as graph has n+1*n+1 nodes 

    
    if(mask==visited_all) return graph[pos][1];                                                     //base case if all visited or if dp has values marked return that
        

    if(dp[mask][pos-1]!=-1) return dp[mask][pos-1];

    int ans=INT_MAX,k;

    for(int city=0;city<graph[0].size();city++){                                                //check for visisted city using bitmask and update path

        if((mask&(1<<city))==0){
            
			int newAns = graph[pos][city+1] + tsp(graph,dp,path,mask|(1<<city),city);         //update ans values choosing min
			if(ans>newAns)
			{
				ans=newAns;				
				k=city;			
			}
		}
	}

    path[mask][pos-1]=k;                                                                  //set path             
    
    return dp[mask][pos-1]=ans;
}


void display_path(vector<vector<int>>path,int source,int N)                                 //path printing 
{
	int count=0,i=0;
	int brr[N];
	for(i=0;i<N;i++)
	{
		brr[i]=-1;
	}

	printf("\n shortest path\t\t: %d ->",source+1);
	while(count<N-1)
	{
		for(i=0;i<(1<<N);i++)
		{
			if(path[i][source]!=-1 && brr[path[i][source]]==-1)
			{
				brr[path[i][source]]++;
				source=path[i][source];
				printf(" %d -> ",source+1);
				count++;

				break;
			}
		}
	}
	printf("%d\n\n",1);	

}


int main(){

    int n;

    cout<<"\nEnter no. of cities";
    cin>>n;
    
    visited_all=(1<<n)-1;
    vector<vector<int>>graph(n+1,vector<int>(n+1,0));
    vector<vector<int>>dp(pow(2,n),vector<int>(n,-1));
    vector<vector<int>>path(pow(2,n),vector<int>(n,0));
    for(int i=1;i<n+1;i++){
        int j,k=1,dist;
        cout<<"\nEnter 1 to add city from  "<<i<<"  0 to exit";
        cin>>k;
        while(k){
            cout<<"\nEnter city and distance from  "<<i;
            cin>>j>>dist;
            graph[i][j]=dist;
            // graph[j][i]=dist;
            cout<<"\nEnter 1 to add city from "<<i<<" 0 to exit";
            cin>>k;
        }
        
    }

    for(int i=0;i<n+1;i++){

        for(int j=0;j<n+1;j++){

            if(i==0) graph[i][j]=j;

            else if(j==0) graph[i][j]=i;
            
            cout<<graph[i][j]<<"\t";
        }

        cout<<"\n";
    }

    cout<<"\nTSP distance "<<tsp(graph,dp,path,1,1);

    // display_path(path,0,n);
}


/*


Enter no. of cities4

Enter 1 to add city from  1  0 to exit1

Enter city and distance from  1 2 10

Enter 1 to add city from 1 0 to exit1

Enter city and distance from  13 15

Enter 1 to add city from 1 0 to exit1

Enter city and distance from  14 20

Enter 1 to add city from 1 0 to exit0

Enter 1 to add city from  2  0 to exit1

Enter city and distance from  21 5

Enter 1 to add city from 2 0 to exit1

Enter city and distance from  23 9

Enter 1 to add city from 2 0 to exit1

Enter city and distance from  24 10

Enter 1 to add city from 2 0 to exit1

Enter city and distance from  22 0

Enter 1 to add city from 2 0 to exit0

Enter 1 to add city from  3  0 to exit1

Enter city and distance from  31 6

Enter 1 to add city from 3 0 to exit1

Enter city and distance from  32 13

Enter 1 to add city from 3 0 to exit1

Enter city and distance from  34 12

Enter 1 to add city from 3 0 to exit0

Enter 1 to add city from  4  0 to exit1

Enter city and distance from  41 8

Enter 1 to add city from 4 0 to exit1

Enter city and distance from  42 8

Enter 1 to add city from 4 0 to exit1

Enter city and distance from  43 9

Enter 1 to add city from 4 0 to exit0
0       1       2       3       4
1       0       10      15      20
2       5       0       9       10
3       6       13      0       12
4       8       8       9       0


TSP distance 35

shortest path 1->2->4->3->1


*/