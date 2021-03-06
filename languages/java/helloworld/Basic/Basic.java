package Basic;

public class Basic {
    public static void main(String args[]) {
        int num;
        num = 100;

        System.out.println("This is num: " + num);
        num *= 2;

        System.out.println("The value num * 2 is ");
        System.out.println(num);

        // Same with c++
        for (int i = 0; i < 10; ++i) {
            System.out.println("This is x: " + i);
        }

        byte b = 0;
        //byte bb = 128;  // Compile error.
        // NOTE: Java doesn't have unsigned type.

        // Different with c++.
        // char is 16-bit type. to support Unicode.
        char ch1 = '설';
        char ch2 = 'a';
        System.out.println("ch1: " + ch1);
        System.out.println("ch21: " + ++ch2);

        boolean t = false;
        System.out.println("t is " + t);
        if(t){
            System.out.println("It's true!");
        }else{
            System.out.println("It's false!");
        }

        // Type casting
        // Auto: from small to large.
        int smaller = 12;
        long bigger = smaller;
        // But, it needs type casting if not.
        byte more_smaller = (byte)smaller;

        // Different with c++.
        // Array could be allocated in memory by using new only.
        int month_days[];  // Just declare the variable. not allocated.
        //month_days[3] = 12;  // Compile error. becasuse array memory is not allocated.
        month_days = new int[12];
        month_days[3] = 12;
        System.out.println("month 3: " + month_days[3]);
        System.out.println("how about 9?: " + month_days[9]);
        //System.out.println("how about overflow?: " + month_days[13]); // Throws exception

        // Initialize with declaration.
        // Q. allocated in heap like using new keyword also?
        int years[] = {1, 2, 3, 4, 5};
        System.out.println(years[1]);

        // Since Java 10, type inference is supported. Only for local variable.
        // I think,the compiler might not know the type of instance variable if the member is declared as var
        // as the member variable isn't intialized yet.
        var avg = 10.0;  // maybe double.

        String str = "This is a test";
        System.out.println(str);

        // if-else, switch, while, for, and break, continue are alomost same with C++. Skip!
        // for-each, like a range based loop of C++
        for(var month : month_days){
            System.out.print(month + ", ");
        }
    }
}
