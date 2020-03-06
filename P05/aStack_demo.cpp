//
// Tomás Oliveira e Silva, AED, October 2014, September 2015
//
// matched-parenthesis verification
//

#include <iostream>
#include "aStack.h"

using std::cout;
using std::cerr;
using std::endl;

int check_parenthesis(const char *s)
{
   aStack<int> stk = aStack<int>(10 + (int)strlen(s));

  for(int i=0; i<(int)strlen(s); i++){
    if( s[i] == '('){
      stk.push(i);
    }
    else if (s[i] == ')'){
      if(stk.is_empty()) {
        cout << "     unmatched ) at position " << i << endl;
        return -1;
      }
      cout << "     ( at position "<<stk.pop()<<" and ) at position "<<i<<endl;
    }
  }

  if(stk.size() > 0){
    for(int i=stk.size(); i>0; i--){
    cout << "     unmatched ( at position " << stk.pop() << endl;
    return -1;
    }
  }



  return !stk.is_empty();
  // put your code here (20 lines of code should be enough)
}

int main(int argc,char **argv)
{
  if(argc == 1)
  {
    cerr << "usage: " << argv[0] << " [arguments...]" << endl;
    cerr << "example: " << argv[0] << " 'abc(def)ghi' 'x)(y'" << endl;
    return 1;
  }
  for(int i = 1;i < argc;i++)
  {
    cout << argv[i] << endl;
    if(check_parenthesis(argv[i]) == 0)
      cout << "     good" << endl << endl;
    else
      cout << "     bad" << endl << endl;
  }
  return 0;
}
