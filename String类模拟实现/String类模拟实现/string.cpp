#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

//模拟实现string类，最主要是实现string类的构造、拷贝构造、赋值运算符重载以及析构函数
//namespace xiaoyang
//{
//	class string {
//	public:
//		//string() //错误写法
//		//      :_str(nullptr)
//		//{}
//		//string(char*  str) //错误的写法
//		//      :_str(str)
//		//{}
//		//string() //可用缺省值代替
//		//      :_str(new char[1])//[]开空间放\0
//		//{
//		//      *_str = '\0';
//		//}
//		//string(const char*  str = nullptr) //错误的写法
//		//string(const char*  str = '\0') //错误的写法
//
//		string(const char*  str = " ") //里面有\0
//			:_str(new char[strlen(str) + 1]) //并非将常量空间的值给与，而是重新开一块空间（堆）//+1 strlen算到\0 要包括\0
//		{
//			strcpy(_str, str); //while(*dst = *src) \0 也拷过去
//		}
//
//		~string() //清理
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		string(const string& s) //string copy(s1) 拷贝构造、深拷贝
//			:_str(new char[strlen(s._str) + 1]) //开s1一样大的空间，this指向copy
//		{
//			strcpy(_str, s._str);
//		}
//
//		//s1 = s2 赋值：释放旧空间、开辟新空间、拷贝
//		string& operator = (const string& s) //支持连续赋值 s1->this s2->s
//		{
//			if (this != &s) //防止自己给自己赋值
//			{
//				delete[] _str; //先释放s1
//				_str = new char[strlen(s._str) + 1]; //再开和s2一样大的空间
//				strcpy(_str, s._str); //再拷贝
//			}
//			return *this;
//		}
//
//		const char* c_str()
//		{
//			return _str;  //返回_str
//		}
//
//		char& operator[](size_t pos) //operator[] 读、写
//		{
//			return _str[pos]; //_str指向string(hello 常量)
//		}
//
//	private:
//		char* _str;
//	};
//}
//
//int main()
//{
//	xiaoyang::string s1("hello");//hello 常量在常量区，不能修改所有使用const
//	s1[0] = 'H'; //修改第一个，调用char& operator[](size_t pos)
//	cout << s1.c_str() << endl; //C型字符串、解引用  //Hello
//
//	xiaoyang::string s2;
//	cout << s2.c_str() << endl; //C型字符串、解引用  //空
//	xiaoyang::string copy(s1);
//	cout << copy.c_str() << endl; //默认生成为浅拷贝  //Hello
//
//	copy[0] = 'h';
//	cout << s1.c_str() << endl;   //Hello
//	cout << copy.c_str() << endl; //hello
//
//	xiaoyang::string s3 = "world";
//	cout << s3.c_str() << endl; //world
//
//	//s1 = s3;  //牵扯赋值空间大小的问题，引入operator赋值
//	//cout << s1.c_str() << endl; //world
//
//	s1 = s3;  //牵扯赋值空间大小的问题，引入operator赋值
//	cout << s1.c_str() << endl; //world
//
//	system("pause");
//	return 0;
//}

//
namespace xiaoyang
{
	class string {
	public:

		typedef char* iterator; //迭代器
		typedef const char* const_iterator; //const迭代器

		const_iterator begin()const //重载
		{
			return _str;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char*  str = " ") //里面有\0
			:_str(new char[strlen(str) + 1]) //并非将常量空间的值给与，而是重新开一块空间（堆）
		{                                    //+1 strlen算到\0 要包括\0
			strcpy(_str, str); //while(*dst = *src) \0 也拷过去
			_size = strlen(str); 
			_capacity = _size; //capacity存有效字符，比真正空间还大一个
		}
		
		~string() //清理
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string(const string& s) //string copy(s1) 拷贝构造、深拷贝
			:_str(new char[s._size + 1]) //可全换capacity
			, _size(s._size)
			,_capacity(s._size)
		{
			strcpy(_str, s._str);
		}
		
		//s1 = s2 赋值：释放旧空间、开辟新空间、拷贝
		string& operator = (const string& s) //支持连续赋值 s1->this s2->s
		{
			if (this != &s) //防止自己给自己赋值
			{
				delete[] _str; //先释放s1
				_str = new char[s._size + 1]; //再开和s2一样大的空间
				strcpy(_str, s._str); //再拷贝
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		const char* c_str()
		{
			return _str;  //返回_str
		}

		char& operator[](size_t pos) //operator[] 读、写
		{
			return _str[pos]; //_str指向string(hello 常量)
		}

		size_t size()
		{
			return _size;
		}

		size_t capacity()
		{
			return _capacity;
		}

		void reserve(size_t n) //reserve
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; //开空间
				strcpy(tmp, _str); //拷数据
				delete[] _str; //释放旧空间
				_str = tmp; //指向新空间
				_capacity = n; //空间大小改变
			}
		}

		void insert(size_t pos, char ch) //插入字符
		{
			//assert(pos < _size);
			//if (_size == _capacity) //看空间是否满了
			//{
			//	reserve(_capacity * 2); //扩容
			//}

			assert(pos <= _size);
			if (_size == _capacity) //看空间是否满了
			{
				reserve(_capacity * 2); //扩容
			}

			//int end = _size; // \0也跟着往后移动
			//while (end >= (int)pos) //end:0-负数，隐式类型转化、有符号转化为无符号
			//{                       //强转
			//	_str[end + 1] = _str[end]; //往后移动一个位置
			//	--end;
			//}

			size_t end = _size + 1;
			while (end >= pos)
			{
				_str[end] = _str[end - 1]; //前一个位置往后移动
				--end;
			}

			_str[pos] = ch; //将字符ch放到pos位置
			++_size;
		}

		void insert(size_t pos, const char* str) //插入字符串
		{
			size_t len = strlen(str); //求出插入字符串的长度
			if (_size + len > _capacity) //判断空间大小
			{
				reserve(_size + len); //扩容，reserve：已知道大小，开多少空间
			}

			//int end = _size;
			//while (end >= (int)pos)
			//{
			//	_str[end + len] = _str[end];
			//	--end;
			//}

			size_t end = _size + len;
			while (end > pos + len)
			{
				_str[end] = _str[end - len];
				--end;
			}

			while (*str) //不能使用strcpy()进行拷贝，它会拷贝\0,会覆盖插入的数据
			{
				_str[pos++] = *str++; //*优先级高于++
			}

			_size += len;
		}

		void push_back(char ch) //在字符串后追加一个字符
		{
			//if (_size == _capacity)
			//{
			//	reserve(_capacity * 2); //扩容
			//}

			//_str[_size] = ch;
			//++_size; //最后会替换\0的位置
			//_str[_size] = '\0'; //放\0

			insert(_size, ch); //assert(pos <= _size);
		}

		void append(const char* str) //在字符串后追加一个字符串
		{
			//size_t len = strlen(str);
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len); //扩容 _size已有、len要加个数
			//}

			//strcpy(_str + _size, str); //strcpy() 会拷贝\0
			//_size += len;

			insert(_size, str); //assert(pos <= _size);
		}

		const string& operator += (char ch)
		{
			push_back(ch);
			return* this;
		}

		const string& operator += (const char* str)
		{
			append(str);
			return* this;
		}
				
		//const string& operator+=(const string& s)
		//{
		//	append(s._str);
		//	return *this;
		//}

		const string& operator > (char ch);
		const string& operator < (char ch);
		const string& operator <= (char ch);
		const string& operator >= (char ch);
		const string& operator == (char ch);


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

void test1()
{
	xiaoyang::string s1("hello");
	cout << s1.c_str() << endl; 

	xiaoyang::string copy(s1);
	cout << copy.c_str() << endl;

	xiaoyang::string::iterator it1 = s1.begin();
	while (it1 != s1.end())   //打印
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : s1) //范围for、自动匹配，由迭代器支撑
	{
		cout << e << " ";
	}
	cout << endl;

}

void test2()
{
	xiaoyang::string s1("yang ");
	cout << s1.capacity()<< endl; //5

	s1 += "beautiful";
	cout << s1.capacity() << endl; //14

	s1 += '!';
	cout << s1.capacity()<< endl; //28
	cout << s1.c_str() << endl; //yang beautiful!

	xiaoyang::string s2("yang beautiful");
	s2.insert(0, 'Y'); //Yyang beautiful, ！不见，改：加 ++_size;
	cout << s2.c_str() << endl;

	s2.insert(0, "hahah~"); //插入字符串
	cout << s2.c_str() << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}