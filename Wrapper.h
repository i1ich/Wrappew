#pragma once
#include <functional>
#include <iostream>
#include <tuple>
#include <array>
#include <utility>
#include "Params.h"
template <typename ...Args>
class Wrapper
{
  //Params Param;
  int(*func)(Args...);
  std::array<std::string, sizeof...(Args)> Names;
  std::array<int, sizeof...(Args)> Values;
public:
  template<class T>
  Wrapper(T *f_class, int(*funcptr)(Args...), Params<sizeof...(Args)> Prmtrs):
    func(funcptr)
  {
    Names = Prmtrs.Names;
    Values = Prmtrs.Arr;
  }
  void Set(Params<sizeof...(Args)> P)
  {
    for (int i = 0; i < sizeof...(Args); i++)
      for (int j = 0; j < sizeof...(Args); j++)
        if (P.Names[i] == Names[j])
          Values[j] = P.Arr[i];
  }
  int Call( void )
  {
    //std::vector<int> = {Args};  // args to call
    //std::vector<std::tuple<int>> Args2;
    /*for (int i = 0; i < Param.Data.size(); i++)
    {
      Args.push_back(Param.Data[i].Data);
      Args2.push_back(Param.Data[i].Data);
    }*/
    /*const int a = Num;
    for (int i = 1; i < Param.Data.size(); i++)
    
    auto Tuple = std::make_tuple(Args);
    for (int i = 0; i < a; i++)
    {
      Arr[i] = Args[i];
    }*/
    //auto f = [](int a, double b, std::string c) { std::cout<<a<<" "<<b<<" "<<c<< std::endl; };
    int tmp = std::apply(*func, Values);
    return tmp;
  }
  //~Wrapper();
};

