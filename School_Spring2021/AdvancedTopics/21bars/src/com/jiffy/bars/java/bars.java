package com.jiffy.bars.java;


import java.util.Random;
import java.util.Scanner;
public class bars {
    public static void main(String args[])
    {
        int bars = 21;
        int aBars = 0;
        int bBars = 0;
        Scanner console = new Scanner(System.in);
        int y;
        boolean aStarts = (System.currentTimeMillis() % 2) == 0;
        boolean game = true;


        while (game)
        {
            if (aStarts == true)
            {
                System.out.printf("Bars = %d      Player A picks: ", bars);
                y = console.nextInt();
                aBars += y;
                bars -= y;
                if (bars <= 0)
                {
                    System.out.println("Player B wins!");
                    game = false;
                }

            }
            else
            {
                System.out.printf("Bars = %d      Player B picks: ", bars);
                y = console.nextInt();
                bBars += y;
                bars -= y;
                if (bars <= 0)
                {
                    System.out.println("Player A wins!");
                    game = false;
                }
            }
        }
    }
}