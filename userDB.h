#include<bits/stdc++.h>
#include<ctime>

vector <Professor> profList;
vector <Student> studList;
vector <Librarian> librList;

template <class T>
bool idExists(string id, vector <T> lis){
    if(sizeof(lis) == 0) return true;
    else{
        for(auto i=0; i< lis.size(); i++){
            if(id == lis[i].getId()) return true;
        }
    }
    return false;
}

void addProf(){
    system("clear");
    string id, password, name;
    cout << "Please enter id: ";
    cin >> id;
    while(idExists(id, profList)){
        cout << "\nId is already in use.\nPlease enter another id: ";
        cin >> id;
    }
    cout << "\nPlease enter name: ";
    cin >> name;
    cout << "\nPlease enter password: ";
    cin >> password;

    Professor temp(id, password, name);
    profList.push_back(temp);
    cout << "User created successfully\n";
}

void addStud(){
    system("clear");
    string id, password, name;
    cout << "Please enter id: ";
    cin >> id;
    while(idExists(id, studList)){
        cout << "\nId is already in use.\nPlease enter another id: ";
        cin >> id;
    }
    cout << "\nPlease enter name: ";
    cin >> name;
    cout << "\nPlease enter password: ";
    cin >> password;

    Student temp(id, password, name);
    studList.push_back(temp);
    cout << "User created successfully\n";
}

void listStud(){
    system("clear");
    cout << "List of students\n\n";
    for(auto i=0; i< studList.size(); i++){
        cout << "Name of student: " << studList[i].getName() << "\nID of student: " << studList[i].getId() << '\n' ; studList[i].calculateFine(); studList[i].displayUserBook();
    }
}

void listProf(){
    system("clear");
    cout << "List of professors\n\n";
    for(auto i=0; i< profList.size(); i++){
        cout << "Name of professor: " << profList[i].getName() << "\nID of professor: " << profList[i].getId() << '\n' ; profList[i].calculateFine(); profList[i].displayUserBook();
    }
}

template <class T>
int searchUserbyId(vector <T> lis){
    system("clear");
    string id;
    cin >> id;
    cout << "Please enter user ID: ";
    cin >> id;
    
    for(auto i = 0; i < lis.size(); i++){
        if(id == lis[i].getId()){
            cout << "\nName: " << lis[i].getName() << "\nID: " << lis[i].getId() << "\n\n";
            return i;
        }
    }
    
    cout << "No such user found\n\n";
    return -1;
}

void updateProf(){
    system("clear");
    cout << "To update user details enter ID: ";
    int inde = searchUserbyId(profList);

    int exi = 1;
    while(exi){
        system("clear");
        cout << "Update\n\n";
        cout << "1. Name\n";
        cout << "2. Password\n";
        cout << "3. Issue book\n";
        cout << "4. Clear dues\n";
        cout << "5. Save changes\n";
        cout << "Please select from the given options (1-5): ";

        int choi;
        string temp;
        cin >> choi ;

        switch (choi)
        {
        case 1:
            cout << "Enter new name: ";
            cin >> temp;
            profList[inde].setName(temp);
            break;

        case 2:
            cout << "Enter new password: ";
            cin >> temp;
            profList[inde].setPassword(temp);
            break;

        case 3:
            cout << "Enter due date in (mm/dd/yyyy): ";
            cin >> temp;
            profList[inde].issueBook(temp);
            break;

        case 4: profList[inde].clearFine();
            break;

        case 5: exi = 0;
            break;
        
        default:
            break;
        }
    }
}

void updateStud(){
    system("clear");
    cout << "To update user details enter ID: ";
    int inde = searchUserbyId(studList);

    int exi = 1;
    while(exi){
        system("clear");
        cout << "Update\n\n";
        cout << "1. Name\n";
        cout << "2. Password\n";
        cout << "3. Issue book\n";
        cout << "4. Clear dues\n";
        cout << "5. Save changes\n";
        cout << "Please select from the given options (1-5): ";

        int choi;
        string temp;
        cin >> choi ;

        switch (choi)
        {
        case 1:
            cout << "Enter new name: ";
            cin >> temp;
            studList[inde].setName(temp);
            break;

        case 2:
            cout << "Enter new password: ";
            cin >> temp;
            studList[inde].setPassword(temp);
            break;

        case 3:
            cout << "Enter due date in (mm/dd/yyyy): ";
            cin >> temp;
            studList[inde].issueBook(temp);
            break;

        case 4: studList[inde].clearFine();
            break;

        case 5: exi = 0;
            break;
        
        default:
            break;
        }
    }
}

void deleteUser(){
    system("clear");
    cout << "To delete user details enter ID: ";
    int inde = searchUserbyId(profList);
    profList[inde].clearFine();
    if(inde != -1)profList.erase(profList.begin() + inde);
    else deleteUser();
}

void deleteStud(){
    system("clear");
    cout << "To delete user details enter ID: ";
    int inde = searchUserbyId(studList);
    studList[inde].clearFine();
    if(inde != -1)studList.erase(studList.begin() + inde);
    else deleteStud();
}