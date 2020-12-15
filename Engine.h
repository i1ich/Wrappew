#pragma once
#include <map>
#include "Wrapper.h"
template<int Num>
class Engine
{
  std::map<std::string, Wrapper<Num> *> M;
public:
  Engine( void )
  {}
  void register_command(Wrapper<Num> *w, const char *Name)
  {
    std::string S(Name);
    M[S] = w;
  }
  
  
  int execute( const char *Name, Params P)
  {
    std::string S(Name);
    Wrapper<Num> *wrap = M[S];
    wrap->Set(P);
    int tmp = wrap->Call();
    return tmp;
  }
  //~Engine();
};

