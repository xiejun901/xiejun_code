#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include<set>
class subject;
class observer {
public:
	virtual void update(subject *) = 0;
	virtual ~observer() = default;
protected:
	observer() = default;
};
class subject {
public:
	virtual ~subject() = default;
	virtual void attach(observer *o) 
	{
		_observers.insert(o);
	}
	virtual void detach(observer *o)
	{
		_observers.erase(o);
	}
	virtual void notify()
	{
		for (auto o : _observers)
		{
			o->update(this);
		}
	}
private:
	std::set<observer*> _observers;
};
#endif
