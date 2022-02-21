fn main() {
    let number = 6;

    // Rust will not automatically try to convert non-Boolean types to a Boolean.
    if number % 4 == 0 {
        println!("number is divisible by 4");
    } else if number % 3 == 0 {
        println!("number is divisible by 3");
    } else {
        println!("number is not divisible by 3, 4");
    }

    let condition = true;
    let number = if condition { 5 } else { 6 };
    println!("The value of number is : {}", number);

    //let number = if condition { 5 } else { "six" };

    let mut count = 0;

    'counting_up: loop {
        println!("count = {}", count);
        let mut remaining = 10;
        loop {
            println!("reamining = {}", remaining);
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }
        count += 1;
    }
    println!("End count = {}", count);

    let mut counter = 0;
    let result = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2;
        }
    };
    println!("The result is {}", result);

    let mut number = 3;
    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }
    println!("LIFTOFF!");

    let a = [10, 20, 30, 40, 50];
    let mut index = 0;

    while index < 5 {
        println!("The value is {}", a[index]);
        index += 1;
    }

    for element in a {
        println!("The value is {}", element);
    }

    for number in (1..4).rev() {
        println!("{}!", number);
    }
    println!("LIFTOFF!");
}
