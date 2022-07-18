use std::io;

fn main() {
    let mut x = 5;
    println!("The value of x: {}", x);
    x = 6;
    println!("The value of x: {}", x);

    // Have to know the difference between immutable variable and const variable.
    const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;

    let spaces = "  ";
    let spaces = spaces.len();

    let mut spaces_other = "  ";
    //spaces_other = spaces_other.len();  // error!

    let t = true;
    let f: bool = false;

    let c = 'a'; // character type is 4 bytes.

    // compound type
    // Tuple type
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let (x, y, z) = tup; // destructuring,
    println!("x: {}, y: {}, z: {}", x, y, z);

    let five_hundred = tup.0;
    let one = tup.2;

    // Array type
    let a = [1, 2, 3, 4, 5];
    let a: [i32; 5] = [1, 2, 3, 4, 5];
    let first = a[0];
    let second = a[1];
    println!("first: {}, second: {}", first, second);

    let a = [3; 5];
    let first = a[0];
    let second = a[1];
    println!("first: {}, second: {}", first, second);

    let a = [1, 2, 3, 4, 5];
    println!("Please enter an array index.");
    let mut index = String::new();

    io::stdin()
        .read_line(&mut index)
        .expect("Failed to read line");

    let index: usize = index
        .trim()
        .parse()
        .expect("Index entered was not a number");

    let element = a[index];
    println!("The value of the element at index {} is {}", index, element);
}
