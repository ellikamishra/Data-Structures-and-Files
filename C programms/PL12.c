
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node //Defining structure of GLL
{
	struct Node *next; //Structure pointer to next node
	int flag;
	union
	{
		char data[MAX];
		struct Node *dlink;
	}u;
}Node;

Node* getnode() //Creates node
{
	Node *new1=(Node*)malloc(sizeof(Node)); //Allocates memory dynamically
	new1->next=NULL;                  //Next of new is set to NULL
	new1->u.dlink=NULL;            //Downlink set of new1 to NULL
	return new1;
}
Node* create_GLL(Node *head,char str[])
{
	int i,j;
	Node *temp; //structure pointer
	for(i=0;str[i]!=NULL;)
	{
		if(str[i]=='(' && i==0)
		{
			 head=getnode(); //new node as head of list
			 temp=head;                  //temp set to head
		}
		else
		{
		    temp->next=getnode();        //next of temp set to new node
			temp=temp->next;   //temp set to next of temp
		}
		i++;        //Increments i by 1
		j=0;
		while(str[i]!=',' && str[i]!='(' && str[i]!=')')
		{
			temp->u.data[j]=str[i]; //Stores data into GLL's node

			i++;
			j++;
		}
             temp->u.data[j]=NULL;
             temp->flag=0;
             if(str[i]=='(') //If sublist is to be started
             {
            	temp->next=getnode();      //new node assigned to next of temp
            	 temp=temp->next;    //temp set to next of temp
            	 temp->flag=1;
            	 temp->u.dlink=create_GLL(NULL,&str[i]);    //Recursive function call
            	 while(str[i]!=')')//Repeat till not end of sublist
            		 i++;
				i++;
             }
             if(str[i]==')')
             {
            	 return head; //Returns head
             }
      }
}

void display(Node *temp)  //Display
{
	static int depth;
	depth++;
	int i;
	if(temp==NULL) //If temp is NULL
	{
		if(depth==1) //Checks if depth is 1
		 	printf("\nList is empty\n");
		else
			printf("\nSublist is empty\n");
	}
	else
	{
		while(temp!=NULL) //Continues till temp doesn't become NULL
		{
			if(temp->flag==0) //Checks flag's status
			{
				printf("\n");
				for(i=1;i<depth;i++)
					printf("  ");
				printf("%s",temp->u.data); //Prints data of node
			}
			else
				  display(temp->u.dlink); //Recursive call to display function
			temp=temp->next;
		}
	}
	depth--;
	printf("\n");
}

int main()
{
	int ch;
	char str[50];
	Node *head=NULL; //Sets head of GLL to NULL
	do
	{
	   printf("\n***MENU***\n1.Input\n2.Display\n3.Exit\n");
	   printf("\nPlease enter your choice => ");
	   scanf("%d",&ch); //Inputs choice
	   switch(ch)
	   {
	     case 1: //Input
		    printf("\nEnter string => ");
		    while(getchar()!='\n');
		    gets(str);
		    head=create_GLL(head,str);
	     	break;

		 case 2: //Display
	    	printf("\n***GENERALIZED LINKED LIST***\n");
	    	display(head);

	    	break;

		 case 3: //Exits
	    	return 0;

	     default: //If no case matches
	     	printf("\nInvalid Choice!\n");
	     	break;
	   }
	}while(1);
}

/*
OUTPUT


***MENU***
1.Input
2.Display
3.Exit

Please enter your choice => 1

Enter string => (1. Computer Evolution(1.1 Von Neumann Architecture,1.2 Harvard Architecture),2. CPU(2.1 CPU Architecture,2.2 Design of ALU),3. The Control Unit(3.1 Single Bus Processor,3.2 Micro Operations),4. Memory And I/O Operations(4.1 Memory Hierarchy,4.2 Cache Memory,4.3 Cache Coherence))

***MENU***
1.Input
2.Display
3.Exit

Please enter your choice => 2

***GENERALIZED LINKED LIST***

1. Computer Evolution
  1.1 Von Neumann Architecture
  1.2 Harvard Architecture

2. CPU
  2.1 CPU Architecture
  2.2 Design of ALU

3. The Control Unit
  3.1 Single Bus Processor
  3.2 Micro Operations

4. Memory And I/O Operations
  4.1 Memory Hierarchy
  4.2 Cache Memory
  4.3 Cache Coherence


***MENU***
1.Input
2.Display
3.Exit

Please enter your choice => 3
*/
