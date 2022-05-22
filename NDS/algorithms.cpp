

#include "algorithms.h"

std::string Algos::LongestCommonSubstring(std::string str1, std::string str2) {
    std::vector<std::vector<int>>* matrix = new std::vector<std::vector<int>>(str1.length());
    for (int row = 0; row < str1.length(); row++) {
        for (int col = 0; col < str2.length(); col++) {
            matrix->at(row).push_back(0);
        }
    }
    int substringLength = 0;
    int rowIndex = 0;
        for (int row = 0; row < str1.length(); row++) {
            for (int col = 0; col < str2.length(); col++) {
                // Check if the characters match
                if (str1[row] == str2[col]) {
                    // Get the value in the cell that's up and to the
                    // left, or 0 if no such cell
                    int upLeft = 0;
                    if (row > 0 && col > 0)
                        upLeft = matrix->at(row - 1).at(col - 1);
                    if (upLeft + 1 > substringLength) {
                        substringLength = upLeft + 1;
                        rowIndex = row;
                    }
                    // Set the value for this cell
                    matrix->at(row).at(col) = 1 + upLeft;
                }
                else
                    matrix->at(row).at(col) = 0;
            }
        }
        int startIndex = rowIndex - substringLength + 1;
        return str1.substr(startIndex, substringLength);
}

//Not done obviously will not work
std::string Algos::DynamicLongestCommonSubstring(std::string str1, std::string str2) {
    int substringLength = 0;
    int rowIndex = 0;
    std::vector<int>* prevCol = new std::vector<int>(str2.length());
    for (int i = 0; i < str2.length(); i++) {
        prevCol->push_back(0);
    }
    for (int row = 0; row < str1.length(); row++) {
        for (int col = 0; col < str2.length(); col++) {
            if (str1[row] == str2[col]) {
                prevCol->at(col)++;
            }
            else {
                prevCol->at(col) = 0;
            }
        }
    }
    int startIndex = rowIndex - substringLength + 1;
    return str1.substr(startIndex, substringLength);
}

int Algos::FibonacciNumber(int termIndex) {
    if (termIndex == 0) {
        return 0;
    }
    int previous = 0;
    int current = 1;
    int i = 1;
        while (i < termIndex) {
            int next = previous + current;
            previous = current;
            current = next;
            i = i + 1;
        }
        return current;
}

std::string Algos::ShuntingYard(std::string infixString) {
    std::queue<char> sQueue;
    std::vector<char> sStack;
    std::map<char, int> precedence = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    for (char c : infixString) {

        switch (c) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':

            while (!sStack.empty() && precedence[sStack.back()] >= precedence[c]) {
                sQueue.emplace(sStack.back());
                std::cout << "Queue push stack back: " << sStack.back() << std::endl;
                sStack.pop_back();
            }
            std::cout << "Stack push: " << c << std::endl;
            sStack.push_back(c);
            
            break;
        case '(':
            sStack.push_back(c);
            break;
        case ')':
            while (!sStack.empty() && sStack.back() != '(') {
                sQueue.emplace(sStack.back());
                std::cout << "Queue push stack back: " << sStack.back() << std::endl;
                sStack.pop_back();
            }
            sStack.pop_back();
            break;
        default:
            if (c - '0' < 10) {
                sQueue.emplace(c);
                std::cout << "Queue emplace number: " << c << std::endl;
            }

            break;

        }
    }
    while (!sStack.empty()) {
        sQueue.emplace(sStack.back());
        sStack.pop_back();
    }

    std::string output = "";
    while (!sQueue.empty()) {
        output += sQueue.front();
        sQueue.pop();
    }
    std::cout << "OUTPUT: " << output << std::endl;
    return output;
}