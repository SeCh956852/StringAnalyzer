#include "StrAnalyzer.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>


StrAnalyzer::StrAnalyzer(std::string text) :
text(text)
{
	
}

std::string StrAnalyzer::getString() {
	return text;
}

void StrAnalyzer::setString(std::string newString) {
	text = newString;
}

int StrAnalyzer::charCount() {
	return text.size();
}

std::map<char,int> StrAnalyzer::charBreakdown() {
	std::map<char, int> mapCharCount;
	for (int i = 0; i < text.size(); i++) {
		char c = text[i];
		if (mapCharCount.count(c)) {
			mapCharCount[c]++;
		}
		else {
			mapCharCount.insert(std::pair<char, int>(c, 1));
		}
	}
	return mapCharCount;
}


std::string StrAnalyzer::trim() {
	std::size_t firstChar = text.find_first_not_of(" \n\r\t");
	std::size_t lastChar = text.find_last_not_of(" \n\r\t");
	int properLength = lastChar - firstChar + 1;
	std::string trimmed = text.substr(firstChar, properLength);
	return trimmed;
}


std::vector<std::string> StrAnalyzer::split(std::string delim) {
	std::string text = trim();
	std::vector<std::string> stringVector;

	std::size_t index = 0;
	std::size_t endIndex = 0;

	while (true) {
		index = text.find(delim, index + 1);

		if (index != std::string::npos) {
			endIndex = endIndex == 0 ? endIndex : ++endIndex;
			std::string sub = text.substr(endIndex, index - endIndex);
			stringVector.push_back(sub);
			endIndex = index;
		}
		else {
			endIndex = endIndex == 0 ? endIndex : ++endIndex;
			std::string sub = text.substr(endIndex);
			stringVector.push_back(sub);
			
			break;
		}
	}

	return stringVector;
}


int StrAnalyzer::wordCount() {
	std::vector<std::string> stringVector = split(" ");
	return stringVector.size();
}

int StrAnalyzer::countOccurances(std::string searchString) {
	int count = 0;
	size_t index = 0;
	size_t length = searchString.size();

	while (true) {
		size_t pos = text.find(searchString, index);
		if (pos != std::string::npos) {
			count++;
			index = pos + length;
		}
		else {
			break;
		}
	}

	return count;
}
