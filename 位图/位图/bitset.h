#pragma once
#include <vector>

class BitSet
{
public:
	BitSet(size_t bitNum) //������λ����
	{
		_bitNum = bitNum;
		//_bits.resize(bitNum / 32 + 1, 0);
		_bits.resize((bitNum >> 5) + 1, 0); //���ռ䲢��ʼ��
	}

	void Set(size_t x)
	{
		//�ҵ�xӳ��λ�����ĸ�����
		//�ҵ�xӳ��������е��Ǹ�λ
		size_t index = (x >> 5);
		size_t pos = x % 32;

		_bits[index] |= (1 << pos); //1����posλ����Ϊ1
	}

	void Reset(size_t x)
	{
		size_t index = x >> 5;
		size_t pos = x % 32;

		_bits[index] &= ~(1 << pos); //1����posλ��ȡ������0
	}

	bool Test(size_t x) //�ж��Ϸ��õ�Ϊ0����1���Ҳ���Ӱ���ֵ
	{
		size_t index = (x >> 5);
		size_t pos = x % 32;

		return _bits[index] & (1 << pos);
	}

private:
	vector<int> _bits;
	size_t _bitNum;
};