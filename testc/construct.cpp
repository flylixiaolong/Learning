#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class S{
public:
    S();
    S(int i);
    S(const S &s):name(s.name){
        cout<<"in S copy cons"<<endl;
    }
    void show(){
        cout<<"hello,"<<name<<endl;
    }
    S &operator=(const S &s1);
private:
    string name="lixiaolong";
};
S::S()=default;
S::S(int i){cout<<"in S cons"<<endl;}
S &S::operator=(const S& s1) // 赋值运算符
{
    cout << "in S copy" << endl ;
    this->name = s1.name ;
    return *this;
}
class D{
public:
    D(string name,S s):cname(name),refms(s),member(s)
    {
        cout<<"ee"<<endl;
    }
    void show(){
        cout<<"hello,"<<cname<<endl;
    }
private:
    const string cname;
    S member=S(1);
    S &refms;
};

int main(){
    S s(1);
    s.show();
    D d("google",s);
    d.show();
    return 0;
}
