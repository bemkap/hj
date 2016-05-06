#include"cm.hh"
#include"lo.hh"
#include"en.hh"
#include"ob.hh"
#include"ut.hh"

static void defworl(en&env){
  ob*worl=env.obs.get("worl");
  worl->oeadd(KBDO,'q',[](in*i){exit(0);});
}
static void defship(en&env){
  ob*ship=env.obs.get("ship");
  ship->spr=env.sps.get("sp0");
  ship->oeadd(STEP,[](in*i){i->x=eget().pst.x;i->y=eget().pst.y;});
  ship->oeadd(COLL,env.obs.iget("bull"),[](in*i){i->st=DEAD;});
  ship->oeadd(COLL,env.obs.iget("enem"),[](in*i){i->st=DEAD;});
}
static void defbull(en&env){
  ob*bull=env.obs.get("bull");
  bull->spr=env.sps.get("sp1");
  bull->oeadd(STEP,[](in*i){
      if(i->x>eget().w||i->x<0||i->y>eget().h||i->y<0)
	i->st=DEAD;
    });
}
static void defenem(en&env){
  ob*enem=env.obs.get("enem");
  enem->spr=env.sps.get("sp1");
  enem->oeadd(ALRM,0,[](in*i){i->hsp*=-1;i->alrn[0]=40;});
  enem->oeadd(ALRM,1,[](in*i){
      en&env=eget();
      in*ship0=(*env.obs.get("ship"))[0];
      double nx=i->x+arb(100)-50,ny=i->y+arb(100)-50;
      REPEAT(3){
	in*bull0=env.obs.get("bull")->oiadd(nx,ny);
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
  for(auto s:obs) env.obs.add(s,new ob);
  defworl(env);
  defship(env);
  defbull(env);
  defenem(env);
}
