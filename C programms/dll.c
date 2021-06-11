/*
 ============================================================================
 Name        : dll.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct student{

	char name[20];
	int rollno;
};




typedef struct node
{  struct student stud;
   struct node *next;
   struct node *prev;

}node;

node *create(node *head);
void display(node *head);
node *insert(node *head);
node *delete(node *head);
void displayr(node *head);
node *mod(node *head);
int main(){


	int choice, num;
		node *head = NULL;

		do
		{
			printf("\nMENU :\n1. Input records\n2. Display record\n3.Insert record\n4. Delete record\n5. Display backward\n0. Exit\n");
			scanf("%d", &choice);
			switch(choice)
			{
			case 1: head=create(head);
			        break;
			case 2: display(head);
                    break;
			case 3: head=insert(head);
			        display(head);
                    break;
			case 4: head=delete(head);
			        display(head);
			        break;
			case 5: displayr(head);
			        break;

			case 6: head=mod(head);
			        display(head);
			        break;
			}
			}while(choice!=0);

			return 0;
		}



node *create(node *head)
{ node *p=NULL;node *q=NULL;
  int n;

     printf("\nEnter records to be created");
	scanf("%d",&n);




	for(int i=0;i<n;i++)
	{ 	if(head==NULL)
			{ head=(node *)malloc(sizeof(node));
	  head->next=NULL;
	  head->prev=NULL;
	  printf("\nEnter name:");
	  scanf("%s",head->stud.name);
	  printf("\nEnter roll no.");
	  scanf("%d",&head->stud.rollno);
	  p = head;
	  q = p;
			}
	else
	{
		p->next = (node*)malloc(sizeof(node));
		p = p->next;
		 printf("\nEnter name:");
		 scanf("%s",p->stud.name);
		 printf("\nEnter roll no.");
		 scanf("%d",&p->stud.rollno);

		p->next = NULL;
		p->prev = q;
		q = p;


		 }}


	return head;
}

void display(node *head)
{ node *p=head;
    printf("\n------------------");
	printf("\nRollno\t\tName");
	printf("\n------------------\n");
    while(p!=NULL)
    {
    	printf("%d\t\t%s\t\t\n",p->stud.rollno,p->stud.name);
        p=p->next;

    }


}

node *insert(node *head)
{  int index,ch;
   node *p=head;
   node *q=NULL;
   node *newnode=NULL;
   newnode=(node *)malloc(sizeof(node));
   printf("\nEnter name:");
   	  scanf("%s",newnode->stud.name);
   	  printf("\nEnter roll no.");
   	  scanf("%d",&newnode->stud.rollno);

printf("\nEnter 1 to insert at front,2 for middle,3 for end");
scanf("%d",&ch);
	switch(ch)
	{
	   case 1: newnode->next=head;
               head->prev=newnode;
               head=newnode;
               break;
	   case 2: printf("\nEnter index to insert");
               scanf("%d",&index);
               while(index-2!=0)
               {
            	    p=p->next;
                    index--;
               }
               newnode->next=p->next;
               newnode->prev=p;
               p->next=newnode;
               break;
	   case 3: while(p->next!=NULL)
	        {
		      p=p->next;

	        }
	        newnode->next=p->next;
	        newnode->prev=p;
	        p->next=newnode;
            break;
	}
	return head;
}

node *delete(node *head)
{ int ch,index;
  node *p,*q;
  p=head;
  q=head;
  printf("\nEnter 1 to delete at front,2 for middle,3 for end");
  scanf("%d",&ch);
  switch(ch)
  { case 1:
            head=head->next;
            head->prev=NULL;
            free(p);
            break;
    case 2:  printf("\nEnter index to delete");
             scanf("%d",&index);
             while(index-1!=0)
             {  q=p;
            	 p=p->next;
            	 index--;
             }
              q->next=p->next;
              p->next->prev=q;
              free(p);
              break;
    case 3:
    	   while(p->next!=NULL)
    	   {
    		   q=p;
    		   p=p->next;

    	   }
    	   q->next=p->next;
    	   free(p);
    	   break;
  }


return head;

}

void displayr(node *head)
{

	node *p = head;
		while(p->next != NULL)
		p = p->next;
		 printf("\n------------------");
		 printf("\nRollno\t\tName");
		 printf("\n------------------\n");
		while(p != NULL)
		{
			printf("%d\t\t%s\t\t\n",p->stud.rollno,p->stud.name);
			p = p->prev;
		}

}

node *mod(node *head)
{ node *p = head;
  int loc, i;
 printf("\nAt which location you want to modify record? ");
  scanf("%d", &loc);

  for(i = 0; i < loc - 1; i++)
  {	p = p->next; }

  printf("\nEnter name:");
  scanf("%s",p->stud.name);
  printf("\nEnter roll no.");
  scanf("%d",&p->stud.rollno);
  printf("\nRecord modified successfully!!");
return head;

}
/*MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
1

Enter records to be created3

Enter name:mohi

Enter roll no.2

Enter name:raji

Enter roll no.3

Enter name:jai

Enter roll no.4

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
2

------------------
Rollno		Name
------------------
2		mohi
3		raji
4		jai

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
3

Enter name:raja

Enter roll no.5

Enter 1 to insert at front,2 for middle,3 for end1

------------------
Rollno		Name
------------------
5		raja
2		mohi
3		raji
4		jai

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
3

Enter name:sumi

Enter roll no.6

Enter 1 to insert at front,2 for middle,3 for end2

Enter index to insert3

------------------
Rollno		Name
------------------
5		raja
2		mohi
6		sumi
3		raji
4		jai

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
3

Enter name:kishi

Enter roll no.7

Enter 1 to insert at front,2 for middle,3 for end3

------------------
Rollno		Name
------------------
5		raja
2		mohi
6		sumi
3		raji
4		jai
7		kishi

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
4

Enter 1 to delete at front,2 for middle,3 for end1

------------------
Rollno		Name
------------------
2		mohi
6		sumi
3		raji
4		jai
7		kishi

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
4

Enter 1 to delete at front,2 for middle,3 for end2

Enter index to delete3

------------------
Rollno		Name
------------------
2		mohi
6		sumi
4		jai
7		kishi

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
4

Enter 1 to delete at front,2 for middle,3 for end3

------------------
Rollno		Name
------------------
2		mohi
6		sumi
4		jai

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
5

------------------
Rollno		Name
------------------
4		jai
6		sumi
2		mohi

MENU :
1. Input records
2. Display record
3.Insert record
4. Delete record
5. Display backward
0. Exit
0
 *
 */
