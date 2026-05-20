// Amy-Rose Masic 28789646

// importing user from file (loadUsers in unilib.cpp)

// references:
// - https://www.cplusplus.com/doc/tutorial/files/

#include "UserList.h"
#include <fstream> // for file I/O
#include <iostream>

namespace {
	void stripTrailingCarriageReturn(std::string& s) {
		if (!s.empty() && s.back() == '\r') {
			s.pop_back();
		}
	}
}

// Load users from file
namespace UserListOps {
	bool loadUsers(const std::string& filename, std::vector<std::shared_ptr<Person>>& users) {
		std::ifstream file(filename);
		if (!file) {
			std::cerr << "Error: Could not open " << filename << std::endl;
			return false;
		}

		users.clear();

		std::string line;
		int userId = 1;
		while (std::getline(file, line)) {
			stripTrailingCarriageReturn(line);

			if (line.empty() || line[0] == '#') {
				continue;
			}

			const char userType = line[0];
			const std::string userName = line.substr(1);

			if (userType == '1') {
				users.push_back(std::make_shared<Student>(userId, userName));
			}
			else if (userType == '2') {
				users.push_back(std::make_shared<Staff>(userId, userName));
			}
			else if (userType == '3') {
				users.push_back(std::make_shared<LibStaff>(userId, userName));
			}
			++userId;
		}

		return true;
	}
}