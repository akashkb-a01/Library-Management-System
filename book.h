#include<bits/stdc++.h>

using namespace std;

class book
{
private:
    string Title;
    string Author;
    string ISBN;
    string Publication;
    bool isAvailable;
    string Issuer;
    string dueDate;

public:
    string getTitle(){
        return Title;
    }

    void setTitle(string title){
        Title = title;
    }

    string getAuthor(){
        return Author;
    }

    void setAuthor(string author){
        Author = author;
    }

    string getISBN(){
        return ISBN;
    }

    void setISBN(string isbn){
        ISBN = isbn;
    }

    string getPublication(){
        return Publication;
    }

    void setPublication(string publication){
        Publication = publication;
    }

    bool availibility(){
        return isAvailable;
    }

    void setAvailibility(bool availab){
        isAvailable = availab;
    }

    string getIssuer(){
        return Issuer;
    }
    
    void setIssuer(string issuer){
        Issuer = issuer;
    }

    string getDueDate(){
        return dueDate;
    }

    void setDueDate(string dat){
        dueDate = dat;
    }
    

    book(string title, string author, string isbn, string publication);
    ~book();
};

book::book(string title, string author, string isbn, string publication)
{
    Title = title;
    Author = author;
    ISBN = isbn;
    Publication = publication;
    isAvailable = true;
}

book::~book()
{
}
