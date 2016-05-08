#include"cm.hh"
#include"di.hh"
#include"lo.hh"
#include"en.hh"
#include"tl.hh"
#include"ut.hh"

static void deftl0(en&env){tl*tl0=env.tls.get("tl0");
  tl0->tladd(  1,[](in*i){i->dir=60;i->spe=40;i->fr=4;});
  tl0->tladd( 11,[](in*i){i->fr=0;});
  tl0->tladd( 20,[](in*i){i->hsp=4;i->alrn[0]=10;i->alrn[1]=3;});
  tl0->tladd(100,[](in*i){i->alrn[1]=0;i->alrn[2]=1;});
}
void loadtls(){en&env=eget();
  env.tls.add("tl0",new tl);
  deftl0(env);
}
