'''
Chapter 7, Exercise 5
Duane Franz
Purpose: Take a random walk and leaves the track in random colors
'''

from turtle import Turtle
from random import randint

def GoodysAdventure():
    '''The main function of the program'''

    #Create a turtle
    goody = Turtle()

    #hide the turtle's body
    goody.hideturtle()

    #set color (RGB) mode to true color system
    goody.screen.colormode(255)

    #start walking randomly
    wander(goody, 30, 50)


def wander(t, turns, distance):
    '''Walk randomly'''

    for i in range(turns):
        #randomize the pen color
        t.pencolor(randint(0,255),randint(0,255),randint(0,255))
        #actual movement
        t.setheading(randint(0,360))
        t.forward(distance)

#The entry point of execution
GoodysAdventure()
