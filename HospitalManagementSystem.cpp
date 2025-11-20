/*
Write a program to implement a hospital management system using OOP.
Create a class Person with basic details.
Derive a class Patient from Person with additional details like disease and room number.
Further derive classes Inpatient and Outpatient from Patient.
Override a function showDetails() in each class.
Create objects of all three derived classes and display their details using a base class pointer array.
*/
#include <iostream>
using namespace std;
class Person{
    public:
    string name,gender;
    int age, height;
    Person(string nam , string gen , int ag , int ht){
        name = nam;
        gender = gen;
        age = ag;
        height = ht;
    }
    virtual void ShowDetails(){
        cout<<name<<" "<<gender<<" "<<age<<" "<<height<<endl;
    }
    virtual ~ Person(){};
};
class patient : public Person{
    public:
    string disease;
    int roomNo;
    patient(string nam , string gen , int ag , int ht , string dis , int rmNo) :Person( nam , gen ,  ag , ht){
        disease = dis;
        roomNo = rmNo;
    }
    void ShowDetails(){
        cout<<name<<" "<<gender<<" "<<age<<" "<<height<< "  "<<disease<<endl;
    }
};
class inPatient: public patient{
    public:
    inPatient(string nam , string gen , int ag , int ht , string dis , int rmNo) :patient( nam , gen ,  ag , ht , dis , rmNo){};
    void ShowDetails(){
        cout<<name<<" "<<gender<<" "<<age<<" "<<height<< "  "<<disease<<" "<< roomNo<<" In hospital "<<endl;
    }
};
class OutPatient: public patient{
    public:
    OutPatient(string nam , string gen , int ag , int ht , string dis , int rmNo) :patient( nam , gen ,  ag , ht , dis , rmNo){};
    void ShowDetails(){
        cout<<name<<" "<<gender<<" "<<age<<" "<<height<< "  "<<disease<<" Out hospital "<<endl;
    }
};
int main(){
    Person* P[4];
    P[0] = new patient("A" , "M" , 10 ,170 , "D1" , 550 );
    P[1] = new inPatient("B" , "F" , 11 ,171 , "D2" , 555 );
    P[2] = new OutPatient("C" , "M" , 10 ,172 , "D3" , 560 );
    P[3] = new Person("D" , "M" , 16 ,200  );
    for(int i = 0 ;  i< 4 ; i++){
        P[i]->ShowDetails();
    }
    for(int i = 0  ; i< 4 ; i++){
        delete P[i];
    }
}