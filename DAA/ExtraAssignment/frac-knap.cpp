#include<bits/stdc++.h>

using namespace std;


void FracKnap(priority_queue<pair<double,int>>ratio,vector<int>weights,vector<int>values,int W)
{
    vector<double>Sack(weights.size(),0);
    int w;
    while(!ratio.empty()){
        w=weights[ratio.top().second];
        if(W>=w)
        {
            Sack[ratio.top().second]=values[ratio.top().second];
            W-=weights[ratio.top().second];
        }else{
            Sack[ratio.top().second]=values[ratio.top().second]*((double)W/(double)w);
            break;
        }
        ratio.pop();
        
    }
    cout<<"\n";
    for(auto it:Sack){
        cout<<it<<"\t";
    }

    cout<<"\nTotal value "<<accumulate(Sack.begin(),Sack.end(),0);
}


int main(){

    int n,W;
    
    priority_queue<pair<double,int>>ratio;

    cout<<"\nEnter max capacity of sack";
    cin>>W;
    cout<<"\nEnter the no. of weights and values";
    cin>>n;
    vector<int>weights(n,0);
    vector<int>values(n,0);
    for(int i=0;i<n;i++){
        cout<<"\nEnter weight of "<<i+1<<"\n";
        cin>>weights[i];
        cout<<"\nEnter value of "<<i+1<<"\n";
        cin>>values[i];
        
        ratio.push(make_pair((double)values[i]/(double)weights[i],i));

    }

    FracKnap(ratio,weights,values,W);

    return 0;
}