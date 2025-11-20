/*
Write a program to implement a result processing system using multiple inheritance.
Create a class Person containing basic personal information.
Derive classes AcademicDetails and SportsDetails from Person using virtual inheritance.
Create a class Student that inherits from both AcademicDetails and SportsDetails.
Store academic marks and sports performance and display the combined result for a student.
*/
#include <iostream>
using namespace std;
class person{
    public:
    string name  , gender;
    int age;
    person(string s , string g , int ag ){
        name =s;
        gender = g;
        age = ag;
    }
    virtual ~person(){};
};
class AcedmicDetails: virtual public person{
    public:
    int mark[3];
    AcedmicDetails(string s , string g , int ag  , int arr[3]): person(s , g, ag){
        for(int i = 0 ; i < 3 ; i++)
        mark[i] = arr[i];
    }
};
class SportsDetails: virtual public person{
    public:
    string sport;
    int performance;
    SportsDetails(string s , string g , int ag  , string s2 , int perf):person(s , g, ag){
        sport =s2;
        performance = perf;
    }
};
class Student :  public SportsDetails ,  public AcedmicDetails{
    public:
    Student(string s , string g , int ag  , string s2 , int perf ,int arr[3] ): person(s,g,ag),SportsDetails(s, g , ag,s2 , perf), AcedmicDetails(s , g, ag , arr){};
    void showDetail(){
        cout<< name <<" "<<gender <<" "<<age <<" "<<sport<<" "<<performance<<" "<<"marks ";
        for(int i = 0 ; i < 3 ; i++){
            cout<<mark[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int mark [3]= {21 , 24 , 87};
    Student s1("arpit" , "Male" , 21 , "Football" , 9 , mark);
    s1.showDetail();
}
