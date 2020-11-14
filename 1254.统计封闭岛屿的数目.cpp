/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
public:
    using PointXY = std::pair<int, int>;
    using Island = std::vector<PointXY>;

    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        maxRow = grid.size();
        maxCol = grid[0].size();
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[0].size(); ++c){
                if(grid[r][c] == 0 && haveSearch.find({c, r}) == haveSearch.end()){
                    haveSearch.emplace(c, r);
                    record.emplace_back();
                    record.back().emplace_back(c, r);
                    DFS(grid, {c, r}, record.back());
                }
            }
        }

        isClosed.resize(record.size(), true);
        for(int i = 0; i < record.size(); ++i){
            for(int j = 0; j < record[i].size(); ++j){
                auto& jt = record[i][j];
                if(jt.first == 0 || jt.first == maxCol - 1 || jt.second == 0 || jt.second == maxRow - 1){
                    isClosed[i] = false;
                    break;
                }
            }
        }

        int ret = 0;
        for(const auto& it : isClosed){
            if(it) ret++;
        }
        return ret;
    }

private:
    int maxRow, maxCol;
    std::vector<Island> record;
    std::vector<int> isClosed;
    std::set<PointXY> haveSearch;

    void DFS(const vector<vector<int>>& grid, const PointXY& xy, Island& island){
        auto xyNew = xy;
        xyNew.first -= 1;
        if(xyNew.first >= 0 && haveSearch.find(xyNew) == haveSearch.end() && grid[xyNew.second][xyNew.first] == 0){
            haveSearch.insert(xyNew);
            island.push_back(xyNew);
            DFS(grid, xyNew, island);
        }
        xyNew.first += 2;
        if(xyNew.first < maxCol && haveSearch.find(xyNew) == haveSearch.end() && grid[xyNew.second][xyNew.first] == 0){
            haveSearch.insert(xyNew);
            island.push_back(xyNew);
            DFS(grid, xyNew, island);
        }
        xyNew.first -= 1;

        xyNew.second -= 1;
        if(xyNew.second >= 0 && haveSearch.find(xyNew) == haveSearch.end() && grid[xyNew.second][xyNew.first] == 0){
            haveSearch.insert(xyNew);
            island.push_back(xyNew);
            DFS(grid, xyNew, island);
        }
        xyNew.second += 2;
        if(xyNew.second < maxRow && haveSearch.find(xyNew) == haveSearch.end() && grid[xyNew.second][xyNew.first] == 0){
            haveSearch.insert(xyNew);
            island.push_back(xyNew);
            DFS(grid, xyNew, island);
        }
    }
};
// @lc code=end

