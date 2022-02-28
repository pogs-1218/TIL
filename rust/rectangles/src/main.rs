#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn width(&self) -> bool {
        self.width > 0
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

impl Rectangle {
    fn square(size: u32) -> Rectangle {
        Rectangle {
            width: size,
            height: size,
        }
    }

    fn new(width: u32, height: u32) -> Rectangle {
        Rectangle { width, height }
    }
}

fn main() {
    let width1 = 30;
    let height1 = 50;

    println!("The area: {}", area(width1, height1));

    let rect1 = (30, 50);
    println!("The area: {}", area2(rect1));

    let scale = 2;
    let rect1 = Rectangle {
        width: dbg!(30 * scale),
        height: 50,
    };
    println!("The area: {}", area3(&rect1));
    println!("rect1 is {:#?}", rect1);
    dbg!(&rect1);

    println!("The area: {}", rect1.area());

    let rect2 = Rectangle {
        width: 30,
        height: 50,
    };
    let rect3 = Rectangle {
        width: 10,
        height: 30,
    };
    println!("Can rect2 hold rect3? {}", rect2.can_hold(&rect3));
    println!("Can rect3 hold rect2? {}", rect3.can_hold(&rect2));

    let square_rect = Rectangle::square(30);
    println!("square area: {}", square_rect.area());

    let new_rect = Rectangle::new(10, 20);
    println!("new_rect area: {}", new_rect.area());
}

fn area(width: u32, height: u32) -> u32 {
    width * height
}

fn area2(dimensions: (u32, u32)) -> u32 {
    dimensions.0 * dimensions.1
}

fn area3(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}
