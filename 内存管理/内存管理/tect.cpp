#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
using namespace std;

//c中 malloc
//int main() 
//{    
//
//	int num = 0;  
//	scanf("%d", &num);      
//
//	int* ptr = NULL;   
//	ptr = (int*)malloc(num*sizeof(int)); 
//
//	if(NULL != ptr) 
//	{       
//		int i = 0;  
//		for(i=0; i<num; i++)   
//		{        
//			*(ptr + i) = 0;
//		}  
//	}  
//	free(ptr); //释放ptr所指向的动态内存 
//
//	system("pause");
//	return 0;
//}

//void GetMemory(char *p) //有误
//{ 
//	p = (char *)malloc(100);
//} 
//
//int main()
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	return 0;
//}

//char *GetMemory(void) //有误
//{
//	char p[] = "hello world";  
//	return p;
//}
//
//int main()
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf(str);
//
//	return 0;
//}

//int main() //world
//{
//	char *str = (char *)malloc(100);   
//	strcpy(str, "hello"); 
//	free(str);  
//
//	if (str != NULL)
//	{ 
//		strcpy(str, "world"); 
//		printf(str);
//	}
//
//	system("pause");
//	return 0;
//}

//void GetMemory(char **p, int num) //hello
//{
//	*p = (char *)malloc(num);
//} 
//
//int main()
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//
//	system("pause");
//	return 0;
//}

//C++中

//int main()
//{
//	int* ptr1 = new int;          // 动态申请一个int类型的空间 
//	int* ptr2 = new int(10);      // 动态申请一个int类型的空间并初始化为10  
//	int* ptr3 = new int[3];       // 动态申请10个int类型的空间
//	
//	delete ptr1;  
//	delete ptr2;   
//	delete[] ptr3;
//
//	system("pause");
//	return 0;
//} 

class Test
{
public:    
	Test()
		: _data(0)
    {
		cout << "Test():" << this << endl;
	}

    ~Test() 
    {
	    cout << "~Test():" << this << endl;
    } 

private: 
	int _data;
};

void Test1() //C语言
{   
	
	Test* p1 = (Test*)malloc(sizeof(Test)); // 申请单个Test类型的空间   
	free(p1);     
	
	Test* p2 = (Test*)malloc(sizeof(Test) * 10); // 申请10个Test类型的空间
	free(p2);
}
	

void Test2() //C++
{    
	Test* p1 = new Test; // 申请单个Test类型的对象 
	delete p1;  

	Test* p2 = new Test[10];  // 申请10个Test类型的对象
	delete[] p2;

}

int main()
{
	Test1();
	Test2();

	system("pause");
	return 0;
}