/*
 ============================================================================
 Name        : quick.c
 Author      : ellika
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>

typedef struct user{

char name[20];
char m[20];
float bill;

}user;

user u[20];
void descend(int left,int right);
void swap(int x,int y);
void ascend(int left,int right);
int main()
{
    int n,ch;
    printf("\n Enter no. of records");
    scanf("%d",&n);
    for(int k=0;k<n;k++)
	{
	  printf("\nEnter name:");
	  scanf("%s",u[k].name);

	  for(int j=0;j<strlen(u[k].name);j++)
	  {
		  if(u[k].name[j]<65||u[k].name[j]>123)
		  {
			  printf("\nRe-enter");
			  scanf("%s",u[k].name);
		  }

	  }

	  printf("\nEnter mobile no. ");
	  scanf("%s",u[k].m);
	   if(strlen(u[k].m)!=10){printf("\n Re-enter"); scanf("%s",u[k].m);}
      for(int j=0;j<10;j++)
       {if(u[k].m[j]<48||u[k].m[j]>57)
           {
               printf("\nRe-enter");
               scanf("%s",u[k].m);}}

	  printf("\n Enter bill:");
	  scanf("%f",&u[k].bill);
    }
    do
 { printf("\nEnter: \n1. for descending in name\n2.for ascending of mobile no.\n3.Display\n0.Exit");
   scanf("%d",&ch);
   switch(ch)
   {
   case 1: descend(0,n-1);
         printf("\n-----------------------------------------------------");
         printf("\n\nName\t\tMobileno.\t\tBill");
         printf("\n-----------------------------------------------------");
          for(int i=0;i<n;i++)
          {
              printf("\n%s\t\t%s\t\t%f",u[i].name,u[i].m,u[i].bill);
          }

           break;
//    case 2: ascend(0,n-1);
//            printf("\nName\t\tMobileno.\t\tBill");
//          for(int i=0;i<n;i++)
//          {
//              printf("\n%s\t\t%s\t\t%f",u[i].name,u[i].m,u[i].bill);
//          }
//
//           break;


} }
while(ch!=0);
return 0;
}

void descend( int left, int right)
{
    if (left< right)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(left, right);

        // Separately sort elements before
        // partition and after partition
        descend( left, pi - 1);
        descend( pi + 1, right);
    }
}
int partition ( int left, int right)
{    char pivot[20];
     static int p;
     static int c;
     strcpy(pivot,u[right].name);// pivot

    int i = (left - 1); // Index of smaller element
    printf("\n-----------------------------------------------------");
    printf("\nPivot before pass:%s at %d",pivot,right);
    for (int j = left; j <= right - 1; j++)
    {    c++;
        // If current element is larger than the pivot
        if (strcmp(u[j].name,pivot)>0)
        {
            i++; // increment index of larger element
            swap(i,j);
        }
    }
    swap(i + 1,right);
    printf("\nPass:%d",p++);
    printf("\nPivot:%s at %d",pivot,i+1);
    printf("\nLeft part:");
    for(int k=0;k<=right;k++)
    { if(k<i+1)
    printf("\n%s\t%s\t\t%f",u[k].name,u[k].m,u[k].bill);
    else if(k==i)printf("\nRight part:");
    else
    printf("\nRight Part:\n%s\t%s\t\t%f",u[k].name,u[k].m,u[k].bill);
    }
    printf("\nNo. of comparisions:%d",c);
    if(p==1){printf("\nBest case!");}
    if(p==right){printf("\nWorst case!");}
    else{printf("\nAverage case!");}
    return (i + 1);
}

void swap(int x,int y)
{user temp;
 temp=u[x];
 u[x]=u[y];
 u[y]=temp;
}
/*Enter no. of records4                                                                                              
                                                                                                                    
Enter name:elika                                                                                                    
                                                                                                                    
Enter mobile no. 1234567890                                                                                         
                                                                                                                    
 Enter bill:45                                                                                                      
                                                                                                                    
Enter name:mohi                                                                                                     
                                                                                                                    
Enter mobile no. 2345678901                                                                                         
                                                                                                                    
 Enter bill:78                                                                                                      
                                                                                                                    
Enter name:mohi                                                                                                     
                                                                                                                    
Enter mobile no. 3456789012                                                                                         
                                                                                                                    
 Enter bill:90        
Enter name:jai                                                                                                      
                                                                                                                    
Enter mobile no. 0987654321                                                                                         
                                                                                                                    
 Enter bill:89                                                                                                      
                                                                                                                    
Enter:                                                                                                              
1. for descending in name                                                                                           
2.for ascending of mobile no.                                                                                       
3.Display                                                                                                           
0.Exit1                                                                                                             
                                                                                                                    
-----------------------------------------------------                                                               
Pivot before pass:jai at 3                                                                                          
Pass:0                                                                                                              
Pivot:jai at 2                                                                                                      
Left part:                                                                                                          
mohi    2345678901              78.000000                                                                           
mohi    3456789012              90.000000                                                                           
Right Part:                                     
Right Part:                                                                                                         
jai     0987654321              89.000000                                                                           
Right Part:                                                                                                         
elika   1234567890              45.000000                                                                           
No. of comparisions:3                                                                                               
Best case!                                                                                                          
Average case!                                                                                                       
-----------------------------------------------------                                                               
Pivot before pass:mohi at 1                                                                                         
Pass:1                                                                                                              
Pivot:mohi at 0                                                                                                     
Left part:                                                                                                          
Right Part:                                                                                                         
mohi    3456789012              90.000000                                                                           
Right Part:                                                                                                         
mohi    2345678901              78.000000                                                                           
No. of comparisions:4                                                                                               
Average case!                                                                                                       
----------------------------------------------------- 
-----------------------------------------------------                                                               
                                                                                                                    
Name            Mobileno.               Bill                                                                        
-----------------------------------------------------                                                               
mohi            3456789012              90.000000                                                                   
mohi            2345678901              78.000000                                                                   
jai             0987654321              89.000000                                                                   
elika           1234567890              45.000000                 
Enter:                                                                                                              
1. for descending in name                                                                                           
2.for ascending of mobile no.                                                                                       
3.Display                                                                                                           
0.Exit0    */ 







*/