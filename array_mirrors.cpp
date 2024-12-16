#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;


// changes the position according to the direction

void changePos(int &curr_row, int &curr_col, char direction)
{
    switch (direction)
    {
    case 'd':
        curr_row++;
        break;

    case 'u':
        curr_row--;
        break;

    case 'r':
        curr_col++;
        break;

    case 'l':
        curr_col--;
        break;

    default:
        break;
    }
}

// changes the direction based on the mirror

char changeDirection(char prev_direction, char mirror)
{

    if (mirror == ' ')
        return prev_direction;
    else if (mirror == '/')
    {
        if (prev_direction == 'd')
            return 'l';
        else if (prev_direction == 'u')
            return 'r';
        else if (prev_direction == 'l')
            return 'd';
        else if (prev_direction == 'r')
            return 'u';
    }
    else if (mirror == '\\')
    {
        if (prev_direction == 'd')
            return 'r';
        else if (prev_direction == 'u')
            return 'l';
        else if (prev_direction == 'l')
            return 'u';
        else if (prev_direction == 'r')
            return 'd';
    }
}
// checks if the rows and columns are within bounds

bool checkWithinBounds(int curr_row, int curr_col)
{

    int num_rows = mirror_array.size();
    int num_columns = mirror_array[0].size();

    if (curr_row >= num_rows)
        return false;
    if (curr_row < 0)
        return false;
    if (curr_col >= num_columns)
        return false;
    if (curr_col < 0)
        return false;

    return true;
}

// makes the light ray move through the array

char traverse(int &curr_row, int &curr_col, char direction)
{
    char prev_direction = direction;
    char curr_direction;

    // check within bounds checks if the current row and column are within bounds

    while (checkWithinBounds(curr_row, curr_col))
    {
        char mirror = mirror_array[curr_row][curr_col];

        // change the direction based on the mirror

        curr_direction = changeDirection(prev_direction, mirror);

        // change the position based on the direction

        changePos(curr_row, curr_col, curr_direction);

        // for the next iteration

        prev_direction = curr_direction;
    }
    return curr_direction;
}

int main()
{

    vector<vector<char>> mirror_array;

    int curr_row = 0;
    int curr_col = 0;

    // direction give the final direction in which it wa moving

    char direction = traverse(curr_row, curr_col, 'd');

    int final_i = curr_row;
    int final_j = curr_col;

    cout << "The ray exits at " << final_i << ", " << final_j << " moving towards " << direction;
}
