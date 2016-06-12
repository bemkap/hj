#include"env.hh"
#include"room.hh"

room::room(const string&file,lua_State*L){
  viewportx=viewporty=viewportw=viewporth=0;
  if(0<luaL_dofile(L,file.c_str())){
    cout<<"ERROR::LUA::ROOM::"<<file<<endl;
  }else{
    int n=file.find_last_of("/\\")+1;
    int m=file.find_last_of(".");    
    if(lua_istable(L,-1)){
      name=file.substr(n,m-n);
      lua_pushnil(L);
      while(lua_next(L,-2)!=0){
	string s=lua_tostring(L,-2);
	if(s=="width") width=lua_tonumber(L,-1);
	else if(s=="height") height=lua_tonumber(L,-1);
	else if(s=="viewportw") viewportw=lua_tonumber(L,-1);
	else if(s=="viewporth") viewporth=lua_tonumber(L,-1);
	else if(s=="legend"){
	  lua_pushnil(L);
	  while(lua_next(L,-2)!=0){
	    legend.push_back(lua_tostring(L,-1));
	    lua_pop(L,1);
	  }
	}else if(s=="tiles"){
	  lua_pushnil(L);
	  while(lua_next(L,-2)!=0){
	    tiles.push_back(lua_tonumber(L,-1));
	    lua_pop(L,1);
	  }
	}else if(s=="objects"){
	  lua_pushnil(L);
	  while(lua_next(L,-2)!=0){
	    float x=lua_tonumber(L,-1);lua_pop(L,1);lua_next(L,-2);
	    float y=lua_tonumber(L,-1);lua_pop(L,1);lua_next(L,-2);
	    string s=lua_tostring(L,-1);lua_pop(L,1);
	    add(s,x,y);
	  }
	}
	lua_pop(L,1);
      }
      if(viewportw==0) viewportw=width;
      if(viewporth==0) viewporth=height;
    }
  }
}
void room::add(string o,float x,float y){
  objects.push_back(tuple<string,float,float>(o,x,y));
}
void room::move(int xo,int yo){viewportx+=xo;viewporty+=yo;}
void room::scale(float xs,float ys){viewportw*=xs;viewporth*=ys;}
void room::init(){
  env&env=env::envget();
  for(auto t:objects){
    object*o=env.objects.get(get<0>(t));
    if(o) o->instancecreate(get<1>(t),get<2>(t));
  }
}
void room::display(GLuint program){
  env&env=env::envget();
  for(int j=0;j<viewporth/32;++j)
    for(int i=0;i<viewportw/32;++i){
      int k=tiles[j*20+i];
      if(k>0){
	csprite*s=env.graphicmng.sprites.get(legend[k-1]);
	if(s) s->display(program,i*32,j*32);
      }
    }
}
void room::reshape(int w,int h){scale(w/viewportw,h/viewporth);}
