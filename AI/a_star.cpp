#include <bits/stdc++.h>

using namespace std;

// define a struct to represent a node in the search tree
struct Node
{
    int x, y;     // coordinates of the node
    int f, g, h;  // f, g, and h values of the node
    Node *parent; // pointer to the parent node

    Node(int x, int y, int f, int g, int h, Node *parent = nullptr)
    {
        this->x = x;
        this->y = y;
        this->f = f;
        this->g = g;
        this->h = h;
        this->parent = parent;
    }

    // define the comparison operator for the priority queue
    bool operator<(const Node &other) const
    {
        return f > other.f;
    }
};

// define a function to calculate the Manhattan distance between two points
int manhattan_distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

// define the A* search function
vector<pair<int, int>> a_star_search(vector<vector<int>> &grid, int start_x, int start_y, int goal_x, int goal_y)
{
    // define the priority queue for the open set
    priority_queue<Node> open;

    // create the start node and add it to the open set
    int h = manhattan_distance(start_x, start_y, goal_x, goal_y);
    Node start_node(start_x, start_y, h, 0, h);
    open.push(start_node);

    // define a 1D array for tracking whether each node has been visited
    vector<bool> visited(grid.size() * grid[0].size(), false);

    // continue searching until the open set is empty
    while (!open.empty())
    {
        // get the node with the lowest f value from the open set
        Node current_node = open.top();
        open.pop();

        // if the current node is the goal, return the path to it
        if (current_node.x == goal_x && current_node.y == goal_y)
        {
            vector<pair<int, int>> path;
            while (current_node.parent != nullptr)
            {
                path.push_back({current_node.x, current_node.y});
                current_node = *current_node.parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // mark the current node as visited
        visited[current_node.x * grid[0].size() + current_node.y] = true;

        // loop over the neighbors of the current node
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                if (dx == 0 && dy == 0)
                    continue; // skip the current node
                int nx = current_node.x + dx;
                int ny = current_node.y + dy;
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == 1 || visited[nx * grid[0].size() + ny])
                {
                    continue; // skip nodes that are out of bounds, obstacles, or already visited
                }
                int cost = dx == 0 || dy == 0 ? 1 : 2; // calculate the cost of moving to the neighbor

                int g = current_node.g + cost; // update the cost of reaching the neighbor

                int h = manhattan_distance(nx, ny, goal_x, goal_y); // calculate the heuristic cost to the goal

                Node neighbor(nx, ny, g + h, g, h, &current_node); // create the neighbor node

                open.push(neighbor); // add the neighbor to the open set
            }
        }
    }

    // if the goal is not reachable, return an empty path
    return vector<pair<int, int>>();
}

// define a helper function to print the path
void print_path(const vector<pair<int, int>> &path)
{
    if (path.empty())
    {
        cout << "No path found." << endl;
        return;
    }
    cout << "Path: ";
    for (const auto &p : path)
    {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

int main()
{
    // create a grid with obstacles
    vector<vector<int>> grid =
        {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 1, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0}};

    int start_x = 0, start_y = 0;
    int goal_x = 4, goal_y = 4;

    // find the path using A* search
    vector<pair<int, int>> path = a_star_search(grid, start_x, start_y, goal_x, goal_y);

    // print the path
    print_path(path);

    return 0;
}
