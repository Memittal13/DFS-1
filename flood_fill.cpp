//Time O(n)
//Space O(n)
//Leetcode: yes
//issue seen: none
class Solution {
public:
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};
    void dfs(vector<vector<int>>& image, int r, int c, int color,
             int old_color) {

        image[r][c] = color;
        for (int i = 0; i < 4; i++) {
            int new_r = r + row[i];
            int new_c = c + col[i];

            // check boundaries
            if (new_r < 0 || new_r > image.size() - 1 || new_c < 0 ||
                new_c > image[0].size() - 1) {
                continue;
            }
            if (image[new_r][new_c] == old_color) {
                dfs(image, new_r, new_c, color, old_color);
            }
        }
    }

    void bfs(vector<vector<int>>& image, int r, int c, int color,
             int old_color) {

        queue<pair<int, int>> q;

        image[r][c] = color;
        q.push({r, c});
        while (!q.empty()) {
            int size = q.size();
            while (size) {
                int ro = q.front().first;
                int co = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int new_r = ro + row[i];
                    int new_c = co + col[i];

                    // check boundaries
                    if (new_r < 0 || new_r > image.size() - 1 || new_c < 0 ||
                        new_c > image[0].size() - 1) {
                        continue;
                    }
                    if (image[new_r][new_c] == old_color) {
                        // dfs(image, new_r, new_c, color, old_color);
                        q.push({new_r, new_c});
                        image[new_r][new_c] = color;
                    }
                }
                size--;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int old_color = image[sr][sc];
        if (old_color == color)
            return image;
        // dfs(image, sr, sc, color, old_color);
        bfs(image, sr, sc, color, old_color);
        return image;
    }
};
