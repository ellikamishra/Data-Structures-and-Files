/*============================================================================
 	Title   : Sequential File
 	Name    : Ellika
 	Roll No : 23221
 	Batch   : F-10
	Problem Statement   :
	Department maintains a student information. The file contains roll number, name,
  division and address. Write a program to create a sequential file to store and
  maintain student data. It should allow the user to add, dlete information of
  student. Display information of particular employee. If record of student does
  not exist an appropriate message is displayed. If student record is found it should
  display the student details.
============================================================================*/
#include<iostream>
#include<fstream>
using namespace std;

typedef struct {

	int rollno;
	char div;
	string name;
	string address;
}
student;

class File {

	ofstream fout;
	ifstream fin;

public:

	void create();
	void insert();
	int search(int rollno);
	int update(int rollno);
	int dlete(int rollno);
	void display();
};

void File::create() {

	int ch;
	fout.open("Student.txt");

	if(fout) {

		cout<<"File Created\n\n";
		fout.close();
		do {

			cout<<"----------------------------\n";
			cout<<"Select the Options\n";
			cout<<"----------------------------\n";
			cout<<"0. Exit\n";
			cout<<"1. Add a Record\n\n";
			cout<<"Your Choice: ";
			cin>>ch;
			cout<<"----------------------------\n\n";

			if(ch==1)
				insert();

			else if(ch>1)
				cout<<"Select Correct Option\n";
		}
		while(ch!=0);
	}
}

void File::insert() {

	char dummy[1];
	student S;

	fout.open("Student.txt",ios::app);

	cout<<"Roll No : ";
	cin>>S.rollno;

	while(search(S.rollno)) {

		cout<<"\n----------------------------\n\n";
		cout<<"Roll Number already exits. Enter Another\n\n";
		cout<<"----------------------------\n\n";
		cout<<"Roll No : ";
		cin>>S.rollno;
	}

	cin.getline(dummy,1);
	cout<<"Name    : ";
	getline(cin,S.name);

	cout<<"Division: ";
	cin>>S.div;

	cin.getline(dummy,1);
	cout<<"Address : ";
	getline(cin,S.address);

	if(fout)
		fout<<S.rollno<<"\t"<<S.name<<"\t"<<S.div<<"\t"<<S.address<<endl;
	cout<<endl;
	fout.close();
}

int File::search(int rollno) {

	student S;
	fin.open("Student.txt");

	while(fin>>S.rollno>>S.name>>S.div>>S.address) {

		if(rollno==S.rollno) {

			cout<<"----------------------------\n\n";
			cout<<"Record Found:\n\n";
			cout<<"Roll No : "<<S.rollno<<endl<<"Name    : "<<S.name<<endl<<"Division: "<<S.div<<endl<<"Address : "<<S.address<<endl;
			fin.close();
			return 1;
		}
	}
	fin.close();
	return 0;
}

int File::update(int rollno) {

	student S;
	char dummy[1];
	int flag=search(rollno);

	if(flag==1) {

		cout<<"----------------------------\n\n";
		cout<<"Updating the Record\n\n";

		fin.open("Student.txt");
		fout.open("Temp.txt");

		while(fin>>S.rollno>>S.name>>S.div>>S.address) {

			if(rollno!=S.rollno)
				fout<<S.rollno<<"\t"<<S.name<<"\t"<<S.div<<"\t"<<S.address<<endl;

			else {

				cin.getline(dummy,1);
				cout<<"New Name    : ";
				getline(cin,S.name);

				cout<<"New Division: ";
				cin>>S.div;

				cin.getline(dummy,1);
				cout<<"New Address : ";
				getline(cin,S.address);

				fout<<S.rollno<<"\t"<<S.name<<"\t"<<S.div<<"\t"<<S.address<<endl;
			}
		}
		flag=remove("Student.txt");
		flag=rename("Temp.txt","Student.txt");
		fin.close();
		fout.close();
		return 1;
	}
	return 0;
}

int File::dlete(int rollno) {

	student S;
	int flag=search(rollno);

	if(flag==1) {

		cout<<"----------------------------\n\n";
		cout<<"Deleting the Record\n";

		fin.open("Student.txt");
		fout.open("Temp.txt");

		while(fin>>S.rollno>>S.name>>S.div>>S.address) {

			if(rollno!=S.rollno)
				fout<<S.rollno<<"\t"<<S.name<<"\t"<<S.div<<"\t"<<S.address<<endl;
		}
		flag=remove("Student.txt");
		flag=rename("Temp.txt","Student.txt");
		fin.close();
		fout.close();
		return 1;
	}
	return 0;
}

void File::display() {

	student S;
	fin.open("Student.txt");
  cout<<"----------------------------\n";
	cout<<"RollNo \t Name \t Div. \t Address\n";
	cout<<"----------------------------\n";
	while(fin>>S.rollno>>S.name>>S.div>>S.address)
		cout<<S.rollno<<"\t"<<S.name<<"\t"<<S.div<<"\t"<<S.address<<endl;
	fin.close();
}

int main() {

	File F;
	int ch,flag,rollno;

	do {

		cout<<"----------------------------\n";
		cout<<"Select the Options\n";
		cout<<"----------------------------\n";
		cout<<"1. Create File\n";
		cout<<"2. Add a Record\n";
		cout<<"3. Search a Record\n";
		cout<<"4. Update a Record\n";
		cout<<"5. Delete a Record\n";
		cout<<"6. Display Records\n";
		cout<<"7. Exit\n\n";
		cout<<"Your Choice: ";
		cin>>ch;
		cout<<"----------------------------\n\n";

		switch(ch) {

			case 1: {

				F.create();
				cout<<endl;
				break;
			}

			case 2: {

				F.insert();
				cout<<endl;
				break;
			}

			case 3: {

				cout<<"Roll Number: ";
				cin>>rollno;
				cout<<endl;
				flag=F.search(rollno);
				if(!flag) {
					cout<<"----------------------------\n\n";
					cout<<"Record not Found\n";
				}
				cout<<endl;
				break;
			}

			case 4: {

				cout<<"Roll Number: ";
				cin>>rollno;
				cout<<endl;
				flag=F.update(rollno);
				if(!flag) {
					cout<<"----------------------------\n\n";
					cout<<"Record not Found\n";
				}
				cout<<endl;
				break;
			}

			case 5: {

				cout<<"Roll Number: ";
				cin>>rollno;
				cout<<endl;
				flag=F.dlete(rollno);
				if(!flag) {
					cout<<"----------------------------\n\n";
					cout<<"Record not Found\n";
				}
				cout<<endl;
				break;
			}

			case 6: {

				F.display();
				cout<<endl;
				break;
			}

			case 7: {

				cout<<"End\n";
				break;
			}

			default: cout<<"Select Correct Option\n\n";
		}
	}
	while(ch!=7);

	return 0;
}


/*
----------------------------
Select the Options
----------------------------
1. Create File
2. Add a Record
3. Search a Record
4. Update a Record
5. Delete a Record
6. Display Records
7. Exit

Your Choice: 1
----------------------------

File Created

----------------------------
Select the Options
----------------------------
0. Exit
1. Add a Record

Your Choice: 1
----------------------------

Roll No : 1
Name    : asdf
Division: 4
Address : wert

----------------------------
Select the Options
----------------------------
0. Exit
1. Add a Record

Your Choice: 1
----------------------------

Roll No : 2
Name    : zxcv
Division: 4
Address : asde

----------------------------
Select the Options
----------------------------
0. Exit
1. Add a Record

Your Choice: 1
----------------------------

Roll No : 3
Name    : yuio
Division: 4
Address : qwer

----------------------------
Select the Options
----------------------------
0. Exit
1. Add a Record

Your Choice: 1
----------------------------

Roll No : 4
Name    : uiop
Division: 5
Address : erty

----------------------------
Select the Options
----------------------------
0. Exit
1. Add a Record

Your Choice: 0
----------------------------


----------------------------
Select the Options
----------------------------
1. Create File
2. Add a Record
3. Search a Record
4. Update a Record
5. Delete a Record
6. Display Records
7. Exit

Your Choice: 2
----------------------------

Roll No : 5
Name    : cvbn
Division: 8
Address : dfgh


----------------------------
Select the Options
----------------------------
1. Create File
2. Add a Record
3. Search a Record
4. Update a Record
5. Delete a Record
6. Display Records
7. Exit

Your Choice: 3
----------------------------

Roll Number: 2

----------------------------

Record Found:

Roll No : 2
Name    : zxcv
Division: 4
Address : asde

----------------------------
Select the Options
----------------------------
1. Create File
2. Add a Record
3. Search a Record
4. Update a Record
5. Delete a Record
6. Display Records
7. Exit

Your Choice: 4
----------------------------

Roll Number: 4

----------------------------

Record Found:

Roll No : 4
Name    : uiop
Division: 5
Address : erty
----------------------------

Updating the Record

New Name    : tryu
New Division: 7
New Address : wqas

----------------------------
Select the Options
----------------------------
1. Create File
2. Add a Record
3. Search a Record
4. Update a Record
5. Delete a Record
6. Display Records
7. Exit

Your Choice: 5
----------------------------

Roll Number: 3

----------------------------

Record Found:

Roll No : 3
Name    : yuio
Division: 4
Address : qwer
----------------------------

Deleting the Record

----------------------------
Select the Options
----------------------------
1. Create File
2. Add a Record
3. Search a Record
4. Update a Record
5. Delete a Record
6. Display Records
7. Exit

Your Choice: 6
----------------------------

----------------------------
RollNo   Name    Div.    Address
----------------------------
1       asdf    4       wert
2       zxcv    4       asde
3       yuio    4       qwer
4       uiop    5       erty
5       cvbn    8       dfgh

----------------------------
Select the Options
----------------------------
1. Create File
2. Add a Record
3. Search a Record
4. Update a Record
5. Delete a Record
6. Display Records
7. Exit

Your Choice: 7
----------------------------

End

--------------------------------
Process exited after 114.6 seconds with return value 0
Press any key to continue . . .
*/
