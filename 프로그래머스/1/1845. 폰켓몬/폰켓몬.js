function solution(nums) {
    var answer = 0;
    
    const unique = new Set(nums).size;
    
    const select = nums.length / 2;
    
    return Math.min(select, unique);
}