#ifndef EV_HH
#define EV_HH
#include<vector>
#include<stack>
#include"cm.hh"
#include"in.hh"
using namespace std;

enum evt { KBDO,KBUP,PTDO,PTUP,STEP,COLL,ALRM };
enum ptbtn { BTN_LE,BTN_RI };
typedef void (*act)(in*);

struct ekbd { evt ty;act a;uchar k; };
struct eptr { evt ty;act a;ptbtn b; };
struct estp { evt ty;act a;         };
struct ecol { evt ty;act a;obid n;  };
struct ealr { evt ty;act a;uint n;  };

union ev { evt ty;ekbd kbd;eptr ptr;estp stp;ecol col;ealr alr; };

#endif
