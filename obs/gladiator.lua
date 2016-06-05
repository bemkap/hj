local gladiator={
   name="gladiator",
   sprite="gladiator_spr",
   skills={
      {name="sword strike",
       level=1,
       power=3,
       cooldown=5,
       mana=10,
       range=15,
       kind=0}
      {name="colera",
       level=1,
       action=function() attack=attack+5 end,
       cooldown=40,
       time=8,
       mana=20}}
   stats={
      hp=5,
      mana=3,
      attack=9,
      defense=5,
      agitily=4,
      inteligence=1,
      concentration=5}
}
return gladiator
