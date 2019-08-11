#ifndef __GLOBALVARIABLE__H
#define __GLOBALVARIABLE__H

#include "Singleton.h"
#include <memory>

class Options;

class GlobalVariable : public Singleton<GlobalVariable>
{
public:
	GlobalVariable();
	~GlobalVariable();
private:
	std::shared_ptr<Options> options_;
private:
	void initialize();
public:
	std::shared_ptr<Options> option()
	{ return options_; }
};
#endif//__GLOBALVARIABLE__H
