#include <iostream>
#include <vector>

using namespace std;

template <class T, class M>
class HashNode {
  public:
    HashNode(T key_, M value_)
      :key(key_), value(value_){}
    T key;
    M value;
};

template <class T, class M>
class HashMap {
  public:
    HashMap() {
      hash_map.resize(100000, 0);
      map_size = 100000;
    }
    void setKey(T key, M value);
    M getVal(T key);

  private:
    size_t hashy(T key);
    std::vector<HashNode<T,M> *> hash_map;
    size_t map_size;
};

template<class T, class M>
size_t HashMap<T, M>::hashy(T key) {

  // This is a template, but hashy an be way better
  size_t s = std::hash<T>{}(key);
  if (s > hash_map.max_size()) {
    return s%map_size;
  } else {
    return s;
  }
}

template<class T, class M>
void HashMap<T,M>::setKey(T key, M value) {
  size_t index = hashy(key);
  HashNode<T,M> *h = new HashNode<T,M>(key,value);
  if(index > map_size) {
    hash_map.resize(index+1, 0);
    map_size = index+1;
  } else {
    hash_map[index] = h;
  }

  return;
}

template<class T, class M>
M HashMap<T,M>::getVal(T key) {
  size_t index = hashy(key);
  HashNode<T,M> *h = hash_map[index];

  return h->value;
}

int main() {

  HashMap<int,int> *h = new HashMap<int,int>();

  h->setKey(1,2);
  std::cout<<h->getVal(1)<<std::endl;


  HashMap<string, int> *s = new HashMap<string, int>();
  s->setKey("a", 40);
  std::cout<<s->getVal("a")<<std::endl;


  return 0;
}
