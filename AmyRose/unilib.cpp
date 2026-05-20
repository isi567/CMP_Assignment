// Amy-Rose Masic 28789646
 


#include "Person.h"
#include "Resource.h"
#include "UserList.h"
#include "ResourceList.h"
#include "Loan.h"
#include <iostream>
#include <vector>
#include <memory> // for smart pointers

namespace {
template <typename T>
std::shared_ptr<T> findById(const std::vector<std::shared_ptr<T>>& items, const std::string& id) {
    for (const auto& item : items) {
        if (item->getID() == id) {
            return item;
        }
    }
    return nullptr;
}
}

void displayMenu() {
    std::cout << "\nLibrary Management System" << std::endl;
    std::cout << "1. List users with loaned books" << std::endl;
    std::cout << "2. List all available resources" << std::endl;
    std::cout << "3. List all loaned resources" << std::endl;
    std::cout << "4. Borrow a resource" << std::endl;
    std::cout << "5. Return a resource" << std::endl;
    std::cout << "6. Show user details" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "================================\n" << std::endl;
}

void listUsers(const std::vector<std::shared_ptr<Person>>& users) {
    std::cout << "\n--- Users with loaned books ---" << std::endl;
    for (const auto& user : users) {
        if (!user->getBorrowedResources().empty()) {
            std::cout << user->asString() << std::endl;
        }
    }
}

void listResources(const std::vector<std::shared_ptr<Resource>>& resources) {
    std::cout << "\n--- All Available Resources ---" << std::endl;
    for (const auto& resource : resources) {
        if (!resource->getIsBorrowed()) {
            std::cout << resource->asString() << std::endl;
        }
    }
}

void listLoanedResources(const std::vector<std::shared_ptr<Resource>>& resources) {
    std::cout << "\n--- All Loaned Resources ---" << std::endl;
    for (const auto& resource : resources) {
        if (resource->getIsBorrowed()) {
            std::cout << resource->asString() << std::endl;
        }
    }
}

void borrowResource(std::vector<std::shared_ptr<Person>>& users, std::vector<std::shared_ptr<Resource>>& resources) {
    std::cout << "Enter user ID: ";
    int userId;
    std::cin >> userId;

    std::cout << "Enter resource ID: ";
    std::string resourceId;
    std::cin >> resourceId;

    std::string message;
    LoanOps::borrowResource(users, resources, userId, resourceId, message);
    std::cout << message << std::endl;
}

void returnResource(std::vector<std::shared_ptr<Person>>& users, std::vector<std::shared_ptr<Resource>>& resources) {
    std::cout << "Enter user ID: ";
    int userId;
    std::cin >> userId;

    std::cout << "Enter resource ID: ";
    std::string resourceId;
    std::cin >> resourceId;

    std::string message;
    LoanOps::returnResource(users, resources, userId, resourceId, message);
    std::cout << message << std::endl;
}

void showUserDetails(const std::vector<std::shared_ptr<Person>>& users, const std::vector<std::shared_ptr<Resource>>& resources) {
    std::cout << "Enter user ID: ";
    int userId;
    std::cin >> userId;

    if (userId < 1 || userId > static_cast<int>(users.size())) {
        std::cout << "Invalid user ID" << std::endl;
        return;
    }

    auto user = users[static_cast<size_t>(userId - 1)];
    std::cout << "\n--- User Details ---" << std::endl;
    std::cout << user->asString() << std::endl;

    auto borrowed = user->getBorrowedResources();
    if (borrowed.empty()) {
        std::cout << "No resources currently borrowed" << std::endl;
        return;
    }

    std::cout << "Borrowed resources:" << std::endl;
    for (const auto& resId : borrowed) {
        auto resource = findById(resources, resId);
        if (resource) {
            std::cout << "  - " << resource->getTitle() << " (" << resId << ")" << std::endl;
        }
    }
}

void runLibrary(std::vector<std::shared_ptr<Person>>& users, std::vector<std::shared_ptr<Resource>>& resources) {
    int choice;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                listUsers(users);
                break;
            case 2:
                listResources(resources);
                break;
            case 3:
                listLoanedResources(resources);
                break;
            case 4:
                borrowResource(users, resources);
                break;
            case 5:
                returnResource(users, resources);
                break;
            case 6:
                showUserDetails(users, resources);
                break;
            case 7:
                std::cout << "Exiting Library Management System" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}


// https://www.geeksforgeeks.org/cpp/library-management-system-2/ for menu 

// Entry point of the program
int main() {
    std::vector<std::shared_ptr<Person>> users;
    std::vector<std::shared_ptr<Resource>> resources;

    if (!UserListOps::loadUsers("A2UserList.txt", users)) {
        return 1;
    }

    if (!ResourceListOps::loadResources("A2ResourceList.txt", resources)) {
        return 1;
    }

    std::cout << "=== Welcome to the Library Management System ===" << std::endl;
    std::cout << "Users and resources loaded successfully!" << std::endl;

    runLibrary(users, resources);

    return 0;
}
   

