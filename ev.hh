#ifndef EV_HH
#define EV_HH
#include<string>
#include<vector>
#include"cm.hh"
#include"in.hh"
using namespace std;

typedef enum { KBDO,KBUP,PTDO,PTUP,STEP,COLL,ALRM } evt;
typedef enum { BTN_LE,BTN_RI } ptbtn;
typedef void (*act)(IIT);

typedef struct { evt ty;act a;uchar k;   } ekbd;
typedef struct { evt ty;act a;ptbtn b;   } eptr;
typedef struct { evt ty;act a;           } estp;
typedef struct { evt ty;act a;obid n ;   } ecol;
typedef struct { evt ty;act a;uint in,n; } ealr;

typedef union { evt ty;ekbd kbd;eptr ptr;estp stp;ecol col;ealr alr; } ev;

typedef vector<ev*>::iterator EIT;

#endif
