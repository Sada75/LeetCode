class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long int total_cost = 0;
        long long int ne_cost;
        long long int prev_cost;
        for(int i=0;i<s.size();i++){
            int present_index = s[i] - 'a';
            int target_index = t[i] - 'a';
            if(present_index == target_index){
                continue;
            }
            ne_cost = 0;
            prev_cost = 0;
            while(present_index != target_index){
                if(present_index == 25){
                    ne_cost += nextCost[25];
                    present_index = 0;
                }else{
                    ne_cost += nextCost[present_index];
                    present_index++;
                }
            }
            present_index = s[i] - 'a';
            while(present_index != target_index){
                if(present_index == 0){
                    prev_cost += previousCost[0];
                    present_index = 25;
                }else{
                    prev_cost += previousCost[present_index];
                    present_index--;
                }
                
            }
            total_cost += std::min(ne_cost,prev_cost);
            
        }
        return total_cost;
    }
};
