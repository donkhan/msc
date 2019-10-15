# -*- coding: utf-8 -*-
"""
Created on Tue Oct 15 12:06:33 2019

@author: 1msc11
"""

import pygame


pygame.init()

win = pygame.display.set_mode((500,500))
pygame.display.set_caption("First Game")

x = 50
y = 50
width = 40
height = 60
vel = 5
run = True

while run:
    pygame.time.delay(100)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False
    keys = pygame.key.get_pressed()
    
    if keys[pygame.K_LEFT]:
        x = x - vel
    if keys[pygame.K_RIGHT]:
        x = x + vel
    if keys[pygame.K_UP]:
        y = y - vel
    if keys[pygame.K_DOWN]:
        y = y + vel
    pygame.draw.rect(win,(255,0,0),(x,y,width,height)
    pygame.display.update()

pygame.quit()
print("Quit")