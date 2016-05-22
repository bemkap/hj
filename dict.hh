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
protected:
  vector<T*> obs;
  map<string,int> oids;
  int idav;
};

template<typename T>dict<T>::dict():idav(0){}
template<typename T>dict<T>::~dict(){
  for(auto i:obs) delete i;
}
template<typename T>void dict<T>::add(string n,T*o){
  obs.push_back(o);
  auto i=oids.insert(pair<string,int>(n,idav));
  if(i.second) idav++;
}
template<typename T>int dict<T>::iget(string n){
  map<string,int>::iterator i;
  if((i=oids.find(n))!=oids.end()) return (*i).second;
  else return -1;
}
template<typename T>T*dict<T>::get(int n){
  return n>=0&&n<int(obs.size())?obs[n]:nullptr;
}
template<typename T>T*dict<T>::get(string n){
  int i=iget(n);
  return -1<i?obs[i]:nullptr;
}
