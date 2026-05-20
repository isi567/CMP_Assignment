
#ifndef RESOURCES_H
#define RESOURCES_H

#include <string>
#include <iostream>

class Resource {
protected:
    std::string ID;
    std::string title;
    bool isBorrowed;
    bool canLend;

public:
    Resource(std::string id, std::string t, bool lendable) 
        : ID(id), title(t), isBorrowed(false), canLend(lendable) {}
    
    virtual ~Resource() {}
    virtual std::string asString() = 0; // Pure virtual for polymorphism
    
    // Getters
    std::string getID() { return ID; }
    std::string getTitle() { return title; }
    bool getCanLend() { return canLend; }
    bool getIsBorrowed() { return isBorrowed; }
    void setBorrowed(bool status) { isBorrowed = status; }
};

class Book : public Resource {
private:
    std::string author;
    int year;

public:
    Book(std::string id, std::string t, std::string a, int y)
        : Resource(id, t, true), author(a), year(y) {}
    
    std::string asString();
    std::string getAuthor() { return author; }
    int getYear() { return year; }
};

class Journal : public Resource {
private:
    int volume;
    std::string issues;

public:
    Journal(std::string id, std::string t, int v, std::string iss)
        : Resource(id, t, true), volume(v), issues(iss) {}
    
    std::string asString();
    int getVolume() { return volume; }
    std::string getIssues() { return issues; }
};

class Conference : public Resource {
private:
    std::string acronym;

public:
    Conference(std::string id, std::string t, std::string acr)
        : Resource(id, t, false), acronym(acr) {}
    
    std::string asString();
    std::string getAcronym() { return acronym; }
};

#endif

