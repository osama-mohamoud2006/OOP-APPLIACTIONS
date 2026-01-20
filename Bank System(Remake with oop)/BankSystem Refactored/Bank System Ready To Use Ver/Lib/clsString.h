#pragma once
#include<iostream>
#include<cctype>
#include <string>
#include <utility>
#include<vector>

class clsString {
private:
    std::string _value;
    static std::string _delmi;

public:
    //no-args constructor
    clsString() {
        this->_value = "";
        _delmi = " ";
    }

    //parametrized constructor
    clsString(std::string value) {
        this->_value = value;
    }

    clsString(std::string value, std::string delmi) {
        this->_value = value;
        _delmi = delmi;
    }

    //property set
    void SetValue(std::string value) {
        this->_value = value;
    }

    static void SetDelmi(std::string delmi) {
        _delmi = delmi;
    }

    //property get
    std::string GetValue() { return this->_value; }
    static std::string GetTheCurrentDelmi() { return  _delmi; }

    // count word//
    static short CountWord(std::string value) {
        std::vector<std::string> word = SplitString(value); // cut the string into words
        return word.size();
    }

    short CountWord() {
        return CountWord(this->_value);
    }


    // The first letter of each word//
    static void PrintFirstLetter(std::string value) {
        std::vector<std::string> word = SplitString(value); // cut the string into words
        for (std::string &w: word) {
            //temp var
            std::string TempWord = w;
            std::cout << TempWord.at(0) << std::endl;
        }
    }

    void PrintFirstLetter() {
        PrintFirstLetter(this->_value);
    }


    static std::string UppercaseTheFirstLetter(std::string value) {
        std::string res = "";
        res += toupper(value.at(0));
        for (int i = 1; i < value.length(); i++) {
            res += value[i];
        }
        return res;
    }

    void UppercaseTheFirstLetter() {
        this->_value = UppercaseTheFirstLetter(_value);
    }

    static std::string LowercaseTheFirstLetter(std::string value) {
        std::string res = "";
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
    static std::vector<std::string> SplitString(std::string value) {
        short pos;
        std::vector<std::string> FinalRes;
        std::string word;
        while ((pos = value.find(_delmi)) != std::string::npos) {
            word = value.substr(0, pos); // get the word
            if (word != "") FinalRes.push_back(word); // uppercase the current word

            value.erase(0, pos + _delmi.length());
        }
        if (value != " " || !value.empty()) FinalRes.push_back(value);
        return FinalRes;
    }

    std::vector<std::string> SplitString() {
        return SplitString(this->_value);
    }

    //upper case first letter of each word
    static std::string UppercaseFirstLetterOfEachWord(std::string value) {
        std::string finalRes = "";
        std::vector<std::string> word = SplitString(value); // cut the string into words
        for (std::string &w: word) {
            //temp var
            std::string TempWord = w;
            TempWord = UppercaseTheFirstLetter(TempWord);
            finalRes += TempWord + _delmi;
        }
        return finalRes.erase(finalRes.length() - _delmi.length());
    }

    void UppercaseFirstLetterOfEachWord() {
        this->_value = UppercaseFirstLetterOfEachWord(this->_value);
    }


    // lower the first letter  for each word//
    static std::string LowercaseFirstLetterOfEachWord(std::string value) {
        std::string finalRes = "";
        std::vector<std::string> word = SplitString(value); // cut the string into words
        for (std::string &w: word) {
            //temp var
            std::string TempWord = w;
            TempWord = LowercaseTheFirstLetter(TempWord);
            finalRes += TempWord + _delmi;
        }
        return finalRes.erase(finalRes.length() - _delmi.length());
    }

    void LowercaseFirstLetterOfEachWord() {
        this->_value = LowercaseFirstLetterOfEachWord(this->_value);
    }


    ///Upper all chars of all words
    static std::string UpperAll(std::string value) {
        std::string res = "";
        for (int i = 0; i < value.length(); i++)res += toupper(value.at(i));

        return res;
    }

    void UpperAll() {
        this->_value = UpperAll(this->_value);
    }

    ///Lower all chars of all words
    static std::string LowerAll(std::string value) {
        std::string res = "";
        for (int i = 0; i < value.length(); i++)res += tolower(value.at(i));

        return res;
    }

    void LowerAll() {
        this->_value = LowerAll(this->_value);
    }

    // invert string
    static std::string InvertStr(std::string value) {
        std::string res = "";
        for (int i = 0; i < value.size(); i++) {
            res += InvertChar(value.at(i));
        }
        return res;
    }

    void InvertStr() {
        this->_value = InvertStr(this->_value);
    }

    //count capital letters , count small lettrs
    static short CountCapitalLetters(std::string value) {
        short c = 0;
        for (int i = 0; i < value.length(); i++)
            if (isupper(value.at(i))) c++;
        return c;
    }

    short CountCapitalLetters() {
        return CountCapitalLetters(this->_value);
    }

    static short CountSmallLetters(std::string value) {
        short s = 0;
        for (int i = 0; i < value.length(); i++)
            if (islower(value.at(i))) s++;
        return s;
    }

    short CountSmallLetters() {
        return CountSmallLetters(this->_value);
    }

    static short GetLengthWithoutCountSpace(std::string value) {
        short count = 0;
        for (int i = 0; i < value.length(); i++)
            if (value[i] != ' ')count++;
        return count;
    }

    short GetLengthWithoutCountSpace() {
        return GetLengthWithoutCountSpace(this->_value);
    }

    //count Specific char in string
    static short CountCharInString(char c, std::string value, bool Match = false) {
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
    static short CountTheVowelCharsInString(std::string value) {
        short count = 0;
        for (int i = 0; i < value.length(); i++)
            if (IsVowel(tolower(value.at(i)))) count++;
        return count;
    }

    short CountTheVowelCharsInString() {
        return CountTheVowelCharsInString(this->_value);
    }

    // Print Vowel chars in string
    static void PrintVowelsInString(std::string value) {
        for (int i = 0; i < value.length(); i++)
            if (IsVowel(tolower(value.at(i)))) std::cout << value.at(i) << " ";
    }

    void PrintVowelsInString() {
        PrintVowelsInString(this->_value);
    }

    // Trim
    static std::string TrimLeft(std::string value) {
        for (int i = 0; i < value.length(); i++)
            if (value[i] != ' ') return value.substr(i, value.length() - 1);
    }

    static std::string TrimRight(std::string value) {
        for (int i = value.length(); i >= 0; i--)
            if (value[i] != ' ') return value.substr(0, i);
    }

    static std::string TrimString(std::string value, std::string option = "all") {
       std::string FinalRes = "";
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
    void TrimString(std::string option = "all") { this->_value = TrimString(this->_value, option); }


    //join string
    static std::string JoinString(std::vector<std::string> VectorOfString) {
        std::string FinalString = "";
        for (std::string &str: VectorOfString)
            FinalString += (str + _delmi);
        return FinalString;
    }

    // reverse string
    static std::string ReverseString(std::string value) {
       std:: vector<std::string> words = SplitString(value);
        std::string res = "";
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
    static std::string ReplaceWordMatchCase(std::string FullLine, std::string WordToreplace, std::string TheNewWord) {
        short pos = 0;
        while ((pos = FullLine.find(WordToreplace)) != std::string::npos) {
            FullLine.erase(pos, WordToreplace.length()); // delete the selected word
            FullLine.insert(pos, TheNewWord);
        }
        return FullLine;
    }

public:
    static std::string ReplaceWord(std::string FullLine, std::string WordToreplace, std::string TheNewWord, bool Match = true) {
        // if the word in line and the word to replace are exactly the same
        if (Match) {
            return ReplaceWordMatchCase(FullLine, WordToreplace, TheNewWord);
        }


        //if the word in line and the word to replace aren't exactly the same
        if (!Match) {
            //Manual implementaion

            //1.Split String
            std::vector<std::string> words = SplitString(FullLine);

            //2.Access Elements
            //3.Replace Element
            for (std::string &SWord: words) {
                if (LowerAll(SWord) == LowerAll(WordToreplace))
                    SWord = TheNewWord;
            }

            return JoinString(words);
        } else return FullLine;
    }

    void ReplaceWord(std::string WordToreplace, std::string TheNewWord, bool Match = true) {
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

    static std::string RemovePunctuation(std::string value) {
        std::string res = "";
        for (int i = 0; i < value.length(); i++)
            if (!IsPunct(value[i])) res += value[i];
        return res;
    }

    void RemovePunctuation() {
        this->_value = RemovePunctuation(this->_value);
    }
};


std::string clsString::_delmi = " ";
