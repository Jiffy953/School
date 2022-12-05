# Jared See
# Assignment 2
# Calculates Sigma(Sigma(10, i=3)2, j=5) with for loops

sum=0 #init
for i in range(3, 11): #Outer sigma 
    for j in range(2, 6): #Inner Sigma
        sum += i *j #Calulation


print("Summation of i and j is:", sum) #output with formatting
