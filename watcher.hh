#pragma once

#include<map>
#include<vector>
#include"object.hh"

template<typename T>class watcher {
public:
  map<T,vector<object*>> subjects;
  void watch(T,object*);
  void signal(T);
};

template<typename T>void watcher<T>::watch(T k,object*o){
  subjects[k].push_back(o);
}
template<typename T>void watcher<T>::signal(T k){
  auto v=subjects.find(k);
  if(v!=subjects.end()) for(object*o:(*v).second) o->apply(k);
}
