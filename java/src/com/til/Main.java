package com.til;
/*
  My first java program!
 */
class Box{
    double width;
    double height;
    double depth;

    Box(double w, double h, double d){
        width = w;
        height = h;
        depth = d;
    }

    double volume(){
        return width * height * depth;
    }
}

// Test to comment. It is same as c++.
 public class Main {
    public static void main(String[] args) {
        System.out.println(("Simple java program!"));
        int num = 100;
        System.out.println("This is num: " + num);
        num = num * 2;
        System.out.println("The value of num*2 is " + num);

        compare(100, 200);

        // Loop. same as c++
        for(int i = 0; i < 10; ++i){
            System.out.println(i);
        }
        boolean b = false;
        System.out.println(b);  // Can print a 'false'!

        byte myByte = 50;
        // error. even though the byte type has 1 byte.
        // the operand is promoted to int type when evaluating expression.
        //myByte = myByte * 2;
        myByte = (byte) (myByte * 2);
        System.out.println(myByte);

        int month_days[] = new int[12]; // Have to be allocated by new. like as c#
        int years[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};      // Don't need to use new.
        for(var year : years) {     // Iteration variable 'year' is read-only.
            System.out.println("year is " + year);
        }

        var avg = 10.0;     // type inference.
        String str = "two";
        switch(str){
            case "one":
                System.out.println("not two");
                break;
            case "two":
                System.out.println("matched");
                break;
            default:
                System.out.println("invalid str");
                break;
        }

        Box myBox = new Box(10, 20, 15);

        // It's different with c++.
        // Class instance(object) is always a reference. so members are not copied.
        Box myBox2 = myBox;

        System.out.println("Volume is " + myBox.volume());
        System.out.println("Volume is " + myBox2.volume());
    }

    public static void compare(int x, int y) {
        // Condition statement. same as c++
        if(x < y)
            System.out.println(x + " is less than " + y);
        else if (x > y){
            System.out.println(x + " is larger than " + y);
        }else{
            System.out.println("equal!");
        }
    }
}
