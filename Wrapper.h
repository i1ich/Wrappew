#pragma once
#include <functional>
#include <iostream>
#include <tuple>
#include <array>
#include <utility>
#include "Params.h"
template<int Num>
class Wrapper
{
  Params Param;
  int(*Func)(int, int);

  std::array<int, Num> Arr;
public:
  template<class T>
  Wrapper(T *f_class, int (*fcnPtr)(int, int), const Params P): Param(P)
  {
    Func = fcnPtr;
  }
  void Set(Params P)
  {
    for (int i = 0; i < P.Data.size(); i++)
      for (int j = 0; j < Param.Data.size(); j++)
        if (P.Data[i].Name == Param.Data[j].Name)
          Param.Data[j].Data = P.Data[i].Data;
  }
  int Call( void )
  {
    std::vector<int> Args;  // args to call
    std::vector<std::tuple<int>> Args2;
    for (int i = 0; i < Param.Data.size(); i++)
    {
      Args.push_back(Param.Data[i].Data);
      Args2.push_back(Param.Data[i].Data);
    }
    const int a = Num;
    for (int i = 1; i < Param.Data.size(); i++)
    
    auto Tuple = std::make_tuple(Args);
    for (int i = 0; i < a; i++)
    {
      Arr[i] = Args[i];
    }
    //auto f = [](int a, double b, std::string c) { std::cout<<a<<" "<<b<<" "<<c<< std::endl; };
    int tmp = std::apply(*Func, Arr);
    return tmp;
  }
  //~Wrapper();
};

