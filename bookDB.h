#include <bits/stdc++.h>

using namespace std;

vector <book> list_of_books;

void displayLibr();

void addBook(){
	system("clear");
	cout << "Adding new book\n\n";
	string title; 
	string author; 
	string isbn;
	string publication;

	cout << "Please enter Title of the book to be added: ";
	cin >> title;
	cout << "Please enter Author of the book to be added: ";
	cin >> author;
	cout << "Please enter ISBN of the book to be added: ";
	cin >> isbn;
	cout << "Please enter Publication of the book to be added: ";
	cin >> publication;

	book Book(title, author, isbn, publication);
	list_of_books.push_back(Book);
	cout << "Book Added Successfully\n";
}

void displayLibr(){
	system("clear");
	cout << "List of books\n\n";
	for(auto i=0; i < list_of_books.size(); i++){
		cout << "Title: " << list_of_books[i].getTitle() << '\n' << "Author: " << list_of_books[i].getAuthor() << '\n' << "ISBN: " << list_of_books[i].getISBN() << '\n' << "Publication: " << list_of_books[i].getPublication() << "\nAvailable: " << list_of_books[i].availibility() << "\nIssuer: " << list_of_books[i].getIssuer() << "\nDue Date (mm/dd/yyyy): " << list_of_books[i].getDueDate() << "\n\n";
	}
}

void displayUser(){
	system("clear");
	cout << "List of books\n\n";
	for(auto i=0; i < list_of_books.size(); i++){
		cout << "Title: " << list_of_books[i].getTitle() << '\n' << "Author: " << list_of_books[i].getAuthor() << '\n' << "ISBN: " << list_of_books[i].getISBN() << '\n' << "Publication: " << list_of_books[i].getPublication() << "\nAvailable: " << list_of_books[i].availibility() << "\n\n";
	}
}

int searchByTitle(){
	system("clear");
	cout << "Enter title of the book: ";
	string title;
	cin >> title;
	for(auto i = 0; i< list_of_books.size(); i++){
		if(list_of_books[i].getTitle() == title){
			cout << "\n\nTitle: " << list_of_books[i].getTitle() << '\n' << "Author: " << list_of_books[i].getAuthor() << '\n' << "ISBN: " << list_of_books[i].getISBN() << '\n' << "Publication: " << list_of_books[i].getPublication() << "\nAvailable: " << list_of_books[i].availibility() << "\n\n";
			return i;
		}
	}
	cout << "No such books found\n";
	return -1;
}

int searchByISBN(){
	system("clear");
	cout << "Enter ISBN of the book: ";
	string title;
	cin >> title;
	for(auto i = 0; i< list_of_books.size(); i++){
		if(list_of_books[i].getISBN() == title){
			cout << "\n\nTitle: " << list_of_books[i].getTitle() << '\n' << "Author: " << list_of_books[i].getAuthor() << '\n' << "ISBN: " << list_of_books[i].getISBN() << '\n' << "Publication: " << list_of_books[i].getPublication() << "\nAvailable: " << list_of_books[i].availibility() << "\n\n";
			return i;
		}
	}
	cout << "No such books found\n";
	return -1;
}

void updateBook(){
	system("clear");
	cout << "To update book find it by its \n\n";
	cout << "1. Title\n";
	cout << "2. ISBN\n";
	cout << "Enter your choice (1-2): ";
	int choi, inde;
	inde = -1;
	cin >> choi;
	while(choi < 1 || choi > 2){
        cout << "\nThe entered preference is not between 1 and 2.\nPlease enter your preference again: ";
        cin >> choi;
    }
	switch (choi)
	{
	case 1: inde = searchByTitle();
		break;

	case 2: inde = searchByISBN();
		break;

	default: updateBook();
		break;
	}
	int exi = 1;
	while(exi){
	if(inde != -1){
		system("clear");
		cout << "Update\n\n";
		cout << "1. Title\n";
		cout << "2. Author\n";
		cout << "3. ISBN\n";
		cout << "4. Publication\n";
		cout << "5. Availibility\n";
		cout << "6. Issuer\n";
		cout << "7. Due date\n";
		cout << "8. Save changes\n";
		cout << "Please select from the given options (1-8): ";

		cin >> choi;
		string temp;
		switch (choi)
		{
		case 1:
			cout << "Enter new title: ";
			cin >> temp;
			list_of_books[inde].setTitle(temp);
			break;

		case 2:
			cout << "Enter new author: ";
			cin >> temp;
			list_of_books[inde].setAuthor(temp);
			break;

		case 3:
			cout << "Enter new ISBN: ";
			cin >> temp;
			list_of_books[inde].setISBN(temp);
			break;

		case 4:
			cout << "Enter new publication: ";
			cin >> temp;
			list_of_books[inde].setPublication(temp);
			break;
		
		case 5:
			cout << "Enter availibility (1/0): ";
			bool te;
			cin >> te;
			list_of_books[inde].setAvailibility(te);
			break;

		case 6:
			cout << "Enter new issuer: ";
			cin >> temp;
			list_of_books[inde].setIssuer(temp);
			break;

		case 7:
			cout << "Enter due date (mm/dd/yyyy): ";
			cin >> temp;
			list_of_books[inde].setDueDate(temp);
			break;

		case 8: exi = 0;
			break;

		default:
			break;
		}
	}}
}

void deleteBook(){
	system("clear");
	cout << "To delete book find it by its \n\n";
	cout << "1. Title\n";
	cout << "2. ISBN\n";
	cout << "Enter your choice (1-2): ";
	int choi, inde;
	inde = -1;
	cin >> choi;
	while(choi < 1 || choi > 2){
        cout << "\nThe entered preference is not between 1 and 2.\nPlease enter your preference again: ";
    	cin >> choi;
    }
	switch (choi)
	{
	case 1: inde = searchByTitle();
		break;

	case 2: inde = searchByISBN();
		break;

	default: updateBook();
		break;
	}
	list_of_books.erase(list_of_books.begin() + inde);
	cout << "\n\n Deleted the above book!!!|n";
	return;
}
