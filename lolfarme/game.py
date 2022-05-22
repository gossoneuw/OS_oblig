import math

import pygame
import sys
import random

width = 1820
height = 980

posx = 200
posy = 200

clickx = 200
clicky = 200

mouseposx = 0
mouseposy = 0

q_cd = 100


white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

background = pygame.image.load("lolbotlane.jpg")
score = 0

def scoreboard():
    font = pygame.font.SysFont("Arial", 26)
    scorenow = font.render("score: " + str(score), True, black)
    screen.blit(scorenow, ((width / 2), 50))

class Player(pygame.sprite.Sprite):
    def __init__(self, posx, posy):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((100,100))
        self.image.fill(red)
        self.rect = self .image.get_rect()
        self.rect.x = posx
        self.rect.y = posy

    def shootQ(self):
        q = abilityQ(self.rect.centerx, self.rect.top, )
        spriteAbilities.add(q)




class Minion(pygame.sprite.Sprite):
    def __init__(self, posx, posy):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((50,50))
        self.image.fill(white)
        self.rect = self.image.get_rect()
        self.rect.x = posx
        self.rect.y = posy

    def update(self):
        hit = pygame.sprite.spritecollide(self, spriteAbilities, False)
        if hit:
            self.kill()

class abilityQ(pygame.sprite.Sprite):
    def __init__(self,posx,posy):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((10,10))
        self.image.fill(green)
        self.rect = self.image.get_rect()
        self.rect.bottom = posy
        self.rect.centerx = posx

    def update(self):
        movediffx = (mouseposx - posx)/100
        if movediffx < 0:
            movediffx = math.sqrt(movediffx * movediffx)

        if mouseposx > posx:
            self.rect.x += movediffx
        if mouseposx <= posx:
            self.rect.x -= movediffx
        movediffy = (mouseposy - posy)/100
        if movediffy < 0:
            movediffy = math.sqrt(movediffy * movediffy)
        if mouseposy > posy:
            self.rect.y += movediffy
        if mouseposy <= posy:
            self.rect.y -= movediffy



pygame.init()
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("LOL")
pygame.key.set_repeat(True)
gameloop = True


spritePlayer = pygame.sprite.Group()
spriteMinion = pygame.sprite.Group()
spriteAbilities = pygame.sprite.Group()

minion = Minion(600,600)
spriteMinion.add(minion)


while gameloop:
    mx, my = pygame.mouse.get_pos()
    mouseposx = mx
    mouseposy = my

    if len(spriteMinion) < 1:
        i = random.randrange(0,2)
        if i == 1:
            minion = Minion(600, 600)
            spriteMinion.add(minion)
        else:
            minion = Minion(300, 300)
            spriteMinion.add(minion)

    if q_cd < 100:
        q_cd += 1
    player = Player(posx, posy)
    spritePlayer.add(player)

    if posx != clickx -50:
        if posx > clickx -50:
            posx -= 1
        if posx < clickx -50:
            posx += 1
    if posy != clicky -50:
        if posy > clicky -50:
            posy -= 1
        if posy < clicky -50:
            posy += 1

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_q and q_cd > 99:
                player.shootQ()
                q_cd = 0
            if event.key == pygame.K_d:
                print(mx,my)
        #movement
        if event.type == pygame.MOUSEBUTTONDOWN:
            mx, my = pygame.mouse.get_pos()
            print(mx,my)
            clickx = mx
            clicky = my

    loselife = pygame.sprite.spritecollide(player,spriteMinion, False)
    if loselife:
        print("lose")
    hit = pygame.sprite.spritecollide(minion, spriteAbilities, False)
    if hit:
        score += 1



    spritePlayer.update()
    spriteMinion.update()
    spriteAbilities.update()


    screen.blit(background, (0,0))
    spritePlayer.draw(screen)
    spriteMinion.draw(screen)
    spriteAbilities.draw(screen)
    spritePlayer.empty()
    scoreboard()

    pygame.display.flip()