#pragma once
#include <initializer_list>
#include <string>
#include <vector>
#include "List.h"
class Argument
{
public:
  std::string Name;
  int Data;
  Argument(const char * name, int parameter);
  ~Argument();

private:

};

struct Params
{
public:
  std::vector<Argument> Data;

  Params(const std::initializer_list<Argument> list);
  ~Params();
};

