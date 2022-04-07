#include<bits/stdc++.h>
#include "book.h"
#include "bookDB.h"
#include "user.h"
#include "userDB.h"
#include "login.h"

using namespace std;


int init()
{
    Professor prof0("profid1","profpassword1","profname1");
    profList.push_back(prof0);

    Professor prof1("profid2","profpassword2","profname2");
    profList.push_back(prof1);

    Professor prof2("profid3","profpassword3","profname3");
    profList.push_back(prof2);

    Student stud0("studid1","studpassword1","studname1");
    studList.push_back(stud0);
    
    Librarian libr0("librid1","librpassword1","librname1");
    librList.push_back(libr0);

    Librarian libr1("librid2","librpassword2","librname2");
    librList.push_back(libr1);

    return 0;
}

int main()
{
    init();
    menu();

    return 0;
}
