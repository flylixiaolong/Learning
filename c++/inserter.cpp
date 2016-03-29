#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;

int main()
{
   vector<int> vint{1,2,3,4,5};
   vint.push_back(7);
   auto insert=inserter(vint,vint.begin()+2);
   fill_n(insert,10,8);
   insert=inserter(vint,vint.begin()+2);
   fill_n(insert,10,6);
   for_each(vint.begin(),vint.end(),[](int i){std::cout<<i<<' ';});
   std::cout<<std::endl;
   list<float> lfloat;
   copy(vint.begin(),vint.end(),front_inserter(lfloat));
   for_each(lfloat.begin(),lfloat.end(),[](float i){std::cout<<i<<' ';});
   std::cout<<std::endl;
   list<int> lint;
   unique_copy(vint.begin(),vint.end(),back_inserter(lint));
   for_each(lint.begin(),lint.end(),[](int i){std::cout<<i<<' ';});
   std::cout<<std::endl;
   list<int> lint2;
   auto iter=front_inserter(lint2);
   iter++;
   iter++;
   iter++;
   iter++;
   unique_copy(lint.begin(),lint.end(),*iter);
   for_each(lint2.begin(),lint2.end(),[](int i){std::cout<<i<<' ';});
   std::cout<<std::endl;
   return 0;
}
