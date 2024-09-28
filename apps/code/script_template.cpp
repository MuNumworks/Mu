#include "script_template.h"

namespace Code {

constexpr ScriptTemplate emptyScriptTemplate(".py", "\x01" R"(from math import *)" "\n" R"(from mu import *)" "\n");

constexpr ScriptTemplate pygameScriptTemplate("pygame.py", "\x01" R"(from kandinsky import fill_rect as fl,fill_circle as fc,draw_string as dr,draw_line as dl,wait_vblank
from ion import*
import time as sys_time
K_OK=KEY_OK
K_BACK=KEY_BACK
K_LEFT=KEY_LEFT
K_RIGHT=KEY_RIGHT
K_UP=KEY_UP
K_DOWN=KEY_DOWN
LOC_KEYS_=K_OK,K_DOWN,K_UP,K_RIGHT,K_LEFT
FULLSCREEN=1
NOFRAME=16
QUIT=268435456
KEYDOWN=256
KEYUP=512
__all__=['Display','Display.set_mode','Display.set_caption','Display.flip','Surface','Surface.fillRect','Rect.colliderect','Rect.move_to','Rect.move','draw','draw.rect','draw.line','draw.circle','time','time.delay','time.Clock','Clock','Clock.tick','Clock.get_fpskey','key.get_pressed']
presses={key:[None,None]for key in LOC_KEYS_}
def presses_update():
	for key in presses.keys():presses[key][-2]=presses[key][-1];presses[key][-1]=keydown(key)
click=lambda key:presses[key][-1]and not presses[key][-2]
release=lambda key:presses[key][-2]and not presses[key][-1]
class init:
	def __init__(self):return
class Surface:
	def __init__(self,width,height):self.width=width;self.height=height;self.to_do={'rect':list(),'line':list(),'circle':list(),'polygon':list()};return
	def fill(self,color):Check._color(color);fl(0,display.YPLUS,self.width,self.height,color);return
class Check:
	def __init__():return
	def _int(*args):
		for i in args:
			if type(i)!=int:raise ValueError('An integer was expected instead of %s'%i)
		return
	def _color(*args):
		for i in args:
			if not(type(i)==str and len(i)==7 and i[0]=='#'or type(i)==tuple):raise ValueError('A tuple was expected instead of %s'%i)
		return
	def _rect(*args):
		for i in args:
			if type(i)!=Rect:raise ValueError('A pygame.Rect object was expected instead of %s'%i)
		return
	def _tuple(*args):
		for i in args:
			if type(i)!=tuple:raise ValueError('A tuple was expected instead of %s'%i)
		return
	def _surface(*args):
		for i in args:
			if type(i)!=Surface:raise ValueError('A pygame.Surface object was expected instead of %s'%i)
		return
class Display:
	def __init__(self):self.width,self.height=None,None;self.caption='Pygame window';self.YPLUS=18;self.surface=None;return
	def __refresh_screen(self):
		if not self.surface:fl(0,self.YPLUS,self.width,self.height,'#000000')
		if self.YPLUS:fl(0,0,self.width,self.YPLUS,'#ffffff');dr(self.caption[:self.width//10-1],5,0)
		return
	def set_caption(self,caption):self.caption=caption;self.__refresh_screen();return
	def set_mode(self,size,flags=0):
		self.width,self.height=size;Check._int(self.width,self.height)
		if flags&NOFRAME:self.YPLUS=0
		if flags&FULLSCREEN:self.width=320;self.height=222-self.YPLUS
		if self.height+self.YPLUS>222:self.height=222
		self.surface=Surface(self.width,self.height);self.__refresh_screen();return self.surface
	def flip(self):self.__refresh_screen();wait_vblank();[fl(*rect)for rect in self.surface.to_do['rect']];[fc(*circle)for circle in self.surface.to_do['circle']];[dl(*line)for line in self.surface.to_do['line']];self.surface.to_do={'rect':list(),'circle':list(),'line':list(),'polygon':list()};return
	def get_surface(self):return self.surface
class draw:
	@staticmethod
	def rect(surface,color,rect):Check._color(color);Check._rect(rect);surface.to_do['rect'].append(rect._get_infos(display.YPLUS)+(color,));return
	@staticmethod
	def circle(surface,color,pos,radius,width=0):Check._color(color);Check._int(radius,width);Check._tuple(pos);surface.to_do['circle'].append((pos[0],pos[1]+display.YPLUS,radius,color));return
	@staticmethod
	def line(surface,color,startpos,endpos):Check._color(color);Check._tuple(startpos,endpos);surface.to_do['line'].append((startpos[0],startpos[1]+display.YPLUS,endpos[0],endpos[1]+display.YPLUS,color));return
class Rect:
	def __init__(self,x,y,width,height):self.x,self.y=x,y;self.width,self.height=width,height
	def __str__(self):return'Rect({%s}, {%s}, {%s}, {%s})'%(self.x,self.y,self.width,self.height)
	def _get_infos(self,yplus=0):Check._int(yplus);return self.x,self.y+yplus,self.width,self.height
	def move(self,x,y):Check._int(x,y);return Rect(self.x+x,self.y+y,self.width,self.height)
	def move_to(self,x,y):Check._int(x,y);self.x,self.y=x,y;return
	def colliderect(self,other):return mu.colliderect((self.x,self.y,self.width,self.height),(other.x,other.y,other.width,other.height))
class key:
	@staticmethod
	def get_pressed():return{key:keydown(key)for key in LOC_KEYS_}
class time:
	@staticmethod
	def Clock():return Clock()
	@staticmethod
	def delay(delay):sys_time.sleep(delay/1000);return
class Clock:
	def __init__(self):self.start_time=sys_time.monotonic();self.last_elapse=None;self.elapsed_time=[];return
	def tick(self,fps=60):
		if not self.last_elapse:self.last_elapse=self.start_time
		while sys_time.monotonic()-self.last_elapse<1/fps:0
		self.elapsed_time.append(sys_time.monotonic()-self.last_elapse)
		if len(self.elapsed_time)>30:del self.elapsed_time[0]
		self.last_elapse=sys_time.monotonic();return
	def get_fps(self):return 1/(sum(self.elapsed_time)/len(self.elapsed_time)+1e-05+1e-05)
display=Display()
event=Events())");

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

const ScriptTemplate * ScriptTemplate::Pygame() {
  return &pygameScriptTemplate;
}
const ScriptTemplate * ScriptTemplate::Perf() {
  return &perfScriptTemplate;
}

}
