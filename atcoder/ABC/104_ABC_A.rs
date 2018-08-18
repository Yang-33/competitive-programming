fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input:Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    let strings = vec!["ABC","ARC","AGC"];
    let x = match input[0] {
        0...1199 => 0,
        1200...2799 => 1,
        _ => 2,
    };
    println!("{}",strings[x]);
}
