#include<bits/stdc++.h>

using namespace std;

class User
{
private:
    string Name;
    string Id;
    string Password;

public:
    string getName(void){
        return Name;
    }

    void setName(string name){
        Name = name;
    }

    string getId(void){
        return Id;
    }

    void setId(string id){
        Id = id;
    }

    string getPassword(void){
        return Password;
    }

    void setPassword(string password){
        Password = password;
    }

    User(string name, string id, string password);
    ~User();
};

User::User(string name, string id, string password)
{
    Name = name;
    Id = id;
    Password = password;
}

User::~User(void)
{
}

class Professor: public User {
    private:
        int Fine_amount;
};

class Student: public User {
    
};

class Librarian: public User {
    
};