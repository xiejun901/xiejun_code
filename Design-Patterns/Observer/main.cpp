#include"observer.h"
#include<iostream>
//²âÊÔobserverÄ£Ê½
class A :public observer {
public:
	A(subject *s):_subject(s)
	{
		_subject->attach(this);
	}
	void update(subject *s)
	{
		std::cout << s << " notify class A" << std::endl;
	}
	~A() 
	{
		_subject->detach(this);
	}
private:
	subject *_subject;
};
class C :public observer {
public:
	C(subject *s) :_subject(s)
	{
		_subject->attach(this);
	}
	void update(subject *s)
	{
		std::cout << s << " notify class C" << std::endl;
	}
	~C()
	{
		_subject->detach(this);
	}
private:
	subject *_subject;
};
class B :public subject {
public:
	void signal()
	{
		notify();
	}
};
int main()
{
	B b1;
	B b2;
	A a1(&b1);
	A a2(&b2);
	C c1(&b1);
	C c2(&b2);
	b1.signal();
	b2.signal();

}