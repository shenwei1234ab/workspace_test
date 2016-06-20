#ifndef PARENT_H
#define PARENT_H

#include <vector>
class Son;
class Parent
{
public:
	void PushSon(Son )	;
private:
	std::vector<Son *> m_sons;
};

#endif
