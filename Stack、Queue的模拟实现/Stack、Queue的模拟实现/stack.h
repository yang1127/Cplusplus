#pragma once

template<class T, class Container> //适配器
class stack
{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}

	void Pop()
	{
		_con.pop_back();
	}

	const T& Top()
	{
		_con.back();
	}

	const T& Top()const 
	{ 
		return _c.back();
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
	Container _con;
};

void TestStack()
{
	// 适配体现在第二个模板参数可以使用不同的容器，然后适配生成的stack效果是一样的。
	//Stack<int, deque<int>> s;
	//Stack<int, vector<int>> s;
	//Stack<int, list<int>> s;

	stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	cout << s.Size() << endl;
	cout << s.Top() << endl;

    s.Pop();
	s.Pop();
	cout << s.Size() << endl;
	cout << s.Top() << endl;
}