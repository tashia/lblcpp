#ifndef TRIE_H
#define TRIE_H

#include <memory>
#include <string>

struct TrieNode{
	std::shared_ptr<TrieNode> next[26];
	bool isCompleted;
	TrieNode() {
		isCompleted = false;
	}
};


class Trie{
public:
	Trie(){
		root_ = std::make_shared<TrieNode>(TrieNode());
	}
	~Trie(){}
	void Insert(const std::string& str) const{
		put(root_, str, 0);
	}

	bool StartsWith(const std::string& str) const{
		auto node = HasIt(str);
		return node != nullptr;
	}

	bool Search(const std::string& str) const{
		auto node = HasIt(str);
		return node == nullptr? false : node->isCompleted;
	}

private:
	void put(const std::shared_ptr<TrieNode>& node, const std::string& str, int depth) const {
		if (depth == (int)str.size()) {
			node->isCompleted = true;
			return;
		}
		int index = str[depth] - 'a';
		if (node->next[index] == nullptr){
			node->next[index].reset(new TrieNode);
		}
		put(node->next[index], str, depth + 1);
		return;
	}

	std::shared_ptr<TrieNode> HasIt(const std::string& str) const {
		auto curr_node = root_;
		int depth = 0;
		for (; depth < str.size(); ++depth){
			auto index = str[depth] - 'a';
			if (curr_node->next[index]){
				curr_node = curr_node->next[index];
			}
			else{
				return nullptr;
			}
		}
		return curr_node;
	}

private:
	std::shared_ptr<TrieNode> root_;
};


#endif // !TRIE_H
