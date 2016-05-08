local ship={
   spr="sp0";
   coll={
      {id="bull",
       act=function(i) instance_destroy(i) end;},
      {id="enem";
       act=function(i) instance_destroy(i) end;}},
   kbdo={
      {key=kb_left;
       act=function(i) i.x=i.x-5-2*keypressed(kb_lshift) end;},
      {key=kb_right;
       act=function(i) i.x=i.x+5-2*keypressed(kb_lshift) end;},
      {key=kb_up;
       act=function(i) i.y=i.y+5-2*keypressed(kb_lshift) end;},
      {key=kb_down;
       act=function(i) i.y=i.y-5-2*keypressed(kb_lshift) end;}}
}
return ship;
