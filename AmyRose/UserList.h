// Amy-Rose Masic 28789646

#ifndef USERLIST_H
#define USERLIST_H

#include "Person.h"
#include <memory>
#include <string>
#include <vector>

namespace UserListOps {
bool loadUsers(const std::string& filename, std::vector<std::shared_ptr<Person>>& users);
}

#endif
