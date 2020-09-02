#include<iostream>

using namespace std;

class S {
  public:
    int a;
    static S* getInstance() {
      if(this_s == nullptr) {
        this_s = new S();
      }
      return this_s;
    } 
  private:
    S() {}
    static S* this_s;
};

S *S::this_s = nullptr;

int main() {

  S *s = S::getInstance();
  s->a = 10;

  S *m(s);

  std::cout<<"ma"<<m->a<<std::endl;
  std::cout<<"m "<<m<<std::endl;


  std::cout<<"sa"<<s->a<<std::endl;
  std::cout<<"s "<<s<<std::endl;

  S *p = S::getInstance();
  std::cout<<"pa"<<p->a<<std::endl;
  std::cout<<"p "<<&p<<std::endl;
  s->a = 30;

  S *r = p;
  std::cout<<"ra"<<r->a<<std::endl;
  std::cout<<"r "<<&r<<std::endl;

  return 0;
}
