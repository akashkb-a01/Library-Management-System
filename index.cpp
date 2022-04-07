#include<bits/stdc++.h>
#include "book.h"
#include "bookDB.h"
#include "user.h"
#include "userDB.h"
#include "login.h"

using namespace std;

int main()
{
    Librarian temp("i", "p", "librName");
    librList.push_back(temp);

    Student temp1("i", "p", "librName");
    studList.push_back(temp1);

    //cout << "User created successfully\n";
    menu();
    //studList[0].calculateFine();

    return 0;
}
