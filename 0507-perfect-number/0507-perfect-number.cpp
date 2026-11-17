class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum =0;
        if(num==1){
            return false;
        }
        else {
            for(int i=1;i<num;i++){
                if(num%i==0){
                    
                    sum=sum+i;
                }
            }
        }
        if (num==sum){
            return true;
        
        }
        else{
            return false;
        }
    }
};