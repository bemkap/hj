#include"cm.hh"
#include"lo.hh"
#include"en.hh"
#include"ob.hh"
#include"ut.hh"

static void defworl(en&env){
  ob*worl=OGET(env,"worl");
  worl->oeadd(KBDO,'q',[](in*i){exit(0);});
}
static void defship(en&env){
  ob*ship=OGET(env,"ship");
  ship->spr=SGET(env,"sp0");
  ship->oeadd(STEP,[](in*i){i->x=eget().pst.x;i->y=eget().pst.y;});
  ship->oeadd(COLL,env.eoiget("bull"),[](in*i){i->st=DEAD;});
  ship->oeadd(COLL,env.eoiget("enem"),[](in*i){i->st=DEAD;});
}
static void defbull(en&env){
  ob*bull=OGET(env,"bull");
  bull->spr=SGET(env,"sp1");
  bull->oeadd(STEP,[](in*i){
      if(i->x>eget().w||i->x<0||i->y>eget().h||i->y<0)
	i->st=DEAD;
    });
}
static void defenem(en&env){
  ob*enem=OGET(env,"enem");
  enem->spr=SGET(env,"sp1");
  enem->oeadd(ALRM,0,[](in*i){i->hsp*=-1;i->alrn[0]=40;});
  enem->oeadd(ALRM,1,[](in*i){
      en&env=eget();
      in*ship0=(*env.eoget(env.eoiget("ship")))[0];
      double nx=i->x+arb(100)-50,ny=i->y+arb(100)-50;
      REPEAT(3){
	in*bull0=env.eoget(env.eoiget("bull"))->oiadd(nx,ny);
	if(ship0) bull0->dir=radtodeg(point_direction(nx,ny,ship0->x,ship0->y));
	bull0->spe=arb(8)+4;
      }
      i->alrn[1]=3;
    });
  enem->oeadd(ALRM,2,[](in*i){});
}
void loadobs(){
  en&env=eget();
  string obs[]={"worl","ship","bull","enem"};
  for(auto s:obs) env.eoadd(s,new ob);
  defworl(env);
  defship(env);
  defbull(env);
  defenem(env);
}
