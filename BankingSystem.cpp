/*
Write a program to implement a banking system using OOP.
Create an abstract class Account with data members accountNo, name, and balance, 
and pure virtual functions deposit(), withdraw() and display().
Derive two classes SavingsAccount and CurrentAccount from Account.
Implement different withdrawal rules in each derived class.
Create multiple account objects and access them using an array of pointers of type Account*.
Perform deposit, withdrawal, and display operations for each account.
*/
#include <iostream>
using namespace std;
class Account{
    public:
    int accountNo;
    string name;
    int balance;

    virtual void deposit(int)=0; 
    virtual void withdraw(int)=0;
    virtual void display()=0;
};
class SavingAccount : public Account{
    public:
    SavingAccount(string name , int accNo ){
        this->name = name;
        accountNo  = accNo;
        balance = 100;
    }
    void deposit(int x){
         cout<<"Depositing "<<x<<" from Saving account"<<endl;
        balance+= x;
    }
    void withdraw(int x){
        cout<<"withdrawing "<<x<<" from Saving account"<<endl;
        balance -= x;
        cout<<"New balance is "<<balance<<endl<<endl;
    }
    void display(){
        cout<<name<<" "<<accountNo<<" "<<balance<<" Account type : Saving "<<endl;
    }
};
class CurrentAccount : public Account{
    public:
    CurrentAccount(string name , int accNo ){
        this->name = name;
        accountNo  = accNo;
        balance = 0;
    }
    void deposit(int x){
        cout<<"Depositing "<<x<<" from current account"<<endl;
        balance+= (x+ (0.5*x));
    }
    void withdraw(int x){
        cout<<"withdrawing "<<x<<" from current account"<<endl;
        balance -= (x+(0.7*x));
        cout<<"New balance is "<<balance<<endl<<endl;
    }
    void display(){
        cout<<name<<" "<<accountNo<<" "<<balance<<" Account type : Current "<<endl;
    }
};
int main(){
    Account* acc[2];
    acc[0] = new CurrentAccount("user1" , 1234);
    acc[1] = new SavingAccount("user2" , 7896);
    acc[0]->deposit(30);
    acc[1]->deposit(100);
    acc[0]->display();
    acc[1]->display();
    acc[0]->withdraw(20);
    acc[1]->withdraw(70);
    acc[0]->display();
    acc[1]->display();
}