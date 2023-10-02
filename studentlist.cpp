//Author: Michael Fu
//Date: 10/17/2023
//Description: This is a student list in CPP that allows the user to add, delete and print student structs that are saved in a vector. 
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;


//create the struct student that will save first name, last name, id and GPA
struct Student{
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

//functions stuff
void add(vector<Student*>& listt, int &num);
void print(vector<Student*>& listt);
void delet(vector<Student*>& listt, int &num);



int main(){
  //initialize variables
  int num;
  bool justKeepGoing = true;
  string inpt;
  vector<Student*> listt;

  //while justKeepGoing is true (its only false when quit is entered in the input
  while(justKeepGoing){
    //output the directions and input the users response
    cout << "add(add), print(print), delete(delete), or quit(quit)?" << endl;
    cin >> inpt;
    cin.ignore();

    //depending on what the user inputs, call the function that corresponds to their input. If they input 'quit' set justKeepGoing to false.
    if(inpt == "add"){
      add(listt, num);
    } else if (inpt == "print"){
      print(listt);
    } else if (inpt == "delete"){
      delet(listt, num);
    } else if (inpt == "quit"){
      justKeepGoing = false;
    }
  }
  return 0;
}


//for the add function, take in the vector of students and the number of students
void add(vector<Student*>& listt, int &num){
  Student* stud = new Student();

  //for the first and last name, output the question and take in the input. Then set the students firstname to fname. 
  char fname[80];
  cout << "what is the first name of the student?" << endl;
  cin.getline(fname, 80);
  strcpy(stud->firstName, fname);

  char lname[80];
  cout << "what is the last name of the student?" << endl;
  cin.getline(lname, 80);
  strcpy(stud -> lastName, lname);

  //for the ID, input the id, and check through the list of students to see if the id is unique. If it isn't, output that the ID is already used and inputs a new ID. 
  int id;
  cout << "enter id" << endl;
  cin >> id;

  for(int i = 0;i<listt.size();i++){
      while(id ==listt[i]->id){
	cout << "please enter a unique ID" << endl;
	cin >> id;
	
      }
   }
  //then make the students ID set to id.
   stud -> id = id; 

   
   //prompt for the GPA, then set the students gpa to gpa. Then add the student with all the correct information saved into the list of students. Then add 1 to the number of students because we added a student. 
   float gpa;
   cout << "enter GPA:" << endl;
   cin >> gpa;
   stud -> gpa = gpa;
   listt.push_back(stud);


   cout << endl;
   num++;
}


//for the print function
void print(vector<Student*>& listt){
  //if there are no students in th list, output that there are no students. 
  if(listt.size() == 0){
    cout << "no students in database" << endl;
    
  }
  //set the cout decimal place to 2 so that it goes to hundredths place
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);

  //go through the list and output the students firtsname, lastname, ID and GPA
  for(int i = 0;i<listt.size();i++){
    cout << listt[i]->firstName << " " << listt[i]->lastName << ", " << listt[i] -> id << ", " << listt[i]->gpa << endl;
  }

  
}

//for the delete function
void delet(vector<Student*>& listt, int &num){
  //create variables studentindex for which index of the list of students the student is at the stuid to keep track of the ID to delete. 
  int studentindex=-1;
  int stuid=0;
  //input the student's ID
  cout << "enter the id of the student to delete" << endl;
  cin >> stuid;

  //go through the list of students and if the id of the student at location i is equal to the one we want to delete, set studentindex to i and subtract 1 from the nunmber of students. 
  for(int i = 0;i<listt.size();i++){
    if(stuid == listt[i]->id){
      studentindex = i;
      num--;
      
    }
    
  }
  //if the studentindex is not -1, or the ID we are looking for was found, then erase that value from the list of students. If the studentindex is -1, or the ID was not found, then output that we could not find the provided ID. 
  if(studentindex != -1){
    listt.erase(listt.begin() + studentindex);
    cout << "student with the ID " << stuid << " has been deleted" << endl;
  } else {
    cout << "failed to find student with provided ID, please try again" << endl;
    
  }
    
}
