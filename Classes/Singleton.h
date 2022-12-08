#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include "cocos2d.h"
template <typename T>
class Singleton
{
protected:
	static T* _instance;
public:
	Singleton();
	~Singleton();
	static T* getIntsance();
	static void destroy();
};

template <typename T>
T* Singleton<T>::_instance = nullptr;

template <typename T>
Singleton<T>::Singleton() {}

template <typename T>
Singleton<T>::~Singleton() {}

template <typename T>
T* Singleton<T>::getIntsance()
{
	if (_instance == nullptr)
	{
		_instance = new T;
	}
	return _instance;
}

template <typename T>
void Singleton<T>::destroy()
{
	if (_instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
}
#endif // !_SINGLETON_H_

