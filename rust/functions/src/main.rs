fn main() {
    println!("Hello, world!");
    another_function(5);
    print_labeled_measurement(5, 'h');

    // Statements are instructions that perform some action and do not return a value. Expressions evaluate to a resulting value.
    // let x = (let y = 5);
    // In C++, x = y = 5;  It's available. But not in Rust.
    // In C/C++, where the assignment returns the value of the assignment.

    // Expressions do not include ending semicolons.
    // If you add a semicolon to the end of an expression, you turn it into a statement, and it will then not return a value.
    let y = {
        let x = five();
        x + 1
    };
    println!("y is {}", y);

    let z = plus_one(1);
    println!("z is {}", z);
}

// must declare the type of each parameter.
fn another_function(x: i32) {
    println!("The value of x is {}", x);
}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is {}{}", value, unit_label);
}

fn five() -> i32 {
    5 // no semicolon, expression!
}

fn plus_one(x: i32) -> i32 {
    return x + 1;
}
