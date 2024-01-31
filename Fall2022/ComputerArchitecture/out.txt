#calculate factorial of number entered by the user
#Complete the program by writing the Factorial function what was covered in lecture
.data
string1: .asciiz "\nEnter the number greater or equal to 0: \n"
string2: .asciiz "\nThe factorial is:\n"
error_string: .asciiz "\nThe number entered is less than 0\n"
.text
#print string1
la $a0, string1
li $v0,4
syscall

#accept number from user
li $v0, 5
syscall
move $s0, $v0 #save the number entered by the user into $s0 register

#check if the number entered is >0
bltz $s0, error

move $a0, $s0 #pass the number n as argument for the factorial function
#call factorial function
jal factorial

move $s1,$v0 #move the result into $s1 s1 = v0
la $a0,string2
li $v0,4
syscall

#printthe result
li $v0, 1
move $a0, $s1
syscall

j exit

error:
     la $a0,error_string
     li $v0,4
     syscall

exit:
	li $v0, 10
	syscall

factorial:
    addi    $sp, $sp, -8 #grow stack by 2
    sw      $s0, 4($sp) #add argument
    sw      $ra, 0($sp) #add return address
    bne     $a0, 0, continue #branch
    addi    $v0, $0, 1 
    j return
       
continue:
    move    $s0, $a0 #move a0 into s0
    addi    $a0, $a0, -1 #decreimnet a0
    jal     factorial #recurive call (kinda)
    multu   $s0, $v0 #unsigned mult
    mflo     $v0 #move mult result into v0 from the low register


return:
    lw      $s0, 4($sp) #get result off stack
    lw      $ra, 0($sp) #get return address off stack
    addi    $sp, $sp, 8 #pop 2 items off stack
    jr      $ra #return
