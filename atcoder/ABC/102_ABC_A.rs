fn gcd(a: u64, b: u64) -> u64 { if b == 0 { a } else { gcd(b, a % b) } }
fn lcm(a: u64, b: u64) -> u64 { a / gcd(a, b) * b }


fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut input: Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let n = input[0];

    let ans = lcm(n as u64, 2);
    println!("{}", ans);
}
