#pragma once
#include <map>
#include "Wrapper.h"
template <typename ...Args>
class Engine
{
  std::map<std::string, Wrapper<Args...> *> M;
public:
  Engine( void )
  {}
  void register_command(Wrapper<Args...> *w, const char *Name)
  {
    std::string S(Name);
    M[S] = w;
  }
  
  
  int execute( const char *Name, Params<sizeof...(Args)> P)
  {
    std::string S(Name);
    Wrapper<Args...> *wrap = M[S];
    wrap->Set(P);
    int tmp = wrap->Call();
    return tmp;
  }
  //~Engine();
};

