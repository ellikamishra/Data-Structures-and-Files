/*
 ============================================================================
 Name        : linked2.c
 Author      : ellika
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct poly{
	int pow;
	int coef;
	struct poly *next;

}poly;
 poly *create(poly *head);
 poly *insert(poly *head,int pow1,int coef1);
 void display(poly *head);
 poly *add(poly *head1,poly *head2,poly *head3);
 poly *mul(poly *head1,poly *head2,poly *head4);
 void eval(poly *head1);
 int power(int x,int pow);

int main()
{ int ch;
  poly *head1=NULL;
  poly *head2=NULL;
  poly *head3=NULL;
  poly *head4=NULL;

  do{
   printf("\nEnter 1 to create poly,2 to add,3 multiply,4 to evalute,0 to exit");
   scanf("%d",&ch);
   switch(ch)
   { case 1: head1=create(head1);
             printf("\nPolynomial 1:\n");
             display(head1);

             head2=create(head2);
             printf("\nPolynomial 2:\n");
             display(head2);
             break;
   case 2:  head3=add(head1,head2,head3);
            printf("\nPolynomial 1:\n");
            display(head1);
            printf("\nPolynomial 2:\n");
            display(head2);
            printf("\nPolynomial after addition:\n");
            display(head3);
            break;

   case 3:     head4=mul(head1,head2,head4);
               printf("\nPolynomial 1:\n");
               display(head1);
               printf("\nPolynomial 2:\n");
               display(head2);
               printf("\nPolynomial after multiplication:\n");
               display(head4);
               break;
   case 4: eval(head1);
           break;

   }
   }while(ch!=0);

  return 0;
}

poly *create(poly *head)
{
	int n,i,pow1,coef1;
		printf("\nEnter no of terms of polynomial::");
		scanf("%d",&n);
		for(i=0;i<n;i++)//repeat for n terms
		{
			printf("\nEnter coefficient of %dth term::",i+1);
			scanf("%d",&coef1);
			printf("\nEnter exponent of %dth term::",i+1);
			scanf("%d",&pow1);
			head=insert(head,pow1,coef1);//inserting one by one coeff and exponent of polynomial
		}
		return head;
}

poly *insert(poly *head,int pow1,int coef1)
{ poly *q=NULL;
  poly *temp=NULL;
  poly *new=NULL;

  new=(poly *)malloc(sizeof(poly));
  new->pow=pow1;
  new->coef=coef1;
  if(head==NULL){
      head=new;
      new->next=head;
      return head;
}

  if(pow1>(head->pow))//inserting if power is greatest
  { temp=head;

    new->next=head;
    while((temp->next)!=head)
    { temp=temp->next;}
      temp->next=new;
      head=new;
      return head;
  }
  q=head;
  while(q->next!=head&&pow1<=q->next->pow)
  {
	  q=q->next;
  }

  if(new->pow==q->pow)
  {
	  q->coef=q->coef+coef1;

  }
  else
  { new->next=q->next;
    q->next=new;
  }
  return head;
  }

void display(poly* head)
{
	poly *temp;
	temp=head;
	do//traversing the whole list
	{
		printf("%dX^%d+",temp->coef,temp->pow);
		temp=temp->next;
	}while(temp!=head);
}

poly *add(poly *head1,poly *head2,poly *head3)
{ poly *temp=NULL;
  if(head1==NULL&&head2==NULL)
  {printf("Invalid addition of polynomials\n");
	return NULL;}
  if(head1!=NULL)
  { temp=head1;
    do{
    	head3=insert(head3,temp->pow,temp->coef);
    	temp=temp->next;
      }while(temp!=head1);
  }

  if(head2!=NULL)
  { temp=head2;
      do{
      	head3=insert(head3,temp->pow,temp->coef);
      	temp=temp->next;
        }while(temp!=head2);
    }

  return head3;

}

poly *mul(poly *head1,poly *head2,poly *head4)
{ poly *temp1=NULL;
  poly *temp2=NULL;

  if(head1==NULL&&head2==NULL)//if both lists are empty
  	{
  		printf("Invalid multiplication of polynomials\n");
  		return NULL;
  	}

  temp1=head1;
  do
  { temp2=head2;
	 do{

	  head4=insert(head4,(temp1->pow)+(temp2->pow),(temp1->coef)*(temp2->coef));
      temp2=temp2->next;



  }while(temp2!=head2);
   temp1=temp1->next;

  }while(temp1!=head1);

return head4;

}

void eval(poly *head1)
{ poly *temp=NULL;
  int sum=0,x;
  printf("\nEnter value of x");
  scanf("%d",&x);
  temp=head1;
do{ printf("\n%d*%d^%d:",temp->coef,x,temp->pow);
    sum=sum+(temp->coef)*power(x,temp->pow);
}while(temp!=head1);
printf("\nValue is:%d",sum);
}

int power(int x,int pow)
{ int i,y=1;
for(i=1;i<=pow;i++)
{
    y=y*x;
}
return y;
}

/*
 * Enter 1 to create poly,2 to add,3 multiply,4 to evalute,0 to exit1

Enter no of terms of polynomial::2

Enter coefficient of 1th term::3

Enter exponent of 1th term::4

Enter coefficient of 2th term::5

Enter exponent of 2th term::4

Polynomial 1:
8X^4+
Enter no of terms of polynomial::3

Enter coefficient of 1th term::3

Enter exponent of 1th term::5

Enter coefficient of 2th term::3

Enter exponent of 2th term::5

Enter coefficient of 3th term::6

Enter exponent of 3th term::7

Polynomial 2:
6X^7+6X^5+
Enter 1 to create poly,2 to add,3 multiply,4 to evalute,0 to exit2

Polynomial 1:
8X^4+
Polynomial 2:
6X^7+6X^5+
Polynomial after addition:
6X^7+6X^5+8X^4+
Enter 1 to create poly,2 to add,3 multiply,4 to evalute,0 to exit3

Polynomial 1:
8X^4+
Polynomial 2:
6X^7+6X^5+
Polynomial after multiplication:
48X^11+48X^9+
Enter 1 to create poly,2 to add,3 multiply,4 to evalute,0 to exit4

Enter value of x2

8*2^4:
Value is:128
Enter 1 to create poly,2 to add,3 multiply,4 to evalute,0 to exit0
 *
 *
 *
 *
 * */




