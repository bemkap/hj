#include"di.hh"

template<class T>dict<T>::dict():idav(0){};
template<class T>dict<T>::~dict(){
  for(auto i:obs) delete i;
}
template<class T>void dict<T>::add(string n,T*o){
  obs.push_back(o);
  auto i=oids.insert(pair<string,T*>(n,idav));
  if(i.second) idav++;
}
template<class T>int dict<T>::iget(string n){
  map<string,int>::iterator i;
  if((i=oids.find(n))!=oids.end()) return (*i).second;
  else return -1;
}
template<class T>T*dict<T>::get(int n){
  return n>=0&&n<obs.size()?obs[n]:nullptr;
}
template<class T>T*dict<T>::get(string n){
  int i=iget(n);
  return -1<i?obs[i]:nullptr;
}
