fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input: Vec<i32> = s.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    let mut state =0;
    if (input[0]- input[2]).abs() <= input[3]{ state =1 }
    if (input[0]- input[1]).abs() <= input[3] &&
        (input[2]- input[1]).abs() <= input[3] { state =1 }

    let ans = vec!["No","Yes"];
    println!("{}",ans[state]);
}
