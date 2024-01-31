#int n1=0,n2=1,n3,i,number;    
#for(i=2;i<number;++i) //loop starts from 2 because 0 and 1 are already printed    
 #{    
  #n3=n1+n2;    
  #print n3    
  #n1=n2;    
  #n2=n3;   
  
.text
 li $s0, 0 #fib1
 li $s1, 1 #fib2
 li $s2, 0
 li $s3, 1 
 li $s4, 10

loop:
bge $s3, $s4, end
add $s2, $s0, $s1

li $v0, 1
move $a0, $s2
syscall 

li $a0, 32
li $v0, 11
syscall 

move $s0, $s1
move $s1, $s2

addi $s3, $s3, 1
j loop
end:
