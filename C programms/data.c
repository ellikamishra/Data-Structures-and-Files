/*
 ============================================================================
 Name        :data.c
 Author      : Ellika
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>
typedef struct student
{  char name[20];
   int  rollno;
   char  p[10];
   int age;
   int m1,m2,m3;
   float per;
   int d;
} student;
  int input(student s[]);
  void display(student s[],int n);
  void search(student s[],int n);
  int  add(student s[],int n);
  void mod(student s[],int n);
  void del(student s[],int n);
int main()
{  student s[50]; int ch,n,i,t;
    do
  {  printf("\nMenu\n");
     printf("\n1.Enter Records\n2.Display Records\n3.Search Records\n4.Add new records\n5.Modify Records\n6.Delete Records\n0.Exit\n");
     printf("\nEnter choice\n");
     scanf("%d",&ch);
    switch(ch)

{ case 1:
        n=input(s);

        break;
  case 2:
         display(s,n);

    break;
  case 3:
	  display(s,n);
      search(s,n);
      break;
  case 4:
      t=add(s,n);

     display(s,t);
     break;
  case 5:
     mod(s,t);
     break;
  case 6:
     del(s,t);

     break;

	}
  }
  while(ch!=0);
    return 0;
}
 int input(student s[])
 {  int n,i,j,k,t=0;

     printf("\nEnter the no. records to be added\n");
        scanf("%d",&n);

        for(i=0;i<n;i++)
   {   if(i==0)
	   {
	       s[i].rollno=23201;
	       printf("\n Roll no. of student %d: %d",i+1,s[i].rollno);
	     }
	   else{

	         s[i].rollno=s[i-1].rollno+1;
             printf("\nRoll no. of student %d",s[i].rollno);}
      set1:
       printf("\nEnter name of student:");
	   scanf("%s",s[i].name);

	   for(k=0;k<strlen(s[i].name);k++)
	   {  if(s[i].name[k]<65||s[i].name[k]>123)
		  { printf("\n Re-enter");
                      goto set1;
                        } }

       set2:
       printf("\n Enter mobile no.");
       scanf("%s",s[i].p);
       if(strlen(s[i].p)!=10){printf("\n Re-enter"); goto set2;}
          for(j=0;j<10;j++)
       {

           if(s[i].p[j]<48||s[i].p[j]>57)
           {
               printf("\nRe-enter");
                 goto set2;

           }
       }
	   printf("\nEnter marks1:");
	   scanf("%d",&s[i].m1);
	   printf("\nEnter marks2:");
	   scanf("%d",&s[i].m2);
	   printf("\nEnter marks3:");
	   scanf("%d",&s[i].m3);
	   s[i].per=((s[i].m1+s[i].m2+s[i].m3)*100)/300;
       printf("\nEnter age:");
       scanf("%d",&s[i].age);
   } return n; }

   void display(student s[],int n)
   { int i,j;
     printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------");
     printf("\n Name of student:\tAge of student:\tRoll no. of student:\tPercentage of student:\tMobile no. of student:");
     printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");
      for(i=0;i<n;i++)
      { if(s[i].d==1){continue;}
        else
        {
        printf("\n%s\t\t\t%d\t\t\t%d\t\t\t%f\t\t\t%s\t\t\t",s[i].name,s[i].age,s[i].rollno,s[i].per,s[i].p);
                     }} }
    void search(student s[],int n)
    { int a,i;
      printf("\nEnter student rollno. to be searched");
      scanf("%d",&a);
      for(i=0;i<n;i++)
     {   if(s[i].d==1){ continue;}
         if(a==s[i].rollno)
         { printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------");
        	 printf("\n Name of student:\tAge of student:\tRoll no. of student:\tPercentage of student:\tMobile no. of student:");
        	 printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------");
        	 printf("\n%s\t\t\t%d\t\t\t%d\t\t\t%f\t\t\t%s\t\t\t",s[i].name,s[i].age,s[i].rollno,s[i].per,s[i].p);

         } } }

     int add(student s[],int n)
     { int i,k,t,j;
       printf("\n Enter the no. of students to be added");
       scanf("%d",&k);
       n=n+k;
       for(i=n-k;i<n;i++)
       { set3:
         printf("\nName of student :");
         scanf("%s",s[i].name);
         for(k=0;k<strlen(s[i].name);k++)
	   {  if(s[i].name[k]<65||s[i].name[k]>123)
		  { printf("\n Re-enter");
                      goto set3;
                        } }
         s[i].rollno=s[i-1].rollno+1;
        printf("\nRoll no. of student: %d ",s[i].rollno);

        printf("\nAge of student:");
        scanf("%d",&s[i].age);
        set4:
       printf("\n Enter mobile no.");
       scanf("%s",s[i].p);
       if(strlen(s[i].p)!=10){ printf("\n Re-enter");goto set4;}
          for(j=0;j<10;j++)
       {if(s[i].p[j]<48||s[i].p[j]>57)
           { printf("\n Re-enter");
    	   goto set4;}
       }
         printf("\nEnter marks1:");
	   scanf("%d",&s[i].m1);
	   printf("\nEnter marks2:");
	   scanf("%d",&s[i].m2);
	   printf("\nEnter marks3:");
	   scanf("%d",&s[i].m3);
	   s[i].per=((s[i].m1+s[i].m2+s[i].m3)*100)/300;}
         t=n;
         return t;
     }

     void mod(student s[],int n)
     { int a,i,ch;
      printf("\nEnter student rollno. to be modified");
      scanf("%d",&a);
      for(i=0;i<n;i++)
     {  if(s[i].d==1){continue;}
         if(a==s[i].rollno)
       { do
        { printf("\n Enter 1 to modify marks , 2 for age,3 for name,0 for exit");
         scanf("%d",&ch);
         switch(ch)
         { case 1:
            printf("\n Enter Percentage");
            scanf("%f",&s[i].per);
            break;
            case 2:
            printf("\n Enter age");
            scanf("%d",&s[i].age);
            break;
            case 3:
            printf("\n Enter name");
            scanf("%s",s[i].name);
            break;
         } }
         while(ch!=0);
}
         display(s,n);
     } }
     void del(student s[],int n)
      {  int k,r,j,i;
         printf("\n Enter no. of records to be deleted");
         scanf("%d",&k);

            for(j=0;j<k;j++)
           { printf("\n Enter roll no. of student  %d to be deleted from record",j+1);
             scanf("%d",&r);

              for(i=0;i<n;i++)
            {
              if(r==s[i].rollno)
              {   s[i].d=1;}} }
            display(s,n); }

/***
Menu

1.Enter Records
2.Display Records
3.Search Records
4.Add new records
5.Modify Records
6.Delete Records
0.Exit

Enter choice
1

Enter the no. records to be added
2

 Roll no. of student 1: 23201
Enter name of student:raji

 Enter mobile no.12345

 Re-enter
 Enter mobile no.1234567890

Enter marks1:15

Enter marks2:14

Enter marks3:17

Enter age:18

Roll no. of student 23202
Enter name of student:mohi

 Enter mobile no.2345678901

Enter marks1:18

Enter marks2:10

Enter marks3:19

Enter age:17

Menu

1.Enter Records
2.Display Records
3.Search Records
4.Add new records
5.Modify Records
6.Delete Records
0.Exit

Enter choice
2

----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			15.000000			1234567890
mohi			17			23202			15.000000			2345678901
Menu

1.Enter Records
2.Display Records
3.Search Records
4.Add new records
5.Modify Records
6.Delete Records
0.Exit

Enter choice
3

----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			15.000000			1234567890
mohi			17			23202			15.000000			2345678901
Enter student rollno. to be searched23201

----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			15.000000			1234567890
Menu

1.Enter Records
2.Display Records
3.Search Records
4.Add new records
5.Modify Records
6.Delete Records
0.Exit

Enter choice
4

 Enter the no. of students to be added1

Name of student :jai

Roll no. of student: 23203
Age of student:15

 Enter mobile no.12345678901

 Re-enter
 Enter mobile no.1234567890

Enter marks1:18

Enter marks2:10

Enter marks3:20

----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			15.000000			1234567890
mohi			17			23202			15.000000			2345678901
jai			15			23203			16.000000			1234567890
Menu

1.Enter Records
2.Display Records
3.Search Records
4.Add new records
5.Modify Records
6.Delete Records
0.Exit

Enter choice
5

Enter student rollno. to be modified23201

 Enter 1 to modify marks , 2 for age,3 for name,0 for exit1

 Enter Percentage45

 Enter 1 to modify marks , 2 for age,3 for name,0 for exit0

----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			45.000000			1234567890
mohi			17			23202			15.000000			2345678901
jai			15			23203			16.000000			1234567890
----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			45.000000			1234567890
mohi			17			23202			15.000000			2345678901
jai			15			23203			16.000000			1234567890
----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			45.000000			1234567890
mohi			17			23202			15.000000			2345678901
jai			15			23203			16.000000			1234567890
Menu

1.Enter Records
2.Display Records
3.Search Records
4.Add new records
5.Modify Records
6.Delete Records
0.Exit

Enter choice
6

 Enter no. of records to be deleted1

 Enter roll no. of student  1 to be deleted from record23203

----------------------------------------------------------------------------------------------------------------------------------------------------------
 Name of student:	Age of student:	Roll no. of student:	Percentage of student:	Mobile no. of student:
-----------------------------------------------------------------------------------------------------------------------------------------------------------
raji			18			23201			45.000000			1234567890
mohi			17			23202			15.000000			2345678901
Menu

1.Enter Records
2.Display Records
3.Search Records
4.Add new records
5.Modify Records
6.Delete Records
0.Exit

Enter choice
0

    */



