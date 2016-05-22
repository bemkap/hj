#pragma once

#include<map>
#include<vector>
#include"object.hh"

template<typename T>class watcher {
public:
  map<T,vector<ob*>> subjects;
  void watch(T,ob*);
  void signal(T);
};

template<typename T>void watcher<T>::watch(T k,ob*o){sub[k].push_back(o);}
template<typename T>void watcher<T>::signal(T k){auto v=sub.find(k);
  if(v!=sub.end()) for(ob*o:(*v).second) o->app(k);
}
