#include"cm.hh"
#include"lo.hh"
#include"en.hh"
#include"ob.hh"
#include"ut.hh"
#include<lua5.2/lua.hpp>
#include<iostream>
using namespace std;
/*
static void defworl(en&env){ob*worl=env.obs.get("worl");
  worl->oeadd(KBDO,kb_q,[](in*i){eget().quit=true;});
}
static void defship(en&env){ob*ship=env.obs.get("ship");
  ship->spr=env.sps.get("sp0");
  ship->oeadd(COLL,env.obs.iget("bull"),[](in*i){instance_destroy(i);});
  ship->oeadd(COLL,env.obs.iget("enem"),[](in*i){instance_destroy(i);});
  ship->oeadd(KBDO,kb_left,[](in*i){i->x-=5-2*(eget().kst[kb_lshf]==PR);});
  ship->oeadd(KBDO,kb_right,[](in*i){i->x+=5-2*(eget().kst[kb_lshf]==PR);});
  ship->oeadd(KBDO,kb_down,[](in*i){i->y-=5-2*(eget().kst[kb_lshf]==PR);});
  ship->oeadd(KBDO,kb_up,[](in*i){i->y+=5-2*(eget().kst[kb_lshf]==PR);});
}
static void defbull(en&env){ob*bull=env.obs.get("bull");
  bull->spr=env.sps.get("sp1");
  bull->oeadd(STEP,[](in*i){
      if(i->x>eget().curo->vpw||i->x<0||i->y>eget().curo->vph||i->y<0)
	instance_destroy(i);
    });
}
static void defbull1(en&env){ob*bull1=env.obs.get("bull1");
  bull1->spr=env.sps.get("sp1");
  bull1->oeadd(ALRM,0,[](in*i){
      instance_destroy(i);
      in*ship0=(*eget().obs.get("ship"))[0];
      REPEAT(30){
	in*bull1i=eget().obs.get("bull")->oiadd(i->x-25+arb(50),
						i->y-25+arb(50));
	if(ship0) bull1i->dir=point_direction(i->x,i->y,ship0->x,ship0->y);
	bull1i->spe=arb(4)+8;
      }
    });
  bull1->oeadd(STEP,[](in*i){i->dir+=2;});
}  
static void defenem(en&env){ob*enem=env.obs.get("enem");
  enem->spr=env.sps.get("sp1");
  enem->oeadd(ALRM,0,[](in*i){i->hsp*=-1;i->alrn[0]=40;});
  enem->oeadd(ALRM,1,[](in*i){en&env=eget();
      in*ship0=(*env.obs.get("ship"))[0];
      double nx=i->x+arb(100)-50,ny=i->y+arb(100)-50;
      REPEAT(3){
	in*bull0=env.obs.get("bull")->oiadd(nx,ny);
	if(ship0) bull0->dir=point_direction(nx,ny,ship0->x,ship0->y);
	bull0->spe=arb(8)+4;
      }
      i->alrn[1]=3;
    });
  enem->oeadd(ALRM,2,[](in*i){
      in*bull1=instance_create(eget(),"bull1",i->x,i->y);
      bull1->alrn[0]=30;
      bull1->dir=180+arb(180);
      bull1->spe=4;
      i->alrn[2]=30;
    });
    }*/
void loadobs(){/*en&env=eget();
  string obs[]={"worl","ship","bull","bull1","enem"};
  for(auto s:obs) env.obs.add(s,new ob);
  defworl(env);
  defship(env);
  defbull(env);
  defbull1(env);
  defenem(env);*/
  lua_State*L=luaL_newstate();
  static const luaL_Reg lualibs[] =
    {
      { "base", luaopen_base },
      { "io", luaopen_io },
      { NULL, NULL}
    };
  const luaL_Reg *lib = lualibs;
  for(; lib->func != NULL; lib++)
    {
      lib->func(L);
      lua_settop(L, 0);
    }
  luaL_dofile(L,"obs/ship.lua");
  if(LUA_TTABLE==lua_type(L,lua_gettop(L))){
    lua_pushnil(L);
    while(lua_next(L,-2)!=0){
      string s=lua_tostring(L,-2);
      if(s=="spr"){
	cout<<lua_tostring(L,-2)<<"="<<lua_tostring(L,-1)<<endl;
      }else if(s=="coll"){
	lua_pushnil(L);
	while(lua_next(L,-2)!=0){
	  cout<<lua_typename(L,lua_type(L,-3))<<endl;
	  lua_pop(L,1);
	}
      }else if(s=="kbdo"){
      }
      lua_pop(L,1);
    }
  }
  lua_close(L);
}
