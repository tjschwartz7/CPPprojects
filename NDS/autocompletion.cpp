
#include "autocompletion.h"
#include "stdin.h"
#include <string>

void Autocomplete::ACWordInput() {
	char input;
	std::string str;
	std::cout << "Enter text (one character at a time)" << std::endl;
	do {
		std::cin >> input;
		if (input != '-') {
			str += input;
			//system("cls");
			std::cout << "Recommended: " << words.weightPriority(str) << std::endl;
		}

	} while (input != '-');
	
	if (words.search(words.root, str) == 0) {
		words.insert(words.root, str);
		std::cout << "Inserted " << str << std::endl;
	}



	words.printTrie();
}
