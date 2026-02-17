//**********************
// Record Management   *
// System              *
//**********************

# include <iostream>
# include <fstream>     
# include <cstring>
# include <cctype>
# include <iomanip>

using namespace std ;
const int ROLL_NO_LENGTH = 11 ;   //globel const. for roll no length
const int NAME_LENGTH = 41 ; //globle const. for name length

struct Student                           // structure having 5 informations for multi students
{
	char rollNo[ROLL_NO_LENGTH] ;
	char name[NAME_LENGTH] ;
	int numCources ;
	double* gpa ;
	double sgpa ;
} ;

Student *readAllRecords (int&) ;       //functions protypes
void readOneRecord (ifstream& ,Student* ,int) ;
void computeAllSGPAs (Student * ,int) ;
void computeOneSGPAs (Student * ,int) ;
void displayMenu (Student*, int) ;
void displayList (Student * ,int) ;
void maximum (Student * ,int) ;
void minimum (Student * ,int) ;
void search (Student * ,int) ;
void updateList (Student* ,int) ;
void quit (Student* ,int) ;

int main()
{
	Student * rptr ; //recieving pointr 
	int nums=0;
	rptr=readAllRecords(nums);
	computeAllSGPAs(rptr,nums);
	displayMenu(rptr,nums) ;
	for(int i=0 ; i<nums ; i++)     // deleting dinamic array of doubles 1 by 1
	{
		delete [] rptr[i].gpa ; 
		rptr[i].gpa = 0 ;
	}
	delete []rptr;             // deleting dimanic array of student
	rptr=0;
	return 0 ;
}

// read all records from the file and return pointer to structure of Student
Student* readAllRecords(int& num)
{
	Student * ptr ;
	ifstream fin("students.txt") ;
	if(!fin)      //check for file opening
	{
		cout<<"error opning file" ;
	}
	else
	{
		fin >> num;  // reading 1st data from file(no. of stunents data containing by file
		ptr = new Student[num];       //dinamic allocation array of students
		for (int i=0;i<num; i++)      // calling function till the loop end
		{
			readOneRecord(fin,ptr,i);
		}
		fin.close();   //closing file
	}
	return ptr;
}

// read data for one student
void readOneRecord(ifstream &fin ,Student* ptr ,int i)
{
	char ngpa[4] ;
	fin >> ptr[i].rollNo ;    //reading roll no.
	fin.ignore() ;
	fin.getline (ptr[i].name , NAME_LENGTH);        //reading name
	fin >> ptr[i].numCources ;
	ptr[i].gpa = new double [ptr[i].numCources] ;
	for(int j=0;j<ptr[i].numCources;j++)
	{
		fin >> ngpa ;
		if(strcmp(ngpa , "f") == 0 || strcmp(ngpa , "F") == 0)
		{
			ptr[i].gpa[j] = 0 ;
		}
		else
		{
			ptr[i].gpa[j] = atof(ngpa) ;
		}
	}
}

// calcula SGPAs for all students
void computeAllSGPAs(Student * sptr,int n)
{
	for(int i=0 ; i<n ;i++) // call function for each student
	{
		computeOneSGPAs(sptr,i);
	}
}

// calulate and store SGPA for one student
void computeOneSGPAs(Student * osptr,int num)
{
	osptr[num].sgpa = 0 ;
	for(int j=0;j<osptr[num].numCources;j++)
	{
		osptr[num].sgpa = (osptr[num].sgpa +osptr[num].gpa[j]);
	}
	osptr[num].sgpa =osptr[num].sgpa /osptr[num].numCources ;

}

// display menu and take input from user
void displayMenu(Student*cp ,int n) 
{
	char choice ;
	cout << "---- Welcome to Student Record Management System ----" << endl ;
	cout << endl ;
	cout << "Reading data from \"students.txt\"..." << endl ;
	cout << endl ;
	cout << "File opened successfully and records of " << n << " students have been read." << endl ;
	cout << endl ;
	do
	{
		cout << "Menu" << endl ;
		cout << "1. Display list of all students" <<endl ;
		cout << "2. Display student record(s) having Maximum SGPA" << endl ;
		cout << "3. Display student record(s) having Minimum SGPA" << endl ;
		cout << "4. Search by Roll Number" << endl ;
		cout << "5. Update a Student record" << endl ;
		cout << "6. Quit" << endl ;
		cout << endl ;
		cout << "Enter your choice : " ;
		cin >> choice ; 
		while ( choice < '1' || choice > '6' ) // input validation
		{
			cout << "ERROR!!! Invalid input ...." << endl ;
			cout << "Enter your choice again : " ;
			cin >> choice ;
			cout << endl << endl ;
		}
		if(choice == '1' )
			displayList (cp,n) ;
		if(choice == '2' )
			maximum (cp,n) ;
		if(choice == '3' )
			minimum (cp,n) ;
		if(choice == '4' )
			search (cp,n) ;
		if(choice == '5' )
			updateList (cp,n) ;
		if(choice == '6' )
			quit (cp,n) ;
	}while (choice != '6') ;
}

//display the list of all students
void displayList (Student* fptr , int n) 
{
	cout<< setw(15) << left << "Roll No." ;
	cout<< setw(45) << left << "Name" ;
	cout<< setw(10) << left << "Courses" ;
	cout<< setw(10) << left << "SGPA" ;
	for(int i=0;i<n;i++)
	{
		cout << setw(15) << left << fptr[i].rollNo  ;
		cout << setw(45) << left << fptr[i].name ;
		cout << setw(10) << left << fptr[i].numCources ;
		cout << setprecision(2) << fixed << setw(10) << left << fptr[i].sgpa ;
		cout << endl ;
	}
	cout << endl << endl ;
	char ch ;
	cout << "Enter any key to approch main menu : " ; //to approach main menu
	cin.get(ch);
	cin.ignore(80,'\n') ;
	cout << endl << endl ;
}

//find and display record of max. SGPA's student
void maximum (Student* fptr ,int n)
{
	double max ;
	max = fptr[0].sgpa ;
	int index = 0 ;
	cout << setw(15) << left << "Roll No." ;
	cout << setw(45) << left << "Name" ;
	cout << setw(10) << left << "Courses" ;
	cout << setw(10) << left << "SGPA" ;
	cout << endl ;
	for(int i=1;i<n;i++)
	{
		if(max <= fptr[i].sgpa)
		{
			max = fptr[i].sgpa ;//find max. SGPA
			index = i ;
		}
		
	}
	cout << setw(15) << left << fptr[index].rollNo  ; //display data of max. SGPA for last index
	cout << setw(45) << left << fptr[index].name ;
	cout << setw(10) << left << fptr[index].numCources ;
	cout << setprecision(2) << fixed << setw(10) << left << fptr[index].sgpa ;
	cout << endl ;
	for (int j=0 ; j<index ; j++)
	{
		if(max == fptr[j].sgpa) //condition for more then one max. SGPA
		{
			index = j ;
			cout << setw(15) << left << fptr[index].rollNo  ;
			cout << setw(45) << left << fptr[index].name ;
			cout << setw(10) << left << fptr[index].numCources ;
			cout << setprecision(2) << fixed << setw(10) << left << fptr[index].sgpa ;
			cout << endl ;
		}
	}
	cout << endl << endl ;
	char ch ;
	cout << "Press any key to approch main menu : " ;
	cin.get(ch);
	cin.ignore() ;
	cout << endl << endl ;
}

//find and display record of min. SGPA's student
void minimum (Student* fptr ,int n) 
{
	double min ;
	min = fptr[0].sgpa ;
	int index = 0 ;
	cout << setw(15) << left << "Roll No." ;
	cout << setw(45) << left << "Name" ;
	cout << setw(10) << left << "Courses" ;
	cout << setw(10) << left << "SGPA" ;
	cout << endl ;
	for(int i=1;i<n;i++)
	{
		if(min >= fptr[i].sgpa) //find min. SGPA
		{
			min = fptr[i].sgpa ;
			index = i ;
		}
		
	}
	cout << setw(15) << left << fptr[index].rollNo  ; //display data of min. SGPA for last index
	cout << setw(45) << left << fptr[index].name ;
	cout << setw(10) << left << fptr[index].numCources ;
	cout << setprecision(2) << fixed << setw(10) << left << fptr[index].sgpa ;
	cout << endl ;
	for (int j=0 ; j<index ; j++)
	{
		if(min == fptr[j].sgpa) //condition for more then one min. SGPA
		{
			index = j ;
			cout << setw(15) << left << fptr[index].rollNo  ;
			cout << setw(45) << left << fptr[index].name ;
			cout << setw(10) << left << fptr[index].numCources ;
			cout << setprecision(2) << fixed << setw(10) << left << fptr[index].sgpa ;
			cout << endl ;
		}
	}
	cout << endl << endl ;
	char ch ;
	cout << "Enter any key to approch main menu : " ;
	cin.get(ch);
	cin.ignore(80,'\n') ;
	cout << endl << endl ;
}

// seach by roll no and display max. combinations
void search (Student* fptr ,int n) 
{
	int count = 0, count2 = 0 ;
	char *strptr = NULL , aray[ROLL_NO_LENGTH] ;
	cout << "Enter a roll no / a part of roll no for searching : " ;
	cin.ignore() ;
	cin >> aray ;//take input from user
	int arayLen ;
	arayLen = strlen(aray);
	for(int i=0 ;i<arayLen;i++)
	{
		aray[i] = toupper(aray[i]) ; // changing array to upper case
	}
	aray[arayLen]= '\0' ;
	for(int i=0 ; i<n ;i++)
	{
		strptr = strstr(fptr[i].rollNo , aray) ; // seaching roll.no for display
		if (strptr)
		{
			if (count2 == 0)
			{
			cout << setw(15) << left << "Roll No." ; // display horizontal pattern
			cout << setw(45) << left << "Name" ;
			cout << setw(10) << left << "Courses" ;
			cout << setw(10) << left << "SGPA" ;
			cout << endl ;
			}
			cout << setw(15) << left << fptr[i].rollNo  ; 
			cout << setw(45) << left << fptr[i].name ;
			cout << setw(10) << left << fptr[i].numCources ;
			cout << setprecision(2) << fixed << setw(10) << left << fptr[i].sgpa ;
			cout << endl ;
			count++ ;
			count2++ ;
		}
	}
	if (count == 0) // condition for unmached items
		cout <<"No match was found !!!" << endl ;
	cout << endl << endl ;
	char ch ;
	cout << "Enter any key to approch main menu  " ;
	cin.get(ch);
	cin.ignore(80,'\n') ;
	cout << endl << endl ;
}

//take rollno. from usre and update the desired data
void updateList (Student* fptr ,int n) 
{
	double *temp = 0 ; // to hold the new gpa array temporarily
	char roll[ROLL_NO_LENGTH] ;
	char choice ;
	cout << "Enter a Roll No of the student for updating : " ; 
	cin >> roll ;
	int j = 0 ;
	while(roll[j] != '\0' )
	{
		roll[j] = toupper(roll[j]) ;
		j++;
	}
	int index = -1 ;
	for(int i=0 ; i<n ;i++)
	{
		if(strcmp(fptr[i].rollNo, roll)==0)
		{
			index = i ;
		}
	}
	if(index == -1) // for invalid rollno.
	{
		cout << "No match is found . " << endl ;
	}
	else
	{
		do
		{
			cout << "   Sub Menu    " << endl ;
			cout << "   a. Update the Name of the student " << endl ;
			cout << "   b. Add a course (i.e. its GPA) for the student." << endl ;
			cout << "   c. For quit sub menu .\n\n" ;
			cout << "Enter your sub menu choice : " ;
			cin >> choice ;
			choice = tolower(choice) ;
			while(choice!='a'&&choice!='b'&&choice!='c')
			{
				cout <<"Error!!! invalid input"<<endl;
				cout << "   Sub Menu    " << endl ;
				cout << "   a. Update the Name of the student " << endl ;
				cout << "   b. Add a course (i.e. its GPA) for the student." << endl ;
				cout << "   c. For quit sub menu .\n\n" ;
				cout << "Enter your sub menu choice again: " ;
				cin >> choice ;
				choice = tolower(choice) ;
			}
			if (choice == 'a')
			{
				char newName[NAME_LENGTH] ;
				cout << "Enter the new name of Roll No. " << roll << " : " ;
				cin.ignore();
				cin.getline (newName,NAME_LENGTH) ; // take new name from user
				int newLen ;
				newLen = strlen(newName);
				for(int i =0 ; i<newLen ; i++)
				{
					fptr[index].name[i] = newName[i] ;// updating name
				}
				fptr[index].name[newLen] = '\0' ;
			}
			if (choice == 'b')
			{
				char aray[4];
				cout <<"Enter the GPA of Roll No. " << roll << " to add a cource : " ;
				cin >> aray ; //take Gpa to add in data
				double gpa ;
				while (!(strcmp(aray , "f") == 0 || strcmp(aray , "F") == 0 || strcmp(aray , "0") == 0)
					                                              &&!((atof(aray) > 0 && atof(aray) <= 4)))//input validation check
				{
						cout << "Error! Invalid input. Enter F or f for fail or gpa\n" ;
						cout <<"Enter the GPA of Roll No. " << roll << " to add a cource : " ;
						cin >> aray ;
				}
				if(strcmp(aray , "f") == 0 || strcmp(aray , "F") == 0)
				{
					gpa = 0 ;
				}
				else
				{
					gpa = atof(aray) ;
				}
				temp = new double [fptr[index].numCources+1] ;
				for (int i = 0; i < fptr[index].numCources; i++) //store data in temp. dinamic array
				{
					temp[i] = fptr[index].gpa[i] ;
				}
				temp[fptr[index].numCources] = gpa;
				delete [] fptr[index].gpa ;
				fptr[index].gpa = temp ;
				temp = 0; // to avoid dangling pointer
				fptr[index].numCources++ ;
				fptr[index].sgpa =0 ;
				for (int i=0 ;i<fptr[index].numCources;i++) //for updating sgpa
				{
					fptr[index].sgpa=fptr[index].sgpa +fptr[index].gpa[i];
				}
				fptr[index].sgpa = fptr[index].sgpa/fptr[index].numCources ;
			}
		}while (choice != 'c') ; // input validation
	}
	cout << endl << endl ;
	char ch ;
	cout << "Enter any key to approch main menu : " ;
	cin.get(ch);
	cin.ignore(80,'\n') ;
	cout << endl << endl ;
}

// quit the program and updating file
void quit (Student* fptr ,int n)
{
	cout << "File is processing ....."<< endl ;
	ofstream fout("students.txt") ;
	if(!fout) // check for file opening
		cout<<"Error opening file ...";
	else
	{
		fout << n << endl ; // n is no of students data 
		for (int i = 0 ; i < n ; i++)
		{
			fout << fptr[i].rollNo << " " ;
			fout << fptr[i].name <<endl;
			fout << fptr[i].numCources <<endl;
			for(int j=0;j<fptr[i].numCources;j++)
			{
				if(fptr[i].gpa[j]==0)
					fout << "F " ;
				else
					fout << fptr[i].gpa[j] << " " ;
			}
			fout << endl ;
		}
		cout << "File has been updated sucessfully  " << endl ;
		fout.close();
	}
	cout << "---- Closing Student Record Management System ----" << endl ;
}