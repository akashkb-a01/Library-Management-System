#include<bits/stdc++.h>
#include<ctime>

using namespace std;

class User
{
private:
    string Id;
    string Password;
    string Name;

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

};

const int monthDays[12] = { 31, 59, 90, 120, 151, 181, 212, 243,
273, 304, 334, 365 };
int countLeapYearDays(int d[]){
   int years = d[2];
   if (d[1] <= 2)
      years--;
   return ( (years / 4) - (years / 100) + (years / 400) );
}
int countNoOfDays(int date1[], int date2[]){
   long int dayCount1 = (date1[2] * 365);
   dayCount1 += monthDays[date1[1]];
   dayCount1 += date1[0];
   dayCount1 += countLeapYearDays(date1);
   long int dayCount2 = (date2[2] * 365);
   dayCount2 += monthDays[date2[1]];
   dayCount2 += date2[0];
   dayCount2 += countLeapYearDays(date2);
   return dayCount1 - dayCount2;
}

class Professor: public User {
    private:
        int Fine_amount;
        

    public:
        vector <book> userBookList; 
        int getFineAmt(){
            return Fine_amount;
        }
        
        int calculateFine(){
            system("clear");
            int ans = 0;
            char s[11];
            time_t t = time(0);
            strftime(s, 11, "%m/%d/%Y", localtime(&t));
            char *pm = strtok(s,"/") ; 
            char *pd = strtok(NULL,"/") ;
            char *py = strtok(NULL,"/") ;
            int predate[3];
            predate[0] = stoi(pm);
            predate[1] = stoi(pd);
            predate[2] = stoi(py);
            for(auto i=0; i < userBookList.size(); i++){
                string nd = userBookList[i].getDueDate();
                char *dm = strtok(s,"/") ; 
                char *dd = strtok(NULL,"/") ;
                char *dy = strtok(NULL,"/") ;
                int duedate[3];
                duedate[0] = stoi(dm);
                duedate[1] = stoi(dd);
                duedate[2] = stoi(dy);
                int noOfDays = countNoOfDays(duedate,predate);
                if(noOfDays > 0) ans += (noOfDays * 5);

            }
            cout << "Total fine is: " << ans << '\n';
            return ans;
        }

        void setFineAmt(){
            Fine_amount = calculateFine();
        }

        void clearFine(){
            for(auto i = 0; i< userBookList.size(); i++){
                userBookList[i].setAvailibility(1);
                userBookList[i].setIssuer("");
                userBookList[i].setDueDate("");
            }
            userBookList.clear();
            Fine_amount = 0;
        }

        void displayUserBook(){
            for(auto i = 0; i < userBookList.size(); i++){
                cout << "Title: " << list_of_books[i].getTitle() << '\n' << "Author: " << list_of_books[i].getAuthor() << '\n' << "ISBN: " << list_of_books[i].getISBN() << '\n' << "Publication: " << list_of_books[i].getPublication() << "\n\n";
            }
        }

        void issueBook(string dat){
            system("clear");
            cout << "To issue book find it by its \n\n";
	        cout << "1. Title\n";
	        cout << "2. ISBN\n";
	        cout << "Enter your choice (1-2): ";
	        int choi, inde;
	        inde = -1;
	        cin >> choi;
	        switch (choi)
	        {
	        case 1: inde = searchByTitle();
		        break;

	        case 2: inde = searchByISBN();
		        break;

	        default: 
		        break;
	        }
            list_of_books[inde].setIssuer(getId());
            list_of_books[inde].setAvailibility(0);
            list_of_books[inde].setDueDate(dat);
            userBookList.push_back(list_of_books[inde]);
        }

        Professor(string id, string password, string name){
            setId(id);
            setPassword(password);
            setName(name);
            setFineAmt();
        }
};

class Student: public User {
    private:
        int Fine_amount;
        
    public:
        vector <book> userBookList;
        int getFineAmt(){
            return Fine_amount;
        }

        int calculateFine(){
            system("clear");
            int ans = 0;
            char s[11];
            time_t t = time(0);
            strftime(s, 11, "%m/%d/%Y", localtime(&t));
            char *pm = strtok(s,"/") ; 
            char *pd = strtok(NULL,"/") ;
            char *py = strtok(NULL,"/") ;
            int predate[3];
            predate[1] = stoi(pm);
            predate[0] = stoi(pd);
            predate[2] = stoi(py);
            
            for(auto i=0; i < userBookList.size(); i++){
                cout << "k";
                string nd = userBookList[i].getDueDate();
                char *dm = strtok(s,"/") ; 
                char *dd = strtok(NULL,"/") ;
                char *dy = strtok(NULL,"/") ;
                int duedate[3];
                duedate[1] = stoi(dm);
                duedate[0] = stoi(dd);
                duedate[2] = stoi(dy);
                int noOfDays = countNoOfDays(duedate,predate);
                if(noOfDays > 0) ans += (noOfDays * 2);

            }
            cout << "Total fine is: " << ans << "\n\n";
            
            return ans;
        }

        void setFineAmt(){
            Fine_amount = calculateFine();
        }

        void clearFine(){
            for(auto i = 0; i< userBookList.size(); i++){
                userBookList[i].setAvailibility(1);
                userBookList[i].setIssuer("");
                userBookList[i].setDueDate("");
            }
            userBookList.clear();
            Fine_amount = 0;
        }

        void displayUserBook(){
            for(auto i = 0; i < userBookList.size(); i++){
                cout << "Title: " << list_of_books[i].getTitle() << '\n' << "Author: " << list_of_books[i].getAuthor() << '\n' << "ISBN: " << list_of_books[i].getISBN() << '\n' << "Publication: " << list_of_books[i].getPublication() << "\n\n";
            }
        }

        void issueBook(string dat){
            if(userBookList.size() < 5)
            {system("clear");
            cout << "To issue a book find it by its \n\n";
	        cout << "1. Title\n";
	        cout << "2. ISBN\n";
	        cout << "Enter your choice (1-2): ";
	        int choi, inde;
	        inde = -1;
	        cin >> choi;
	        switch (choi)
	        {
	        case 1: inde = searchByTitle();
		        break;

	        case 2: inde = searchByISBN();
		        break;

	        default: 
		        break;
	        }
            list_of_books[inde].setIssuer(getId());
            list_of_books[inde].setAvailibility(0);
            list_of_books[inde].setDueDate(dat);
            userBookList.push_back(list_of_books[inde])
            ;
            }
            else cout << "User book issue limit exceeded\n\n";

        }

        Student(string id, string password, string name){
            setId(id);
            setPassword(password);
            setName(name);
            setFineAmt();
        }
    
};

class Librarian: public User {
    public:
        Librarian(string id, string password, string name){
            setId(id);
            setPassword(password);
            setName(name);
        }

        ~Librarian(void){};
};
