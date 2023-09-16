//通用数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	// 有参构造函数
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	// 拷贝构造函数
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity]; //深拷贝
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	// =运算符重载，防止浅拷贝
	MyArray& operator=(const MyArray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	// 尾插法
	void Push_Back(const T& value)
	{
		if (this->m_Size == this->m_Capacity)
		{
			return;
		}
		this->pAddress[this->m_Size] = value;
		this->m_Size++;
	}

	// 尾删法
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	// 通过下标访问数组元素

	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	// 返回数组容量
	int GetCapacity()
	{
		return this->m_Capacity;
	}

	// 返回数组大小
	int GetSize()
	{
		return this->m_Size;;
	}

	// 析构函数
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	T* pAddress; //指向堆区开辟的真实数组
	int m_Capacity; //数组容量
	int m_Size; //数组大小
};
