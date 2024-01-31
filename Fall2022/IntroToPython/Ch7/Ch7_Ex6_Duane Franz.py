"""
Chapter 7, Exercise 6
Duane Franz
Purpose: Draw a colorful donut (YUMMMM)(LOL)
"""

from turtle import Turtle
from random import randint

def donut():
    '''The main function of the program'''

    #create a turtle
    goofy = Turtle()

    #hide the turle's body
    goofy.hideturtle()

    #set RGB mode
    goofy.screen.colormode(255)

    #draw the donut
    numCircle = 50
    degTurn = 360/numCircle
    radius = 20
    innerRadius = 15
    for i in range(numCircle):
        #randomize pen color
        goofy.pencolor(randint(0,255), randint(0,255), randint(0,255))
        #draw a circle of radius 20 pixels
        goofy.circle(radius)
        goofy.left(degTurn)
        goofy.forward(innerRadius)

#the entry point of execution
donut()
