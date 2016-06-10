local warrior={
   sprite="warrior",
   crte={act=function() imagespeed=0.3 end},
   kbdo={
      {key=string.byte("A"),
       act=function() hspeed=-2; end},
      {key=string.byte("W"),
       act=function() vspeed= 2; end},
      {key=string.byte("D"),
       act=function() hspeed= 2; end},
      {key=string.byte("S"),
       act=function() vspeed=-2; end}},
   kbup={
      {key=string.byte("A"),
       act=function() hspeed=0; end},
      {key=string.byte("W"),
       act=function() vspeed=0; end},
      {key=string.byte("D"),
       act=function() hspeed=0; end},
      {key=string.byte("S"),
       act=function() vspeed=0; end}}
}
return warrior;
