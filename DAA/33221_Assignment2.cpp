#include<bits/stdc++.h>

using namespace std;

int maxe,mine;                              //global variables to find maximum and minimum

void min_max(int* a,int l,int h){           //min -max function using divide and conquer
    int m=(l+h)/2;                          //dividing array into 2 parts and printing low,mid and high values
    cout<<"\nLow-Mid-High\n";
    cout<<l<<"\t"<<m<<"\t"<<h<<"\n";
    cout<<"\nElements in call-\n";
    for(int i=l;i<=h;i++)                    //printing elements in call
            cout<<a[i]<<"\t";
    cout<<"\n";
    if(l==h){                               //base case if only 1 element remains compare with max and min,update if found
        if(a[l]>maxe)
            maxe=a[l];
        else if(a[l]<mine)
            mine=a[l];
        cout<<"Min-"<<mine<<"\nMax-"<<maxe;
        
    }
    else if(h-l==1){                        //base case if 2 elements remain compare with max and min, max and min value among them,update if found
        cout<<"Min-"<<min(a[l],a[h])<<"\nMax-"<<max(a[l],a[h])<<"\n";
        if(max(a[l],a[h])>maxe)
            maxe=max(a[l],a[h]);
        else if(min(a[l],a[h])<mine)
            mine=min(a[l],a[h]);
        cout<<"\nMin-"<<mine<<"\nMax-"<<maxe;
    }
    else{                                   //else divide array again
        min_max(a,l,m);
        min_max(a,m+1,h);
    }
    
}

int main(){

    int n;
    cout<<"\nEnter no. of elements";        //input no. of elements and arrat elements
    cin>>n;
    int* a=new int[n];
    cout<<"\nEnter elements";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    maxe=a[0];                              //inititlise maxe and mine with first array element
    mine=a[0];
    
    min_max(a,0,n-1);
    cout<<"\n---------------------------\n";
    cout<<"Minimum-"<<mine<<"\nMaximum-"<<maxe;     //print maximum and minimum found
    free(a);                                         //free space

}

/****OUTPUT
 * 
 * 
 Enter no. of elements10

Enter elements-9 12 34 20 50 12 2 -1 33 1

Low-Mid-High
0       4       9

Elements in call-
-9      12      34      20      50      12      2       -1      33      1

Low-Mid-High
0       2       4

Elements in call-
-9      12      34      20      50

Low-Mid-High
0       1       2

Elements in call-
-9      12      34

Low-Mid-High
0       0       1

Elements in call-
-9      12
Min--9
Max-12

Min--9
Max-12
Low-Mid-High
2       2       2

Elements in call-
34
Min--9
Max-34
Low-Mid-High
3       3       4

Elements in call-
20      50
Min-20
Max-50

Min--9
Max-50
Low-Mid-High
5       7       9

Elements in call-
12      2       -1      33      1

Low-Mid-High
5       6       7

Elements in call-
12      2       -1

Low-Mid-High
5       5       6

Elements in call-
12      2
Min-2
Max-12

Min--9
Max-50
Low-Mid-High
7       7       7

Elements in call-
-1
Min--9
Max-50
Low-Mid-High
8       8       9

Elements in call-
33      1
Min-1
Max-33

Min--9
Max-50
---------------------------
Minimum--9
Maximum-50
 
 *****/