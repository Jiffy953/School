"""
Chapter 9, Exercise 3
Student Name: Duane Franz
Purpose: Represent a die by a class type, and give the == and != operators 
"""

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
    print(d1)
    print(d2)

    #compare these two dice
    if (d1>d2): #will be translated into "if(d1.__gt__(d2)):"
        print('d1 is greater than d2')
    else:
        print('d1 is not greater than d2')

    #roll both dice
    d1.roll()
    d2.roll()

    #print both dice again
    print(d1)
    print(d2)

    #compare these two dice again
    if (d1==d2): #will be translated into "if(d1.__eq__(d2)):"
        print('d1 is equal to d2')
    else:
        print('d1 is not equal to d2')



#Entry point of execution
main()
    
