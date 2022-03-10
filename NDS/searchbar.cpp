
#include "searchbar.h"
#include "stdin.h"
#include <vector>
#include <string>


void Searchbar::SBWordInput() {
	char input;
	std::string str;
	std::cout << "Enter text (one character at a time)" << std::endl;
	do {
		std::cin >> input;
		if (input != '-') {
			//std::cout << "Enters conditional" << std::endl;
			str += input;
			//system("cls");
			TrieNode* node = words.findStringNode(words.root, str);
			if(node != nullptr)
			words.printFromNode(node);
		}

	} while (input != '-');

	//words.printTrie();
}

Searchbar::Searchbar() {
	words.insert(words.root, "kitchen");
	words.insert(words.root, "library");
	words.insert(words.root, "hallway");
	words.insert(words.root, "home");
	words.insert(words.root, "garage");
	words.insert(words.root, "bedroom");
	words.insert(words.root, "bathroom");
	words.insert(words.root, "shower");
	words.insert(words.root, "closet");
	words.insert(words.root, "cantina");
	words.insert(words.root, "porch");
	words.insert(words.root, "backyard");
	words.insert(words.root, "lawn");
	words.insert(words.root, "shed");
	words.insert(words.root, "attic");
	words.insert(words.root, "foyer");
	words.insert(words.root, "theater");
	words.insert(words.root, "pool");
	words.insert(words.root, "anteroom");
	words.insert(words.root, "lobby");
	words.insert(words.root, "office");
	words.insert(words.root, "desk");
	words.insert(words.root, "suite");
	words.insert(words.root, "storage");
	words.insert(words.root, "pantry");
	words.insert(words.root, "parlor");
	words.insert(words.root, "den");
	words.insert(words.root, "sunroom");
	words.insert(words.root, "laundry");
	words.insert(words.root, "basement");
	words.insert(words.root, "nursery");
	words.insert(words.root, "playroom");
	words.insert(words.root, "gameroom");
	words.insert(words.root, "gym");
	words.insert(words.root, "cellar");
	words.insert(words.root, "loft");
}