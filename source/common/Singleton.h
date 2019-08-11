#ifndef __SINGLETON__H
#define __SINGLETON__H


#ifndef WIN32
#include <mutex>
#else
#include <Windows.h>
#endif

class FakeLocker
{
	public:
		void lock() {}
		void unlock() {}
};

#ifndef WIN32
class RealLocker
{
	private:
		std::mutex mtx;
	public:
		void lock()
		{
			mtx.lock();
		}

		void unlock() 
		{
			mtx.unlock();
		}
};
#else
class RealLocker
{
public:
	RealLocker()
	{
		InitializeCriticalSection(&cs_);
	}
	~RealLocker()
	{
		DeleteCriticalSection(&cs_);
	}

	void lock()
	{
		EnterCriticalSection(&cs_);
	}

	void Unlock()
	{
		LeaveCriticalSection(&cs_);
	}
private:
	CRITICAL_SECTION cs_;
};
      
#endif

template<typename T, typename LOCKER = FakeLocker>
class Singleton
{
	protected:
		Singleton() {}
		~Singleton() {}
	private:
		Singleton(Singleton&);
		Singleton& operator=(const Singleton&);
	private:
		static T* instance_;
		static LOCKER locker_;
	public:
		static T& instance()
		{
			if (!instance_)
			{
				locker_.lock();
				if(!instance_)
				{
					instance_ = new T;
				}
				locker_.unlock();
			}
			return *instance_;
		}

};

template<typename T, typename LOCKER>
T* Singleton<T, LOCKER>::instance_ = 0;

template<typename T, typename LOCKER>
LOCKER Singleton<T, LOCKER>::locker_ ;

#endif//__SINGLETON__H
