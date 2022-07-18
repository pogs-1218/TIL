use std::fmt::Display;

struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn x(&self) -> &T {
        &self.x
    }

    // fn mixup<U>(self, other: Point<U>) -> Point<T> {
    //     Point {
    //         x: self.x,
    //         y: other.y,
    //     }
    // }
}

impl Point<f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

fn main() {
    let number_list = vec![45, 50, 24, 100, 152];
    let result = largest(&number_list);
    println!("The largest number is {}", result);

    let char_list = vec!['y', 'm', 'a', 'q'];
    let result = largest(&char_list);
    println!("The largest character is {}", result);

    let integer = Point { x: 1, y: 2 };
    let float = Point { x: 1.2, y: 4.2 };

    // let int_ret = integer.distance_from_origin();  --> error
    let float_ret = float.distance_from_origin();
}

fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];
    for &item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}
