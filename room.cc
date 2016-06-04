#include"env.hh"
#include"room.hh"

room::room(const char*file,lua_State*L){
  if(0<luaL_dofile(L,file)){
    cout<<"lua error file "<<file<<endl;
  }else{
    if(lua_istable(L,-1)){
      vector<string> legend;
      vector<tuple<int,double,double>> temp;
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string s=lua_tostring(L,-2);
	if(s=="name") name=lua_tostring(L,-1);
	else if(s=="width") width=viewportw=lua_tonumber(L,-1);
	else if(s=="height") height=viewporth=lua_tonumber(L,-1);
	else if(s=="legend"){
	  lua_pushnil(L);
	  while(lua_next(L,-2)!=0){
	    legend.push_back(lua_tostring(L,-1));
	    lua_pop(L,1);
	  }
	}else if(s=="room"){
	  lua_pushnil(L);
	  for(int i=0;lua_next(L,-2)!=0;i++){
	    lua_pushnil(L);
	    for(int j=0;lua_next(L,-2)!=0;j++){
	      temp.push_back(tuple<int,double,double>(lua_tonumber(L,-1),i*32,j*32));
	      lua_pop(L,1);
	    }
	    lua_pop(L,1);
	  }
	}
	lua_pop(L,1);
      }
      for(auto&i:temp)
	add(legend[get<0>(i)%legend.size()],get<1>(i),get<2>(i));
      viewportx=viewporty=0;
    }
  }
}
void room::add(string o,double x,double y){
  objects.push_back(tuple<string,double,double>(o,x,y));
}
void room::move(int xo,int yo){viewportx+=xo;viewporty+=yo;}
void room::scale(double xs,double ys){viewportw*=xs;viewporth*=ys;}
void room::display(){
  env&env=envget();
  for(auto t:objects){
    object*o=env.objects.get(get<0>(t));
    if(o) o->instancecreate(get<1>(t),get<2>(t));
  }
}
void room::reshape(int w,int h){scale(w/viewportw,h/viewporth);}
