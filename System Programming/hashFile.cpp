#include <iostream>
#include<fstream>
#include<string>
using namespace std;
#define max 25
struct mot{
	int chain,flag;
	string mne;
	string opcode,size,oper,var1,var2;
};
mot obj[max];
void init_mot(){
	fstream table_file;
	mot tab;
	char c;
	int hme,i,prev;
	for(i=0;i<max;i++){
		obj[i].flag=0;
		obj[i].chain=-1;
	}
	table_file.open("table1.txt",ios::in);
	while(!table_file.eof()){
		table_file>>tab.mne;
		table_file>>tab.opcode;
		table_file>>tab.size;
		table_file>>tab.oper;
		table_file>>tab.var1;
		table_file>>tab.var2;
		c=tab.mne.at(0);
		hme=int(c)-65;
		prev=hme;
		while(1){
			if(obj[hme].flag==0){
				obj[hme].flag=1;
				obj[hme].mne=tab.mne;
				obj[hme].opcode=tab.opcode;
				obj[hme].size=tab.size;
				obj[hme].oper=tab.oper;
				obj[hme].var1=tab.var1;
				obj[hme].var2=tab.var2;
				break;
			}
			else
			{
				hme++;
			}
		}
		if(prev!=hme)
		{
			while(obj[prev].chain!=-1)
				prev=obj[prev].chain;
			obj[prev].chain=hme;
		}
	}
}
string search(string key){
	int hme=int(key.at(0))-65;
	while(hme!=-1){
		if(key==obj[hme].mne)
			return obj[hme].opcode;
		else
			hme=obj[hme].chain;
	}
}
int main(){
	fstream input_file;
	fstream table_file;
	string ch;
	mot tab;
	init_mot();
	for(int i=0;i<max;i++)
	{
		cout<<i<<"\t"<<obj[i].chain<<"\t"<<obj[i].flag<<"\t"<<obj[i].mne<<"\t"<<obj[i].opcode<<"\t"<<obj[i].oper<<"\t"<<obj[i].size<<"\t"<<obj[i].var1<<"\t"<<obj[i].var2<<endl;
	}
	input_file.open("code.txt",ios::in);
	if(!input_file){
		cout<<"File creation failed.\n";
	}
	else{
		cout<<"File opend successfully.\n";
		while(!input_file.eof()){
			getline(input_file,tab.oper,' ');
			getline(input_file,tab.mne,' ');
			getline(input_file,tab.var1,' ');
			getline(input_file,tab.var2,' ');
			ch= search(tab.mne);
			cout<<tab.oper<<'	'<<" MNE:: "<<tab.mne<<'	'<<tab.var1<<'	'<<tab.var2<<"	"<<"(opcode: "<<ch<<")"<<endl;
		}
		input_file.close();
	}
	return 0;
}

