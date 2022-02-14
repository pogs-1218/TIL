// c++: #include <iostream>
use std::io;

fn main() {
    println!("Guess the number!");
    println!("Please input your guess.");

    // the let statement to create the variable.
    // In Rust, variables are immutable by default.
    // To make a variable mutable, we add mut before the variable name:
    let mut guess = String::new();
    // c++: std::cin >>
    io::stdin()
        .read_line(&mut guess) // The string argument needs to be mutable so the method can change the string’s content.
        .expect("Failed to read line"); // expect is not exception of c++!
    println!("You guessed: {}", guess);
}
