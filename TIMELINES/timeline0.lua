local timeline0={
   {n=10,
    act=function()
       for i=1,10 do
	  w=getobject("warrior")
	  instancecreate("enemy",w.x+i*16,w.y)
       end
   end}
}
return timeline0
       
