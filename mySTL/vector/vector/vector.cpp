/*vector�����¹��ܣ�
vector()	���캯��
~vector()	��������
vector(const vector& vec)	�������캯��
vector& operator=(const vector& vec)	��ֵ��������غ���
value_type& operator[](allSize_t index)	[]��������غ���������ȡ��vectorʵ��������ĵ�index��Ԫ�أ�
bool operator==(const vector& vec)const	==��������غ����������ж�����vector�����Ƿ���ȣ�
void push_back(value_type val)	��vectorʾ������������Ԫ��
void pop_back()	ɾ��vectorʵ�����������һ��Ԫ��
void insert(iterator it,value_type val)	��vectorʵ���������itλ�ò���һ��Ԫ��
void erase(iterator it)	ɾ��vectorʵ��������itλ�õ�Ԫ��
value_type front()const	ȡ��vector�����еĵ�һ��Ԫ��
value_type back()const	ȡ��vector�����е����һ��Ԫ��
iterator begin()	��ȡvectorʵ���������Ԫ���׵�ַ
iterator end()	��ȡvectorʵ������������һ��Ԫ�ص���һ����ַ
allSize_t allSize()const	��ȡvectorʵ���������Ԫ�ظ���
allSize_t allCapacity()const	��ȡvectorʵ����������ռ�ռ��С
bool empty()	�ж�vectorʵ���������Ƿ�Ϊ��
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
	//���캯��
	vector() :pData(NULL), allSize(0), allCapacity(0) {}
	//��������
	~vector()
	{
		delete[] pData;
		pData = nullptr;
		allSize = 0;
		allCapacity = 0;
	}
	//�������캯��
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
	//����=
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
	//����[]
	value_type& operator[](size_t index)
	{
		return pData[index];
	}
	//==���������
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
	//push_back ����Ԫ��
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
	//insert ����Ԫ��
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
	//pop_back ɾ�����һ��Ԫ��
	void pop_back()
	{
		--allSize;
	}
	//earse ɾ��ָ��Ԫ��
	void erase(iterator it)
	{
		size_t index = it - pData;
		for (;index < allSize - 1;++index)
		{
			pData[index] = pData[index + 1];
		}
		--allSize;
	}
	//front ���ص�һ��Ԫ��
	value_type front() const
	{
		return pData[0];
	}
	//back �������һ��Ԫ��
	value_type back() const
	{
		return pData[allSize - 1];
	}
	//begin ���ص�һ��Ԫ�صĵ�ַ
	iterator begin()
	{
		return pData;
	}
	//end �������һ��Ԫ�صĵ�ַ
	iterator end()
	{
		return pData + allSize;
	}
	//size ����Ԫ�ظ���
	size_t size()
	{
		return allSize;
	}
	//capacity ��������Ŀռ�Ĵ�С
	size_t capacity()
	{
		return allCapacity;
	}
	//empty �ж��Ƿ�Ϊ��
	bool empty()
	{
		return allSize == 0;
	}

private:
	value_type* pData;//���������ռ��ָ��
	size_t allSize;//���vector��Ԫ�ظ���
	size_t allCapacity;//���vector������Ŀռ��С:������ñ����ķ�ʽ�����С.
};

}
