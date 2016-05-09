local ship={
   spr="sp0";
   coll={
      {id="bull",
       act=function(i) instance_destroy(i) end;},
      {id="enem";
       act=function(i) instance_destroy(i) end;}},
   kbdo={
      {key=227,--kb_left;
       act=function(i) i.x=i.x-5-2*keydown(239) end;},--lshf
      {key=229,--kb_right,
       act=function(i) i.x=i.x+5-2*keydown(239) end;},--lshf
      {key=228,--kb_up;
       act=function(i) i.y=i.y+5-2*keydown(239) end;},--lshf
      {key=230,--kb_down;
       act=function(i) i.y=i.y-5-2*keydown(239) end;}}--lshf
}
return ship;
