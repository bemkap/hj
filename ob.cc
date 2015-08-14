#include"ob.hh"
#include"cm.hh"
#include"en.hh"

ob::ob():spr(nullptr),tl(nullptr){}
ob::~ob(){
  for(auto i:evs) delete i;
  for(auto i:ins) delete i;
}
void ob::oeadd(evt t,act a){
  ev*e=new ev;
  e->stp={STEP,a};
  evs.push_back(e);
}
void ob::oeadd(evt t,act a,uint n){
  ev*e=new ev;
  switch(t){
  case KBDO: {e->kbd={t,a,uchar(n)};break;}
  case KBUP: {e->kbd={t,a,uchar(n)};break;}
  case ALRM: {e->alr={t,a,n,n};break;}
  case COLL: {e->col={t,a,obid(n)};break;}
  default  : return;
  }
  evs.push_back(e);
}
void ob::oeadd(evt t,act a,ptbtn b){
  ev*e=new ev;
  e->ptr={t,a,b};
  evs.push_back(e);
}
in*ob::oiadd(float x,float y){
  in*i=new in(x,y);
  ins.push_back(i);
  return i;
}
void ob::oidel(in*i){
  i->del=true;
}
void ob::oupd(){
  en&env=eget();
  for(auto i:evs){
    switch(i->ty){
    case KBDO: {if(env.kst[i->kbd.k]==PR)
	  for(auto&j:ins) i->kbd.a(j);
	break;}
    case KBUP: {if(env.kst[i->kbd.k]==RE)
	  for(auto&j:ins) i->kbd.a(j);
	break;}
    case PTDO: {if((env.pst.le==PR&&i->ptr.b==BTN_LE)||
		   (env.pst.ri==PR&&i->ptr.b==BTN_RI))
	  for(auto&j:ins) i->ptr.a(j);
	break;}
    case PTUP: {if((env.pst.le==RE&&i->ptr.b==BTN_LE)||
		   (env.pst.ri==RE&&i->ptr.b==BTN_RI))
	  for(auto&j:ins) i->ptr.a(j);
	break;}
    case STEP: {for(auto&j:ins) i->stp.a(j);break;}
    case COLL: {en&env=eget();
      ob*o=env.eoget(i->col.n);
      bool c=false;
      for(auto&j:ins)
	for(auto&k:o->ins){
	  poly p1=spr->smget(j->x,j->y,j->xsc,j->ysc);
	  poly p2=o->spr->smget(k->x,k->y,k->xsc,k->ysc);
	  c=intersect(p1,p2);
	}
      if(c) for(auto&j:ins) i->col.a(j);
      break;}
    case ALRM: {if(--i->alr.n<=0)
	  for(auto&j:ins){
	    i->alr.a(j);
	    i->alr.n=i->alr.in;
	  }
	break;}
    }
  }
  if(tl) for(auto&i:ins)
	   if(tl->st&&++i->tlcurt>=tl->nds[i->tlcurn].step){
	     tl->nds[i->tlcurn].a(i);
	     if(i->tlcurn<tl->nds.size()) ++i->tlcurn;
	   }
  for(uint i=0;i<ins.size();++i){
    in*j=ins.front();ins.pop_front();
    if(j->del) delete j;
    else {j->move();ins.push_back(j);}
  }
}
