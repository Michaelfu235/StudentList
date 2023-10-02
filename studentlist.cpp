#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

struct Student{
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

void add(vector<Student*>& listt, int &num);
void print(vector<Student*>& listt);
void delet(vector<Student*>& listt, int &num);



int main(){
  int num;
  bool justKeepGoing = true;
  string inpt;
  vector<Student*> listt;

  while(justKeepGoing){
    cout << "add(add), print(print), delete(delete), or quit(quit)?" << endl;
    cin >> inpt;
    cin.ignore();

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

void add(vector<Student*>& listt, int &num){
  Student* stud = new Student();

  char fname[80];
  cout << "what is the first name of the student?" << endl;
  cin.getline(fname, 80);
  strcpy(stud->firstName, fname);

  char lname[80];
  cout << "what is the last name of the student?" << endl;
  cin.getline(lname, 80);
  strcpy(stud -> lastName, lname);

  int id;
  cout << "enter id" << endl;
  cin >> id;

  for(int i = 0;i<listt.size();i++){
      while(id ==listt[i]->id){
	cout << "please enter a unique ID" << endl;
	cin >> id;
	
      }
   }
   stud -> id = id; 

   float gpa;
   cout << "enter GPA:" << endl;
   cin >> gpa;
   stud -> gpa = gpa;
   listt.push_back(stud);


   cout << endl;
   num++;
}


void print(vector<Student*>& listt){
  if(listt.size() == 0){
    cout << "no students in database" << endl;
    
  }
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);

  for(int i = 0;i<listt.size();i++){
    cout << listt[i]->firstName << " " << listt[i]->lastName << ", " << listt[i] -> id << ", " << listt[i]->gpa << endl;
  }

  
}


void delet(vector<Student*>& listt, int &num){
  int studentindex=-1;
  int stuid=0;
  cout << "enter the id of the student to delete" << endl;
  cin >> stuid;
  
  for(int i = 0;i<listt.size();i++){
    if(stuid == listt[i]->id){
      studentindex = i;
      num--;
      
    }
    
  }

  if(studentindex != -1){
    listt.erase(listt.begin() + studentindex);
    cout << "student with the ID " << stuid << " has been deleted" << endl;
  } else {
    cout << "failed to find student with provided ID, please try again" << endl;
    
  }
    
}
