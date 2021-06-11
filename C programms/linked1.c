/*
 ============================================================================
 Name        : linked1.c
 Author      : ellika
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node{

int data;
struct node *next;

}node;
node *create(node *head);
void display(node *head);
node *insert(node *head);
node *delete(node *head);
node *revert(node *head);
void reverse(node *head);
int main()
{   int ch;
    node *head=NULL;
   do
   {printf("\nEnter choice:1. to create\n2. to display\n3. to insert\n4. to delete\n5.to revert\n6.to display reverse\n0 to exit)");
   scanf("%d",&ch);
    switch(ch)
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
        case 5: head=revert(head);
                display(head);
                break;
        case 6: printf("\nReversed list:- ");
        	    reverse(head);
                break;

    }


}while(ch!=0);
return 0;
}

node *create(node *head)
{ int n;
  node *p;

  printf("\nEnter no. of elements");
  scanf("%d",&n);
  printf("\nEnter the elements");
  head=(node*)malloc(sizeof(node));
//  scanf("%d",&head->data);
//  head->next=NULL;
  p=head;
  for(int i=0;i<n;i++)
  {   p->next=(node*)malloc(sizeof(node));
      scanf("%d",&p->data);
      if(i==n-1)
      {p->next=NULL;}
      else
      {p=p->next;}
   }
   return head;
}

void display(node *head)
{ int n=0;
  node *curr=head;
  printf("\nElements:");
  while(curr!=NULL)
  {
      printf("%d\t",curr->data);
      curr=curr->next;
      n++;
  }
  printf("\nNo. of nodes:- %d",n);

}

node *insert(node *head)
{ int ch,index,m;

 node *currnode=head;
  node *newnode=(node*)malloc(sizeof(node));


   printf("\nEnter 1 to insert at start,2 for middle,3 for end,0 to exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\nEnter value to insert");
                scanf("%d",&m);
                newnode->data=m;
                newnode->next=head;
                head=newnode;
                break;
        case 2: printf("\nEnter index to insert at");
                scanf("%d",&index);
                printf("\nEnter value to insert");
                scanf("%d",&m);
                newnode->data=m;
                while(index-2!=0)
                {
                    index--;
                    currnode=currnode->next;

                }
                newnode->next=currnode->next;
                currnode->next=newnode;
                break;
         case 3: printf("\nEnter value to insert");
                 scanf("%d",&m);
                 newnode->data=m;
                 while(currnode->next!=NULL)
                 {
                     currnode=currnode->next;
                 }
                newnode->next=currnode->next;
                currnode->next=newnode;
                break;

    }
    return head;
}

node *delete(node *head)
{ int ch,index;
  node *temp=head;
  node *prev=head;
  printf("\nEnter 1 to delete first,2 for middle,3 for end,0 to exit");
  scanf("%d",&ch);
    switch(ch)
    {
      case 1: temp=head;
              head=head->next;
              free(temp);
              break;
      case 2: printf("\nEnter index for deletion");
              scanf("%d",&index);
              while(index-1!=0)
              { prev=temp;
                temp=temp->next;
                index--;
              }
              prev->next=temp->next;
              free(temp);
              break;
     case 3: while(temp->next!=NULL)
            { prev=temp;
              temp=temp->next;
            }
            prev->next=temp->next;
            free(temp);
            break;

        }
    return head;
}

node *revert(node *head)
{  node *curr;
   node *temp;
   node *result;
   temp=NULL;
   result=NULL;
   curr=head;
   if(head->next==NULL)
	   return head;
   while(curr!=NULL)
   { temp=curr->next;
	 curr->next=result;
	 result=curr;
	 curr=temp;
	}
   head=result;
   return head;
}

void reverse(node *head)
{ if(head!=NULL)
{reverse(head->next);
 printf("%d\t",head->data);
}
}

/*
 * Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)1

Enter no. of elements3

Enter the elements1
2
3

Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)2

Elements:1	2	3
No. of nodes:- 3
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)3

Enter 1 to insert at start,2 for middle,3 for end,0 to exit1

Enter value to insert4

Elements:4	1	2	3
No. of nodes:- 4
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)3

Enter 1 to insert at start,2 for middle,3 for end,0 to exit2

Enter index to insert at3

Enter value to insert5

Elements:4	1	5	2	3
No. of nodes:- 5
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)3

Enter 1 to insert at start,2 for middle,3 for end,0 to exit3

Enter value to insert6

Elements:4	1	5	2	3	6
No. of nodes:- 6
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)4

Enter 1 to delete first,2 for middle,3 for end,0 to exit1

Elements:1	5	2	3	6
No. of nodes:- 5
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)4

Enter 1 to delete first,2 for middle,3 for end,0 to exit2

Enter index for deletion3

Elements:1	5	3	6
No. of nodes:- 4
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)4

Enter 1 to delete first,2 for middle,3 for end,0 to exit3

Elements:1	5	3
No. of nodes:- 3
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)5

Elements:3	5	1
No. of nodes:- 3
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)2

Elements:3	5	1
No. of nodes:- 3
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)6

Reversed list:- 1	5	3
Enter choice:1. to create
2. to display
3. to insert
4. to delete
5.to revert
6.to display reverse
0 to exit)0
 *
 */











