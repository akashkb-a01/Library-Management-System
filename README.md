# Library-Management-System

For running the program first `clone` using `git clone https://github.com/akashkb-a01/Library-Management-System.git`.\
After navigating to the folder open a terminal and enter \
`g++ index.cpp` \
`./a.out` 
## Following are some login credentials 
For Professor \
Id: `profid1`\
Password: `profpassword1`\
Id: `profid2`\
Password: `profpassword2`\
For Student \
Id: `studid1`\
Password: `studpassword1`\
For Librarian \
Id: `librid1`\
Password: `librpassword1` \
Id: `librid2`\
Password: `librpassword2`
### Librarian can add more Students and Professors after logging in
Librarian can issue books to the users. Whereas users can see the list of the books they have issued in their name.\
Librarian can do following things
1. Add new book
2. Add Student
3. Add Professor 
4. List of Books 
5. List of students 
6. List of professors 
7. Search book by Title
8. Search book by ISBN
9. Search student by ID
10. Search Professor by ID
11. Update book
12. Update student details
13. Update professor details
14. Delete book
15. Delete Student
16. Delete Professor
17. Logout 

Whereas normal users have access to these following functions 
1. List of books 
2. Issued books
3. Calculate Fine amount
4. Logout 

Librarian can issue book to student or clear dues using `Update Student details`, similar action can be done for Professor using option 13. Students can only issue 5 books whereas, there is no such limit for the Professor. \
The normal users can see the list of books but it is different from that of the librarian, as they cannot see the book issuer and the due date.
