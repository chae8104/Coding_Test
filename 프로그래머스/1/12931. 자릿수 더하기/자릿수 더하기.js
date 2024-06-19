function solution(n)
{
    var answer = 0;
    
    var num = n.toString();
    
    for(var i = 0; i< num.length; i++){
        answer += Number(num[i]);
    }

    return answer;
}