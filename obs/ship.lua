local ship={
   name="ship",
   spr="sp0",
   kbdo={
      {key=65,
       act=function() x=x+0.1;y=y+0.1; end;}
   }
}
return ship;
