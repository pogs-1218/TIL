struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

// Tuple structs
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

// Unit-like structs
struct AlwaysEqual;

fn main() {
    let mut user1 = User {
        email: String::from("test@test.com"),
        username: String::from("hun"),
        active: true,
        sign_in_count: 1,
    };
    println!("name: {}", user1.username);

    user1.username = String::from("unknown");
    println!("name: {}", user1.username);

    let user1 = build_user(String::from("my@google.com"), String::from("user"));
    println!("user2's name: {}", user1.username);

    // let user2 = User {
    //     active: user1.active,
    //     username: user1.username,
    //     email: String::from("another@example.com"),
    //     sign_in_count: user1.sign_in_count,
    // };

    let user2 = User {
        email: String::from("another@example.com"),
        ..user1
    };

    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);

    let subject = AlwaysEqual;
}

fn build_user(email: String, username: String) -> User {
    User {
        email, // same as email: email
        username,
        active: true,
        sign_in_count: 1,
    }
}
