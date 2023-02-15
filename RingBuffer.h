#pragma once
#include <cstdint>
#include <iostream>


class RingBuffer
{
private:

	uint16_t size;

	size_t popCount = 0;
	int *buff;

	int indexIn, indexOut;
	int lastPopIndex = -1;

	int endIn, endOut;


	void toNext(int &index) 
	{ 
		index = ((index + 1) >= size ? 0 : (index + 1));
	}
	int getCorrect(int index)
	{
		//if (index == -1) return size;
		return index >= size ? 0 : index;
	}
	int* collision()
	{
		return buff;
	}
public:

	RingBuffer(const int lenght):
		size(lenght), indexIn(0), indexOut(0), endIn(false), endOut(false)
	{
		if (lenght < 0) throw 1;

		buff = new int[size + 1];

		for (int i = 0; i < size; ++i)
			buff[i] = 0;
	}
	~RingBuffer() { delete[] buff; }



	void push(const int vl)
	{
		popCount = 0;
		buff[getCorrect(indexIn)] = vl;

		if (getCorrect(indexIn) == lastPopIndex) {
			toNext(lastPopIndex);
			endIn = lastPopIndex;													/// !!!!!!!!!!!!!!!!
		}
		
		toNext(indexIn);

		if (lastPopIndex == -1)
			lastPopIndex = 0;
	}

	void pop()
	{
		int *ptr = buff;
		++popCount;

		if (popCount >= size) {
			clear();
			return;
		}

		buff[getCorrect(lastPopIndex)] = 0;
		toNext(lastPopIndex);
		if (lastPopIndex == indexIn)
			--lastPopIndex;


		
	}

	int top() { return buff[indexIn];}

	RingBuffer& operator << (int vl) { push(vl); return *this; }
	RingBuffer& operator >> (int &vl) { vl = top(); pop(); return *this; }


	void clear()
	{
		for (int i = 0; i < size; ++i)
			buff[i] = 0;
		lastPopIndex = -1;
		indexIn = 0;
		popCount = 0;
	}

	size_t lenght() { return size; }

	void outBuff()
	{
		for (int i = 0; i < size; ++i)
			std::cout << buff[i] << '\t';
		std::cout << std::endl;
	}
};