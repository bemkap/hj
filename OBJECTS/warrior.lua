local kb=require"OBJECTS/common"
local warrior={
   sprite="rightwarrior",
   crte={act=function()imagespeed=0.2;end},
   step={act=function()setcamera(x,y);end},   
   kbdo={
      {key=kb.a,
       act=function()hspeed=-2;sprite="leftwarrior";end},
      {key=kb.w,
       act=function()vspeed=2;sprite="backwarrior";end},
      {key=kb.d,
       act=function()hspeed=2;sprite="rightwarrior";end},
      {key=kb.s,
       act=function()vspeed=-2;sprite="frontwarrior";end}},
   kbup={
      {key=kb.a,
       act=function()if(hspeed<0)then hspeed=0;end;end},
      {key=kb.w,
       act=function()if(vspeed>0)then vspeed=0;end;end},
      {key=kb.d,
       act=function()if(hspeed>0)then hspeed=0;end;end},
      {key=kb.s,
       act=function()if(vspeed<0)then vspeed=0;end;end}}
}
return warrior
