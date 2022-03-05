#include <iostream>
#include <string>
#include <vector>
#include <map>

#pragma once
class StrAnalyzer
{
	public:
		//Constructor
		StrAnalyzer(std::string text);
		
		//Methods
		std::string getString(); //Get text property
		void setString(std::string newString); //Set text property
		std::string trim(); //Return string with removed leading and trailing whitespaces
		std::vector<std::string> split(std::string delim); //Return vector with string splitted using delim
		int charCount(); // Return int with no of characters in string
		std::map<char, int> charBreakdown(); // Return map containing no. of occurances of each letter in string
		int wordCount(); // Return no of words in string

		template <class T>
		int countOccurances(T A); 
		/*
			Return no of occurances of a substring in text
			if argument is of type std::string, then count occurance of A in text
			if argument is of type const char *, then count total occurance of any character in A
		*/
		//int countOccurances(std::string A); // Return no of occurances of A in text
		//int countOccurances(const char* A); // Return no of occurances of any characters in A in text		
		
		bool containsNumeric(); //Return 1 if string contains a number, else return 0
		bool containsLetters(); //Return 1 if string contains a letter, else return 0
		bool containsSpecial(); //Return 1 if string contains a special character, else return 0
		
		//Returns a new string, replace count occurances of the targetSubstr with newSubstr
		std::string replace(std::string targetSubstr, std::string newSubstr, size_t count);

		//Returns a new string, replace all occurances of the targetSubstr with newSubstr
		std::string replaceAll(std::string targetSubstr, std::string newSubstr); 

	private:
		//Properties
		std::string text; //Contains current string

		//Methods
		size_t getArgSize(std::string A);
		size_t getArgSize(const char* A);
		/*
			Used by countOccurance method
			Return a size_t value based on the argument type
			If type is of std::string, then return A.size()
			If type is of const char*, then return 1;
		*/

		size_t findIndex(std::string A, size_t startPos);
		size_t findIndex(const char* A, size_t startPos);
		/*
			Used by countOccurance method
			Return a size_t value based on the argument type
			If type is of std::string, then return index using find
			If type is of const char*, then return index using find_first_of
		*/
};

