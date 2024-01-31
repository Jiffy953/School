#Jared See
#Assignment 4
#Write a program in which the main function prompts the user to enter a non-neg int and then calls a recurive function to count the amount of digits in it


def main():
    value = int(input("Please input a positive integer:\n"))
    if(value < 0): #checks if number is a non neg int 
        raise ValueError("Input must be a positive integer") #if it is raises an error that describes the issue and exits
    count(value, 1) #first call to counting function

def count(value, digits):
    if value >= 10: #recurive case
        count(value / 10, digits+1) #recurive call, divides the input by 10 removing a decimal place and increases the count of digits
    else: #base case
        print(digits) #output solution 
main() #start main
