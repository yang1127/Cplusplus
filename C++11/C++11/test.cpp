#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <array>
using namespace std;

//int main()
//{
//	//C++98
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//
//	int* p1 = new int(10); // C++98
//	//int* p2 = new int[5](1);//C++98��֧��new����ĳ�ʼ��
//	//C++11֧��{}��ʼ��
//	int* p3 = new int[5]{1,2,3,4,5};//C++11
//
//	vector<int> v1{ 1, 2, 3, 4, 5 };
//	vector<int> v2 = { 1, 2, 3, 4, 5 };
//
//	set<int> s1 = { 2, 3, 1, 5, 3, 5 };
//	map<string, int> countMap = { { "sort", 1 }, { "string", 3 } }; // =�����У�����û��
//
//	return 0;
//}

// C++98
//class A
//{
//public:
//	//explicit A(int a)
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class Point
//{
//public:
//	Point(int x, int y) : _x(x), _y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};

//int main()
//{
//	//C++98
//	A a1(1); // ���ù��캯��
//	A a2 = 2; // ����ת��    -> 1��������ʱ���� + ��������a2 + �Ż� = ֱ�ӹ���
//	string s1("hello");
//	string s2 = "hello";
//
//	int i = 0;
//	const double& d = i;
//
//	Point p1(1, 1);
//	//Point p2 = (2,2);  // C++98��֧�ֶ����������ת��
//	Point p3 = { 3, 3 }; //C++11
//
//	// ��ô����Ϳ��Կ���map�ĳ�ʼ����set�ĳ�ʼ��ʱһ���ķ�ʽ֧�ֵģ�ֻ��map����
//	// һ��һ����pair��{ "sort", 1 }ת��һ��pair����
//	set<int> s1 = { 2, 3, 1, 5, 3, 5 };
//	map<string, int> countMap = { { "sort", 1 }, { "string", 3 } }; // =�����У�����û��
//
//	return 0;
//}

//int main()
//{
//	initializer_list<int> l1 = { 1, 2, 3, 4, 5 };
//	initializer_list<int>::iterator it1 = l1.begin();
//	while (it1 != l1.end())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//	
//	//vector (initializer_list<value_type> il,const allocator_type& alloc = allocator_type());
//	// ����������Ҳ�����Ƶķ�ʽ֧�ֵ�
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	cout << typeid(v).name() << endl;
//
//	int a = 10;
//	int b = 20;
//
//	// ��decltype����a+b��ʵ�����ͣ���Ϊ����c������
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//
//	// 1����Χfor�����������ԣ��ײ����ɵ�����֧�ֵġ�
//	for (auto e : v)
//		cout << e << " ";
//	// 2��������ȡv�����е�ֵ���θ�ֵ��e��Ҳ����˵��e�ĸı䲻��Ӱ��v
//	for (auto& e : v)
//		e *= 2;
//	// 3����ʱe������Ҵ�Ķ���ʱ��ע����&
//	vector<string> vs{"sort", "string"};
//	for (const auto& e : vs)
//		// ...
//}

//int main()
//{
//	// a����ֵ��10��һ����ֵ
//	int a = 10;
//	// ����ߵ�һ����ֵ���ǵ�
//	// ���ұߵ�һ������ֵ�𣿲�һ��,����������ʽ��a
//	int b = a;
//	// ��ֵͨ���ǣ����Ա��޸ĵĶ���
//	// ��ֵͨ���ǣ����������ʽ�ķ���ֵ(��ʱ����)
//	int c = a + b;
//}

//int main()
//{
//	// 1����ֵ���ÿ���������ֵ
//	int a = 10;
//	int& b = a;
//
//	// 2����ֵ�����ܷ�������ֵ�����У�����const��ֵ���ÿ���
//	const int& c = 10;
//	const int& d = a + b;
//
//	return 0;
//}

//int main()
//{
//	// ������������ֵ
//	// ��ֵ�����ܷ�������ֵ������,
//	// ���ǿ���ʹ��move����ֵת������ֵ,�Ϳ�����ֵ������
//	int a = 10;
//	//int&& b = a; // ���뱨��
//	int && b = move(a);
//	int&& c = 10;
//	int&& d = a + 10;
//}

/*
// ʵ��String�����
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	// ��������
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		cout << "String(const String& s)" << endl;
		strcpy(_str, s._str);
	}

	// �ƶ�����->Ϊʲô������ֱ�ӽ����ƶ�����Ϊs����ֵ�еĽ���ֵ��
	// �����㶼Ҫ���ˣ��Ҳ�Ҫ�����ˣ�ֱ�ӽ�����Դ�ƶ����ҿɺá�
	String(String&& s)
		:_str(nullptr)
	{
		cout << "String(String&& s)" << endl;
		swap(_str, s._str);
	}

	// s1 = tmp
	// �ƶ�����
	String& operator = (String&& s)
	{
		swap(_str, s._str);

		return *this;
	}

	String& operator=(const String& s)
	{
		cout << "String& operator=(const String& s)" << endl;

		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}

	// s1 + s2
	// s1.operator+(&s1, s2)
	String operator+(const String& s) const
	{
		String tmp;
		tmp._str = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(tmp._str, _str);
		strcat(tmp._str, s._str);
		return tmp;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}

	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};

// �ƶ�������ƶ���ֵ

int main()
{
	String s1("hello");
	String s2("world");
	String ret = s1 + s2; // ->��������
	cout << ret.c_str() << endl;

	String s3(s1);       // ��������
	String s5(move(s1)); // �ƶ�����

	return 0;
}
*/

//int main()
//{
//	vector<String> v;
//	//String s1("��ֵ");
//	//v.push_back(s1);               // ��������-���-���۴�
//	//v.push_back("��ֵ-����ֵ");    // �ƶ�����-�ƶ���Դ-����С
//	v.push_back(move(s1));         // �ƶ�����-����Ḷ�����ۣ����������ã�s1���ƿ���
//
//
//	String s2("��ֵ");  // �˽�һ�£�һ����������ǻ���ʹ������push_pack�Ϳ���
//	v.emplace_back(s2);
//	v.emplace_back(String("��ֵ-����ֵ"));
//
//	return 0;
//}


//void Fun(int &x){ cout << "lvalue ref" << endl; }
//void Fun(int &&x){ cout << "rvalue ref" << endl; }
//void Fun(const int &x){ cout << "const lvalue ref" << endl; }
//void Fun(const int &&x){ cout << "const rvalue ref" << endl; }
//
//template<typename T>
//void PerfectForward(T && t)   //ģ�崫�εĹ����У���ֵ���Իᶪʧ -������ת�����Խ��
//{
//	Fun(t);
//}
//
//int main()
//{
//	PerfectForward(10); // rvalue ref
//
//	int a = 0;
//	PerfectForward(a); // lvalue ref
//	PerfectForward(std::move(a)); // rvalue ref
//
//	const int b = 8;
//	PerfectForward(b); // const lvalue ref
//	PerfectForward(std::move(b)); // const rvalue ref
//
//	return 0;
//}

struct Goods
{
	string _name;
	double _price;
	int _evaluation; // ����
	// ���磺�������ۺ�����
};

bool PriceCompare(const Goods& g1, const Goods& g2)
{
	return g1._price < g2._price;
}

bool EvaluationCompare(const Goods& g1, const Goods& g2)
{
	return g1._evaluation < g2._evaluation;
}

struct PriceCompareOBJ
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price < g2._price;
	}
};

struct EvaluationCompareOBJ
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._evaluation < g2._evaluation;
	}
};

//int main()
//{
//	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
//	[]{};
//
//	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
//	int a = 3, b = 4,c=5;
//	[a,b]{return a + b; }; // ����׽a,b
//	[=]{return a + b; }; // ����׽������ж���
//
//	// дһ������a��b��lamber
//	// mutable�ı䲶׽����a��b�������Ըı�
//	auto lamber_swap1 = [a, b]()mutable->void{int tmp = a; a = b; b = tmp; };
//	lamber_swap1(); // ���ܷ�����������ֵ�����ķ�ʽ��׽a��b
//
//	// ��ʽ��д��
//	auto lamber_swap2 = [&a, &b](){int tmp = a; a = b; b = tmp; };
//	lamber_swap2(); 
//
//	auto lamber_swap3 = [](int& a, int& b){int tmp = a; a = b; b = tmp; };
//	lamber_swap3(a, b);
//
//	auto lamber_swap4 = [&](){int tmp = a; a = b; b = tmp; };
//	lamber_swap4();
//
//	return 0;
//}

//int main()
//{
//	Goods gds[] = { { "ƻ��", 2.1,  5}, { "�㽶", 3, 4}, { "����", 2.2, 2}, { "����", 1.5, 2} };
//	// ���۸�/�������������д��
//	// 1������ָ�� C��Ϯ����
//	PriceCompare(gds[0], gds[1]);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), PriceCompare);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), EvaluationCompare);
//
//	// 2���º���/�������� -> ������ָ������ƣ�������Ϊ������ģ��������ݣ�Ҳ�����ں���������Ϊ����
//	PriceCompareOBJ pcobj;
//	pcobj(gds[0], gds[1]);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), pcobj);
//
//	EvaluationCompareOBJ ecobj;
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), ecobj);
//
//	// ������ǻ��Ǽ۸������۵Ľ��������������ۺ�������
//	// ���ǻᷢ�֣�����Ҫд�ܶ�����������Ƿº�������û�и��õĽ����ʽ�أ�-��labmber
//
//	// 3.labmber���ʽ  ->����������ַ�ʽ�򵥷���,�����Ϥlabmber�﷨֮�󣬴���ɶ��Ը�ǿ
//	auto priceLess = [](const Goods& g1, const Goods& g2)->bool
//	{
//		return g1._price < g2._price;
//	};
//
//	// ����ֵ����ʡ�ԣ����ǽ���д��
//	auto priceGreater = [](const Goods& g1, const Goods& g2)
//	{
//		return g1._price > g2._price;
//	};
//	priceLess(gds[0], gds[1]);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), priceLess);
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), priceGreater);
//
//	// ��ʵʵ���и���Ķ�����ȡ���֣�ֱ����
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._price < g2._price; });
//
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._price > g2._price; });
//
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._evaluation < g2._evaluation; });
//
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//	{return g1._evaluation > g2._evaluation; });
//
//	return 0;
//}

class Rate
{
public:
	Rate(double rate) : _rate(rate)
	{}

	double operator()(double money, int year)
	{
		return money * _rate * year;
	}

private:
	double _rate;
};

int main()
{
	// ��������
	double rate = 0.49;
	Rate r1(rate);
	r1(10000, 2);

	// lamber
	auto r2 = [=](double monty, int year)->double {return monty * rate*year; };
	r2(10000, 2);
	return 0;
}