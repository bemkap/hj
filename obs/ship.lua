require"common"
local ship={
   name="ship",
   spr="sp0",
   coll={
      {id="bull",
       act=function(i) instance_destroy(i) end;},
      {id="enem";
       act=function(i) instance_destroy(i) end;}},
   kbdo={
      {key=kb_left,
       act=function(i) translate(i,-2,0) end;},
      {key=kb_right,
       act=function(i) translate(i,2,0) end;},
      {key=kb_up,
       act=function(i) translate(i,0,2) end;},
      {key=kb_down,
       act=function(i) translate(i,0,-2) end;}}
}
return ship;

