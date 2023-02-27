#pragma once
#include <string>		// test
#include <list>
#include <initializer_list>
#include <iostream>







struct Node
{
	int key;
	std::string value;

	Node(const int k, const std::string &v): key(k), value(v){}
};

class HashTable
{
private:

	static size_t default_capacity;
	static float full_redist;

	size_t lenght, capacity;
	std::list<Node*> *arr;

	int Hash(Node *node) { return node->key % capacity; }
	//int operator()(Node* node) { return Hash(node); }

	void DestroyArray()
	{
		for (int i = 0; i < capacity; ++i)
			for (const auto &j : arr[i])
				delete j;

		delete[] arr;
	}

public:

	HashTable(int cpct = 0):lenght(0)
	{
		if (cpct < 0) throw 1;

		if (cpct == 0)
			cpct = default_capacity;

		capacity = cpct;

		arr = new std::list<Node*>[cpct];
		
	}
	///*HashTable(const HashTable& copy)
	//{
	//	if (&copy == this) return;
	//
	//	lenght = copy.lenght;
	//	capacity = copy.capacity;
	//
	//	arr = copy.arr;
	//}
	
	void operator=(const HashTable& copy)
	{
		if (&copy == this) return;

		lenght = copy.lenght;
		capacity = copy.capacity;

		DestroyArray();

		arr = copy.arr;
	}

	~HashTable() { DestroyArray(); }

	void reserv(const int cpct)
	{
		std::cout << "\n\nRESERV\n\n";

		size_t tempCap = cpct / 2;
		std::list<Node*> *temp = arr;
		arr = new std::list<Node*>[cpct];

		capacity = cpct;

		for (int i = 0; i < tempCap; ++i)
			for (const auto &j : temp[i])
				arr[Hash(j)].push_back(j);

		//DestroyArray();
	}

	void push(const int key, const std::string& value)
	{
		Node *newData = new Node(key, value);

		arr[Hash(newData)].push_back(newData);

		if (++lenght * 1.0 / capacity >= full_redist)
			reserv(capacity * 2);
	}
	
	Node* find(const int key)
	{
		for (const auto &i : arr[key % capacity])
			if (i->key == key)
				return i;

		return nullptr;
	}

	void pop(const int key)
	{
		for (const auto &i : arr[key % capacity])
			if (key == i->key) {
				delete i;
				//arr[key % capacity].erase(i);
			}	
	}

	void out()
	{
		for (int i = 0; i < capacity; ++i) {
			for (const auto &j : arr[i])
				std::cout << '(' << j->key << ' ' << j->value << ")\t";
			std::cout << '\n';
		}
			
	}
};


size_t HashTable::default_capacity = 10;
float HashTable::full_redist = 0.75;
