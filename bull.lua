local bull={
   spr="spr1",
   step={act=function(i) if outside(i) then instance_destroy(i) end end}
}
return bull;
