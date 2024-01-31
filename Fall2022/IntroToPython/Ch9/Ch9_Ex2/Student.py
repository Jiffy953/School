"""
Chapter 9, Exercise 2 (module)
Title: Student
Student Name: Duane Franz
Purpose:Define in which the Student class is provided
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

