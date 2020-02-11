#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "Podminka.h"
#include <sstream>

/*	try
	{
		HashTable<double, Entity > a{};

		for (int i = 0; i < 5; i++)
		{
			Entity first_in_hash(i + 1);
			Entity second_in_hash(i + 11);
			Entity third_in_hash(i + 111);

			a.put(i + 0.1, first_in_hash);
			a.put(i + 0.01, second_in_hash);
			a.put(i + 0.001, third_in_hash);
		}
		Entity* temp = a.get(0.0001);
		std::string ret = a.to_string();
		std::cout << ret << std::endl;

		
	}
	catch (Podminka & ex)
	{
		std::cerr << ex.GetMsg();
	}*/

template<typename K, typename V>
class HashTable
{
public:
	HashTable() {
		_table_size = 10;
		_table = new Node * [_table_size];
		for (int i = 0; i < _table_size; i++)
			_table[i] = nullptr;
	};
	~HashTable() {
		for (int i = 0; i < _table_size; i++)
		{
			Node* entry = _table[i];

			while (entry != nullptr)
			{
				Node* prev = entry;
				if (entry->_next != nullptr)
				{
					entry = entry->_next;
				}
				delete prev;
			}
			delete[] _table;
		}
	};

	V* get(const K& key) {
		auto hash_value = _function(key);
		Node* entry = _table[hash_value];

		while (entry != nullptr)
		{
			if (entry->_key == key)
			{
				return &(entry->_value);
			}
			entry = entry->_next;
		}
		return nullptr;
	}

	void put(const K& key, V& value) {
		auto hash_value = _function(key);
		auto node = _table[hash_value];

		Node* nextNode = new Node(key, value);
		if (node != nullptr)
		{
			while (node->_next != nullptr && node->_key != key)
			{
				node = node->_next;
			}

			if (node->_key == key)
			{
				node->_value = value;
			}
			else
			{
				node->_next = nextNode;
			}
		}
		else
		{
			_table[hash_value] = nextNode;
		}

	}
	void remove(const K& key) {
		auto hash_value = _function(key);
		Node* prev = nullptr;
		Node* entry = _table[hash_value];

		while (entry != nullptr && entry->_key != key)
		{
			prev = entry;
			entry = entry->_next;
		}

		if (entry == nullptr)
			throw Podminka("Remove: key not found");
		else
		{
			if (prev == nullptr)
				_table[hash_value] = entry->_next;

			else
				prev->_next = entry->_next;

			delete entry;
		}
	}
	std::string to_string() {
		std::string ret;
		std::stringstream ss;
		for (int i = 0; i < _table_size; i++)
		{
			Node* temp = _table[i];
			while (temp != nullptr)
			{
				ss << "index: " << i << " Key: " << temp->_key << " value: " << temp->_value << std::endl;
				temp = temp->_next;
			}

		}
		ret.assign(ss.str());


		return ret;
	}
private:
	struct Node
	{
		Node(K key, V data) : _key(key), _value(data), _next(nullptr) {}
		K _key;
		V _value;
		//_next node with same data
		Node* _next;
	};



	template<typename K, size_t tablesize>
	struct Key_hash
	{
		unsigned long operator()(const K& key) const
		{
			return static_cast<unsigned long>(key) % tablesize;
		}
	};

	Node** _table;
	Key_hash<K, 10> _function;
	int _table_size;

	Node* find_last(Node* node);
};

#endif // !HASHTABLE_H




	

	

	

