fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input: Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    let mut state = 1;
    if input[0] >8 || input[1]> 8{
        state = 0;
    }
    let ans = vec![":(","Yay!"];
    println!("{}", ans[state]);
}
