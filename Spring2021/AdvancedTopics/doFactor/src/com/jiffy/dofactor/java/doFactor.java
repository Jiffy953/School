package com.jiffy.dofactor.java;

import java.util.Scanner;

public class doFactor {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        int x;
        System.out.print("Enter x: ");
        x=console.nextInt();
        System.out.printf("x = %d \n", x);

        for (int i=2; i < x; i++) {
             while (x % i == 0){
                 System.out.println(i+" ");
                 x = x/i;
             }
        }
        if (x > 2){
            System.out.println(x);
        }
    }
}
