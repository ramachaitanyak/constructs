#include <iostream>

using namespace std;

class Singleton {
  public:
    static Singleton& getInstance();
    // Delete copy constructor
    Singleton(Singleton const &) = delete;
    void operator=(Singleton const &) = delete;

  private:
    Singleton() {}
};

Singleton&
Singleton::getInstance() {
  static Singleton s;
  return s;
}

void checkCopy(Singleton& s) {
  return;
}

int main() {
  checkCopy(Singleton::getInstance());

  return 0;
}
