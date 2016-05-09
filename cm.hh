#pragma once

const int    FPS=50;
const double PIE=3.141592653;

typedef unsigned char uchar;
typedef unsigned int uint;

enum kb_code {
  kb_tab  =   9,
  kb_enter=  13,
  kb_esc  =  27,
  kb_space=  32,
  kb_comma=  44,
  kb_dot  =  46,
  kb_a    =  97,
  kb_b    =  98,
  kb_c    =  99,
  kb_d    = 100,
  kb_e    = 101,
  kb_f    = 102,
  kb_g    = 103,
  kb_h    = 104,
  kb_i    = 105,
  kb_j    = 106,
  kb_k    = 107,
  kb_l    = 108,
  kb_m    = 109,
  kb_n    = 110,
  kb_o    = 111,
  kb_p    = 112,
  kb_q    = 113,
  kb_r    = 114,
  kb_s    = 115,
  kb_t    = 116,
  kb_u    = 117,
  kb_v    = 118,
  kb_w    = 119,
  kb_x    = 120,
  kb_y    = 121,
  kb_z    = 122,
  kb_del  = 127,
  kb_left = 227,
  kb_right= 229,
  kb_up   = 228,
  kb_down = 230,
  kb_f1   = 128,
  kb_f2   = 129,
  kb_f3   = 130,
  kb_f4   = 131,
  kb_f5   = 132,
  kb_f6   = 133,
  kb_f7   = 134,
  kb_f8   = 135,
  kb_f9   = 136,
  kb_f10  = 137,
  kb_f11  = 138,
  kb_f12  = 139,
  kb_lshf = 239,
  kb_rshf = 240,
  kb_lctrl= 241,
  kb_rctrl= 242,
  kb_alt  = 243
};
  
#define REPEAT(n) for(int _i=0;_i<(n);++_i)
