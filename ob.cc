#include<algorithm>
#include"cm.hh"
#include"en.hh"
#include"di.hh"
#include"ob.hh"

ob::ob(sp*s):spr(s),tline(nullptr){}
ob::ob():ob(nullptr){}
ob::~ob(){
  for(auto i:evs) delete i;
  for(auto i:ins) delete i;
}
void ob::oidel(in*i){i->st=DEAD;}
void ob::oeadd(evt t,act a){ev*e=new ev;
  switch(t){
  case CRTE: {e->crt={t,a};break;}
  case STEP: {e->stp={t,a};break;}
  case DEST: {e->stp={t,a};break;}
  default  : {delete e;return;}
  }
  evs.push_back(e);
}
void ob::oeadd(evt t,uint n,act a){ev*e=new ev;
  switch(t){
  case KBDO: {e->kbd={t,a,uchar(n)};break;}
  case KBUP: {e->kbd={t,a,uchar(n)};break;}
  case COLL: {e->col={t,a,uint(n)};break;}
  case ALRM: {e->alr={t,a,n};break;}
  default  : {delete e;return;}
  }
  evs.push_back(e);
}
void ob::oeadd(evt t,ptbtn b,act a){ev*e=new ev;
  e->ptr={t,a,b};
  evs.push_back(e);
}
in*ob::oiadd(double x,double y){in*i=new in(x,y);
  ins.push_back(i);
  return i;
}
in*ob::operator[](uint i){
  try{return ins.at(i);}
  catch(out_of_range e){return nullptr;}
}
void ob::oupd(){en&env=eget();bool df=false;act b;
  for(auto i:evs){
    switch(i->ty){
    case CRTE: {for(auto&j:ins)
	  if(j->st==BORN){i->crt.a(j);j->st=LIVE;}
  	break;}
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
    case COLL: {ob*o=env.obs.get(i->col.n);
	if(o)
	  for(auto&j:ins)
	    for(auto&k:o->ins){
	      poly p1=spr->smget(j->x,j->y,j->xsc,j->ysc);
	      poly p2=o->spr->smget(k->x,k->y,k->xsc,k->ysc);
	      if(intersect(p1,p2)) i->col.a(j);
	    }
	break;}
    case ALRM: {for(auto&j:ins)
	  if(j->alrn[i->alr.n%11]>0&&--j->alrn[i->alr.n%11]<=0) i->alr.a(j);
	break;}
    case DEST: {df=true;b=i->des.a;break;}
    }
  }
  if(tline&&tline->st)
    for(auto&i:ins)
      if(++i->tlcurt>=tline->nds[i->tlcurn].step){
	tline->nds[i->tlcurn].a(i);
	if(i->tlcurn<tline->nds.size()-1) ++i->tlcurn;
	else tline->st=false;
      }
  for(auto i=ins.begin();i!=ins.end();){
    if((*i)->st==DEAD){if(df) b(*i);i=ins.erase(i);}
    else{(*i)->move();i++;}
  }
}
void ob::disp(double x,double y,double xsc,double ysc){
  if(spr) spr->disp(x,y,xsc,ysc);
}
