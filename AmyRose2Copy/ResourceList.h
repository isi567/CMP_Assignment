// Amy-Rose Masic 28789646

#ifndef RESOURCELIST_H
#define RESOURCELIST_H

#include "Resource.h"
#include <memory>
#include <string>
#include <vector>

namespace ResourceListOps {
	bool loadResources(const std::string& filename, std::vector<std::shared_ptr<Resource>>& resources);
}

#endif
