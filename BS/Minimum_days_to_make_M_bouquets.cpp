class Solution {
public:

    bool adj_counter(vector<int>& bloomDay,int m,int k,int mid){
        int m_count = 0;
        int k_count = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                k_count++;
                if(k_count == k){
                    m_count++;
                    k_count = 0;
                    if(m_count >= m){
                        return true;
                    }
                }
                
            }else{
                k_count = 0;
            }
        }
        return m_count >= m;
    }



    int minDays(vector<int>& bloomDay, int m, int k) {
        int max = bloomDay[0];
        for(int i=0;i<bloomDay.size();i++){
            max = std::max(max,bloomDay[i]);
        }
        int left = 1;
        int right = max;
        long long int req_flowers = static_cast<long long>(m)*k;
        int ans = -1;
        while(left <= right){
            int mid = (left + right)/2;
            bool a = adj_counter(bloomDay,m,k,mid);
            if(a){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
