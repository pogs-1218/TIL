struct ImportantExcerpt<'a> {
    part: &'a str,
}

fn main() {
    {
        let r;
        {
            let x = 5;
            r = &x;
        }
        //println!("r: {}", r); // error, &x is deleted already.
    }

    let string1 = String::from("abcd");
    let string2 = "xyz";

    let result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);

    // longest가 반환하는 &str은 'a lifetime을 가짐. 함수 시그니쳐에서 반환되는 &str은
    // 파라미터들과 같아야하고, 그 기준은 파라미터 둘중 작은것에 맞춤.(그래야 안전하니깐)
    // 만약, 그렇지 않다면, 위코드에서 string2는 먼저 삭제되고, 만약 반환값이 string2라면
    // result는 유효하지 않은 메모리를 가리키게 됨!
    let string1 = String::from("long string is long");
    let result;
    {
        let string2 = String::from("xyz");
        result = longest(string1.as_str(), string2.as_str());
    }
    //println!("The longest string is {}", result);

    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    {
        let i = ImportantExcerpt {
            part: first_sentence,
        };
    }
    println!("novel: {}", novel);
    println!("first sentence: {}", first_sentence);
}

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
