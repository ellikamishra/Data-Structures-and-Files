/*
 ============================================================================
 Name        : sort.c
 Author      : ellika
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct student
{ char name[20];
  int roll;
  float per;

}student;

void ascend(student s[],int n);
void swap(student s[],int x,int y);
void descend(student s[],int n);
int search(student s[],int n);
int comp(int a,int b);
  int main(void) {
	student s[20];
	int n,ch,k;
	printf("\n Enter the no. of student records");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{ printf("\nEnter roll no.");
	  scanf("%d",&s[i].roll);
	  printf("\nEnter name:");
	  scanf("%s",s[i].name);

	  for(int j=0;j<strlen(s[i].name);j++)
	  {
		  if(s[i].name[j]<65||s[i].name[j]>123)
		  {
			  printf("\nRe-enter");
			  scanf("%s",s[i].name);
		  }

	  }


	  printf("\n Enter percentage:");
	  scanf("%f",&s[i].per);
    }

	do
 { printf("\nEnter: \n1. for ascending in rollno.\n2.for descending in name\n3.Display\n0.Exit");
   scanf("%d",&ch);
   switch(ch)
   {
   case 1: ascend(s,n);
           break;
   case 2:
          descend(s,n);
          break;
   case 3:
          k=search(s,n);
          if(k!=-1){
            printf("\nRollno.\tName\t\tPercentage");
            printf("\n%d\t%s\t\t%f",s[k].roll,s[k].name,s[k].per);}
            else printf("\nNot found!");
            break;
 } }

   while(ch!=0);
return 0;

}

 void ascend(student s[],int n)
 {  int b=0,c=0,e=0,p=1;
	int l=n-1;
	for(int i=0;i<l&&b==0;i++)
	{ b=1;
	  for(int j=l;j>i;j--)
	  { c++;
		  if(s[j-1].roll>s[j].roll)
		  { swap(s,j,j-1);e++;
                    b=0;}}
          printf("\nPass:%d",p++);
          for(int k=0;k<n;k++)
        {printf("\n%d\t%s\t\t%f",s[k].roll,s[k].name,s[k].per);}
    }
	printf("\nSorted list:\nRollno.\tName\t\tPercentage");
	for(int i=0;i<n;i++)
	{printf("\n%d\t%s\t\t%f",s[i].roll,s[i].name,s[i].per);}
    printf("\nComparisions:%d\nSwaps:%d",c,e);
    if(e==0&&p==1)printf("\nBest case!");
   else if(e==c&&e!=0&&p==n-1) printf("\nWorst case!");
   else printf("\nAverage case!");
}
void swap(student s[],int x,int y)
{
    student temp;
    temp=s[x];
    s[x]=s[y];
    s[y]=temp;
}

void descend( student s[],int n)
{ int c=0,e=0,pa=1;
     for(int i=0;i<n;i++)
  {
   int p=i;
   for(int j=i+1;j<n;j++)
   { c++;
    if(strcmp(s[j].name,s[p].name)>0)
     {p=j;
     swap(s,i,p);e++;} }
     printf("\nPass:%d",pa++);
     for(int k=0;k<n;k++)
        {printf("\n%d\t%s\t\t%f",s[k].roll,s[k].name,s[k].per);}

 }
  printf("\nSorted list:\nRollno.\tName\t\tPercentage");
	for(int i=0;i<n;i++)
	{printf("\n%d\t%s\t\t%f",s[i].roll,s[i].name,s[i].per);}
printf("\nComparisions:%d\nSwaps:%d",c,e);
if(e==0&&pa==1)printf("\nBest case!");
else if(e==c&&e!=0&&pa==n-1) printf("\nWorst case!");
else printf("\nAverage case!");
}


int  search(student s[],int n)
{ ascend(s,n);
 int k;int l=0,r=n-1,m,ch,c=0;
  printf("\nEnter recored to display");
  scanf("%d",&k);

  while(l<=r)
  { m=(l+r)/2;
  ch=comp(s[m].roll,k);
    switch(ch)
    {
        case 1:
               r=m-1;c++;
                break;
        case 2:
               l=m+1;c++;
                break;
        case 0:
               c++;
               printf("\nComparisions:%d",c);
               if(c==1){printf("\nBest case!");}
               else if(c<=n/2) printf("\nAverage case!");
               else printf("\nWorst case!");
               return m;
    }
    }
  return -1;
}

int comp(int a,int b)
{
    if(a>b) {return 1;}
    else if(a<b) {return 2;}
    else {return 0;}
 }
/*output-
 Enter the no. of student records4                                                                                  
                                                                                                                    
Enter roll no.1                                                                                                     
                                                                                                                    
Enter name:elika                                                                                                    
                                                                                                                    
 Enter percentage:78                                                                                                
                                                                                                                    
Enter roll no.2                                                                                                     
                                                                                                                    
Enter name:mohi                                                                                                     
                                                                                                                    
 Enter percentage:40                                                                                                
                                                                                                                    
Enter roll no.9                                                                                                     
                                                                                                                    
Enter name:jai                                                                                                      
                                                                                                                    
 Enter percentage:90     
Enter roll no.5                                                                                                     
                                                                                                                    
Enter name:raji                                                                                                     
                                                                                                                    
 Enter percentage:80                                                                                                
                                                                                                                    
Enter:                                                                                                              
1. for ascending in rollno.                                                                                         
2.for descending in name                                                                                            
3.Display                                                                                                           
0.Exit1                                                                                                             
                                                                                                                    
Pass:1                                                                                                              
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
Pass:2                                                                                                              
1       elika           78.000000                                                                                   
2       mohi            40.000000  
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
Pass:2                                                                                                              
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
Sorted list:                                                                                                        
Rollno. Name            Percentage                                                                                  
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
Comparisions:5                                                                                                      
Swaps:1                                                                                                             
Average case!                                                                                                       
Enter:                                                                                                              
1. for ascending in rollno.                                                                                         
2.for descending in name                                                                                            
3.Display                   
0.Exit2                                                                                                             
                                                                                                                    
Pass:1                                                                                                              
5       raji            80.000000                                                                                   
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
9       jai             90.000000                                                                                   
Pass:2                                                                                                              
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
Pass:3                                                                                                              
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
2       mohi            40.000000                                                                                   
1       elika           78.000000                                                                                   
Pass:4                                                                                                              
5       raji            80.000000                                                                                   
9       jai             90.000000   
2       mohi            40.000000                                                                                   
1       elika           78.000000                                                                                   
Sorted list:                                                                                                        
Rollno. Name            Percentage                                                                                  
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
2       mohi            40.000000                                                                                   
1       elika           78.000000                                                                                   
Comparisions:6                                                                                                      
Swaps:5                                                                                                             
Average case!                                                                                                       
Enter:                                                                                                              
1. for ascending in rollno.                                                                                         
2.for descending in name                                                                                            
3.Display                                                                                                           
0.Exit3                                                                                                             
                                                                                                                    
Pass:1                                                                                                              
1       elika           78.000000                                                                                   
5       raji            80.000000    
9       jai             90.000000                                                                                   
2       mohi            40.000000                                                                                   
Pass:2                                                                                                              
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
Pass:3                                                                                                              
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
Sorted list:                                                                                                        
Rollno. Name            Percentage                                                                                  
1       elika           78.000000                                                                                   
2       mohi            40.000000                                                                                   
5       raji            80.000000                                                                                   
9       jai             90.000000                                                                                   
Comparisions:6                                                                                                      
Swaps:5                     
Average case!                                                                                                       
Enter recored to display1                                                                                           
                                                                                                                    
Comparisions:2                                                                                                      
Average case!                                                                                                       
Rollno. Name            Percentage                                                                                  
1       elika           78.000000                                                                                   
Enter:                                                                                                              
1. for ascending in rollno.                                                                                         
2.for descending in name                                                                                            
3.Display                                                                                                           
0.Exit0                                                                                                             
    */             
