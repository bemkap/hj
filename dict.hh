#pragma once

#include<iostream>
#include<map>
#include<vector>
using namespace std;
  
template<typename T>class dict{
public:
  dict();~dict();
  void add(string,T*);
  int  iget(string);
  T*   get(int);
  T*   get(string);
  vector<T*> entries;
  map<string,int> ids;
  int available;
};

template<typename T>dict<T>::dict():available(0){}
template<typename T>dict<T>::~dict(){
  for(auto i:entries) delete i;
}
template<typename T>void dict<T>::add(string n,T*o){
  entries.push_back(o);
  auto i=ids.insert(pair<string,int>(n,available));
  if(i.second) available++;
}
template<typename T>int dict<T>::iget(string n){
  map<string,int>::iterator i;
  if((i=ids.find(n))!=ids.end()) return (*i).second;
  else return -1;
}
template<typename T>T*dict<T>::get(int n){
  return n>=0&&n<int(entries.size())?entries[n]:nullptr;
}
template<typename T>T*dict<T>::get(string n){
  return get(iget(n));
}
