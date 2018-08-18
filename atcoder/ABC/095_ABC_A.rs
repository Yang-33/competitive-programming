fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();

    let ans = 700 + 100*s.chars().filter(|x| *x=='o').count();

    println!("{}",ans);
}
