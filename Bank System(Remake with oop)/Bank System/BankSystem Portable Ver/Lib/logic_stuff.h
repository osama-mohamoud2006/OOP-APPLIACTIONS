#pragma once
#include <cmath>
#include <iostream>
#include<vector>
#include <unordered_map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enCharType
{
	smallLetter = 1,	  // Represents lowercase letters (ASCII 97 to 122).
	capitalLetter = 2,	  // Represents uppercase letters (ASCII 65 to 90).
	specialCharacter = 3, // Represents special characters (ASCII 33 to 47).
	digit = 4			  // Represents digits (ASCII 48 to 57).
};
enum enoperation
{
	add = 1,
	sub = 2,
	divison = 3,
	mod = 4,
	multi = 5
};
enum enScreen_color
{
	black = 1,
	red = 2,
	yellow = 3,
	green = 4,
	red_on_black = 5,
	purple = 6
};
namespace AllStuff
{

	// check it is even or odd even return true , odd return false
	bool even_or_odd(int number)
	{
		bool result;
		(number % 2 == 0) ? result = true : result = false;
		return result;
	}

	// check even only
	bool is_even(int number)
	{
		return (number % 2 == 0);
	}

	// check odd only
	bool is_odd(int number)
	{
		return (number % 2 != 0);
	}

	// is prime?
	bool prime_or_not(int number)
	{
		if (number <= 1)
			return false;
		int untill = number / 2;
		for (int i = 2; i <= untill; i++)
		{
			if (number % i == 0)
				return false;
		}
		return true;
	}

	// generate random number {
	int random(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}

	// generate random values according to enum
	char get_random_stuff(enCharType CharType)
	{
		// Use a switch-case to handle the different character types.
		switch (CharType)
		{
		case enCharType::smallLetter:
			return char(random(97, 122));
			break;
		case enCharType::capitalLetter:
			return char(random(65, 90));
			break;
		case enCharType::specialCharacter:
			return char(random(33, 48));
			break;
		case enCharType::digit:
			return char(random(48, 57));
			break;
		default:
			return '\0';
		}
	}

	// reverse number
	int reversed_number(int Number)
	{
		int Remainder = 0;
		int Number2 = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}

		return Number2;
	}

	// reverse string
	string reverse_word(string yourword)
	{
		string reversed = "";
		for (int i = yourword.length() - 1; i >= 0; i--)
		{

			reversed += yourword[i];
		}
		return reversed;
	}

	// simple calculator
	double calculator(double number1, double number2, enoperation type)
	{
		switch (type)
		{
		case ::enoperation::add:
			return number1 + number2;

		case ::enoperation::sub:
			return number1 - number2;

		case enoperation::divison:
			if (number2 == 0)
				return number1;
			else
				return number1 / number2;

		case enoperation::mod:
			if (number1 > 0.0 || number2 > 0.0)
				return fmod(number1, number2);
			else
				return (int)number1 % (int)number2;

		case enoperation::multi:
			return number1 * number2;

		default:
			return 0;
		}
	}

	// convert char to int
	int char_to_int(char i)
	{
		int digit = i - '0';
		return digit;
	}

	// count how many times number repeated
	int count_digit_frequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0, Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;

			if (DigitToCheck == Remainder)
			{
				FreqCount++;
			}
		}
		return FreqCount;
	}

	// change screen color
	void screen_color(enScreen_color color)
	{
		if (color == black)
			system("color 0F"); // black
		if (color == green)
			system("color 2F"); // green
		if (color == yellow)
			system("color 6F"); // yellow
		if (color == red)
			system("color 4F"); // red
		if (color == red_on_black)
			system("color 0C"); // red on black
		if (color == purple)
			system("color 0D"); // purple text
	}

	// check if it is digit or number
	bool is_it_number(char i)
	{
		bool res;
		(isdigit(i)) ? res = true : res = false; // it is number
		//  return false; // it is char
		return res;
	}

	// the whole string to upper
	string Upper(string word)
	{
		for (int i = 0; i < word.size(); i++)
		{
			word[i] = toupper(word[i]);
		}
		return word;
	}

	// the whole string to lower
	string lower(string word)
	{
		for (int i = 0; i < word.size(); i++)
		{
			word[i] = tolower(word[i]);
		}
		return word;
	}

	char invert(char c)
	{
		return islower(c) ? c = toupper(c) : c = tolower(c);
	}

	void CPlusPlusVersion()
	{

		cout << "C++ Version: " << __cplusplus << endl;
		if (__cplusplus == 201703L)
		{
			cout << "C++17" << endl; // 201703L | C++17
		}
		else if (__cplusplus == 201402L)
		{
			cout << "C++14" << endl; // 201402L | C++14
		}
		else if (__cplusplus == 201103L)
		{
			cout << "C++11" << endl; // 201103L | C++11
		}
		else if (__cplusplus == 199711L)
		{
			cout << " C++98 / C++03" << endl; // 199711L | C++98 / C++03
		}
		else
		{
			cout << "Unknown C++ version" << endl;
		}
	}

	// split string into single words 
	vector<string> SplitString(string str, string delmi) {
		vector<string> res;
		short pos = 0;
		string sword;
		while ((pos = str.find(delmi)) != string::npos)
		{
			sword = str.substr(0, pos);
			if (sword != "") res.push_back(sword);
			str.erase(0, pos + delmi.length());
		}

		if (str != "") res.push_back(str);
		return res;
	}

	// to show text when you back to main menu or after function finished
	void back_to_menu(string TextAppearWhenYouBack = "press any key to back to main menu !") {
		screen_color(enScreen_color::black);
		cout << "\033[1;31m";
		cout << "\n " << TextAppearWhenYouBack << endl;
		cout << "\033[0m";
		system("pause>0");

	}

	//// tp print the option of menu you enter 
	//void print_menu_option(string option_name) {
	//	cout << "\n_________________________________________________\n\n\n";
	//	cout << "\t" << option_name << "\n";
	//	cout << "\n_________________________________________________\n";
	//}

	////enter yes or not return true if yes 
	//bool EnterY_N() {
	//	char c;
	//	cin >> c;
	//	return (toupper(c) == 'Y'); // return true if it is yes 
	//}

	//change text color 
	string colorText(const string& text, const string& color, bool background = false) {
		static unordered_map<string, string> namedColors = {
			{"black", "0;0;0"}, {"red", "255;0;0"}, {"green", "0;255;0"},
			{"yellow", "255;255;0"}, {"blue", "0;0;255"}, {"magenta", "255;0;255"},
			{"cyan", "0;255;255"}, {"white", "255;255;255"},
			{"gray", "128;128;128"}, {"lightgray", "211;211;211"},
			{"purple", "128;0;128"}, {"lightpurple", "177;156;217"},
			{"orange", "255;165;0"}, {"pink", "255;192;203"}
		};

		string rgb;
		if (namedColors.count(color)) {
			rgb = namedColors[color];
		}
		else if (color.find(";") != string::npos) {
			// assume it's "R;G;B"
			rgb = color;
		}
		else {

			return text;
		}

		string prefix = background ? "48" : "38";
		return "\033[" + prefix + ";2;" + rgb + "m" + text + "\033[0m";
	}

}



