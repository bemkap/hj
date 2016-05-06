#pragma once

#include<vector>
#include<map>
using namespace std;

template<class T>class dict{public:
  dict();~dict();
  vector<T*> obs;
  map<string,int> oids;
  int idav;
  void add(string,T*);
  int  iget(string);
  T*   get(int);
  T*   get(string);
};
