fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let input:Vec<String> = s.split_whitespace().map(|x| x.parse::<String>().unwrap()).collect();
    let mut v = input[0].chars().collect::<Vec<char>>();
    v.sort();
    let mut state = 0;
    let ref vv = v.into_iter().collect::<String>();
    if vv == "abc" {state = 1}
    let ans = vec!["No", "Yes"];
    println!("{}", ans[state]);
}
