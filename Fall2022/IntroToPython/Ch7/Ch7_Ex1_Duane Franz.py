"""
Chapter 7, Exercise 1
Duane Franz
Purpose: draw a square by using red line and fill it in with yellow
"""
import time
from turtle import * # bring in the Turtle class
# create a turtle
t = Turtle()

#raise pen from the drawing surface
t.up()

# go to the starting location for drawing
#(assume it stars from (100,-100))
t.goto(100,-100)

#set the pen color to red
t.pencolor('red')

#lower the pen to touch the drawing surface
t.down()

#set the fill color to yellow
t.fillcolor('yellow')


#draw the square (4 sides) and fill in the color
t.begin_fill()

for i in range(8):
    t.left(45)
    t.forward(100)
    
t.end_fill()

#hide the turlte body
t.hideturtle()

time.sleep(5)
