#pragma once

#include<map>
#include<vector>
#include"ob.hh"

template<typename T>class wa {public:
  map<T,vector<ob*>> sub;
  void reg(T,ob*);
  void sign(T);
};

template<typename T>void wa<T>::reg(T k,ob*o){sub[k].push_back(o);}
template<typename T>void wa<T>::sign(T k){auto v=sub.find(k);
  if(v!=sub.end()) for(ob*o:(*v).second) o->app(k);
}
