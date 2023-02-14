#pragma once

#pragma once
#include <cstdint>
#include <iostream>


class RingBuffer
{
private:

	uint16_t size;
	int *buff;

	size_t indexIn, indexOut;

	bool endIn, endOut;

public:

	RingBuffer(const int lenght) :
		size(lenght), indexIn(0), indexOut(0), endIn(false), endOut(false)
	{
		if (lenght < 0) throw 1;

		buff = new int[size];

		for (int i = 0; i < size; ++i)
			buff[i] = 0;
	}
	~RingBuffer() { delete[] buff; }



	void push(const int &vl)
	{
		buff[indexIn++] = vl;

		if (indexIn >= size) {
			indexIn = 0;
			indexOut = -1;
			endIn = true;
		}
		else
			endIn = false;
	}

	void pop()
	{
		if (indexOut == -1)
			indexOut = indexIn;

		//int data = buff[indexOut];
		
		buff[indexOut++] = 0;

		if (indexOut >= size) {
			indexOut = 0;
			endOut = true;
		}
		else
			endOut = false;

		//return data;
	}

	int top() { return indexOut == -1 ? buff[indexIn] : buff[indexOut]; }

	RingBuffer& operator << (int vl) { push(vl); return *this; }
	RingBuffer& operator >> (int &vl) { vl = top(); pop(); return *this; }


	bool eob()
	{
		bool res = false;

		if (endIn) {
			endIn = false;
			res = true;
		}
		if (endOut) {
			endOut = false;
			res = true;
		}

		return res;
	}

	size_t lenght() { return size; }

	void outBuff()
	{
		for (int i = 0; i < size; ++i)
			std::cout << buff[i] << '\t';
		std::cout << std::endl;
	}
};