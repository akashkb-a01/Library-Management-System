#include<bits/stdc++.h>

using namespace std;

void menu();
void registr();
int login();
template <class T>
void userMenu(vector <T> lis, int inde);
void librMenu();

void profLogin(){
    system("clear");
    string userId;
    cout << "Please enter your user Id: ";
    cin >> userId;
    for (auto i = 0; i < profList.size(); i++)
    {
        if(profList[i].getId() == userId){
            cout << "Please enter your password: ";
            string userPass;
            cin >> userPass;
            while(userPass != profList[i].getPassword()){
                cout << "\nIncorrect password\nPlease enter your password: ";
                cin >> userPass;
            }
            userMenu(profList, i);
            return;
        }
    }
    cout << "User not found\nPlease re-enter correct user Id\n";
    profLogin();
}

void studLogin(){
    system("clear");
    string userId;
    cout << "Please enter your user Id: ";
    cin >> userId;
    for (auto i = 0; i < studList.size(); i++)
    {
        if(studList[i].getId() == userId){
            cout << "Please enter your password: ";
            string userPass;
            cin >> userPass;
            while(userPass != studList[i].getPassword()){
                cout << "\nIncorrect password\nPlease enter your password: ";
                cin >> userPass;
            }
            userMenu(studList, i);
            return;
        }
    }
    cout << "User not found\nPlease re-enter correct user Id\n";
    studLogin();
}

void librLogin(){
    system("clear");
    cout << "Librarian Login\n\n";
    string userId;
    cout << "Please enter your user Id: ";
    cin >> userId;
    for (auto i = 0; i < librList.size(); i++)
    {
        if(librList[i].getId() == userId){
            cout << "Please enter your password: ";
            string userPass;
            cin >> userPass;
            while(userPass != librList[i].getPassword()){
                cout << "\nIncorrect password\nPlease enter your password: ";
                cin >> userPass;
            }
            librMenu();
            return;
        }
    }
    cout << "User not found\nPlease re-enter correct user Id\n";
    librLogin();
}


// void registr(){
//     system("clear");
//     cout << "Welcome to Library Management System \nPlease select your role from below to register \n\n1. Professor \n2. Student \n3. Librarian\n4. Go back to main menu \nPlease enter your choice (1-4): ";
//     int role;
//     cin >> role;
//     while(role < 1 || role > 4){
//         cout << "\nThe entered choice is not between 1 and 3.\nPlease enter your choice again: ";
//         cin >> role;
//     }
    
//     switch (role)
//     {
//     case 1: addProf(); menu();
//         break;

//     case 2: addStud(); menu();
//         break;

//     case 3: addLibr(); menu();
//         break;

//     case 4: menu();
//         break;

//     default: cout << "Please select correct role\n";
//         break;
//     }
//     return ;
// }

int login()
{
    system("clear");
    cout << "Welcome to Library Management System \nPlease select your role from below to login \n\n1. Professor \n2. Student \n3. Librarian\nPlease enter your choice (1-3): ";
    int role;
    cin >> role;
    while(role < 1 || role > 3){
        cout << "\nThe entered choice is not between 1 and 3.\nPlease enter your choice again: ";
        cin >> role;
    }
    cout << role << "\n";
    switch (role)
    {
    case 1: profLogin();
        break;

    case 2: studLogin();
        break;

    case 3: librLogin();
        break;

    default: cout << "Please select correct role\n";
        break;
    }
    return 0;
}

void menu(){
    system("clear");
    cout << "Welcome to Library Management System \nPlease select your preference from below \n\n1. Login \n2. Exit\nPlease enter your choice (1-2): ";
    int option;
    cin >> option;
    while(option < 1 || option > 2){
        cout << "\nThe entered preference is not between 1 and 2.\nPlease enter your preference again: ";
        cin >> option;
    }
    switch (option)
    {
    case 1: login();
        break;

    // case 2: registr();
    //     break;

    case 2: return ;
        break;

    default: cout << "Please select correct preference\n";
        break;
    }
    return ;
}

void librMenu()
{
    system("clear");
    cout << "Welcome to Library Management System \n";
    cout << "Please select a task from below options \n";
    cout << "\n1. Add new book";
    cout << "\n2. Add Student";
    cout << "\n3. Add Professor ";
    cout << "\n4. List of Books ";
    cout << "\n5. List of students ";
    cout << "\n6. List of professors ";
    cout << "\n7. Search book by Title";
    cout << "\n8. Search book by ISBN";
    cout << "\n9. Search student by ID";
    cout << "\n10. Search Professor by ID";
    cout << "\n11. Update book";
    cout << "\n12. Update student details";
    cout << "\n13. Update professor details";
    cout << "\n14. Delete book";
    cout << "\n15. Delete Student";
    cout << "\n16. Delete Professor";
    cout << "\n17. Logout ";
    cout << "\nPlease enter your choice (1-17): ";
    int task;
    cin >> task;
    while(task < 1 || task > 17){
        cout << "Entered task is not between given range \nPlease enter task again: ";
        cin >> task;
    }
    char temp;
    switch (task)
    {
    case 1: addBook(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;
    
    case 4: displayLibr(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 2: addStud(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 3: addProf(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 5: listStud(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 6: listProf(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 7: searchByTitle(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;
    
    case 8: searchByISBN(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;
    
    
    case 9: searchUserbyId(studList); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 10: searchUserbyId(profList); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 11: updateBook(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 12: updateStud(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 13: updateProf(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 14: deleteBook(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 15: deleteStud(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 16: deleteUser(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')librMenu();
        break;

    case 17: menu();
        break;

    default: cout << "\n";
        break;
    }
    return ;
}

template <class T>
void userMenu(vector <T> lis, int inde){

    system("clear");
    cout << "Welcome to Library Management System ";
    cout << "\nPlease select a task from below options \n";
    cout << "\n1. List of books ";
    cout << "\n2. Issued books";
    cout << "\n3. Logout ";
    cout << "\nPlease enter your choice (1-3): ";
    int task;
    cin >> task;
    while(task < 1 || task > 3){
        cout << "Entered task is not between given range \nPlease enter task again: ";
        cin >> task;
    }
    char temp;
    switch (task)
    {
    case 1: displayUser(); cout << "Enter y to go back to previous menu: "; cin >> temp; if(temp == 'y')userMenu(lis, inde);
        break;

    case 2: 
        lis[inde].displayUserBook(); 
        cout << "Enter y to go back to previous menu: "; 
        cin >> temp; 
        if(temp == 'y')userMenu(lis, inde);
        break;

    case 3: return menu();

    default: cout << "\n";
        break;
    }
    return ;
}
