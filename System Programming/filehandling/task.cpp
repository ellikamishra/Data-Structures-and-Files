#include<bits/stdc++.h>

#include<fstream>
using namespace std;

int main()
{
	string line1,line2;

	
	fstream file1,file2;   //file pointer 
	file1.open("input.txt");
	cout<<"\nInput file-\n";
	while(getline(file1,line1)) //print contents of input file and table
	{
		cout<<line1<<"\n";
	}

	file1.close();
	file2.open("table.txt");
	cout<<"\nTable-\n";
	while(getline(file2,line2))
	{
		cout<<line2<<"\n";
	}

	file2.close();
	file1.open("input.txt");
	cout<<"\nTokens-\n";
	while(getline(file1,line1))  //tokenise the contents of input file
	{	char* data=new char(line1.length());
		int i=0;
		strcpy(data,line1.c_str());
		while(strtok_r(data," ",&data)){           //count tokens for each line
			
			i++;
		}
		
		cout<<line1<<"-"<<i<<"\n";
		
        
	}
	file1.close();
	file1.open("input.txt");
	file2.open("table.txt");
	cout<<"\nOp code-\n";
	while(getline(file1,line1))               //find op code from table
	{  
		
		int pos1=line1.find(" ");

		while(getline(file2,line2))
		{   
			int pos2=line2.find(" ");
			
			if(line1.substr(0,pos1)==line2.substr(0,pos2)&&line2.length()>pos2)           //if substring word found with code print 
			{
				cout<<line1.substr(0,pos1)<<"-"<<line2.substr(pos2+1)<<"\n";
				

				break;
			}
			
		}
		file2.close();
		file2.open("table.txt");

	}
	

	file1.close();
	file2.close();
	return 0;

}

/*
OUTPUT-
Input file-
START 2000     
MOVER  AREG A    
ADD AREG X  
DIV BREG A 
XYZ   SUB  DREG  A
STOP
A  DC  ‘10’
X  DS   100
END

Table-
ADD 01
SUB 02
DIV 03
MOVER 04
MOVEM 05
JUMP
STOP
START 11


Tokens-
START 2000     -2
MOVER  AREG A    -3
ADD AREG X  -3
DIV BREG A -3
XYZ   SUB  DREG  A-4
STOP-1
A  DC  ‘10’-3
X  DS   100-3
END-1

Op code-
START-11
MOVER-04
ADD-01
DIV-03













*/