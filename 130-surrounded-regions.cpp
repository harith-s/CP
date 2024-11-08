// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and
// none of the region cells are on the edge of the board.
// A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;

// template <typename T>
// void swap(T &a, T &b)
// {
//     T temp = a;
//     a = b;
//     b = temp;
// }
struct Element
{
    pair<int, int> node;
    pair<int, int> parent;
    int size;

    Element()
    {
        node = {-1, -1};
        parent = node;
        size = 0;
    }

    Element(pair<int, int> n)
    {
        node = n;
        parent = n;
        size = 1;
    }
};

class UnionFind
{
    vector<vector<Element *>> elements;
    set<pair<int, int>> Rep;

public:
    UnionFind(int num_rows, int num_cols)
    {
        elements = vector<vector<Element *>>(num_rows, vector<Element *>(num_cols));

        for (int row = 0; row < num_rows; row++)
        {
            for (int col = 0; col < num_cols; col++)
            {
                elements[row][col] = new Element({row, col});
                Rep.insert({row, col});
            }
        }
    }

    pair<int, int> findParent(pair<int, int> index)
    {
        int row = index.first;
        int col = index.second;

        if (index != elements[row][col]->parent)
            elements[row][col]->parent = findParent(elements[row][col]->parent);
        return elements[row][col]->parent;
    }

    void combine(pair<int, int> x, pair<int, int> y)
    {
        auto Px = findParent(x);
        auto Py = findParent(y);

        if (Px == Py)
            return;
        auto xPtr = elements[Px.first][Px.second];
        auto yPtr = elements[Px.first][Px.second];

        if (xPtr->size < yPtr->size)
        {
            swap(xPtr, yPtr);
        }

        yPtr->parent = xPtr->parent;

        xPtr->size += yPtr->size;

        Rep.erase(Py);
    }

    set<pair<int, int>> getRep()
    {
        return Rep;
    }
};

set<pair<int, int>> bfs(pair<int, int> node)
{

}
void solve(vector<vector<char>> &board)
{
    int num_rows = board.size();
    int num_cols = board[0].size();

    UnionFind obj(num_rows, num_cols);

    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_cols; col++)
        {
            if (board[row][col] == board[row][col + 1] && col + 1 < num_cols)
                obj.combine({row, col}, {row, col + 1});
            if (board[row][col] == board[row + 1][col] && row + 1 < num_rows)
                obj.combine({row, col}, {row + 1, col});
        }
    }

    auto Rep = obj.getRep();

    for (auto rep : Rep)
    {
        auto nodes = bfs(rep);
        
    }
}
int main()
{
    return 0;
}
