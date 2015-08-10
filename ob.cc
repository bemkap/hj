#include"ob.hh"
#include"cm.hh"
#include"en.hh"

ob::ob():spr(NULL){}
void ob::oeadd(evt t,act a){
  ev*e=new ev;
  e->ty=STEP;
  e->stp.a=a;
  evs.push_back(e);
}
void ob::oeadd(evt t,act a,uint n){
  ev*e=new ev;
  e->ty=t;
  switch(t){
  case KBDO: {e->kbd.a=a;e->kbd.k=uchar(n);break;}
  case KBUP: {e->kbd.a=a;e->kbd.k=uchar(n);break;}
  case ALRM: {e->alr.a=a;e->alr.in=e->alr.n=n;break;}
  case COLL: {e->col.a=a;e->col.n=n;break;}
  default  : return;
  }
  evs.push_back(e);
}
void ob::oeadd(evt t,act a,ptbtn b){
  ev*e=new ev;
  e->ty=t;
  e->ptr.a=a;
  e->ptr.b=b;
  evs.push_back(e);
}
IIT ob::oiadd(float x,float y){
  in*i=new in(x,y);IIT r;
  ins.push_back(i);
  r=ins.end();--r;
  return r;
}
void ob::oidel(IIT i){
  (*i)->del=true;
}
void ob::oupd(){
  en&env=eget();
  for(EIT i=evs.begin();i!=evs.end();++i){
    switch((*i)->ty){
    case KBDO: {if(env.kst[(*i)->kbd.k]==PR)
	  for(IIT j=ins.begin();j!=ins.end();++j) (*i)->kbd.a(j);
	break;}
    case KBUP: {if(env.kst[(*i)->kbd.k]==RE)
	  for(IIT j=ins.begin();j!=ins.end();++j) (*i)->kbd.a(j);
	break;}
    case PTDO: {if((env.pst.le==PR&&(*i)->ptr.b==BTN_LE)||
		   (env.pst.ri==PR&&(*i)->ptr.b==BTN_RI))
	  for(IIT j=ins.begin();j!=ins.end();++j) (*i)->ptr.a(j);
	break;}
    case PTUP: {if((env.pst.le==RE&&(*i)->ptr.b==BTN_LE)||
		   (env.pst.ri==RE&&(*i)->ptr.b==BTN_RI))
	  for(IIT j=ins.begin();j!=ins.end();++j) (*i)->ptr.a(j);
	break;}
    case STEP: {for(IIT j=ins.begin();j!=ins.end();++j) (*i)->stp.a(j);break;}
    case COLL: {en&env=eget();
      ob*o=env.eoget((*i)->col.n);
      bool c=false;
      for(IIT j=ins.begin();!c&&j!=ins.end();++j)
	for(IIT k=o->ins.begin();!c&&k!=o->ins.end();++k){
	  poly p1=spr->smget((*j)->x,(*j)->y);
	  poly p2=o->spr->smget((*k)->x,(*k)->y);
	  c=intersect(p1,p2);
	}
      if(c) for(IIT j=ins.begin();j!=ins.end();++j) (*i)->col.a(j);
      break;}
    case ALRM: {if(--(*i)->alr.n<=0)
	for(IIT j=ins.begin();j!=ins.end();++j){
	  (*i)->alr.a(j);
	  (*i)->alr.n=(*i)->alr.in;
	}
	break;}
    }
  }
  for(uint i=0;i<ins.size();++i){
    in*j=ins.front();ins.pop_front();
    if(j->del) delete j;
    else {j->move();ins.push_back(j);}
  }
}
ob::~ob(){
  for(EIT i=evs.begin();i!=evs.end();++i) delete (*i);
  for(IIT i=ins.begin();i!=ins.end();++i) delete (*i);
}
