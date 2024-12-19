
class Node
{
public:
    Node *child[2];
    bool isEnd;
};

Node *newNode()
{
    Node *temp = new Node();
    temp->child[1] = temp->child[0] = NULL;
    temp->isEnd = 0;
    return temp;
}

bool insert(Node **root, int M[MAX][MAX], int row, int col, int COL)
{
    if ((*root) == NULL)
        (*root) = newNode();

    if (col < COL)
    {
        insert(&((*root)->child[M[row][col]]), M, row, col + 1, COL);
    }
    else
    {
        if (!(*root)->isEnd)
            return (*root)->isEnd = 1;
        return 0;
    }
}

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    Node *root = newNode();
    int i;
    vector<vector<int>> ans;

    for (i = 0; i < row; i++)
    {
        if (insert(&root, M, i, 0, col))
        {
            // insert in ans vector
            vector<int> temp;
            for (int j = 0; j < col; j++)
                temp.push_back(M[i][j]);
            ans.push_back(temp);
        }
    }

    return ans;
}