// Amy-Rose Masic 28789646

// rename to person.cpp

#include "Person.h"
#include <string>
#include <sstream>

// --- Student ---
// Students are initialised with a borrow limit of 1 
Student::Student(int id, std::string n) 
    : Person(id, n, 1) {} 

std::string Student::asString() {
    return "[ID: " + std::to_string(ID) + "] " + name + " (Student) - Limit: 1 - Currently Borrowed: " + std::to_string(getNumBorrowed());
}

// --- Staff ---
// Staff are initialised with a borrow limit of 2 
Staff::Staff(int id, std::string n) 
    : Person(id, n, 2) {}

std::string Staff::asString() {
    return "[ID: " + std::to_string(ID) + "] " + name + " (Staff) - Limit: 2 - Currently Borrowed: " + std::to_string(getNumBorrowed());
}

// --- LibStaff ---
// Library Staff are initialised with a borrow limit of 0 
LibStaff::LibStaff(int id, std::string n) 
    : Person(id, n, 0) {}

std::string LibStaff::asString() {
    return "[ID: " + std::to_string(ID) + "] " + name + " (Library Staff) - Limit: 0 - Currently Borrowed: " + std::to_string(getNumBorrowed());
}