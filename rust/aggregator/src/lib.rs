use std::fmt::{Debug, Display};

pub trait Summary {
  fn summarize_author(&self) -> String;

  fn summarize(&self) -> String {
    format!("Read more {}...", self.summarize_author()) // default implementation
  }
}

pub struct NewsArticle {
  pub headline: String,
  pub location: String,
  pub author: String,
  pub content: String,
}

impl Summary for NewsArticle {
  fn summarize_author(&self) -> String {
    format!("{}, by {} ({})", self.headline, self.author, self.location)
  }
}

pub struct Tweet {
  pub username: String,
  pub content: String,
  pub reply: bool,
  pub retweet: bool,
}

impl Summary for Tweet {
  fn summarize_author(&self) -> String {
    format!("@{}", self.username)
  }
}

// pub fn notify(item: &impl Summary) {
//   println!("Breaking new! {}", item.summarize());
// }

// trait bound
pub fn notify<T: Summary>(item: &T) {
  println!("Breaking new! {}", item.summarize());
}

// pub fn notify(item1: &impl Summary, item2: &impl Summary) is same as
// pub fn notify<T: Summary>(item1: &T, item2: &T)

// Use more than on trait bound
// pub fn notify<T: Summary + Display>(item: &T)

// Specifying trait bounds inside a where clause
pub fn some_function<T, U>(t: &T, u: &U) -> i32
where
  T: Display + Clone,
  U: Clone + Debug,
{
  1
}

// Can only use impl Trait if you’re returning a single type now!!
pub fn returns_summarizable() -> impl Summary {
  Tweet {
    username: String::from("horse_ebooks"),
    content: String::from("of course, as you probably already know, people"),
    reply: false,
    retweet: false,
  }
}
