#include <bits/stdc++.h>
using namespace std;

class Book{
private:
    string title;
    string author;
    bool avail;
public:
    void set_title(string t){
        title =t;
    }
    string get_title(){
        return title;
    }
    void set_author(string aut){
        author = aut;
    }
    string get_author(){
        return author;
    }
    void set_availability(bool a){
        avail=a;
    }
    bool get_availability(){
        return avail;
    }
    void display(){
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Availability: ";
        if(avail) cout<<"Available"<<endl;
        else cout<<"Not available"<<endl;
        cout<<endl;
    }

    Book(){
        title="No title";
        author="N/A";
        avail=false;
    }
    ~Book(){}
};

class LibraryMember{
private:
    string name;
    int card_no;
public:
    void set_name(string n){
        name =n;
    }
    string get_name(){
        return name;
    }
    void set_cardno(int n){
        card_no=n;
    }
    int get_cardno(){
        return card_no;
    }
    void display(){
        cout<<"Member Name: "<<name<<endl;
        cout<<"Card No.: "<<card_no<<endl;
        cout<<endl;
    }

    LibraryMember(){
        name="No name";
        card_no = 0;
    }
    LibraryMember(string n,int card){
        name = n;
        card_no=card;
    }
};

class Library{
private:
    int book_max;
    int book_size=0;
    int mem_max;
    int mem_size=0;
    Book *books;
    LibraryMember *members;
public:
    Library(){
        book_max=100;
        books=new Book[book_max];
        mem_max=100;
        members=new LibraryMember[book_max];
    }
    Library(int b_max,int m_max){
        book_max=b_max;
        books=new Book[book_max];
        mem_max=m_max;
        members=new LibraryMember[book_max];
    }
    Library& operator=(const Library &ob){
        if(this==&ob) return *this;
        delete[] members;
        delete[] books;
        book_max = ob.book_max;
        books=new Book[book_max];
        book_size=ob.book_size;
        for(int i=0;i<book_size;i++){
            books[i]=ob.books[i];
        }

        mem_max = ob.mem_max;
        members=new LibraryMember[mem_max];
        mem_size=ob.mem_size;
        for(int i=0;i<mem_size;i++){
            members[i]=ob.members[i];
        }
        return *this;
    }
    void addBook(string ti,string aut){
        books[book_size].set_title(ti);
        books[book_size].set_author(aut);
        books[book_size].set_availability(true);
        book_size++;
    }
    void removeBook(string ti){
        for(int i=0;i<book_size;i++){
            if(books[i].get_title()==ti){
                for(int j=i;j<book_size;j++){
                    books[j]=books[j+1];
                }
                books[i].set_availability(false);
                book_size--;
                return;
            }
        }
    }
    void registerMember(string nam,int card){
        members[mem_size].set_cardno(card);
        members[mem_size].set_name(nam);
        mem_size++;
    }
    void removeMember(int card){
        for(int i=0;i<mem_size;i++){
            if(card == members[i].get_cardno()){
                for(int j=i;j<mem_size;j++){
                    members[j]=members[j+1];
                }
                mem_size--;
                return;
            }
        }
    }
    void borrowBook(string ti,int card){
        cout<<"Book: "<<ti<<"has been borrowed by"<<endl;
        for(int i=0;i<mem_size;i++){
            if(card == members[i].get_cardno()){
                cout<<"Name: "<<members[i].get_name();
                cout<<"Library card number: "<<members[i].get_cardno()<<endl;
                break;
            }
        }
        for(int i=0;i<book_size;i++){
            if(books[i].get_title()==ti){
                books[i].set_availability(false);
            }
        }
    }
    void returnBook(string ti,int card){
        cout<<"Book: "<<ti<<"has been returned by"<<endl;
        for(int i=0;i<mem_size;i++){
            if(card == members[i].get_cardno()){
                cout<<"Name: "<<members[i].get_name();
                cout<<"Library card number: "<<members[i].get_cardno()<<endl;
                break;
            }
        }
        for(int i=0;i<book_size;i++){
            if(books[i].get_title()==ti){
                books[i].set_availability(true);
            }
        }
    }

    void displayAllMembers(){
        for(int i=0;i<mem_size;i++){
            members[i].display();
            cout<<endl;
        }
        cout<<endl;
    }
    void displayAllBooks(){
        for(int i=0;i<book_size;i++){
            books[i].display();
            cout<<endl;
        }
    }
};

int main() {
    Library library;
    // Adding books
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("Pride and Prejudice", "Jane Austen");
    // Displaying all books
    library.displayAllBooks();
    // Registering members
    library.registerMember("John Doe", 1234);
    library.registerMember("Jane Smith", 5678);
    // Displaying all members
    library.displayAllMembers();
    
    Library lib2;
    lib2 = library;
    
    lib2.displayAllBooks();
    lib2.displayAllMembers();
    return 0;
    }