fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut  input:Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    input.sort();
    let ans = input[2] - input[0];
    println!("{}",ans);
}
