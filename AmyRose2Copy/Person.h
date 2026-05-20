// Amy-Rose Masic 28789646

#ifndef PERSON_H
#define PERSON_H

// rename to person.h

#include <string>
#include <iostream>
#include <vector>

class Person {
protected:
    int ID;
    std::string name;
    int borrow_limit;
    std::vector<std::string> borrowed_resources;

public:
    Person(int id, std::string n, int limit)
        : ID(id), name(n), borrow_limit(limit) {
    }

    virtual ~Person() {}
    virtual std::string asString() = 0;

    int getBorrowLimit() { return borrow_limit; }
    int getID() { return ID; }
    std::string getName() { return name; }

    size_t getNumBorrowed() { return borrowed_resources.size(); }
    bool canBorrow() { return static_cast<int>(getNumBorrowed()) < borrow_limit; }

    void addBorrowedResource(std::string resourceID) {
        if (canBorrow()) {
            borrowed_resources.push_back(resourceID);
        }
    }

    bool returnResource(std::string resourceID) {
        for (auto it = borrowed_resources.begin(); it != borrowed_resources.end(); ++it) {
            if (*it == resourceID) {
                borrowed_resources.erase(it);
                return true;
            }
        }
        return false;
    }

    std::vector<std::string> getBorrowedResources() { return borrowed_resources; }
};

class Student : public Person {
public:
    Student(int id, std::string n);
    std::string asString();
};

class Staff : public Person {
public:
    Staff(int id, std::string n);
    std::string asString();
};

class LibStaff : public Person {
public:
    LibStaff(int id, std::string n);
    std::string asString();
};

#endif
