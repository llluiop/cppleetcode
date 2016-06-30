#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class TrieNode {
public:
	static const int dict_num = 26;
	// Initialize your data structure here.
	TrieNode() {
		c_ = '\n';
		end_ = false;
		for (int i = 0; i < dict_num; i++)
		{
			next_[i] = nullptr;
		}
	}

	void setter(char c)
	{
		c_ = c;
	}

	char getter()
	{
		return c_;
	}

	void setend(bool end)
	{
		end_ = end;
	}

	bool getend()
	{
		return end_;
	}
	
	TrieNode*& getNode(char c)
	{
		return next_[c - 'a'];
	}

private:
	char c_;
	bool end_;
	TrieNode* next_[dict_num];


};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		auto cur = root;
		for (auto s : word)
		{
			auto& node = cur->getNode(s);
			if (node == nullptr)
			{
				node = new TrieNode();
				node->setter(s);
			}

			cur = node;
		}
		cur->setend(true);
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		auto cur = root;
		for (auto s : word)
		{
			auto& node = cur->getNode(s);
			if (node == nullptr)
			{
				return false;
			}

			cur = node;
		}
		return cur->getend();
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		auto cur = root;
		for (auto s : prefix)
		{
			auto& node = cur->getNode(s);
			if (node == nullptr)
			{
				return false;
			}

			cur = node;
		}
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main()
{
	Trie trie;
	trie.insert("somestring");
	cout<<trie.search("key");
	cout << trie.search("some");
	cout << trie.search("somestring");
	cout << trie.startsWith("some");
	cout << trie.startsWith("somestring");

	return getchar();
}