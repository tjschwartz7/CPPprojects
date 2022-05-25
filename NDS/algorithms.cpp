

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
                //std::cout << "Queue push stack back: " << sStack.back() << std::endl;
                sStack.pop_back();
            }
            //std::cout << "Stack push: " << c << std::endl;
            sStack.push_back(c);
            
            break;
        case '(':
            sStack.push_back(c);
            break;
        case ')':
            while (!sStack.empty() && sStack.back() != '(') {
                sQueue.emplace(sStack.back());
                //std::cout << "Queue push stack back: " << sStack.back() << std::endl;
                sStack.pop_back();
            }
            sStack.pop_back();
            break;
        default:
            if (c - '0' < 10) {
                sQueue.emplace(c);
                //std::cout << "Queue emplace number: " << c << std::endl;
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
    return output;
}

std::string Algos::scramble(std::string bits, int operations, double key) {
    int n = 0;
    for (int i = 0; i < bits.size(); i++) bits[i]+=key;
    while (n < operations) {
        if(n % 2 == 0)
            bits[n % bits.size()] += key;
        else bits[n % bits.size()] = bits[n % bits.size()] + key + n;
        n++;
    }
    for (int j = 0; j < rand() % bits.size() + 7500; j++) {
        bits += (char)rand() % 255;
    }
    return bits;
}

std::string Algos::descramble(std::string bits, int operations, int key, int size) {
    int n = 0;
    while (n < operations) {
        if (n % 2 == 0)
            bits[n % size] -= key;
        else bits[n % size] = bits[n % size] - key - n;
        n++;
    }
    for (int i = 0; i < size; i++) bits[i]-=key;
    return bits.substr(0, size);
}

std::vector<int> Algos::bitonicSequence(std::vector<int> set) {
   // for (int i = 0; i < set.size(); i++) {

   // }
    return set;
}

std::string Algos::BinaryToHexConverter(std::string bits) {
    BHConversion converter;
    if (bits[0] == '0' && bits[1] == 'b') bits = bits.substr(2, bits.size()-2);
    //std::cout << "Size: " << bits.size() << std::endl;
    //std::cout << "Current bits: " << bits << std::endl;
    // O(3) = O(1) Big O
    while(bits.size() % 4 != 0) {
        bits = '0' + bits;
        //std::cout << "Bits: " << bits << std::endl;
    }
    std::string output = "";
    //O(k / 4) (Size of string / 4) = O(k) Big O
    for (int i = 0; i < bits.size(); i += 4) {
        //std::cout << "Counter: " << i << std::endl;
        //std::cout << "Substring: " << bits.substr(i, i + 4) << std::endl;
        std::string fourBit = bits.substr(i, 4);
        //std::cout << "Four Bits: " << fourBit << std::endl;
        output += converter.chartBH[fourBit];

    }
    return "0x" + output;
}

std::string Algos::HexToBinaryConverter(std::string hex) {
    if (hex[0] == '0' && hex[1] == 'x') hex = hex.substr(2, hex.size()-2);
    BHConversion converter;
    //std::cout << "Size: " << bits.size() << std::endl;
    std::string output = "";
    //O(k / 4) (Size of string / 4) = O(k) Big O
    for (int i = 0; i < hex.size(); i++) {
        //std::cout << bits.substr(i, i + 4) << std::endl;
        output += converter.chartHB[toupper(hex[i])];
    }
    return "0b" + output;
}

std::string createRandomBinary() {
    int size = rand() % 255 * 4;
    std::string bits = "";
    for (int i = 0; i < size; i++) {
        int randomBit = rand() % 2;
        (randomBit == 1) ? bits += '1' : bits += '0';
    }
    return "0b" + bits;
}

bool Algos::HexBinaryConversionTester(int numTests) {
    srand(time(NULL));
    auto t1 = std::chrono::system_clock::now();
    for (int i = 0; i < numTests; i++) {
        std::string randBits = createRandomBinary();
        std::string hex = BinaryToHexConverter(randBits);
        std::string outputBinary = HexToBinaryConverter(hex);
        //std::cout << randBits << " " << hex << " Outputs " << outputBinary << std::endl;
        if (outputBinary != randBits) return false;
    }
    auto t2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = t2 - t1;
    std::cout << "Elapsed time during " << numTests << " tests: " << elapsed_seconds.count() << "s" << std::endl;
    return true;
}

int Algos::ShuntingYardSolver(std::string postfixInput) {
    std::vector<int> sStack;
    int total = 0;
    int num1;
    int num2;
    for (char c : postfixInput) {

        switch (c) {
        case '+':
            num1 = sStack.back();
            sStack.pop_back();
            num2 = sStack.back();
            sStack.pop_back();
            sStack.push_back(num2 + num1);
            break;
        case '-':
            num1 = sStack.back();
            sStack.pop_back();
            num2 = sStack.back();
            sStack.pop_back();
            sStack.push_back(num2 - num1);
            break;
        case '/':
            num1 = sStack.back();
            sStack.pop_back();
            num2 = sStack.back();
            sStack.pop_back();
            sStack.push_back(num2 / num1);
            break;
        case '*':
            num1 = sStack.back();
            sStack.pop_back();
            num2 = sStack.back();
            sStack.pop_back();
            sStack.push_back(num2 * num1);
            break;
        case '^':
            num1 = sStack.back();
            sStack.pop_back();
            num2 = sStack.back();
            sStack.pop_back();
            sStack.push_back((int)pow(num2, num1));
            break;
        default:
            if (c - '0' < 10) {
                sStack.push_back(c - '0');
                //std::cout << "Queue emplace number: " << c << std::endl;
            }

            break;

        }
        //for (int j = 0; j < sStack.size(); j++) {
          //  std::cout << sStack[j] << std::endl;
        //}
        //std::cout << std::endl;
    }
    if (sStack.empty()) {
        std::cout << "The stack is empty! This means something went terribly wrong with the calculation. Sorry about that." << std::endl;
        return 0;
    }
    else
    return sStack.back();
}