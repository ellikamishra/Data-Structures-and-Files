#include<bits/stdc++.h>

#include<fstream>
using namespace std;
/*
Structure for storing location counter,opcode,operand1 and operand2.
*/
struct Icval{

    int lc=0;
    string opcode="";
    string opr2="";
    int opr1=0;
};
/*
Array of Intermediate code lines
*/
Icval ic_lines[50];
unordered_map<string,string>mp1;    //mp1 for purpose of hashing language strings
unordered_map<string,int>symtable;  //symbol table as map with symbol and location
unordered_map<string,int>ltable;    //literal table as map with symbol and location
vector<string>registers={"AREG","BREG","CREG","DREG","LT","GT"};    //vector of registers and conditional codes
int main()
{
    string line1;
    fstream file1;
    file1.open("input2.txt");
    if(file1.fail())
    {
        cout<<"Error!";
    }else{
	cout<<"\nInput file-\n";
	while(getline(file1,line1)) //print contents of input file and table
	{
		cout<<line1<<"\n";
	}
    }
    file1.close();
    file1.open("HashTable.txt");
    if(file1.fail())
    {
        cout<<"Error!";
    }else{
	    cout<<"\nTable file-\n";
    int index=1;

	while(getline(file1,line1)) 
	{
		cout<<line1<<"\n";
        int pos1=line1.find(" ");
    

        mp1.insert(make_pair(line1.substr(0,pos1),line1));      //mapping to respective information values in mp1 map.
        
	}

	file1.close();
    cout<<"\nHashed values-\n";
    for(auto it=mp1.begin();it!=mp1.end();it++)
    {   
        cout<<it->first<<"-"<<it->second<<"\n";
    }
    file1.open("input2.txt");
    int j=0,size=0,i;
    string s2;

    while(getline(file1,line1))  //readong input file to generate intermediate code
	{	char* data=new char(line1.length());
		// int i=0;
		strcpy(data,line1.c_str());
        for(int i=0;i<4;i++)        //counter to check for 4 possible tokens-lc,opcode,opr1,opr2
        {   
            char* s=strtok_r(data," ",&data);       //tokenizing  string
            if(i==0){
                
                if(j==0){
                    continue;
                }else{
                    ic_lines[j].lc=ic_lines[j-1].lc+size;       //set lc to previous location + size of previous instruction
                    if(s!="-"){
                        if(symtable.find(s)!=symtable.end()){
                        symtable.find(s)->second=ic_lines[j].lc;
                        }else{
                        symtable.insert(make_pair(s,ic_lines[j].lc));
                        }
                    }else{
                        continue;
                    }
                    
                }
                
            }else if(i==1){         //finding opcode,instruction type and size of instruction 
                auto it=mp1.find(s);
                if(it!=mp1.end()){
                    if(s=="LTORG"){
                        for(auto it1=ltable.begin();it1!=ltable.end();it1++)
                        {
                            it1->second=distance(ltable.begin(),it1)+1+ic_lines[j].lc;
                        }
                        
                    }
                    s2=it->second;
                    int pos1=s2.find(" ");
                    ic_lines[j].opcode=s2.substr(pos1+6,3)+','+s2.substr(pos1,3);
                    if(s2.substr(pos1+6,3)=="AD"){
                        continue;
                    }
                size=stoi(s2.substr(pos1+3,3));     //size is set
                }else{
                    cout<<"\nInvalid opcode";
                }
                
                
                
            }else if(i==2)
            {   if(*s!='-')
                {
                    ic_lines[j].opr1=(find(registers.begin(),registers.end(),s)-registers.begin())+1;   //finding registers or conditional code index value from vector
                }
                
            }else{
                
                string s3(s);           //handeling symbols and literals 
                
                if(isdigit(*s)){        //check if constant
                    ic_lines[j].opr2="C,"+s3;
                    
                }else if(isupper(*s)){      //check if Capital
                    
                    if(symtable.find(s3)==symtable.end()){
                        symtable.insert(make_pair(s3,-1));
                    }
                    ic_lines[j].opr2="S,"+to_string(distance(symtable.begin(),symtable.find(s3))+1);
                    symtable.insert(make_pair(s3,-1));
                }else{      //else it is literal
                    if(*s!='-'){
                    if(ltable.find(s3)==ltable.end()){
                        ltable.insert(make_pair(s3,-1));
                    }
                    ic_lines[j].opr2="L,"+to_string(distance(ltable.begin(),ltable.find(s3)));
                    }
                }
                if(j==0)
                {
                    ic_lines[j].lc=stoi(s);
                }
                
            }
            
        }
		
        j++;        //update ic array index
	}
    cout<<"\n-------------------------------------------";
    cout<<"\nLC\tType-Code\tOp1\tOp2\n";
    for(i=0;i<j;i++)
 
    {
       cout<<ic_lines[i].lc<<"\t"<<ic_lines[i].opcode<<"\t\t"<<ic_lines[i].opr1 <<"\t"<<ic_lines[i].opr2<<"\n";
    }
    cout<<"\n--------------------------------------------";
    cout<<"\n---SYMBOL TABLE---\n";
    cout<<"Symbol\t\tAddress\n";
    for(auto it=symtable.begin();it!=symtable.end();it++)
    {   
        cout<<it->first<<"\t\t"<<it->second<<"\n";
    }
    cout<<"\n---LITERAL TABLE---\n";
    cout<<"Literal\t\tAddress\n";
    for(auto it=ltable.begin();it!=ltable.end();it++)
    {   if(it->second==-1)
            it->second=ic_lines[j-1].lc+(distance(ltable.begin(),it));      //if literal address unassigned  
        cout<<it->first<<"\t\t"<<it->second<<"\n";
    }
    file1.close();
    
    }
    return 0;
}

/****OUTPUT****
 * 
 * 
 * Input file-
- START - 2000     
- MOVER AREG A    
- ADD AREG X  
- DIV BREG A 
XYZ SUB DREG A
- BC LT XYZ
- STOP - -
A DC - ‘10’
X DS - 100
- END - -

Table file-
ADD 01 02 IS 2 
SUB 02 02 IS 2
MULT 03 02 IS 2 
DIV 08 02 IS 2 
BC 07 02 IS 2 
READ 09 01 IS 1 
PRINT 10 01 IS 1 
START 01 00 AD 0
ORIGIN 02 00 AD 1 
LTORG 03 00 AD 0 
END 04 00 AD 0
EQU 05 00 AD 1 
STOP 00 01 IS 0 
MOVER 04 03 IS 2 
MOVEM 05 04 IS 2 
DC 01 01 DL 1 
DS 02 01 DL 1 

Hashed values-
DS-DS 02 01 DL 1 
DC-DC 01 01 DL 1 
MOVEM-MOVEM 05 04 IS 2 
MOVER-MOVER 04 03 IS 2 
ADD-ADD 01 02 IS 2 
MULT-MULT 03 02 IS 2 
END-END 04 00 AD 0
DIV-DIV 08 02 IS 2 
BC-BC 07 02 IS 2 
STOP-STOP 00 01 IS 0 
READ-READ 09 01 IS 1 
PRINT-PRINT 10 01 IS 1 
SUB-SUB 02 02 IS 2
START-START 01 00 AD 0
ORIGIN-ORIGIN 02 00 AD 1 
EQU-EQU 05 00 AD 1 
LTORG-LTORG 03 00 AD 0 

-------------------------------------------
LC      Type-Code       Op1     Op2
2000     AD, 01         0       C,2000
2000     IS, 04         1       S,1
2003     IS, 01         1       S,2
2005     IS, 08         2       S,1
2007     IS, 02         4       S,2
2009     IS, 07         5       S,1
2011     IS, 00         0
2012     DL, 01         0       L,1
2013     DL, 02         0       C,100
2014     AD, 04         0

--------------------------------------------
---SYMBOL TABLE---
Symbol          Address
XYZ             2007
A               2012
X               2013
-               2014

---LITERAL TABLE---
Literal         Address
‘10’            2014
 * 
 * 
 * */