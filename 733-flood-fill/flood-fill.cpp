class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& image, int sr, int sc, int startingNode, int color){
        if(sr < 0 || sc < 0 || sr >= n || sc >= m) 
            return;

            if(image[sr][sc]!= startingNode)
            return;
            
        
        image[sr][sc] = color;
        dfs(image, sr+1, sc, startingNode, color);
        dfs(image, sr-1, sc, startingNode, color);
        dfs(image, sr, sc+1, startingNode, color);
        dfs(image, sr, sc-1, startingNode, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int startingNode = image[sr][sc];
        n = image.size();
        m = image[0].size();
        if (startingNode == color)
        return image;
        dfs(image, sr, sc, startingNode, color);
        return image;
    }
 
};