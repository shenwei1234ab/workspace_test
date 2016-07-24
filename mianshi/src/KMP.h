#ifndef _KMP_H
#define _KMP_H
#include <string>
//��򵥵�bpģʽƥ��
int BPMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);

	int i = 0;
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			//�������ǰ�ַ�ƥ��ɹ�����S[i] == P[j]������i++��j++      
			i++;
			j++;
		}
		else
		{
			//�����ʧ�䣨��S[i]! = P[j]������i = i - (j - 1)��j = 0  ,s������P��    
			i = i - j + 1;
			j = 0;
		}
	}
	//ƥ��ɹ�������ģʽ��p���ı���s�е�λ�ã����򷵻�-1  
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int GetNext(int val)
{
	return 0;
}
int KmpSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++      
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]      
			//next[j]��Ϊj����Ӧ��nextֵ        
			j = GetNext(j);
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

#endif