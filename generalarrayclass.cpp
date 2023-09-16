#include<iostream>
#include "MyArray.hpp"
using namespace std;

void test(MyArray <int> &arr)
{
	for (int i = 0; i < 5; i++)
	{
		arr.Push_Back(i);
	}
	cout << "array中的数据为：" << endl;
}

void printarray(MyArray <int>& arr)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		cout << arr[i] << endl;
	}
}


int main()
{
	MyArray <int>arr(5);
	test(arr);
	printarray(arr);
	system("pause");
	return 0;
}
