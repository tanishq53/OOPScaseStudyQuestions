/*
Write a program to manage books in a library using OOP.
Create a class Book with data members title, author, and price, and declare display() as a virtual function.
Derive classes TextBook, ReferenceBook, and Magazine from Book, each overriding the display() function.
Create objects of all derived classes and store their addresses in an array of base class pointers.
Display details of all books using runtime polymorphism.
*/
#include <iostream>
using namespace std;
class Book{
    public:
    string title , author ;
    double price;
    Book(string tit , string aut , double price = 10){
        title = tit;
        author = aut;
        this->price =  price;
    }
    virtual void display(){         
        cout<<title<<" with price "<<price<<" author "<<author<<" type UNKNOWN"<<endl;
    }
    ~Book(){};
};
class TextBook : public Book{
    public:
    TextBook(string tit , string aut , int pr):Book(tit , aut , pr){};
    void display(){
        cout<<title<<" with price "<<price<<" author "<<author<<" type TextBook"<<endl;
    }
};
class ReferenceBook : public Book{
    public:
ReferenceBook(string tit , string aut , int pr):Book(tit , aut , pr){};
    void display(){
        cout<<title<<" with price "<<price<<" author "<<author<<" type ReferenceBook"<<endl;
    }
};
class Magazine : public Book{
    public:
    Magazine(string tit , string aut , int pr):Book(tit , aut , pr){};
    void display(){
        cout<<title<<" with price "<<price<<" author "<<author<<" type Magazine"<<endl;
    }
};
int main(){
    Book* arr[3];
    arr[0] = new TextBook("Book1" , "Auth 1" , 100);
    arr[1] = new TextBook("Book2" , "Auth 2" , 110);
    arr[2] = new TextBook("Book3" , "Auth 3" , 120);
    for(int i = 0  ; i< 3 ; i++){
        arr[i]->display();
    }
    for(int i = 0 ; i < 3 ; i++){
        delete arr[i];
    }
}