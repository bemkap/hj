#include<iostream>
#include"en.hh"
#include"lo.hh"
#include"ro.hh"

static void defro0(en&env){ro*ro0=env.ros.get("ro0");
  ro0->add("bull",10,10);
}
void loadros(){en&env=eget();
  env.ros.add("ro0",new ro(500,500));
  defro0(env);
}
