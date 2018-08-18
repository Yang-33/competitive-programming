fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input: Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let mut state = 0;
    let lefta = input[2] - input[0];
    if lefta >= 0 && lefta <= input[1] { state = 1 }

    let ans = vec!["NO", "YES"];
    println!("{}", ans[state]);
}
