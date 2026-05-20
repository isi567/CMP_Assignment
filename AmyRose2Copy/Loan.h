// Amy-Rose Masic 28789646

#ifndef LOAN_H
#define LOAN_H

#include "Resource.h"
#include "Person.h"
#include <memory>
#include <string>
#include <vector>

namespace LoanOps {
	bool borrowResource(
		std::vector<std::shared_ptr<Person>>& users,
		std::vector<std::shared_ptr<Resource>>& resources,
		int userId,
		const std::string& resourceId,
		std::string& message);

	bool returnResource(
		std::vector<std::shared_ptr<Person>>& users,
		std::vector<std::shared_ptr<Resource>>& resources,
		int userId,
		const std::string& resourceId,
		std::string& message);
}

#endif
