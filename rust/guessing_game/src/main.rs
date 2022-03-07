use rand::Rng;
use std::cmp::Ordering;
use std::io; // c++: #include <iostream>

pub struct Guess {
    value: i32,
}

impl Guess {
    pub fn new(value: i32) -> Guess {
        if value < 1 || value > 100 {
            panic!("Guess value must be between 1 and 100, got {}", value);
        }
        Guess { value }
    }
    pub fn value(&self) -> i32 {
        self.value
    }
}

fn main() {
    println!("Guess the number!");

    // range expression: 1..101
    let secret_number = rand::thread_rng().gen_range(1..101);
    println!("The secret number is {}", secret_number);

    loop {
        println!("Please input your guess.");

        // the let statement to create the variable.
        // In Rust, variables are immutable by default.
        // To make a variable mutable, we add mut before the variable name:
        let mut guess = String::new();
        // c++: std::cin >>
        io::stdin()
            .read_line(&mut guess) // The string argument needs to be mutable so the method can change the string’s content.
            .expect("Failed to read line"); // expect is not exception of c++!

        // Shadow the previous guess.
        //let guess: u32 = guess.trim().parse().expect("Please input the number.");
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue, // The underscore, _, is a catchall value;
        };
        println!("You guessed: {}", guess);

        // A match expression is made up of arms.
        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small"),
            Ordering::Greater => println!("Too big"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
