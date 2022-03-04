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

		//Attributes
		
		//Methods
		std::string getString();
		void setString(std::string newString);
		std::string trim(); //Return string with removed leading and trailing whitespaces
		std::vector<std::string> split(std::string delim); //Return vector with string splitted using delim
		int charCount(); // Return int with no of characters in string
		std::map<char, int> charBreakdown(); // Return map containing no. of occurances of each letter in string
		int wordCount(); // Count no of words in string
		int countOccurances(std::string searchString); // Count no of occurances of specificed string in text
		
	private:
		std::string text;
};

