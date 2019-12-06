use std::fs::File;
use std::io::{self, prelude::*, BufReader};


fn main() -> io::Result<()> {
    let file = File::open("Input1.txt")?;
    let reader = BufReader::new(file);

    let mut val = 0;
    let mut sum = 0;
    for line in reader.lines() {
        match line {
            Ok(v) => val = v.parse::<u32>().unwrap(),
            Err(e) => println!("Error parsing line: {:?}", e),
        }

        sum += (val / 3) - 2;
    }

    println!("Total: {}", sum);

    Ok(())
}

fn problem1() {
    
}
