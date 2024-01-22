class Solution {
public:
    int reverse(int x) {
       
        long r=0;      // decleare r 
        while(x){
         r=r*10+x%10; // find remainder and add its to r
         x=x/10;     // Update the value of x
        }
        if(r>int_max || r<int_min) return 0; // check range if r is outside the range then return 0  
        return int(r);
        
    }
};