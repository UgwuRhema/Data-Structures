use std::io::{self, Write};

struct Node
{
    val: i64,
    next: Option<Box<Node>>,
}

impl Node
{
    fn new(val: i64) -> Self {
        Self {
            val: val,
            next: None,
        }
    }
}

fn main()
{
    println!("Lists");
    let head : Box<Node> = Box::new(Node::new(5));
}
