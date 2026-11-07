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

    fn printlist(&self) {
        let mut curr = Some(self);
        while let Some(node) = curr {
            print!("{}->", node.val);
            curr = node.next.as_deref();
        }
        println!("NULL");
    }
}

fn main()
{
    let mut head: Box<Node> = Box::new(Node::new(5));
    let mut one: Option<Box<Node>> = Some(Box::new(Node::new(7)));
    let two: Option<Box<Node>> = Some(Box::new(Node::new(12)));
    one.as_mut().unwrap().next = two;
    head.next = one;
    head.printlist();
}
