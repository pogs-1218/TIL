use std::collections::HashMap;

#[derive(Debug)]
enum SpreadsheetCell {
    Int(i32),
    Float(f64),
    Text(String),
}

fn main() {
    // Create an empty vector
    let v: Vec<i32> = Vec::new();

    let v = vec![1, 2, 3];

    let mut v = Vec::new();
    v.push(5);
    v.push(6);
    v.push(7);
    v.push(8);

    let third = &v[2];
    println!("The third element is {}", third);

    match v.get(6) {
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element"),
    }

    v.push(10);
    //println!("The third element is {}", third);

    let v = vec![100, 32, 48];
    for i in &v {
        println!("{}", i);
    }

    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Float(10.2),
        SpreadsheetCell::Text(String::from("blue")),
    ];

    for i in &row {
        println!("{:?}", i);
    }

    // All the same!
    let data = "initial contents";
    let s = data.to_string();
    let s = "initial contents".to_string();
    let s = String::from("initial contents");

    let mut s = String::from("foo");
    let bar = "bar";
    s.push_str(bar);
    println!("s: {}, bar: {}", s, bar);

    let mut s = String::from("lo");
    s.push('l');
    println!("s: {}", s);

    let s1 = String::from("hello, ");
    let s2 = String::from("world!");
    let s3 = s1 + &s2;
    println!("s3: {}, s2: {}", s3, s2);

    let mut s1 = String::from("tic");
    let mut s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = format!("{}-{}-{}", s1, s2, s3);
    println!("s: {}", s);
    s1.push_str("tac?");
    s2.push_str("tt");

    // Indexing of String is not allowed. -> Unicode support.
    //let h = s1[0];

    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);
    scores.insert(String::from("yellow"), 50);
    println!("{:?}", scores);

    let team_name = String::from("blue");
    let score = scores.get(&team_name);

    // overwrite
    scores.insert(String::from("blue"), 25);
    println!("{:?}", scores);

    scores.entry(String::from("red")).or_insert(100);
    scores.entry(String::from("yellow")).or_insert(52);
    println!("{:?}", scores);

    let teams = vec![String::from("blue"), String::from("yellow")];
    let initial_scores = vec![10, 50];
    let mut scores: HashMap<_, _> = teams.into_iter().zip(initial_scores.into_iter()).collect();

    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    // field_name and field_value are invalid at this point.
    //field_name.push_str("aa");

    let text = "hello world wonderful world";
    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        // mutable reference is returned.
        let count = map.entry(word).or_insert(0);
        *count += 1; // deref
    }
    println!("{:?}", map);
}
