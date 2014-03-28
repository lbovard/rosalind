#sometimes it's just easier in python...
from math import log10
bp=raw_input()
values=raw_input()
bp=[bp.count(x) for x in ['A','C','G','T']]
values=[float(x) for x in values.split()]
for x in values:
  cont=[log10((1.0-x)/2.0),log10(x/2.0),log10(x/2.0),log10((1.0-x)/2.0)]
  prob=0.0
  for i in range(0,4):
    prob=prob+bp[i]*cont[i]
  print prob

  

