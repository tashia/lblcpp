#include <iostream>
#include <vector>
#include "trie.h"

using namespace std;

int main(){
	vector<string> tstr{"caonimade", "caonimei", "cccc", "caonidayede"};
	shared_ptr<Trie> trie = make_shared<Trie>(Trie());
	for (auto e : tstr){
		trie->Insert(e);
	}
	tstr.push_back("caoninainaia");
	for (auto e : tstr){
		cout << e << endl;
		cout << trie->Search(e) << endl;
	}
	cout << trie->StartsWith("caoni") << endl;

	return 0;
}