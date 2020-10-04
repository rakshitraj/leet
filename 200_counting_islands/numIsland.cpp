#include <iostream>
#include <vector>
#include <cassert>

class Solution {
private:
    void dfs(std::vector<std::vector<char>>& grid, int r, int c, int nr, int nc) {
        // nr = grid.size();
        // nc = grid[0].size();

        // Mark root as visited
        grid[r][c] = '0';

        if (r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c, nr, nc);
        if (r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c, nr, nc);
        if (c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1, nr, nc);
        if (c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1, nr, nc);
    }
public:
    int numIsland(std::vector<std::vector<char>> &grid) {
        int nr = grid.size();   // number of rows
        if (!nr) return 0;      // no rows, empty grid
        int nc = grid[0].size(); // number of columns

        int island = 0;

        for (int r=0; r<nr; ++r)
            for (int c=0; c<nc; ++c)
            {
                if (grid[r][c] == '1') {
                    ++island;
                    dfs(grid, r, c, nr, nc);
                }
            }
    return island;
    }
};

void test(Solution obj){
    std::vector<std::vector<char>> grid;
    int count = 0, islands = 0;
    
    //TEST 1
    grid  = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    islands = 1;
    count = obj.numIsland(grid);
    assert(count == islands);
    
    //TEST 2
    grid.clear();
    grid = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    islands = 1;
    count = obj.numIsland(grid);
    assert(count == islands);

    // TEST 3
    grid.clear();
    grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    islands = 3;
    count = obj.numIsland(grid);
    assert(count == islands);
}

int main(){
    Solution obj;
    test(obj);
    return 0;
}