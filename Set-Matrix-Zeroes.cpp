class Solution {
public:
    

    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size(); int n = matrix[0].size();
        unordered_map<int, int> map_i;
        unordered_map<int, int> map_j;
       for(int i = 0; i < m; ++i){
           for(int j = 0; j < n; ++j){
               if(matrix[i][j] == 0){
                   map_i[i]++;
                   map_j[j]++;
               } 
           }
        }
       

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(map_i.count(i) > 0 || map_j.count(j) > 0){
                matrix[i][j] = 0;
            }
        }
    }

      
    }
};
