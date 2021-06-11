/*
 ============================================================================
 Name        : Assignment8.c
 Author      : ellika
 Roll no : 23221 f10
 Problem Statement:
 Implement Sparse matrix and perform following operations on it:1.Addition2.Simple Transpose
 3.Fast Transpose
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct sparse
{
	int rowid;
	int colid;
	int value;
}sparse;
void input(int mat[20][20],int,int);
void display(int mat[20][20],int,int);
void convert(int mat[20][20],int,int,sparse sp[]);
void display_sparse(sparse sp[]);
void Ftranspose(sparse[],sparse[]);
void Stranspose(sparse[],sparse[]);
void addsparse(sparse[],sparse[],sparse[]);
void init(sparse[]);
int getrow();
int getcol();

int main(void)
{
	sparse sp[20],sp2[20],result[20];
	int mat[20][20],row,col,choice,row2,col2,mat2[20][20];
	do{
	printf("\n\tMENU-\n1.Input and display normal matrix\n2.Convert and display sparse matrix\n3.Simple transpose\n"
			"4.Fast transpose\n5.Addition\n6.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1 : printf("\nMATRIX 1 :\n");
	         row = getrow();
	         col = getcol();
		     input(mat,row,col);
	         display(mat,row,col);
	        
	         break;

	case 2 : printf("\nMATRIX IN SPARSE FORM : \n");
	         convert(mat,row,col,sp);
             display_sparse(sp);
   	         break;

    case 3 : printf("\nSIMPLE TRANSPOSE : \n");
	         Stranspose(sp,result);
             display_sparse(result);
             break;
             
    case 4 : printf("\nFAST TRANSPOSE : \n");
	         Ftranspose(sp,result);
             display_sparse(result);
             break;
             
    case 5 : printf("\nMATRIX 2 :\n");
    		 printf("\nEnter matrix to be added : \n");
	         row2 = getrow();
	         col2 = getcol();
	         input(mat2,row2,col2);
	         display(mat2,row2,col2);
	         convert(mat2,row2,col2,sp2);
	         printf("\nMATRIX1 - : \n");
	         convert(mat,row,col,sp);
             display_sparse(sp);
             printf("\nMATRIX2 - : \n");
             display_sparse(sp2);
    	     addsparse(sp,sp2,result);
    	     printf("\n\nADDITION RESULT :\n");
             display_sparse(result);
             break;

	case 6 : return EXIT_SUCCESS;
	}
     }while(1);
}

int getrow()
{
	int row;
	printf("\nEnter row : ");
	scanf("%d",&row);
	return row;
}


int getcol()
{
	int col;
	printf("\nEnter column : ");
	scanf("%d",&col);
	return col;
}

void input(int mat[20][20],int row,int col)
{
    int i,j;

    printf("\nEnter matrix\n");
    for(i=0;i<row;i++)
    {
     for(j=0;j<col;j++)//for ith row, jth column element is scanned.
     {
        printf("\nEnter element [%d][%d] : ",i+1,j+1);
        scanf("%d",&mat[i][j]);
     }
    }
}

void display(int mat[20][20],int row,int col)
{
    int i,j;
    printf("\nMatrix:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
        printf("%d\t",mat[i][j]);//for ith row, jth column element is printed.
     }
     printf("\n");
    }
}

void convert(int mat[20][20],int row,int col,sparse sp[])
{
	int i,j,k=1;
	sp[0].rowid = row;
	sp[0].colid = col;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(mat[i][j]!=0){
				sp[k].rowid=i;
				sp[k].colid=j;
				sp[k++].value = mat[i][j];
			}
		}
	}
	sp[0].value = k-1;
}

void init(sparse sp[])
{   int  i;
	 for(i=1;i<=sp[0].value;i++)
	 {
		  sp[i].colid=-1;  		//initialise everything to -1
		  sp[i].rowid=-1;
		  sp[i].value =-1;
	 }
}

void display_sparse(sparse sp[])
{
	int i;
	printf("\n---------------------------------------------------------------------------");
	printf("\nINDEX  ROWID  COLID  VALUE\n");
	printf("\n---------------------------------------------------------------------------\n");
	for(i=0;i<=sp[0].value;i++){
		printf("%d\t%d\t%d\t%d\n",i,sp[i].rowid,sp[i].colid,sp[i].value);
	}
	printf("\n---------------------------------------------------------------------------");
}

void Stranspose(sparse sp1[],sparse sp2[])
{
	int i,j,k=1,num_terms;
	sp2[0].rowid = sp1[0].colid;
	sp2[0].colid = sp1[0].rowid;
	sp2[0].value = sp1[0].value;
	
	num_terms = sp1[0].value;
	for(i=0;i<sp1[0].colid;i++){
		for(j=1;j<=num_terms;j++){
			//if colid of current triple==i then insert current triple in sp2
			if(i==sp1[j].colid){
				sp2[k].rowid = i;
				sp2[k].colid = sp1[j].rowid;
				sp2[k].value = sp1[j].value;
				k++;
			}
		}
	}
}

void Ftranspose(sparse sp1[],sparse sp2[])
{	
	int row_terms[20],start_pos[20];
	int i,j,p,k,num_terms,num_cols;
	num_cols = sp1[0].colid;
	num_terms = sp1[0].value;
	sp2[0].rowid = sp1[0].colid;
	sp2[0].colid = sp1[0].rowid;
	sp2[0].value = sp1[0].value;
	
	if(num_terms>0){
		
		for(i=0;i<num_cols;i++)  row_terms[i]=0; 
		for(i=1;i<=num_terms;i++)  row_terms[sp1[i].colid]++; //This array stores 1 in position which has value in col 
		
		start_pos[0] = 1;//init
	
		for(i=1;i<num_cols;i++)
			start_pos[i] = start_pos[i-1] + row_terms[i-1];
		printf("\nSTARTING POSITION- ");
		printf(" [ ");
		for(i=0;i<num_cols;i++) printf("\t%d,",start_pos[i]);
		printf(" ]\n");
			init(sp2);
			display_sparse(sp2);
		for(i=1;i<=num_terms;i++){
			j = start_pos[sp1[i].colid]++;
			printf("\nSTARTING POSITION-");
			printf(" [ ");
			for(k=0;k<num_cols;k++)
			printf("\t%d,",start_pos[k]);
			printf("]");
			printf("\nPASS %d-\n",i);
			if(i>num_terms)
			printf("\nFAST TRANSPOSE-\n");
			sp2[j].rowid = sp1[i].colid;
		    sp2[j].colid = sp1[i].rowid;
		    sp2[j].value = sp1[i].value;
		    display_sparse(sp2);
		    printf("\n");
		}
		
	}
}

void addsparse(sparse sp1[],sparse sp2[],sparse result[])

{
	int num_terms1,num_terms2,i,j,k,pass=1;
	num_terms1 = sp1[0].value;
	num_terms2 = sp2[0].value;
	i=j=k=1;
	result[0].rowid = sp1[0].rowid;
	result[0].colid = sp1[0].colid;
	init(result);
	printf("\nPASSWISE OUTPUT FOR ADDITION OF MATRICES 1 AND 2 :\n");
	while(i<=num_terms1 && j<=num_terms2)
	{
		if(sp1[i].rowid < sp2[j].rowid){
			result[k].rowid = sp1[i].rowid;
			result[k].colid = sp1[i].colid;
			result[k].value = sp1[i].value;
			k++;
			i++;
			printf("\nPASS %d-\n",pass++);
			display_sparse(result);
		}
		
		else if(sp2[j].rowid < sp1[i].rowid){
        //row numbers are not equal
			result[k].rowid = sp2[j].rowid;
			result[k].colid = sp2[j].colid;
			result[k].value = sp2[j].value;	       
			k++;
			j++;
			printf("\nPASS %d-\n",pass++);
			display_sparse(result);      
		}
		
		else if(sp1[i].colid < sp2[j].colid){
		//row numbers are equal,compare column				         
			result[k].rowid = sp1[i].rowid;       
			result[k].colid = sp1[i].colid;
			result[k].value = sp1[i].value;
			k++;
			i++;
			printf("\nPASS %d-\n",pass++);
			display_sparse(result);
		}
					
		else if(sp2[j].colid < sp1[i].colid){
		//row numbers are equal,compare column				         
			result[k].rowid = sp2[j].rowid;       
			result[k].colid = sp2[j].colid;
			result[k].value = sp2[j].value;
			k++;
			j++;
			printf("\nPASS %d-\n",pass++);
			display_sparse(result);
		}
				
		else {
		//row and column numbers are equal				         
			result[k].rowid = sp1[i].rowid;       
			result[k].colid = sp1[i].colid;
			result[k].value = sp1[i].value + sp2[j].value;
			k++;
			i++;
			j++;
			printf("\nPASS %d-\n",pass++);
			display_sparse(result);
		}
	}

		while(i<=num_terms1) //copy remaining terms from sp1
		    {
			result[k].rowid = sp1[i].rowid;
			result[k].colid = sp1[i].colid;
			result[k].value = sp1[i].value;
		    i++;
		    k++;
			printf("\nPASS %d-\n",pass++);
		    display_sparse(result);
		    }
		while(j<=num_terms2) //copy remaining terms from sp2
			{
		result[k].rowid = sp2[j].rowid;
		result[k].colid = sp2[j].colid;
		result[k].value = sp2[j].value;
		j++;
		k++;
		printf("\nPASS %d-\n",pass++);
		display_sparse(result);
			}
   
       result[0].value = k-1; //set numberof terms in sp3
}

/*
	                                                                                                                                                         
        MENU-                                                                                                                                             
1.Input and display normal matrix                                                                                                                         
2.Convert and display sparse matrix                                                                                                                       
3.Simple transpose                                                                                                                                        
4.Fast transpose                                                                                                                                          
5.Addition                                                                                                                                                
6.Exit                                                                                                                                                    
1                                                                                                                                                         
                                                                                                                                                          
MATRIX 1 :                                                                                                                                                
                                                                                                                                                          
Enter row : 4                                                                                                                                             
                                                                                                                                                          
Enter column : 4                                                                                                                                          
                                                                                                                                                          
Enter matrix                                                                                                                                              
                                                                                                                                                          
Enter element [1][1] : 1                                                                                                                                  
                                                                                                                                                          
Enter element [1][2] : 2                                                                                                                                  
                                                                                                                                                          
Enter element [1][3] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [1][4] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [2][1] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [2][2] : 0                   

                                                                                                                                                          
Enter element [2][3] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [2][4] : 5                                                                                                                                  
                                                                                                                                                          
Enter element [3][1] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [3][2] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [3][3] : 4                                                                                                                                  
                                                                                                                                                          
Enter element [3][4] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [4][1] : 7                                                                                                                                  
                                                                                                                                                          
Enter element [4][2] : 90                                                                                                                                 
                                                                                                                                                          
Enter element [4][3] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [4][4] : 0                                                                                                                                  
                                                                                                                                                          
Matrix:                                                                                                                                                   
1       2       0       0                                                                                                                                 
0       0       0       5                                                                                                                                 
0       0       4       0                         
7       90      0       0                                                                                                                                 
                                                                                                                                                          
        MENU-                                                                                                                                             
1.Input and display normal matrix                                                                                                                         
2.Convert and display sparse matrix                                                                                                                       
3.Simple transpose                                                                                                                                        
4.Fast transpose                                                                                                                                          
5.Addition                                                                                                                                                
6.Exit                                                                                                                                                    
2                                                                                                                                                         
                                                                                                                                                          
MATRIX IN SPARSE FORM :                                                                                                                                   
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       0       1       2                                                                                                                                 
3       1       3       5                                                                                                                                 
4       2       2       4                                                                                                                                 
5       3       0       7                                                                                                                                 
6       3       1       90                                                                                                                                
                                                                                                                                                         
---------------------------------------------------------------------------                                                                               
        MENU-                                                                                                                                             
1.Input and display normal matrix                                                                                                                         
2.Convert and display sparse matrix                                                                                                                       
3.Simple transpose                                                                                                                                        
4.Fast transpose                                                                                                                                          
5.Addition                                                                                                                                                
6.Exit                                                                                                                                                    
4                                                                                                                                                         
                                                                                                                                                          
FAST TRANSPOSE :                                                                                                                                          

STARTING POSITION- [    1,      3,      5,      6,] 
                                                                                                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       -1      -1      -1                                                                                                                                
2       -1      -1      -1                                                                                                                                
3       -1      -1      -1                                                                                                                                
4       -1      -1      -1                                                                                                                                
5       -1      -1      -1                                                                                                                                
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
STARTING POSITION- [    2,      3,      5,      6,]                                                                                                       
PASS 1-                                                                                                                                                   
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       -1      -1      -1                                                                                                                                
3       -1      -1      -1                                                                                                                                
4       -1      -1      -1                                                                                                                                
5       -1      -1      -1                                                             
5       -1      -1      -1                                                                                                                                
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
                                                                                                                                                          
STARTING POSITION- [    2,      4,      5,      6,]                                                                                                       
PASS 2-                                                                                                                                                   
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       -1      -1      -1                                                                                                                                
3       1       0       2                                                                                                                                 
4       -1      -1      -1                                                                                                                                
5       -1      -1      -1                                                                                                                                
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
                                                                                                                                                          
STARTING POSITION- [    2,      4,      5,      7,]                                                                                                       
PASS 3-                                                                                                                                                   
                                                                                                                                                          
---------------------------------------------------------------------------                                                                        
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       -1      -1      -1                                                                                                                                
3       1       0       2                                                                                                                                 
4       -1      -1      -1                                                                                                                                
5       -1      -1      -1                                                                                                                                
6       3       1       5                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
                                                                                                                                                          
STARTING POSITION- [    2,      4,      6,      7,]                                                                                                       
PASS 4-                                                                                                                                                   
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       -1      -1      -1                                                                                                                                
3       1       0       2                                                                                                                                 
4       -1      -1      -1                   
5       2       2       4                                                                                                                                 
6       3       1       5                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
                                                                                                                                                          
STARTING POSITION- [    3,      4,      6,      7,]                                                                                                       
PASS 5-                                                                                                                                                   
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       0       3       7                                                                                                                                 
3       1       0       2                                                                                                                                 
4       -1      -1      -1                                                                                                                                
5       2       2       4                                                                                                                                 
6       3       1       5                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
                                                                                                                                                          
STARTING POSITION- [    3,      5,      6,      7,]                                                                                                       
PASS 6-                                                                                                                                                   
                                                             
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       0       3       7                                                                                                                                 
3       1       0       2                                                                                                                                 
4       1       3       90                                                                                                                                
5       2       2       4                                                                                                                                 
6       3       1       5                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               

FAST TRANSPOSE RESULT-
                                                                                                                                                
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       0       3       7                                                                                                                                 
3       1       0       2                                                                                                                                 
4       1       3       90                                                                                                                                
5       2       2       4                                                                                                                                 
6       3       1       5                                   
---------------------------------------------------------------------------                                                                               
        MENU-                                                                                                                                             
1.Input and display normal matrix                                                                                                                         
2.Convert and display sparse matrix                                                                                                                       
3.Simple transpose                                                                                                                                        
4.Fast transpose                                                                                                                                          
5.Addition                                                                                                                                                
6.Exit                                                                                                                                                    
3                                                                                                                                                         
                                                                                                                                                          
SIMPLE TRANSPOSE :                                                                                                                                        
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       1                                                                                                                                 
2       0       3       7                                                                                                                                 
3       1       0       2                                                                                                                                 
4       1       3       90                                                                                                                                
5       2       2       4                                                                                                                                 
6       3       1       5                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
        MENU-                                                                                                                                             
1.Input and display normal matrix                                                                                                                         
2.Convert and display sparse matrix                                                                                                                       
3.Simple transpose                           
4.Fast transpose                                                                                                                                          
5.Addition                                                                                                                                                
6.Exit        
5
                                                                                                                                                
Enter matrix to be added :                                                                                                                                
                                                                                                                                                          
Enter row : 4                                                                                                                                             
                                                                                                                                                          
Enter column : 4                                                                                                                                          
                                                                                                                                                          
Enter matrix                                                                                                                                              
                                                                                                                                                          
Enter element [1][1] : 1                                                                                                                                  
                                                                                                                                                          
Enter element [1][2] : 1                                                                                                                                  
                                                                                                                                                          
Enter element [1][3] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [1][4] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [2][1] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [2][2] : 9                                                                                                                                  
                                                                                                                                                          
Enter element [2][3] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [2][4] : 4                                                                                                                                  
                                                                                                                                                          
Enter element [3][1] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [3][2] : 1                                 
                                                                                                                                            
Enter element [3][3] : 3                                                                                                                                  
                                                                                                                                                          
Enter element [3][4] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [4][1] : 6                                                                                                                                  
                                                                                                                                                          
Enter element [4][2] : 0                                                                                                                                  
                                                                                                                                                          
Enter element [4][3] : 4                                                                                                                                  
                                                                                                                                                          
Enter element [4][4] : 0                                                                                                                                  
                                                                                                                                                          
Matrix:                                                                                                                                                   
1       1       0       0                                                                                                                                 
0       9       0       4                                                                                                                                 
0       1       3       0                                                                                                                                 
6       0       4       0                                                                                                                                 
                                                                                                                                                          
MATRIX1 - :                                                                                                                                               
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                          
1       0       0       1                                                                                                                                 
2       0       1       2                                                                                                                                 
3       1       3       5                                                                                                                                 
4       2       2       4                                                                                                                                 
5       3       0       7                                                                                                                                 
6       3       1       90                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
MATRIX2 - :                                                                                                                                               
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       8                                                                                                                                 
1       0       0       1                                                                                                                                 
2       0       1       1                                                                                                                                 
3       1       1       9                                                                                                                                 
4       1       3       4                                                                                                                                 
5       2       1       1                                                                                                                                 
6       2       2       3                                                                                                                                 
7       3       0       6                                                                                                                                 
8       3       2       4                           
                                                                                                                                                         
---------------------------------------------------------------------------                                                                               
PASSWISE OUTPUT FOR ADDITION OF MATRICES 1 AND 2 :                                                                                                        

PASS 1-                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                                                                                                                 
2       -1      -1      -1                                                                                                                                
3       -1      -1      -1                                                                                                                                
4       -1      -1      -1                                                                                                                                
5       -1      -1      -1                                                                                                                                
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               

PASS 2-
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                                                                                                                 
2       0       1       3                                                                                                                                 
3       -1      -1      -1                         
4       -1      -1      -1                                                                                                                                
5       -1      -1      -1                                                                                                                                
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------        

PASS 3-                                                                       
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                                                                                                                 
2       0       1       3                                                                                                                                 
3       1       1       9                                                                                                                                 
4       -1      -1      -1                                                                                                                                
5       -1      -1      -1                                                                                                                                
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------     

PASS 4-                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                                                                                                                 
2       0       1       3                           
3       1       1       9                                                                                                                                 
4       1       3       9                                                                                                                                 
5       -1      -1      -1                                                                                                                                
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------        

PASS 5-                                                                       
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                                                                                                                 
2       0       1       3                                                                                                                                 
3       1       1       9                                                                                                                                 
4       1       3       9                                                                                                                                 
5       2       1       1                                                                                                                                 
6       -1      -1      -1                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------       

PASS 6-                                                                        
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                   
3       1       1       9                                                                                                                                 
4       1       3       9                                                                                                                                 
5       2       1       1                                                                                                                                 
6       2       2       7                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------          

PASS 7-                                                                     
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                                                                                                                 
2       0       1       3                                                                                                                                 
3       1       1       9                                                                                                                                 
4       1       3       9                                                                                                                                 
5       2       1       1                                                                                                                                 
6       2       2       7                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------    

PASS 8-
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       6                                                                                                                                 
1       0       0       2                                                                                                                                 
2       0       1       3                                                                                                                                 
3       1       1       9                                                                                                                                 
4       1       3       9                                                                                                                                 
5       2       1       1                                                                                                                                 
6       2       2       7                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
                                                                                                                                                          
ADDITION RESULT :                                                                                                                                         
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
INDEX  ROWID  COLID  VALUE                                                                                                                                
                                                                                                                                                          
---------------------------------------------------------------------------                                                                               
0       4       4       9                                                                                                                                 
1       0       0       2                                                                                                                                 
2       0       1       3                                                                                                                                 
3       1       1       9                                                                                                                                 
4       1       3       9                                                                                                                                 
5       2       1       1                                                                                                                                 
6       2       2       7                    
7       3       0       13                                                                                                                                
8       3       1       90                                                                                                                                
9       3       2       4                                                                                                                                 
                                                                                                                                                          
---------------------------------------------------------------------------                                                                                                                                                                                                                
                                                                                                                                                          
        MENU-                                                                                                                                             
1.Input and display normal matrix                                                                                                                         
2.Convert and display sparse matrix                                                                                                                       
3.Simple transpose                                                                                                                                        
4.Fast transpose                                                                                                                                          
5.Addition                                                                                                                                                
6.Exit                                                                                                                                                    
                                                                                                                                                          
                                                                                                                                                          
...Program finished with exit code 9                                                                                                                      
Press ENTER to exit console.                      
 */



