cmd + shift + b --> build project 
./build/Debug/outDebug --> run project


library Management System
This project implements a simple University Library Management System in C++. 
The system allows users to manage library resources, including books and journals, 
and provides functionalities for borrowing and returning resources.

features
- List users with loaned books
- List all available resources
- List all loaned resources
- Borrow a resource
- Return a resource
- Show user details 

classes
- `Person`: represents a person with a name and ID.
- `Resource`: represents a library resource with attributes like title, author, and availability
- `Loan`: represents a loan transaction, linking a user to a resource and tracking the loan date.
- `UserList`: manages a list of users and their loaned resources.
- `ResourceList`: manages a list of library resources and their availability.

files
- `unilib.cpp`: contains the main function and user interface for the library management system.
- `UserList.cpp` and `UserList.h`: implement the `UserList` class
- `ResourceList.cpp` and `ResourceList.h`: implement the `ResourceList` class
- `Loan.cpp` and `Loan.h`: implement the `Loan` class



