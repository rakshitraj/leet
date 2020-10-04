class Solution:
    def dfs(self, grid: List[List[str]], r: int, c: int, nr: int, nc: int):
        # mark cell as visited
        grid[r][c] = '0'

        if r-1 >=0 and grid[r-1][c] is '1': self.dfs(grid, r-1, c, nr, nc) 
        if r+1 <nr and grid[r+1][c] is '1': self.dfs(grid, r+1, c, nr, nc)
        if c-1 >=0 and grid[r][c-1] is '1': self.dfs(grid, r, c-1, nr, nc) 
        if c+1 <nc and grid[r][c+1] is '1': self.dfs(grid, r, c+1, nr, nc)

    def numIslands(self, grid: List[List[str]]) -> int:
        nr = len(grid)
        if nr == 0: return 0 
        nc = len(grid[0])

        islands = 0

        for r in range(nr):
            for c in range (nc):
                if (grid[r][c] is '1'):
                    islands += 1
                    self.dfs(grid, r, c, nr, nc)
        return islands