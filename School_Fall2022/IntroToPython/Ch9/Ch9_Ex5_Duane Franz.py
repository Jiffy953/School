"""
Chapter 9, Exercise 5
Student Name: Duane Franz
Purpose: Have the Dog class extend/inherit the Pet Class
"""

#The super (parent) class
class Pet(object):
    '''Represents a pet'''
    
    def __init__(self, initAge = 0):
        '''The Constructor'''

        self.age = initAge

    def getAge(self):
        '''Returns the pet's age'''

        return self.age

    def setAge(self, newAge):
        '''Resets the pet's age'''

        self.age = newAge

    def happy(self):
        '''When the pet is happy (a polymorphing function)'''

        print('Jumping')

    def __str__(self):
        '''Returns a string representation of the pet'''

        return 'Age = ' + str(self.age)


#The subclass(child class)
class Dog(Pet): #the Dog class extends the Pet class
    '''Represents a dog'''

    def __init__(self, initAge, initName):
        '''The constructor'''

        Pet.__init__(self, initAge)
        self.name = initName

    def getName(self):
        '''Returns the dog's name'''

        return self.name

    def setName(self, newName):
        """Resets the dog's name"""

        self.name = newName

    def happy(self):
        '''When dog is happy (a polymorphic function)'''

        print('Wagging tail')
        

    def __str__(self):
        '''Returns a string representation of the dog'''

        return Pet.__str__(self) + ', Name: ' + self.name 


def main():
    '''The main function of the program'''

    #instantiates a pet and a dog
    myPet = Pet(3)
    myDog = Dog(2, 'Goofy')

    #display my pet and my dog
    print('In my pet: ',myPet)
    print('In my dog: ',myDog)

    #changes my dog
    myDog.setAge(10)
    myDog.setName('Gouda')

    #display my dog again
    print('My dog is changed to: ',myDog)

    #when my pet is happy
    myPet.happy()

    #when my dog is happy
    myDog.happy()

#entry point of execution
main()
