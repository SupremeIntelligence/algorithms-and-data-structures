#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

struct Tree
{
private:
    int item;
    Tree* left;
    Tree* right;
    bool initialization;
public:
    Tree() : item(0), left(nullptr), right(nullptr), initialization(false) {};

    Tree(int value) : item(value), left(nullptr), right(nullptr), initialization(true) {};

    ~Tree()
    {
        delete left;
        delete right;
    };

    void insert(int value)
    {
        if (!initialization)
        {
            item = value;
            initialization = true;
        }
        else
        {
            if (value < item)
            {
                if (left == nullptr)        left = new Tree(value);
                else                        left->insert(value);

                //cout << "Left: " << value<<endl;
            }
            else if (value > item)
            {
                if (right == nullptr)         right = new Tree(value);
                else                          right->insert(value);
                //cout << "Right: " << value << endl;
            }
        }
    }

    bool isEmpty()
    {
        return !initialization;
    }
    void straigthLeftOrder(ostream& output)
    {
        if (!this->isEmpty())
        {
            output << item << endl;
            if (left != nullptr)     left->straigthLeftOrder(output);
            if (right != nullptr)    right->straigthLeftOrder(output);

        }
    }

};

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    vector<int> values;

    int value;
    while (input >> value)
    {
        values.push_back(value);
    }

    Tree tree;
    for (int i = 0; i < values.size(); i++)
    {
        tree.insert(values[i]);
    }

    tree.straigthLeftOrder(output);

    return 0;
}