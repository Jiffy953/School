"""
Chapter 9, Exercise 4
Student Name: Duane Franz
Purpose: Pickling die objects, i.e., file input/output of die objects 
"""

from pickle import * #

#bring in the random module
from random import randint # for rolling a die

class DieD6(object): # Syntatically, "(object)" is optional,
                     # but is part of industry standard
    """Represents a die"""

    def __init__(self, initValue =1):
        '''Instantiates a die with the given initial value'''

        self.value = initValue

    def getValue(self):
        '''Return the die's value'''

        return self.value

    def roll(self):
        '''Rolls the die'''

        self.value = randint(1,6)


    def __str__(self):
        '''Returns a string representation of the die'''

        return 'Value: ' + str(self.value)

    def __gt__(self, other):
        """The greater than operator"""

        return self.value > other.value
    
    def __lt__(self, other):
        """The less than operator"""

        return self.value < other.value
    
    def __ge__(self, other):
        """The greater than operator"""

        return self.value >= other.value

    
    def __le__(self, other):
        """The less than operator"""

        return self.value <= other.value

    def __eq__(self, other):
        """The equal operator"""

        if self is other:
            return True #the same object
        elif type(self) != type(other):
            return False #type mismatch
        else:
            return self.value == other.value
    

def main():
    '''The main function of the program'''

    #instantiate two dice
    d1 = DieD6()  #Since we did not define an initValue, the default is 1
    d2 = DieD6(3)  #initValue = 3

    #print both dice
    print('In d1,', d1)
    print('In d2,', d2)

    #propmt for a file name
    fileName = input("Please enter a file name: ")

    #open the file in writing block ("wb") mode
    outFile = open(fileName, "wb")

    #dump(write) d1 and d1 to the file
    dump(d1, outFile)
    dump(d2, outFile)

    #close the file
    outFile.close()

    #reopen the file in reading block mode
    inFile = open(fileName, 'rb')

    #load (read) two dice from the file
    d3 = load(inFile)
    d4 = load(inFile)

    #print both dice
    print('In d3,', d3)
    print('In d4,', d4)



#Entry point of execution
main()
    
