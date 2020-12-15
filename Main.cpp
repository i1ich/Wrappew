#include <iostream>
#include "Engine.h"
#include "Wrapper.h"
class Subject
{
public:

static int f3 (int a, int b)
{
  return a+b;
}
private:

};
void main (void)
{
   Subject subj;
   void *f = &Subject::f3;
   Wrapper<2> wrapper(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});
   //Wrapper     w(&subj, &Subject::f3, {{"arg1", 0}, {"arg2", 0}});
   Engine<2> engine;
  
  engine.register_command(&wrapper, "command1");
  
  std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;
}