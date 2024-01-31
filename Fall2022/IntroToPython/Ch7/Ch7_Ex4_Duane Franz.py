'''
Chapter 7, Exercise 4
Duane Franz
Purpose: Take a random walk
'''

from turtle import Turtle
from random import randint

def GoodysAdventure():
    '''The main function of the program'''

    #Create a turtle
    goody = Turtle()

    #hide the turtle's body
    goody.hideturtle()

    #start walking randomly
    wander(goody, 30, 50)


def wander(t, turns, distance):
    '''Walk randomly'''

    for i in range(turns):
        t.setheading(randint(0,360))
        t.forward(distance)

#The entry point of execution
GoodysAdventure()
