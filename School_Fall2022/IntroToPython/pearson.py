'''
Assignment 5
Student's Name: Pearson Harris
Purpose: Create a class type to represent a tricycle.
'''

'''
The Tricycle class type should contain the following methods:
__init__: the constructor that instantiates a tricycle with a given initial speed or a default initial speed zero.
getSpeed: returns the tricycle’s speed
setSpeed: resets the tricycle’s speed to a new speed
pedal: increases the tricycle’s speed by one
__neq__: the unequal operator to see if two tricycles are not having the same speed
__str__: returns a string representation of a tricycle so that it shows the tricycle’s speed in the format of speed: 0 or speed: 3.
'''


class Tricycle(object):
    '''Represents a tricycle'''
    def __init__(self, initSpeed = 0):
        '''Constructor that creates a tricycle with either
        a given inital speed or an initial speed of 0. '''
        self.speed = initSpeed
        
    def getSpeed(self):
        '''Returns the tricycle's speed.'''
        return self.speed

    def setSpeed(self, newSpeed):
        '''Reset's the tricycle's speed to a new speed.'''
        self.speed = newSpeed

    def pedal(self):
        ''' Incrases the tricycle's speed by one'''
        self.speed += 1

    def __neq__(self, other):
        '''The unequal operator to see if two tricycles are not 
        having the same speed.'''
        #Checks to see if self & other are identical
        if self is other:
            return True #the same object
        #if the types of self & other are not identical
        elif type(self) != type(other): 
            return False #type mismatch
        else:
            #Checks the equivalency between the two
            return not(self.speed == other.speed) 

    def __str__(self):
        #Prints a string representation of the tricycle's speed
        return str(self.speed) 


def main():
    """The main function of this program"""

    #create two tricycles
    myTricycle = Tricycle(2)
    yourTricycle = Tricycle()

    #print both tricycles
    print("My tricycle has", myTricycle)
    print("Your tricycle has", yourTricycle)

    #change your tricycle's speed to 2
    yourTricycle.setSpeed(2)
 
    #pedal your tricycle
    #yourTricycle.pedal()

    #print both tricycles again
    print("My tricycle has", myTricycle)
    print("Your tricycle has", yourTricycle)

    #check if my tricycle and your tricle are not having the same speed
    if (myTricycle != yourTricycle):
        print("My tricle and your tricle are not having the same speed")

main()
