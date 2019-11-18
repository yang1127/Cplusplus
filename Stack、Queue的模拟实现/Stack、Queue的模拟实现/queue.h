#pragma once

template<class T, class Container> //������
class Queue
{
public:
	Queue() {}

	void Push(const T& x) 
	{ 
		_c.push_back(x); 
	}


































	void Pop()
	{ 
		_c.pop_front();
	}

	T& Back() 
	{ 
		return _c.back();
	}

	const T& Back()const
	{ 
		return _c.back();
	}

	T& Front() 
	{
		return _c.front();
	}

	const T& Front()const
	{
		return _c.front(); 
	}

	size_t Size()const 
	{ 
		return _c.size();
	}

	bool Empty()const
	{ 
		return _c.empty();
	}

private:
	Con _c;
};
void TestQueue()
{
	// ���������ڵڶ���ģ���������ʹ�ò�ͬ��������Ȼ���������ɵ�queueЧ����һ���ġ�
	//Queue<int, deque<int>> q;
	//Queue<int, list<int>> q;

	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout << q.Size() << endl;
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	q.Pop();
	q.Pop();
	cout << q.Size() << endl;
    cout << q.Front() << endl;
	cout << q.Back() << endl;
}