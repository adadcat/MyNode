/*vector有以下功能：
vector()	构造函数
~vector()	析构函数
vector(const vector& vec)	拷贝构造函数
vector& operator=(const vector& vec)	赋值运算符重载函数
value_type& operator[](allSize_t index)	[]运算符重载函数（用于取出vector实例化对象的第index个元素）
bool operator==(const vector& vec)const	==运算符重载函数（用于判断两个vector对象是否相等）
void push_back(value_type val)	向vector示例化对象增添元素
void pop_back()	删除vector实例化对象最后一个元素
void insert(iterator it,value_type val)	向vector实例化对象的it位置插入一个元素
void erase(iterator it)	删除vector实例化对象it位置的元素
value_type front()const	取出vector对象中的第一个元素
value_type back()const	取出vector对象中的最后一个元素
iterator begin()	获取vector实例化对象的元素首地址
iterator end()	获取vector实例化对象的最后一个元素的下一个地址
allSize_t allSize()const	获取vector实例化对象的元素个数
allSize_t allCapacity()const	获取vector实例化对象所占空间大小
bool empty()	判断vector实例化对象是否为空
*/

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

namespace miniSTL 
{

template<typename T>
class vector
{
public:
	typedef T value_type;
	typedef T* iterator;
public:
	//构造函数
	vector() :pData(NULL), allSize(0), allCapacity(0) {}
	//析构函数
	~vector()
	{
		delete[] pData;
		pData = nullptr;
		allSize = 0;
		allCapacity = 0;
	}
	//拷贝构造函数
	vector(const vector& vec)
	{
		pData = new value_type[allCapacity];
		allSize = vec.allSize;
		allCapacity = vec.allCapacity;
		for (size_t i = 0;i < allSize;++i)
		{
			pData[i] = vec.pData[i];
		}
	}
	//重载=
	vector& operator = (const vector& vec)
	{
		if (this == &vec)
		{
			return *this;
		}

		value_type* tmp = new value_type[allCapacity];
		for (size_t i = 0;i < allSize;++i)
		{
			tmp[i] = vec.pData[i];
		}
		
		delete[] pData;
		pData = tmp;
		allSize = vec.allSize;
		allCapacity = vec.allCapacity;

		return *this;
	}
	//重载[]
	value_type& operator[](size_t index)
	{
		return pData[index];
	}
	//==运算符重载
	bool operator==(const vector& vec)const
	{
		if (allSize != vec.allSize)
		{
			return false;
		}

		for (size_t i = 0;i < allSize;++i)
		{
			if (pData[i] != vec[i])
			{
				return false;
			}
		}

		return true;
	}
	//push_back 增添元素
	void push_back(value_type val)
	{
		if (0 == allCapacity)
		{
			allCapacity = 1;
			pData = new value_type[1];
		}
		else if (allSize + 1 > allCapacity)
		{
			allCapacity *= 2;
			value_type* tmp = new value_type[allCapacity];
			for (size_t i = 0;i < allSize;++i)
			{
				tmp[i] = pData[i];
			}

			delete[] pData;
			pData = tmp;
		}

		pData[allSize] = val;
		++allSize;
	}
	//insert 增添元素
	void insert(iterator it, value_type val)
	{
		int index = it - pData;

		if (0 == allCapacity)
		{
			allCapacity = 1;
			pData = new value_type[1];
			pData[0] = val;
		}
		else if (allSize + 1 > allCapacity)
		{
			allCapacity *= 2;
			value_type* tmp = new value_type[allCapacity];
			for (size_t i = 0;i < index;++i)
			{
				tmp[i] = pData[i];
			}
			tmp[index] = val;
			for (size_t j = index; j < allSize; ++j)
			{
				tmp[j] = pData[j];
			}
			delete[] pData;
			pData = tmp;
		}
		else
		{
			for (int i = allSize - 1; i >= index; --i) 
			{
				pData[i + 1] = pData[i];
			}
			pData[index] = val;
		}

		++allSize;
	}
	//pop_back 删除最后一个元素
	void pop_back()
	{
		--allSize;
	}
	//earse 删除指定元素
	void erase(iterator it)
	{
		size_t index = it - pData;
		for (;index < allSize - 1;++index)
		{
			pData[index] = pData[index + 1];
		}
		--allSize;
	}
	//front 返回第一个元素
	value_type front() const
	{
		return pData[0];
	}
	//back 返回最后一个元素
	value_type back() const
	{
		return pData[allSize - 1];
	}
	//begin 返回第一个元素的地址
	iterator begin()
	{
		return pData;
	}
	//end 返回最后一个元素的地址
	iterator end()
	{
		return pData + allSize;
	}
	//size 返回元素个数
	size_t size()
	{
		return allSize;
	}
	//capacity 返回申请的空间的大小
	size_t capacity()
	{
		return allCapacity;
	}
	//empty 判断是否为空
	bool empty()
	{
		return allSize == 0;
	}

private:
	value_type* pData;//申请连续空间的指针
	size_t allSize;//存放vector的元素个数
	size_t allCapacity;//存放vector所申请的空间大小:这里采用倍增的方式申请大小.
};

}
