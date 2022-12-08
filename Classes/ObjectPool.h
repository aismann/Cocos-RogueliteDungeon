#ifndef _OBJECT_POOL_H_
#define _OBJECT_POOL_H_
#include <list>
#include "cocos2d.h"
template <class T>
class ObjectPool
{
public:
	T* getOnce()
	{
		if (_pool.empty())
		{
			//log("pool size is empty return new");
			return new T;
		}
		else
		{
			T* first = _pool.front();
			_pool.pop_front();
			//log("pool size is not empty return front [%d]", first);
			return first;
		}
	}
	void returnObject(T* object)
	{
		_pool.push_back(object);
		//log("pool size [%d] after push_back [%d]", _pool.size(), _pool.back());
	}
	void destroy()
	{
		typename std::list<T*>::iterator it;
		for (it = _pool.begin(); it != _pool.end(); ++it) {
			delete* it;
		}
	}
protected:
	std::list<T*> _pool;
};
#endif // !_OBJECT_POOL_H_

