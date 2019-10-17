#include<iostream>
#include<string>
using namespace std;

//// string类对象的常见构造
//int main()
//{
//	string s1;                // 构造空的string类对象s1
//	string s2("hello xiao yang");   // 用C格式字符串构造string类对象s2
//	string s3(10, 'a');       // 用10个字符'a'构造string类对象s3
//	string s4(s2);            // 拷贝构造s4
//	string s5(s3, 5);         // 用s3中前5个字符构造string对象s5
//
//	system("pause");
//	return 0;
//}

//// string类对象的容量操作
//int main()
//{
//  //string s1;                
//	//string s2("xiao yang"); 
//
//	////for (size_t i = 0; i < s2.size(); i++)
//	////{
//	////	cout << s2[i] << endl;
//	////}
//	//
//	////字符串有效字符长度，优先使用size
//	//cout << s1.size() << endl;
//	//cout << s1.length() << endl;
//	//cout << s2.size() << endl;
//	//cout << s2.length() << endl;
//
//	////空间总大小
//	//cout << s1.capacity() << endl;
//	//cout << s1.capacity() << endl;
//	//cout << s2.capacity() << endl;
//  //cout << s2.capacity() << endl;
//
//	////清空有效字符
//	//s2.clear(); //只清空不释放空间，释放空间<->析构
//	//cout << s2.size() << endl;
//	//cout << s2.capacity() << endl;
//
//	////resize()
//	////将有效字符的个数该成n个，多出的空间用字符c填充
//	//s2.resize(10, 'a'); //将s1有效字符的个数增加到10个，多出的位置"a"填充
//	//cout << s2.size() << endl; //10
//	//cout << s2.capacity() << endl; //15
//  //cout << s2 << endl; //"xiao yanga"
//
//	////将有效字符的个数改成n个，多出的空间用0填充
//	////当s2中有效字符增加到15个，多出的位置用缺省值'\0'进行填充
//	//s2.resize(15);
//	//cout << s2.size() << endl; //15
//  //cout << s2.capacity() << endl; //15
//	//cout << s2 << endl; //xiao yang\0\0\0\0\0\0
//
//	//// 将s2中有效字符个数缩小到5
//	////只缩小字符长度，不缩小空间
//	//s2.resize(5); 
//	//cout << s2.size() << endl; //5
//	//cout << s2.capacity() << endl; //15
//	//cout << s2 << endl; //xiao \0\0\0\0\0\0\0\0\0\0
//
//	////reserve 为字符串预留空间
//	//string s;     
//	//s.reserve(100);
//	//cout << s.size() << endl; // 0
//	//cout << s.capacity() << endl; //111
// //  
//	//s.reserve(50); 
//	//cout << s.size() << endl; //0
//	//cout << s.capacity() << endl; //63
//
//	//s.reserve(10);
//	//cout << s.size() << endl; //0
//	//cout << s.capacity() << endl; //15
//	//
//	system("pause");
//	return 0;
//}

//// string类对象的访问操作
//int main()
//{
//	string s1("hello world");
//	const string s2("xiao yang");
//	cout << s1 << " " << s2 << endl; //hello world xiao yang
//	cout << s1[0] << " " << s2[0] << endl; //h x
//
//	s1[0] = 'x';
//	cout << s1 << endl; //xello world
//
//	for (size_t i = 0; i < s1.size(); ++i)
//	{ 
//		cout << s1[i] << endl;
//	}     
//
//	 //s2[0] = 'h';   //const类型对象不能修改
//
//	system("pause");
//	return 0;
//}

void teststring()
{
	//string s;
	//s.push_back(' ');    // 在s后插入空格
	//s.append("hello ");  // 追加一个字符"hello"
	//s += 'a';            // 追加一个字符'b'
	//s += " xiao yang";   // 追加一个字符串"xiaoyang" 

	//cout<< s <<endl;     // hello a xiao yang
	//cout<< s.c_str() <<endl;   // 以C语言的方式打印字符串 // hello a xiao yang

	////从字符串pos位置开始往后找字符c，返回该字符在字符串中的位置
	////size_t ﬁnd (char c, size_t pos = 0)const
	////取出域名
	//string sl("http://www.cplusplus.com/reference/string/string/find/");
	//cout << sl << endl;

	//size_t start = sl.find("://");// 从：//这个位置开始找
	//if (start == string::npos) 
	//{ 
	//	cout << "invalid sl" << endl; 
	//	return; 
	//}    
	//start += 3; 
	//size_t finish = sl.find('/', start);
	//string address = sl.substr(start, finish - start);//在str中从pos位置开始，截取n个字符，然后将其返回
	//cout << address << endl; // www.cplusplus.com

	////删除协议前缀
	//start = sl.find("://"); //start<->pos
	//sl.erase(0, start + 3);
	//cout << sl << endl;//www.cplusplus.com/reference/string/string/find/


}
				
////增容
//void PushBack() 
//{
//	string s;
//	size_t sz = s.capacity(); //开始空间
//	s.reserve(100); //已经知道要扩容多少时，使用reserve（），可以减少扩容带来的开销
//	
//	s.reserve(50);
//	cout << s.capacity() << endl; //容易扩容，不容易缩，缩容的话，要开辟新空间
//
//	cout << "making s grow:\n"; 
//	for (int i = 0; i < 100; ++i)
//	{ 
//		s += 'c'; 
//		s.push_back('c'); //尾插 push_back(char c)
//		if (sz != s.capacity()) 
//		{ 
//			sz = s.capacity(); //增容
//			cout << "capacity changed: " << sz << '\n';
//		} 
//	}
//}

int main()
{
	teststring();
	//PushBack();

	system("pause");
	return 0;
}