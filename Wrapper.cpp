#include "Wrapper.h"



//template<class T>
//Wrapper::Wrapper(T * f_class/*, /*void * func,*/ /*Params P*/)
//{
//  //Param = P;
//  /*Func = func;*/
//}

/*void Wrapper::Set(Params P)
{
  for (int i = 0; i < P.Data.size(); i++)
    for (int j = 0; j < Param.Data.size(); j++)
      if (P.Data[i].Name == Param.Data[j].Name)
        Param.Data[j].Data = P.Data[i].Data;
}*/

template <typename R, typename ... Types> constexpr size_t getArgumentCount( R(*f)(Types ...))
{
   return sizeof...(Types);
}


