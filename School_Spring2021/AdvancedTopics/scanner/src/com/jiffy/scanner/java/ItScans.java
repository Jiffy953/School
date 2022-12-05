package com.jiffy.scanner.java;

import java.util.Scanner;
public class ItScans {
    public static void scanner(String[] args){
        java.util.Scanner console = new java.util.Scanner(System.in);
        int x;
        System.out.print("Enter x: ");
        x=console.nextInt();
        System.out.printf("x = %d \n", x);
        console.close();
    }
}
