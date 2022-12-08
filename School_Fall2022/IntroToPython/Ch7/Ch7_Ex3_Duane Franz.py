'''
Chapter 7, Exercise 3
Duane Franz
Purpose: Draw a shape by connecting a list of points
'''

from turtle import Turtle #bring in the Turtle class

def TrackGomez(): #You don't have to call the main function "main" in Python!
    '''The main function of the program.''' #You just have to note what the
                                            #function is.

    #create a turtle
    gomez = Turtle()

    #hide the turtle's body
    gomez.hideturtle()

    #the given list of points
    listOfLocations = [(100, 100), (90, 150), (200, 250), (60, 10)]

    #before drawing
    gomez.up()

    #set pencolor
    gomez.pencolor('green')

    #start drawing
    drawPath(gomez, listOfLocations)

def drawPath(target, locations):
    '''Draw a shapeby connecting a list of points'''

    #go to the last point
    (x, y) = locations[-1]
    target.goto(x, y)

    #lower the pen
    target.down()

    #connecting all points
    for (x, y) in locations:
        target.goto(x, y)

#The entry point of execution
TrackGomez()




    
