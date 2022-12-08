"""
Chapter 7, Exercise 2
Duane Franz
Purpose: draw a square by using red line and fill it in with yellow
"""

from turtle import * # bring in the Turtle class
import time

def main():
    '''The main function of the program'''

    # create a turtle
    myTurtle = Turtle()

    #set the pen color to red
    myTurtle.pencolor('red')

    #hide the turlte body
    myTurtle.hideturtle()

    #start drawing
    drawSquare(myTurtle, 100, -100, 200)
    drawSquare(myTurtle, 0, -100, 200)
    time.sleep(5)


def drawSquare(t, x, y, length):
    """Draws a square and fills it in yellow"""

    #raise pen from the drawing surface
    t.up()

    #go to the starting location
    t.goto(x, y)

    #lower the pen to touch the drawing surface
    t.down()

    #set the fill color to yellow
    t.fillcolor('yellow')

    #draw the square (4 sides) and fill in the color
    t.begin_fill()
    
    for i in range(4):
        t.left(90)
        t.forward(length)
    
    t.end_fill()

#entry point for execution
main()

