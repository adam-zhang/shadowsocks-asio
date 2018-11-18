#ifndef __PROPERITES__H
#define __PROPERITES__H

#define PROPERTY(type, name, method) \
	private: \
		type name##_; \
	public: \
		const type& name()const \
		{ return name##_; } \
		void method(const type& value) \
		{ name##_ = value; }

#endif//__PROPERITES__H
