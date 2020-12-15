#include "Params.h"

Argument::Argument(const char * name, const int argument)
{
  Name = name;
  Data = argument;
}
Argument::~Argument()
{
}

Params::Params(const std::initializer_list<Argument> list)
{
  Data.insert(Data.end(), list.begin(), list.end());
}


Params::~Params()
{
}
