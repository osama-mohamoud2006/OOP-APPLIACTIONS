#pragma once
#include<iostream>
#include<cctype>
#include <string>
#include <utility>
#include<vector>
using namespace std;

class clsString {
private:
    string _value;
    static string _delmi;

public:
    //no-args constructor
    clsString() {
        this->_value = "";
        _delmi = " ";
    }

    //parametrized constructor
    clsString(string value) {
        this->_value = value;
    }

    clsString(string value, string delmi) {
        this->_value = value;
        _delmi = delmi;
    }

    //property set
    void SetValue(string value) {
        this->_value = value;
    }

    static void SetDelmi(string delmi) {
        _delmi = delmi;
    }

    //property get
    string GetValue() { return this->_value; }
    static string GetTheCurrentDelmi() { return _delmi; }

    // count word//
    static short CountWord(string value) {
        vector<string> word = SplitString(value); // cut the string into words
        return word.size();
    }

    short CountWord() {
        return CountWord(this->_value);
    }


    // The first letter of each word//
    static void PrintFirstLetter(string value) {
        vector<string> word = SplitString(value); // cut the string into words
        for (string &w: word) {
            //temp var
            string TempWord = w;
            cout << TempWord.at(0) << endl;
        }
    }

    void PrintFirstLetter() {
        PrintFirstLetter(this->_value);
    }


    static string UppercaseTheFirstLetter(string value) {
        string res = "";
        res += toupper(value.at(0));
        for (int i = 1; i < value.length(); i++) {
            res += value[i];
        }
        return res;
    }

    void UppercaseTheFirstLetter() {
        this->_value = UppercaseTheFirstLetter(_value);
    }

    static string LowercaseTheFirstLetter(string value) {
        string res = "";
        res += tolower(value.at(0));
        for (int i = 1; i < value.length(); i++) {
            res += value[i];
        }
        return res;
    }

    void LowercaseTheFirstLetter() {
        this->_value = LowercaseTheFirstLetter(_value);
    }


    static char InvertChar(char c) {
        return (isupper(c)) ? tolower(c) : toupper(c);
    }

public:
    // cut the full sentence into vector of words
    static vector<string> SplitString(string value) {
        short pos;
        vector<string> FinalRes;
        string word;
        while ((pos = value.find(_delmi)) != string::npos) {
            word = value.substr(0, pos); // get the word
            if (word != "") FinalRes.push_back(word); // uppercase the current word

            value.erase(0, pos + _delmi.length());
        }
        if (value != " " || !value.empty()) FinalRes.push_back(value);
        return FinalRes;
    }

    vector<string> SplitString() {
        return SplitString(this->_value);
    }

    //upper case first letter of each word
    static string UppercaseFirstLetterOfEachWord(string value) {
        string finalRes = "";
        vector<string> word = SplitString(value); // cut the string into words
        for (string &w: word) {
            //temp var
            string TempWord = w;
            TempWord = UppercaseTheFirstLetter(TempWord);
            finalRes += TempWord + _delmi;
        }
        return finalRes.erase(finalRes.length() - _delmi.length());
    }

    void UppercaseFirstLetterOfEachWord() {
        this->_value = UppercaseFirstLetterOfEachWord(this->_value);
    }


    // lower the first letter  for each word//
    static string LowercaseFirstLetterOfEachWord(string value) {
        string finalRes = "";
        vector<string> word = SplitString(value); // cut the string into words
        for (string &w: word) {
            //temp var
            string TempWord = w;
            TempWord = LowercaseTheFirstLetter(TempWord);
            finalRes += TempWord + _delmi;
        }
        return finalRes.erase(finalRes.length() - _delmi.length());
    }

    void LowercaseFirstLetterOfEachWord() {
        this->_value = LowercaseFirstLetterOfEachWord(this->_value);
    }


    ///Upper all chars of all words
    static string UpperAll(string value) {
        string res = "";
        for (int i = 0; i < value.length(); i++)res += toupper(value.at(i));

        return res;
    }

    void UpperAll() {
        this->_value = UpperAll(this->_value);
    }

    ///Lower all chars of all words
    static string LowerAll(string value) {
        string res = "";
        for (int i = 0; i < value.length(); i++)res += tolower(value.at(i));

        return res;
    }

    void LowerAll() {
        this->_value = LowerAll(this->_value);
    }

    // invert string
    static string InvertStr(string value) {
        string res = "";
        for (int i = 0; i < value.size(); i++) {
            res += InvertChar(value.at(i));
        }
        return res;
    }

    void InvertStr() {
        this->_value = InvertStr(this->_value);
    }

    //count capital letters , count small lettrs
    static short CountCapitalLetters(string value) {
        short c = 0;
        for (int i = 0; i < value.length(); i++)
            if (isupper(value.at(i))) c++;
        return c;
    }

    short CountCapitalLetters() {
        return CountCapitalLetters(this->_value);
    }

    static short CountSmallLetters(string value) {
        short s = 0;
        for (int i = 0; i < value.length(); i++)
            if (islower(value.at(i))) s++;
        return s;
    }

    short CountSmallLetters() {
        return CountSmallLetters(this->_value);
    }

    static short GetLengthWithoutCountSpace(string value) {
        short count = 0;
        for (int i = 0; i < value.length(); i++)
            if (value[i] != ' ')count++;
        return count;
    }

    short GetLengthWithoutCountSpace() {
        return GetLengthWithoutCountSpace(this->_value);
    }

    //count Specific char in string
    static short CountCharInString(char c, string value, bool Match = false) {
        short count = 0;
        for (int i = 0; i < value.length(); i++) {
            if (!Match) {
                if (toupper(value[i]) == toupper(c)) count++; // isn't case senstive
            } else {
                if (value[i] == c) count++; // case senstive
            }
        }

        return count;
    }

    short CountCharInString(char c, bool Match = false) {
        return CountCharInString(c, this->_value, Match);
    }

    // vowel char
    static bool IsVowel(char c) {
        char vowel[] = {'a', 'e', 'i', 'o', 'u'};
        return (c == vowel[0] || c == vowel[1] || c == vowel[2] || c == vowel[3] || c == vowel[4]) ? true : false;
    }

    //Count Vowel chars in string
    static short CountTheVowelCharsInString(string value) {
        short count = 0;
        for (int i = 0; i < value.length(); i++)
            if (IsVowel(tolower(value.at(i)))) count++;
        return count;
    }

    short CountTheVowelCharsInString() {
        return CountTheVowelCharsInString(this->_value);
    }

    // Print Vowel chars in string
    static void PrintVowelsInString(string value) {
        for (int i = 0; i < value.length(); i++)
            if (IsVowel(tolower(value.at(i)))) cout << value.at(i) << " ";
    }

    void PrintVowelsInString() {
        PrintVowelsInString(this->_value);
    }

    // Trim
    static string TrimLeft(string value) {
        for (int i = 0; i < value.length(); i++)
            if (value[i] != ' ') return value.substr(i, value.length() - 1);
    }

    static string TrimRight(string value) {
        for (int i = value.length(); i >= 0; i--)
            if (value[i] != ' ') return value.substr(0, i);
    }

    static string TrimString(string value, string option = "all") {
        string FinalRes = "";
        if (option == "all") {
            return TrimRight(TrimLeft(value));
        } else if (option == "right") {
            //right
            return TrimRight(value);
        } else if (option == "left") {
            //left
            return TrimLeft(value);
        } else return value;
    }

    void TrimLeft() { this->_value = TrimLeft(this->_value); }
    void TrimRight() { this->_value = TrimRight(this->_value); }
    void TrimString(string option = "all") { this->_value = TrimString(this->_value, option); }


    //join string
    static string JoinString(vector<string> VectorOfString) {
        string FinalString = "";
        for (string &str: VectorOfString)
            FinalString += (str + _delmi);
        return FinalString;
    }

    // reverse string
    static string ReverseString(string value) {
        vector<string> words = SplitString(value);
        string res = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i] + _delmi;
        }
        return res.erase(res.length() - _delmi.length());
    }

    void ReverseString() {
        this->_value = ReverseString(this->_value);
    }


    //replace word
private:
    static string ReplaceWordMatchCase(string FullLine, string WordToreplace, string TheNewWord) {
        short pos = 0;
        while ((pos = FullLine.find(WordToreplace)) != string::npos) {
            FullLine.erase(pos, WordToreplace.length()); // delete the selected word
            FullLine.insert(pos, TheNewWord);
        }
        return FullLine;
    }

public:
    static string ReplaceWord(string FullLine, string WordToreplace, string TheNewWord, bool Match = true) {
        // if the word in line and the word to replace are exactly the same
        if (Match) {
            return ReplaceWordMatchCase(FullLine, WordToreplace, TheNewWord);
        }


        //if the word in line and the word to replace aren't exactly the same
        if (!Match) {
            //Manual implementaion

            //1.Split String
            vector<string> words = SplitString(FullLine);

            //2.Access Elements
            //3.Replace Element
            for (string &SWord: words) {
                if (LowerAll(SWord) == LowerAll(WordToreplace))
                    SWord = TheNewWord;
            }

            return JoinString(words);
        } else return FullLine;
    }

    void ReplaceWord(string WordToreplace, string TheNewWord, bool Match = true) {
        this->_value = ReplaceWord(this->_value, WordToreplace, TheNewWord, Match);
    }

    //remove punctuation
    static bool IsPunct(char p) {
        return (p == '(' || p == ')' || p == '\'' ||
                p == '.' || p == '-' || p == ':' || p == '?'
                || p == ',' || p == ';' || p == '!' || p == '"')
                   ? true
                   : false;
    }

    static string RemovePunctuation(string value) {
        string res = "";
        for (int i = 0; i < value.length(); i++)
            if (!IsPunct(value[i])) res += value[i];
        return res;
    }

    void RemovePunctuation() {
        this->_value = RemovePunctuation(this->_value);
    }
};


string clsString::_delmi = " ";

