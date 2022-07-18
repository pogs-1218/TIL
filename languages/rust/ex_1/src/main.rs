fn main() {
    let temp = convert_fahrenheit_to_celsius(50.0);
    println!("degree is {}", temp);

    let fib_number = fib(20);
    println!("fib number is {}", fib_number);
}

fn convert_fahrenheit_to_celsius(f: f64) -> f64 {
    (f - 32.0) / 1.8000
}

fn fib(i: u32) -> u32 {
    if i == 0 {
        0
    } else if i == 1 {
        1
    } else {
        fib(i - 1) + fib(i - 2)
    }
}
