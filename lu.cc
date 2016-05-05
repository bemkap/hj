#include"lu.hh"
#include<vector>
#include<boost/filesystem.hpp>
using namespace boost::filesystem;

lua::lua():st(luaL_newstate()){}
lua::~lua(){lua_close(st);}
void oplib(lua_State*s){luaL_openlibs(s);}
void exall(lua_State*s,const string&d){
  path p(d);
  vector<path> v;
  copy(directory_iterator(p),directory_iterator(),back_inserter(v));
  for(vector<path>::const_iterator i(v.begin());i!=v.end();++i)
    luaL_dofile(s,i->c_str());
}
