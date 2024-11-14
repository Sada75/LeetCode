class Solution {
public:

    int no_of_days(vector<int>& weights,int mid){
        int count = 1;
        int weight = 0;
        for(int i=0;i<weights.size();i++){
            if(weight + weights[i]> mid){
                weight = weights[i];
                count++;
            }else{
                weight += weights[i];
            }
            
        }
        return count;
    
    }



    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int max = weights[0];
        for(int a:weights){
            sum += a;
            max = std::max(max,a);
        }
        int ans;
        int left = max;
        int right = sum;
        while(left <= right){
            int mid = (left + right)/2;
            int count = no_of_days(weights,mid);
            // if(count == days){
            //     right = mid - 1;
            // }
            if(count > days){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};
