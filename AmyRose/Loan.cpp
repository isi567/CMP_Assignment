// Amy-Rose Masic 28789646

// borrow resource  (borrowResource in unilib.cpp)
// returning resource (returnResource in unilib.cpp)

#include "Loan.h"

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

namespace LoanOps {
bool borrowResource(
	std::vector<std::shared_ptr<Person>>& users,
	std::vector<std::shared_ptr<Resource>>& resources,
	int userId,
	const std::string& resourceId,
	std::string& message) {
	if (userId < 1 || userId > static_cast<int>(users.size())) {
		message = "Invalid user ID";
		return false;
	}

	auto resource = findById(resources, resourceId);
	if (!resource) {
		message = "Resource not found";
		return false;
	}

	if (!resource->getCanLend()) {
		message = "This resource cannot be borrowed";
		return false;
	}

	if (resource->getIsBorrowed()) {
		message = "This resource is already borrowed";
		return false;
	}

	auto user = users[static_cast<size_t>(userId - 1)];
	if (!user->canBorrow()) {
		message = "User has reached their borrow limit";
		return false;
	}

	user->addBorrowedResource(resourceId);
	resource->setBorrowed(true);
	message = "Resource successfully borrowed!";
	return true;
}

bool returnResource(
	std::vector<std::shared_ptr<Person>>& users,
	std::vector<std::shared_ptr<Resource>>& resources,
	int userId,
	const std::string& resourceId,
	std::string& message) {
	if (userId < 1 || userId > static_cast<int>(users.size())) {
		message = "Invalid user ID";
		return false;
	}

	auto resource = findById(resources, resourceId);
	if (!resource) {
		message = "Resource not found";
		return false;
	}

	auto user = users[static_cast<size_t>(userId - 1)];
	if (!user->returnResource(resourceId)) {
		message = "User does not have this resource borrowed";
		return false;
	}

	resource->setBorrowed(false);
	message = "Resource successfully returned!";
	return true;
}
}