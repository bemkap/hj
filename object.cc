#include<algorithm>
#include"common.hh"
#include"env.hh"
#include"dict.hh"
#include"object.hh"

ob::ob(sp*s):spr(s),tline(nullptr){}
ob::ob():ob(nullptr){}
ob::~ob(){for(auto i:ins) delete i;}
void ob::app(uchar k){auto a=kbh.find(k);
  if(a!=kbh.end()) for(auto i:ins) ((*a).second)(i);
}
void ob::app(ptbtn b){auto a=pth.find(b);
  if(a!=pth.end()) for(auto i:ins) ((*a).second)(i);
}
void ob::app(uint n){auto a=coh.find(n);
  if(a!=coh.end()) for(auto i:ins) ((*a).second)(i);
}
void ob::oidel(in*i){
  if(dest) (*dest)(i);
  i->st=DEAD;
}
in*ob::oiadd(double x,double y){in*i=new in(x,y);
  if(crte) (*crte)(i);
  ins.push_back(i);
  return i;
}
in*ob::operator[](uint i){
  try{return ins.at(i);}
  catch(out_of_range e){return nullptr;}
}
void ob::oupd(){
  if(step) for(in*i:ins) (*crte)(i);
  for(int i=0;i<11;++i)
    if(alrm[i])
      for(in*j:ins)
	if(j->alrn[i]>0&&--j->alrn[i]<=0) (*alrm[i])(j);
  /*
  if(tline&&tline->st)
    for(auto&i:ins)
      if(++i->tlcurt>=tline->nds[i->tlcurn].step){
	tline->nds[i->tlcurn].a(i);
	if(i->tlcurn<tline->nds.size()-1) ++i->tlcurn;
	else tline->st=false;
      }
  */
  for(in*i:ins) i->move();
  remove_if(ins.begin(),ins.end(),[](in*i){return i->st==DEAD;});
}
void ob::disp(double x,double y,double xsc,double ysc){
  if(spr) spr->disp(x,y,xsc,ysc);
}
