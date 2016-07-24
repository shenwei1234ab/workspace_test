#ifndef _DIRTY_MANAGER_
#define _DIRTY_MANAGER_
#include <map>
#include <iostream>
class StringTree
{
public:
	void Add(const char *pArray, size_t size)
	{
		Node *pNode = &m_root;
		for (; size&&*pArray; --size, ++pArray)
		{
			char c = *pArray;
			pNode = &pNode->nodes[c];
			pNode->val = c;
		}
		pNode->null = true;
	}


	bool Check(const char *pArray, size_t size)
	{
		Node *pNode = &m_root;
		for (; size && *pArray; --size, ++pArray) 
		{
			if (pNode->null)
			{
				//���û���ҵ�
				return false;
			}
			auto &map = pNode->nodes;
			auto iter = map.find(*pArray);
			if (iter == map.end())
			{
				//û���ҵ�
				return false;
			}
			pNode = &iter->second;
		}
		return true;
	}

private:
	struct Node
	{
		char val;
		std::map<char, Node> nodes;
		bool null = false;
	};

	Node m_root;
};



class DiryManger
{
private:
	DiryManger()   //���캯����˽�е�  
	{
		std::cout << "Dirymanager constructor" << std::endl;
	}
	DiryManger(const DiryManger &);
	DiryManger & operator = (const DiryManger &);
public:
	//�����ʼ��,���ǲ����̰߳�ȫ�ģ�c++0x�ǰ�ȫ�ģ�
	static DiryManger & GetInstance()
	{
		static DiryManger instance;   //�ֲ���̬����  
		return instance;
	}



	bool Init()
	{
		//test
		char str[] = { 's', 'h', 'e', 'n' };
		m_tree.Add(str, 4);
		return true;
	}

	bool Check(const std::string &str)
	{
		return m_tree.Check(str.c_str(), str.length());
	}
private:
	StringTree m_tree;
};

#endif 