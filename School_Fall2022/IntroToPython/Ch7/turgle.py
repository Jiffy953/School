import time
from random import randint
from turtle import *
t = Turtle()
def main():
    t.up
    t.goto(0, 0)
    t.screen.colormode(255)
    t.down
    for x in range(50):
        t.pencolor(randint(0, 255), randint(0, 255), randint(0, 255))
        t.setheading(randint(0, 360))
        t.forward(randint(10, 150))
    
main()