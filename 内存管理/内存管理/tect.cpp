#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
using namespace std;

//c�� malloc
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
//	free(ptr); //�ͷ�ptr��ָ��Ķ�̬�ڴ� 
//
//	system("pause");
//	return 0;
//}

//void GetMemory(char *p) //����
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

//char *GetMemory(void) //����
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

//C++��

//int main()
//{
//	int* ptr1 = new int;          // ��̬����һ��int���͵Ŀռ� 
//	int* ptr2 = new int(10);      // ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10  
//	int* ptr3 = new int[3];       // ��̬����10��int���͵Ŀռ�
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

void Test1() //C����
{   
	
	Test* p1 = (Test*)malloc(sizeof(Test)); // ���뵥��Test���͵Ŀռ�   
	free(p1);     
	
	Test* p2 = (Test*)malloc(sizeof(Test) * 10); // ����10��Test���͵Ŀռ�
	free(p2);
}
	

void Test2() //C++
{    
	Test* p1 = new Test; // ���뵥��Test���͵Ķ��� 
	delete p1;  

	Test* p2 = new Test[10];  // ����10��Test���͵Ķ���
	delete[] p2;

}

int main()
{
	Test1();
	Test2();

	system("pause");
	return 0;
}