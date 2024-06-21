#include "script_template.h"

namespace Code {

constexpr ScriptTemplate emptyScriptTemplate(".py", "\x01" R"(from math import *)" "\n" R"(from mu import *)" "\n");

constexpr ScriptTemplate perfScriptTemplate("perf.py", "\x01" R"(## Perf - Kojiverse Productions
from time import *
from ion import *

global _FPSs
_FPSs = list(range(30))
global _start_frame
_start_frame = [0]

presses = {key:[None,None] for key in (KEY_OK,KEY_BACK)}
def presses_update():
  for key in presses.keys():
    presses[key][-2]=presses[key][-1]
    presses[key][-1]=keydown(key)    

click = lambda key:presses[key][-1] and not presses[key][-2]
release = lambda key:presses[key][-2] and not presses[key][-1] 

def max_fps():
  _FPSs.append(monotonic()-_start_frame[0])
  del _FPSs[0]
  _start_frame[0] = monotonic()
  return round(1/(sum(_FPSs)/len(_FPSs)))

def cap(fps):
  while monotonic()-_start_frame[0]<1/fps:
    pass
  _start_frame[0]=monotonic())");


const ScriptTemplate * ScriptTemplate::Empty() {
  return &emptyScriptTemplate;
}

const ScriptTemplate * ScriptTemplate::Perf() {
  return &perfScriptTemplate;
}


}
