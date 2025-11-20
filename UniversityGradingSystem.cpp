/*
Design a C++ program using advanced OOP concepts to model a university grading system. 
Create a base class Student that stores studentName, rollNumber, and marks. 
Include a static data member maxMarks shared by all students and a virtual function calculateGrade()
that returns the grade as a character based on performance.
Implement function overloading for a function updateMarks() — one version that updates marks by a single subject score, 
and another that updates marks by accepting an array of subject scores.

Derive two classes, Undergraduate and Postgraduate, from Student.
In Undergraduate, override the calculateGrade() function using the logic:
If percentage ≥ 75 → Grade A
60–74 → Grade B
else → Grade C

In Postgraduate, override the function using stricter criteria:
If percentage ≥ 80 → Grade A
65–79 → Grade B
else → Grade C

*/

#include <iostream>
using namespace std;
class student{
protected:
    string name;
    int rollNo;
    int arr[3];
    int percentage;
    public:
    static int MaxMark;
    student (string namee ,int roll ,int arr[] ){
        name = namee;
        rollNo = roll;
        for(int i = 0 ; i < 3 ; i++){
            this->arr[i] = arr[i];
            MaxMark = max(arr[i] , MaxMark);
        }
        percentage = (arr[1]+arr[0]+arr[2])/3;
        
    }
    void updateMark(int mark){
        arr[0] = mark;
        MaxMark = max(mark , MaxMark);
        percentage = (arr[1]+arr[0]+arr[2])/3;
    }
    void updateMark(int mark[]){
        for(int i = 0 ; i < 3 ; i++){
            arr[i] = mark[i]; 
            MaxMark = max(arr[i], MaxMark);
        }
        percentage = (arr[1]+arr[0]+arr[2])/3;
    }
    void show(){
        cout<<name <<"  "<<rollNo <<"Marks are";
        for(int i = 0 ; i < 3  ;i++){
            cout<<arr[i]<<" ";
        }
        cout<<" \n max marks are "<<MaxMark<<endl;
    }
    virtual char calcGrade(){
        return '\0';
    }
};
class UG : public student{
    public:
    UG(string namee ,int roll ,int arr[]): student(namee, roll , arr){};
    char calcGrade(){
        if(percentage >= 75) return 'A';
        if(percentage < 60) return 'C';
        return 'B';
    }
};
class PG : public student{
    public:
    PG(string namee ,int roll ,int arr[]): student(namee, roll , arr){};
    char calcGrade(){
        if(percentage >= 80) return 'A';
        if(percentage < 65) return 'C';
        return 'B';
    }
};
int student :: MaxMark = 0;
int main(){
    int arrr[] = {79,78 ,75 };
    UG st1("arpit", 101 , arrr);
    PG s2("arpit", 101 , arrr);
    st1.show();
     cout<<"\n grade of Student 1 is "<<st1.calcGrade()<<"\n";
     cout<<"\n grade of Student 1 is "<<s2.calcGrade();
    s2.show();
}
