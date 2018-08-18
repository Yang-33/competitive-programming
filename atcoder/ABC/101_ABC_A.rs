fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();

    let mut ans = 0;
//    for c in s.into_bytes(){
//        if c=='+' as u8{ ans+=1 }
//        else if c=='-' as u8{
//            ans-=1
//        }
//    }
//

    for c in s.trim().chars(){
        if c== '+'{ ans +=1}
            else { ans -=1 }
    }
    println!("{}", ans);
}
