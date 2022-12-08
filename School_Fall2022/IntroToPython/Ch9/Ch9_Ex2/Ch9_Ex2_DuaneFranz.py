"""
Chapter 9, Exercise 2
Student Name: Duane Franz
Purpose:Define in which the Student class is provided
"""
from Student import * #bring in the Student class type

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
        
