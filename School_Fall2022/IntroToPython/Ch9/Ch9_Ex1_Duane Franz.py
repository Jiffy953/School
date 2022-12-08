"""
Chapter 9, Exercise 1
Student Name: Duane Franz
Purpose: Represent a student by class type
"""

class Student(object):
    '''Represent a student'''

    def __init__(self, initName, initScore):
        '''The constructor to initiate a student object'''

        self.name = initName
        self.score = initScore

    def getName(self):
        '''Returns the student's name'''

        return self.name

    def setName(self, newName):
        '''Resets the student's name'''

        self.name = newName

    def getScore(self):
        '''Returns the student's score'''

        return self.score

    def setScore(self, newScore):
        '''Resets the student's score'''

        self.score = newScore

    def __str__(self):
        '''The string representation of the current'''

        return "Name: " + self.name + "\nScore: " + str(self.score)


def main():
    '''The main function of the program'''

    #instantiate (create) a student
    myStudent = Student('Nancy', 98)

    #print the student
    print(myStudent)

    #change the student
    myStudent.setName('Mandy')
    myStudent.setScore(100)

    #print the student again
    print(myStudent)

#The entry point of execution
main()
        
