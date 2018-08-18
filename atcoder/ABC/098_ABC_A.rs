fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input: Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    let A = input[0];let B = input[1];
//    let mut ans=std::cmp::max(A+B,A-B);
//    ans =std::cmp::max(ans, A*B);
    let xs = [A+B,A-B,A*B];
    let ans = xs.iter().max().unwrap();
    println!("{}",ans);
}
