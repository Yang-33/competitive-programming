fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}

fn main() {

    let c1:Vec<char> = read::<String>().chars().collect();
    let c2:Vec<char> = read::<String>().chars().collect();
    let c3:Vec<char> = read::<String>().chars().collect();
    let ans = format!("{}{}{}",c1[0],c2[1],c3[2]);
    println!("{}",ans);
}
