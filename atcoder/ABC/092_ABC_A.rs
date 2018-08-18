fn read<T: std::str::FromStr>() -> T {
    use std::io::*;
    let stdin = stdin();
    let mut buf = String::new();
    stdin.lock().read_line(&mut buf);
    buf.trim().parse().ok().unwrap()
}

fn main() {
    let a:i32 = read(); let b = read(); let c:i32 = read(); let d =read();
    let ans = std::cmp::min(a,b) + std::cmp::min(c,d);
    println!("{}", ans);
}
