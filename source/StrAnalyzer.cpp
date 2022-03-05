#include "StrAnalyzer.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>


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

		endIndex = endIndex == 0 ? endIndex : ++endIndex;
		if (index != std::string::npos) {
			
			std::string sub = text.substr(endIndex, index - endIndex);
			stringVector.push_back(sub);
			endIndex = index;
		}
		else {
			
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

size_t StrAnalyzer::getArgSize(std::string A) {
	return A.size();
}

size_t StrAnalyzer::getArgSize(const char* A) {
	return 1;
}

size_t StrAnalyzer::findIndex(std::string A, size_t startPos) {
	return text.find(A, startPos);
}

size_t StrAnalyzer::findIndex(const char* A, size_t startPos) {
	return text.find_first_of(A, startPos);
}

template <class T>
int StrAnalyzer::countOccurances(T A) {
	int count = 0;
	size_t index = 0;
	size_t length = getArgSize(A);

	while (true) {
		size_t pos = findIndex(A, index);
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

bool StrAnalyzer::containsNumeric(){
	const char* numeric = "123456789";
	return countOccurances(numeric) > 0 ? true : false;
}

bool StrAnalyzer::containsLetters(){
	const char* letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return countOccurances(letters) > 0 ? true : false;
}

bool StrAnalyzer::containsSpecial(){
	const char* special = "!@#$%^&*()_+-=[]{}\|;:'\"<>,./?`~";
	return countOccurances(special) > 0 ? true : false;
}

std::string StrAnalyzer::replace(std::string targetSubstr, std::string newSubstr, size_t count = 1) {
	std::string copyString = text;
	size_t targetSubstrSize = targetSubstr.size();
	size_t newSubstrSize = newSubstr.size();
	size_t index = 0;
	for (; count > 0; count--) {
		index = copyString.find(targetSubstr, index);
		if (index != std::string::npos) {
			copyString.replace(index, targetSubstrSize, newSubstr);
			index += newSubstrSize;
		}
		else {
			break;
		}
	}
	return copyString;
}

std::string StrAnalyzer::replaceAll(std::string targetSubstr, std::string newSubstr) {
	return replace(targetSubstr, newSubstr, std::numeric_limits<size_t>::max());
}


