//Time O(m x n)
//Space O(mxn)
//Leetcode: yes
//issue seen: none

class Solution {
public:
    int row[4] = {0, 0, 1, -1};
    int col[4] = {-1, 1, 0, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    mat[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            int size = q.size();
            while(size) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int new_r = r + row[i];
                    int new_c = c + col[i];
                    // check boundaries
                    if (new_r < 0 || new_r > mat.size() - 1 || new_c < 0 ||
                        new_c > mat[0].size() - 1) {
                        continue;
                    }
                    if (mat[new_r][new_c] == -1) {
                        mat[new_r][new_c] = mat[r][c] + 1;
                        q.push({new_r, new_c});
                    }
                }
                size--;
            }
        }
        return mat;
    }
};
