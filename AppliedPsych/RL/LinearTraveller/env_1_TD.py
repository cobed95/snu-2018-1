import numpy as np
import numpy.random as r
import pygame
from pygame.locals import *
from sys import exit




# for environment

R = np.ones(7)*(-1); R[6]=0



sz = 160
delay = 400
pygame.init()
screen = pygame.display.set_mode((80+40+7*sz, 100+sz*1+150), 0, 32)
screen.fill((100,100,200))
font01 = pygame.font.SysFont("arial",30)
font02 = pygame.font.SysFont("arial",40)

agent = pygame.image.load("00.png").convert_alpha(screen)

def set_screen(S):
    
    for i in xrange(7):
        c = (220,220,220)
        if i == 6 : c = (200,150,100)
        pygame.draw.rect(screen,c,(Rect(100+sz*i,70,sz-2,sz-2)))
        
    pygame.draw.rect(screen,(200,100,100),(Rect(100+sz*S,70,sz-2,sz-2)))
    screen.blit(agent,(100+sz*S,70))
    pygame.display.update()
    pygame.time.delay(delay)
    if S in range(0,6) : c = (220,220,220)
    else : c = (200,150,100)
    
    screen.blit(agent,(100+sz*S,70))
    pygame.display.update()
    pygame.time.delay(delay)
    pygame.draw.rect(screen,(200,100,100),(Rect(100+sz*S,70,sz-2,sz-2)))
    return




def terminal():
    
    pygame.time.delay(10000)
    pygame.quit()


def end_trace():
    pygame.time.delay(delay*2)
    c0 = (100,100,200)
    

    return



def e_greedy(S,V,eps):
    
    
    Left = S-1; Right = S+1
    if S == 0: Left = S
    if V[Left]==V[Right]:    new_S = r.choice([Left,Right],p=[0.5,0.5])
    elif V[Left] > V[Right]: new_S = r.choice([Left,Right],p=[1-eps,eps])
    else : new_S = r.choice([Left,Right],p=[eps,1-eps])

    if new_S in range(0,6) : c = (220,220,220)
    else : c = (200,150,100)
    


    screen.blit(agent,(100+sz*new_S,70))
    pygame.display.update()
    pygame.time.delay(delay)
    pygame.draw.rect(screen,c,(Rect(100+sz*new_S,70,sz-2,sz-2)))
    return new_S

    

def view_V(S,n,v,g):
    if S in range(0,6) : c = (220,220,220)
    else : c = (200,150,100)
    c0 = (100,100,200)
    
    pygame.draw.rect(screen,c0,(Rect(100+sz*S,80+150,sz-2,sz-2)))
    text_1 = font01.render("n=%d"%n,True,(0,0,0),c0)
    text_2 = font01.render("G=%3.1f"%g,True,(0,0,0),c0)
    text_3 = font01.render("V=%3.2f"%v,True,(0,0,0),c0)
    screen.blit(text_1,(100+sz*S+25,80+150))
    screen.blit(text_2,(100+sz*S+25,110+150))
    screen.blit(text_3,(100+sz*S+25,140+150))
    
    pygame.display.update()
    return
    
    

