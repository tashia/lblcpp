#include <iostream>
#include <vector>
#include "trie.h"
#include <deque>

using namespace std;

int main(){
	vector<string> tstr{"gggnimade", "gggnimei", "cccc", "gggnidayede"};
	deque<int> intq{9, 7 , 3, 2, 9};
	for(const auto i: intq){
		cout<<i<<endl;
	}
	shared_ptr<Trie> trie = make_shared<Trie>(Trie());
	for (auto e : tstr){
		trie->Insert(e);
	}
	tstr.push_back("gggninainaia");
	for (auto e : tstr){
		cout << e << endl;
		cout << trie->Search(e) << endl;
	}
	cout << trie->StartsWith("gggni") << endl;

	return 0;
}