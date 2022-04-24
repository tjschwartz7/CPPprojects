#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include "searchbar.h"
#include <string>
#include "Trie.h"
#include <vector>

class Searchbar {
public:
	void SBWordInput();
	Searchbar();
private:
	Trie words;
};

#endif // !SEARCHBAR_H
