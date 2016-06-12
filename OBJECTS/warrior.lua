local kb=require"OBJECTS/common"
local warrior={
   sprite="old",
   crte={act=function()imagespeed=0.15;end},
   kbdo={
      {key=kb.left,
       act=function()hspeed=-2;xscale=-1;end},
      {key=kb.up,
       act=function()vspeed=2;end},
      {key=kb.right,
       act=function()hspeed=2;xscale=1;end},
      {key=kb.down,
       act=function()vspeed=-2;end}},
   kbup={
      {key=kb.left,
       act=function()if(hspeed<0)then hspeed=0;end;end},
      {key=kb.up,
       act=function()if(vspeed>0)then vspeed=0;end;end},
      {key=kb.right,
       act=function()if(hspeed>0)then hspeed=0;end;end},
      {key=kb.down,
       act=function()if(vspeed<0)then vspeed=0;end;end}}
}
return warrior
