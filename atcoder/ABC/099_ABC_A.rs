fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input: Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    let base = input[0] % 1000;
    if input[0] / 1000 == 1 {
        println!("ABD");
    } else {
        println!("ABC");
    }
}
