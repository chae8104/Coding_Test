function solution(sizes) {
    var answer = 0;
    var max_num= 0;
    var min_num= 0;
    var w;
    var h;
    
    for(var i = 0; i< sizes.length; i++){
        w = Math.max(sizes[i][0],sizes[i][1]);
        h = Math.min(sizes[i][0], sizes[i][1]);
        
        max_num = Math.max(max_num, w);
        min_num = Math.max(min_num, h);
    }
    return max_num * min_num;
}