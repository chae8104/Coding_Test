function solution(n) {
    var answer = [];
    var num = n.toString().split('').reverse();
    
    for(var i = 0; i < num.length; i++){
        answer.push(parseInt(num[i]));
    }
    return answer;
}
