import numpy as np
import numpy.random as r
import pygame
from pygame.locals import *
from sys import exit




# for environment

R = np.zeros(7);R[6]=1




sz = 160
delay = 100
pygame.init()
screen = pygame.display.set_mode((80+40+7*sz, 100+sz*1+150), 0, 32)
screen.fill((100,100,200))
font01 = pygame.font.SysFont("arial",30)
font02 = pygame.font.SysFont("arial",40)

agent = pygame.image.load("00.png").convert_alpha(screen)

def set_screen(S):
    #cell_size = 160


    for i in xrange(7):
        c = (220,220,220)
        if i == 0 or i == 6 : c = (200,150,100)

        pygame.draw.rect(screen,c,(Rect(100+sz*i,70,sz-2,sz-2)))

    screen.blit(agent,(100+sz*S,70))
    pygame.display.update()
    pygame.time.delay(delay)
    if S in range(1,6) : c = (220,220,220)
    pygame.draw.rect(screen,c,(Rect(100+sz*S,70,sz-2,sz-2)))
    pygame.display.update()
    return


def random_move(S):
    if S in range(1,6) : c = (220,220,220)
    else : c = (200,150,100)
    pygame.draw.rect(screen,c,(Rect(100+sz*S,70,sz-2,sz-2)))
    new_S = r.choice([S-1,S+1],p=[0.5,0.5])
    screen.blit(agent,(100+sz*new_S,70))
    pygame.display.update()
    pygame.time.delay(delay)
    return new_S


def terminal():

    pygame.time.delay(10000)
    pygame.quit()

def view_V(S,n,rd,v,g,gamma):
    if S in range(1,6) : c = (220,220,220)
    else : c = (200,150,100)
    pygame.draw.rect(screen,c,(Rect(100+sz*S,70,sz-2,sz-2)))
    pygame.draw.circle(screen,(200,100,100),(180+sz*S,70+80),25)
    pygame.time.delay(500)
    c0 = (100,100,200)
    pygame.draw.rect(screen,c0,(Rect(100+sz*S,80+150,sz-2,sz-2)))
    text_1 = font01.render("n=%d"%n,True,(0,0,0),c0)
    text_2 = font01.render("G=%2.1f"%g,True,(0,0,0),c0)
    text_3 = font01.render("V=%3.2f"%v,True,(0,0,0),c0)
    screen.blit(text_1,(100+sz*S+25,80+150))
    screen.blit(text_2,(100+sz*S+25,110+150))
    screen.blit(text_3,(100+sz*S+25,140+150))
    pygame.display.update()
    pygame.time.delay(delay*1)
    pygame.draw.rect(screen,c,(Rect(100+sz*S,70,sz-2,sz-2)))
    #pygame.draw.rect(screen,c,(Rect(100+sz*S,70,sz-2,sz-2)))


def end_trace():
    pygame.time.delay(delay*2)
    c0 = (100,100,200)
    pygame.draw.rect(screen,c0,(Rect(100,110+150,sz*7,30)))





def e_greedy(S,V,eps):
    if S in range(1,6) : c = (220,220,220)
    else : c = (200,150,100)
    pygame.draw.rect(screen,c,(Rect(100+sz*S,70,sz-2,sz-2)))
    if V[S-1]==V[S+1]:    new_S = r.choice([S-1,S+1],p=[0.5,0.5])
    elif V[S-1] > V[S+1]: new_S = r.choice([S-1,S+1],p=[1-eps,eps])
    else : new_S = r.choice([S-1,S+1],p=[eps,1-eps])
    screen.blit(agent,(100+sz*new_S,70))
    pygame.display.update()
    pygame.time.delay(delay)
    return new_S

