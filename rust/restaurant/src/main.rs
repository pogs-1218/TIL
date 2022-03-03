use std::fmt::Result;
//use std::io::Result;  --> error.
use std::io::Result as IoResult;

use restaurant;

fn main() {
  restaurant::eat_at_restaurant();
}
