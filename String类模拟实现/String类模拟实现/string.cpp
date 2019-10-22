#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

//ģ��ʵ��string�࣬����Ҫ��ʵ��string��Ĺ��졢�������졢��ֵ����������Լ���������
//namespace xiaoyang
//{
//	class string {
//	public:
//		//string() //����д��
//		//      :_str(nullptr)
//		//{}
//		//string(char*  str) //�����д��
//		//      :_str(str)
//		//{}
//		//string() //����ȱʡֵ����
//		//      :_str(new char[1])//[]���ռ��\0
//		//{
//		//      *_str = '\0';
//		//}
//		//string(const char*  str = nullptr) //�����д��
//		//string(const char*  str = '\0') //�����д��
//
//		string(const char*  str = " ") //������\0
//			:_str(new char[strlen(str) + 1]) //���ǽ������ռ��ֵ���룬�������¿�һ��ռ䣨�ѣ�//+1 strlen�㵽\0 Ҫ����\0
//		{
//			strcpy(_str, str); //while(*dst = *src) \0 Ҳ����ȥ
//		}
//
//		~string() //����
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		string(const string& s) //string copy(s1) �������졢���
//			:_str(new char[strlen(s._str) + 1]) //��s1һ����Ŀռ䣬thisָ��copy
//		{
//			strcpy(_str, s._str);
//		}
//
//		//s1 = s2 ��ֵ���ͷžɿռ䡢�����¿ռ䡢����
//		string& operator = (const string& s) //֧��������ֵ s1->this s2->s
//		{
//			if (this != &s) //��ֹ�Լ����Լ���ֵ
//			{
//				delete[] _str; //���ͷ�s1
//				_str = new char[strlen(s._str) + 1]; //�ٿ���s2һ����Ŀռ�
//				strcpy(_str, s._str); //�ٿ���
//			}
//			return *this;
//		}
//
//		const char* c_str()
//		{
//			return _str;  //����_str
//		}
//
//		char& operator[](size_t pos) //operator[] ����д
//		{
//			return _str[pos]; //_strָ��string(hello ����)
//		}
//
//	private:
//		char* _str;
//	};
//}
//
//int main()
//{
//	xiaoyang::string s1("hello");//hello �����ڳ������������޸�����ʹ��const
//	s1[0] = 'H'; //�޸ĵ�һ��������char& operator[](size_t pos)
//	cout << s1.c_str() << endl; //C���ַ�����������  //Hello
//
//	xiaoyang::string s2;
//	cout << s2.c_str() << endl; //C���ַ�����������  //��
//	xiaoyang::string copy(s1);
//	cout << copy.c_str() << endl; //Ĭ������Ϊǳ����  //Hello
//
//	copy[0] = 'h';
//	cout << s1.c_str() << endl;   //Hello
//	cout << copy.c_str() << endl; //hello
//
//	xiaoyang::string s3 = "world";
//	cout << s3.c_str() << endl; //world
//
//	//s1 = s3;  //ǣ����ֵ�ռ��С�����⣬����operator��ֵ
//	//cout << s1.c_str() << endl; //world
//
//	s1 = s3;  //ǣ����ֵ�ռ��С�����⣬����operator��ֵ
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

		typedef char* iterator; //������
		typedef const char* const_iterator; //const������

		const_iterator begin()const //����
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

		string(const char*  str = " ") //������\0
			:_str(new char[strlen(str) + 1]) //���ǽ������ռ��ֵ���룬�������¿�һ��ռ䣨�ѣ�
		{                                    //+1 strlen�㵽\0 Ҫ����\0
			strcpy(_str, str); //while(*dst = *src) \0 Ҳ����ȥ
			_size = strlen(str); 
			_capacity = _size; //capacity����Ч�ַ����������ռ仹��һ��
		}
		
		~string() //����
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		string(const string& s) //string copy(s1) �������졢���
			:_str(new char[s._size + 1]) //��ȫ��capacity
			, _size(s._size)
			,_capacity(s._size)
		{
			strcpy(_str, s._str);
		}
		
		//s1 = s2 ��ֵ���ͷžɿռ䡢�����¿ռ䡢����
		string& operator = (const string& s) //֧��������ֵ s1->this s2->s
		{
			if (this != &s) //��ֹ�Լ����Լ���ֵ
			{
				delete[] _str; //���ͷ�s1
				_str = new char[s._size + 1]; //�ٿ���s2һ����Ŀռ�
				strcpy(_str, s._str); //�ٿ���
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		const char* c_str()
		{
			return _str;  //����_str
		}

		char& operator[](size_t pos) //operator[] ����д
		{
			return _str[pos]; //_strָ��string(hello ����)
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
				char* tmp = new char[n + 1]; //���ռ�
				strcpy(tmp, _str); //������
				delete[] _str; //�ͷžɿռ�
				_str = tmp; //ָ���¿ռ�
				_capacity = n; //�ռ��С�ı�
			}
		}

		void insert(size_t pos, char ch) //�����ַ�
		{
			//assert(pos < _size);
			//if (_size == _capacity) //���ռ��Ƿ�����
			//{
			//	reserve(_capacity * 2); //����
			//}

			assert(pos <= _size);
			if (_size == _capacity) //���ռ��Ƿ�����
			{
				reserve(_capacity * 2); //����
			}

			//int end = _size; // \0Ҳ���������ƶ�
			//while (end >= (int)pos) //end:0-��������ʽ����ת�����з���ת��Ϊ�޷���
			//{                       //ǿת
			//	_str[end + 1] = _str[end]; //�����ƶ�һ��λ��
			//	--end;
			//}

			size_t end = _size + 1;
			while (end >= pos)
			{
				_str[end] = _str[end - 1]; //ǰһ��λ�������ƶ�
				--end;
			}

			_str[pos] = ch; //���ַ�ch�ŵ�posλ��
			++_size;
		}

		void insert(size_t pos, const char* str) //�����ַ���
		{
			size_t len = strlen(str); //��������ַ����ĳ���
			if (_size + len > _capacity) //�жϿռ��С
			{
				reserve(_size + len); //���ݣ�reserve����֪����С�������ٿռ�
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

			while (*str) //����ʹ��strcpy()���п��������´��\0,�Ḳ�ǲ��������
			{
				_str[pos++] = *str++; //*���ȼ�����++
			}

			_size += len;
		}

		void push_back(char ch) //���ַ�����׷��һ���ַ�
		{
			//if (_size == _capacity)
			//{
			//	reserve(_capacity * 2); //����
			//}

			//_str[_size] = ch;
			//++_size; //�����滻\0��λ��
			//_str[_size] = '\0'; //��\0

			insert(_size, ch); //assert(pos <= _size);
		}

		void append(const char* str) //���ַ�����׷��һ���ַ���
		{
			//size_t len = strlen(str);
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len); //���� _size���С�lenҪ�Ӹ���
			//}

			//strcpy(_str + _size, str); //strcpy() �´��\0
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
	while (it1 != s1.end())   //��ӡ
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	for (auto e : s1) //��Χfor���Զ�ƥ�䣬�ɵ�����֧��
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
	s2.insert(0, 'Y'); //Yyang beautiful, ���������ģ��� ++_size;
	cout << s2.c_str() << endl;

	s2.insert(0, "hahah~"); //�����ַ���
	cout << s2.c_str() << endl;
}

int main()
{
	//test1();
	test2();

	system("pause");
	return 0;
}