#include "GlobalVariable.h"
#include "Options.h"

using namespace std;

GlobalVariable::GlobalVariable()
{
	initialize();
}

GlobalVariable::~GlobalVariable()
{
}

void GlobalVariable::initialize()
{
	options_ = make_shared<Options>();
}
