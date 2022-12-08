"""
Chapter 9, Exercise 6

Duane Franz

Purpose: the three dimensional poit extends the
         two dimensional point
"""

#the parent class (super class)
class Point2D(object):
    '''Represents a 2D point'''

    def __init__(self, initX, initY):
        '''The constructor to initate a 2D point'''

        self.x = initX
        self.y = initY

    def goto(self, newX, newY):
        '''Mov the 2D point to a new location'''

        self.x = newX
        self.y = newY

    def __str__(self):
        '''Represents the 2D point as a string
           in the format of (x, y)'''

        return '(' + str(self.x) + ', ' + str(self.y) + ')'

class Point3D(Point2D):
    '''Represents a 3D point'''

    def __init__(self, initX, initY, initZ):
        '''The constructor to instantiate a 3D point'''

        Point2D.__init__(self, initX, initY)
        self.z = initZ

    def goto(self, newX, newY, newZ):
        '''Move the 3D point to a new location'''

        Point2D.goto(self, newX, newY)
        self.z = newZ

    def __str__(self):
        '''Represents the 3D point as a string
           in the format of (x, y, z)'''

        return '(' + str(self.x) + ', ' + str(self.y) + ', ' + str(self.z) + ')'


#instantiate a 2D point and a 3D point
d1 = Point2D(1, 2)
d2 = Point3D(3, 6, 9)

#display d1 and d2
print('d1 is at ', d1)
print('d2 is at ', d2)

#move d1 and d2
d1.goto(5,8)
d2.goto(1,2,3)

#display d1 and d2 again
print('d1 is moved to ', d1)
print('d2 is moved to ', d2)


        
