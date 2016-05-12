local bull1={
   spr="sp1",
   alrm={
      {n=0,
       act=function(i)
	  instance_destroy(i);
	  j=getob("ship"):getin(0);
	  for a=1,10 do
	     k=oget("bull"):addin(i.x-25+arb(50),i.y-25+arb(50));
	     k:dir=point_direction(i,j);
	     k:spe=arb(4)+8;
	  end
   end}}
   step={act=function(i) i:dir=i:dir+2 end}
}
return bull1;
   
       
