fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input: Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let ans = if input[0] <= input[1]{ input[0]} else { input[0] -1 };
    println!("{}",ans);
}
