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
template <int N>
struct Params
{
public:
  std::vector<Argument> Data;
  std::array<std::string, N> Names;
  std::array<int, N> Arr;
  Params(const std::initializer_list<Argument> list)
  {
    Data.insert(Data.end(), list.begin(), list.end());
    for (int i = 0; i < N; i++)
    {
      Arr[i] = Data[i].Data;
      Names[i] = Data[i].Name;
    }
  }
};

