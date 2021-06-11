#include<bits/stdc++.h>

using namespace std;
void Merge(vector<int>&v,int l,int m,int h){
    int n1,n2;
    n1=m-l+1;
    n2=h-m;
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = v[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = v[m + 1 + j];

    int i=0,j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(left[i]<right[j])
        {   v[k]=left[i];
            k++;i++;
        }

        else{
            v[k]=right[j];
            j++;k++;
        }
    }

    while(i<n1)
    {  
        v[k]=left[i];
        i++;k++;
    }

    while(j<n2)
    {  
        v[k]=right[j];
        j++;k++;
    }

    //   for(int it=0;it<v.siz;it++)
    // {
    //     cout<<v[it];
    // }
 

 }


void mergeSort(vector<int>&v,int l,int h){
    
    if(l<h)
    {
        int m=(l+h)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,h);
        Merge(v,l,m,h);
    }

   

}

 
// int main()
// {

//     int n,i;
//     // int v[1000];
//     cout<<"\n Enter number of ints\n";
//     cin>>n;
//     vector<int>v(n);
//     cout<<"\n Enter numbers\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>v[i];
//     }
//     for(i=0;i<n-1;i++)
//     {
//         if(v[i]>v[i+1])
//             {
//                 mergeSort(v,0,n-1);
//                 cout<<"\n Sorted array:\n";
//                 for(i=0;i<n;i++)
//                 {
//                     cout<<v[i];
//                 }
//                 break;
//             }

        
//     }
 
//     if(i==n-1)
//     {
//         cout<<"\nSorted array as input\n";
//         for(i=0;i<n;i++)
//             {
//                 cout<<v[i];
//             }
//     }

   

// }

