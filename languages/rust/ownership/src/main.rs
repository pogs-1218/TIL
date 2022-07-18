// The ownership of Rust is similar with the combination of std::unique_ptr and std::move in C++
fn main() {
    let s = String::from("hello");
    take_ownership(s);
    //println!("s: {}", s);  --> error! The ownership of s was moved into take_ownership function then was dropped.

    let x = 5;
    makes_copy(x);
    println!("x: {}", x);

    let s1 = give_ownership();
    println!("s1: {}", s1);

    let s2 = takes_and_gives_back(s1);
    println!("s2: {}", s2);

    let hello = String::from("hello");
    calculate_length2(&hello);
    println!("{}", hello);

    //change(&mut hello); --> Error! hello is not mutable variable.

    let mut s = String::from("hello");
    change(&mut s);

    // you can have only one mutable reference to a particular piece of data at a time.
    // Prevent data races!!!
    let r1 = &mut s;
    //let r2 = &mut s;
    //println!("{}, {}", r1, r2);
    println!("{}", r1);

    let r1 = &s;
    let r2 = &s;
    //let r3 = &mut s;  --> error! We also cannot have a mutable reference while we have an immutable one to the same value
    println!("{}, {}", r1, r2);

    let s = String::from("hello world");
    let hello = &s[0..5];
    let world = &s[6..];

    let h = first_word(&s);
    println!("h: {}", h);

    let mut s = String::from("hello");
    let word = first_word(&s);
    //s.clear();
    println!("{}", word);

    let intj = "intj"; // The type of string literal is &str
    let mbti = first_word(&intj);
}

fn take_ownership(some_string: String) {
    println!("{}", some_string);
}

fn give_ownership() -> String {
    let some_string = String::from("yours");
    some_string
}

fn takes_and_gives_back(a_string: String) -> String {
    a_string
}

fn makes_copy(some_integer: i32) {
    println!("{}", some_integer);
}

// s should be returned in order to be used later as the ownership of s is moved to the function.
fn calculate_length(s: String) -> (String, usize) {
    let len = s.len();
    (s, len)
}

fn calculate_length2(s: &String) -> usize {
    s.len()
}

// Reference of Rust is like a const pointer(or reference) in C++
// Error! All variables are immuntable by default, so are references
//fn change(some_string: &String) {
//    some_string.push_str(", world");
//}

fn change(some_string: &mut String) {
    some_string.push_str(", world");
}

// &str is an immutable reference
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}
