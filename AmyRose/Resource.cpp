// Amy-Rose Masic 28789646

#include "Resource.h"

std::string Book::asString() {
    return "[Book] ID: " + ID + " | Title: " + title + " | Author: " + author + 
           " | Year: " + std::to_string(year) + " | Status: " + 
           (isBorrowed ? "Borrowed" : "Available ");
}

std::string Journal::asString() {
    return "[Journal] ID: " + ID + " | Title: " + title + " | Volume: " + 
           std::to_string(volume) + " | Issues: " + issues + " | Status: " + 
           (isBorrowed ? "Borrowed" : "Available ");
}

std::string Conference::asString() {
    return "[Conference] ID: " + ID + " | Title: " + title + " | Acronym: " + 
           acronym + " | Status: Not Borrowable ";
}
