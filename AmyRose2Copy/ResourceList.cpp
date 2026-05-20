// Amy-Rose Masic 28789646

// load resources (unilib.cpp)

// references:
// - https://www.cplusplus.com/doc/tutorial/files/
// - https://www.cplusplus.com/reference/string/string 

#include "ResourceList.h"

#include <fstream>
#include <iostream>

namespace {
	enum class Section { Books, Journals, Conferences };

	void stripTrailingCarriageReturn(std::string& s) {
		if (!s.empty() && s.back() == '\r') {
			s.pop_back();
		}
	}

	std::string normaliseAuthor(const std::string& line) {
		const auto comma = line.find(',');
		if (comma == std::string::npos) {
			return line;
		}

		std::string author = line.substr(0, comma);
		std::string name = line.substr(comma + 1);
		while (!name.empty() && name.front() == ' ') {
			name.erase(name.begin());
		}
		return author + " " + name;
	}

	std::string parseJournalIssues(const std::string& line, int& volume) {
		const auto colon = line.find(':');
		if (colon == std::string::npos) {
			volume = 1;
			return line;
		}

		volume = std::stoi(line.substr(0, colon));
		std::string issues = line.substr(colon + 1);
		while (!issues.empty() && issues.front() == ' ') {
			issues.erase(issues.begin());
		}
		return issues;
	}
}

namespace ResourceListOps {
	bool loadResources(const std::string& filename, std::vector<std::shared_ptr<Resource>>& resources) {
		std::ifstream file(filename);
		if (!file) {
			std::cerr << "Error: Could not open " << filename << std::endl;
			return false;
		}

		resources.clear();

		std::vector<std::string> lines;
		std::string line;
		while (std::getline(file, line)) {
			stripTrailingCarriageReturn(line);
			lines.push_back(line);
		}

		int bookId = 1;
		int journalId = 1;
		int conferenceId = 1;
		Section section = Section::Books;
		std::string currentJournalTitle;

		for (size_t i = 0; i < lines.size(); ++i) {
			const std::string& currentLine = lines[i];

			if (currentLine.empty()) {
				continue;
			}

			if (currentLine.find("RESOURCE LIST") != std::string::npos) {
				section = Section::Books;
				currentJournalTitle.clear();
				continue;
			}

			if (currentLine == "#####") {
				continue;
			}

			if (currentLine.find("Transactions") != std::string::npos) {
				section = Section::Journals;
				currentJournalTitle = currentLine;
				continue;
			}

			if (section == Section::Books) {
				if (currentLine[0] == '#') {
					continue;
				}

				if (i + 2 >= lines.size()) {
					break;
				}

				const std::string title = lines[++i];
				const std::string yearLine = lines[++i];
				resources.push_back(std::make_shared<Book>(
					"B" + std::to_string(bookId++),
					title,
					normaliseAuthor(currentLine),
					std::stoi(yearLine)));
				continue;
			}

			if (section == Section::Journals) {
				if (currentLine.find("Conference") != std::string::npos) {
					section = Section::Conferences;
				}
				else if (!currentJournalTitle.empty()) {
					int volume = 1;
					const std::string issues = parseJournalIssues(currentLine, volume);
					resources.push_back(std::make_shared<Journal>(
						"J" + std::to_string(journalId++),
						currentJournalTitle,
						volume,
						issues));
					continue;
				}
				else {
					continue;
				}
			}

			if (section == Section::Conferences) {
				if (currentLine[0] == '#') {
					continue;
				}

				if (i + 1 >= lines.size()) {
					break;
				}

				const std::string acronym = lines[++i];
				resources.push_back(std::make_shared<Conference>(
					"C" + std::to_string(conferenceId++),
					currentLine,
					acronym));
			}
		}

		return true;
	}
}