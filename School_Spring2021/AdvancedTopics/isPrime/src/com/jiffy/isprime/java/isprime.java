package com.jiffy.isprime.java;

import java.util.Scanner;

public class isprime {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        int x;
        System.out.print("Enter x: ");
        x=console.nextInt();
        System.out.printf("x = %d \n", x);
        boolean prime = true;
        for (int i=2; i < x; i++) {
            if (x % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            System.out.printf("%d is a prime number\n", x);
        else
            System.out.printf("%d is not a prime number\n", x);
    }
}
