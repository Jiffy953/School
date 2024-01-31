# Jared See
# Assignment  1
# 9/7/2022
# Caclulates the volume of a cone after taking its height and radius from keyboard input then displays result with 2 decimal percision


height = float(input("Please enter the height of the cone: "))
radius = float(input("Please enter the radius of the cone: "))
volume = 3.14159 * radius ** 2 * (height / 3) #using hard coded value of pi rather than math.pi to avoid import
print("The volume of a cone with height", height, "and radius", radius, "is:", round(volume, 2)) #displays everything in one line