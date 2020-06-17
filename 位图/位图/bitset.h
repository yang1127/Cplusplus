#pragma once
#include <vector>

class BitSet
{
public:
	BitSet(size_t bitNum) //开多少位个数
	{
		_bitNum = bitNum;
		//_bits.resize(bitNum / 32 + 1, 0);
		_bits.resize((bitNum >> 5) + 1, 0); //开空间并初始化
	}

	void Set(size_t x)
	{
		//找到x映射位置在哪个整型
		//找到x映射的整型中的那个位
		size_t index = (x >> 5);
		size_t pos = x % 32;

		_bits[index] |= (1 << pos); //1左移pos位：置为1
	}

	void Reset(size_t x)
	{
		size_t index = x >> 5;
		size_t pos = x % 32;

		_bits[index] &= ~(1 << pos); //1左移pos位，取反：置0
	}

	bool Test(size_t x) //判断上方置的为0还是1，且不能影响该值
	{
		size_t index = (x >> 5);
		size_t pos = x % 32;

		return _bits[index] & (1 << pos);
	}

private:
	vector<int> _bits;
	size_t _bitNum;
};