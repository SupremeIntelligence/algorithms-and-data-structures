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

    Tree() : item(0), left(nullptr), right(nullptr), initialization (false) {};

    Tree(int value) : item(value), left(nullptr), right(nullptr), initialization (true) {};

    ~Tree()
    {
        //cout << left << endl;
        //cout << right << endl;
        if (left != nullptr)
        {
            delete left;
            //left = nullptr;
        }
        if (right != nullptr)
        {
            delete right;
           //right = nullptr;
        }

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
    Tree* findItem(int value)
    {
        if (value == item)
        {
            return this;
        }
        else if (value < item)
        {
            if (left != nullptr)    return left->findItem(value);
            else                    return nullptr;
        }
        else if (value > item)
        {
            if (right != nullptr)   return right->findItem(value);
            else                    return nullptr;
        }
        else
        {
            //cout << endl << "There is no element equals " << value << endl;
            return nullptr;
        }

    }

    static Tree* findMinTopOnRight(Tree* top)
    {
                                            // top - вершина, которая заменяет удаляемую вершину
        Tree* parentTop = nullptr;          //родитель вершины, на которую заменяется удаляемая
                                            
        if (top->left == nullptr)            //если топ не имеет слева детей
        {
            return top;
        }
        while (top->left != nullptr)        //двигаемся по левым веткам правого поддерева удаляемого значения. 
        {
            parentTop = top;                
            top = top->left;
        }
        return parentTop;                   
    }

    void copy(Tree* obj)
    {
        this->item = obj->item;
        this->initialization = obj->initialization;

        if (obj->left != nullptr)
        {
            this->left = new Tree;
            this->left->copy(obj->left);
        }
        else
        {
            this->left = nullptr;
        }
        if (obj->right != nullptr)
        {
            this->right = new Tree;
            this->right->copy(obj->right);
        }
        else
        {
            this->right = nullptr;
        }
    }

    void removeTop(int value)
    {
        Tree* top = this;
        Tree* parentTop = nullptr;

        while (top != nullptr && top->item != value)        //пока не найдем элемент или же его нету
        {
            parentTop = top;
            if (value < top->item) top = top->left;
            else top = top->right;
        }

        if (top == nullptr)                                 //элемент не найден
            return;

        if (parentTop == nullptr)                                       //удаляется корень
        {
            if (top->right == nullptr && top->left == nullptr)       //случай, когда есть только корень  //ok
            {
                top = nullptr;
                this->initialization = false;
            }
            else if (top->left != nullptr && top->right == nullptr) //корень имеет только левое поддерево  //ok
            {
                
                this->copy(top->left);
                top = nullptr;
            }
            else if (top->right != nullptr && top->left == nullptr) //корень имеет только правое поддерево  //ok
            {
                this->copy(top->right);
                top = nullptr;
            }
            else                                                    //корень имеет оба поддерева
            {
                Tree* parentNewTop = Tree::findMinTopOnRight(top->right);
                if (parentNewTop->left == nullptr)                  //если родитель заменяющей вершины является самой заменяющей вершиной.
                {
                    parentNewTop->left = top->left;
                    this->copy(parentNewTop);
                    parentNewTop = nullptr;
                }
                else //ok
                {
                    Tree* newRoot = new Tree;
                    newRoot->copy(parentNewTop->left);
                    if (newRoot->right != nullptr)
                    {
                        parentNewTop->left->copy(newRoot->right);
                    }
                    else
                    {
                        parentNewTop->left = nullptr;
                    }
                    newRoot->left = top->left;
                    newRoot->right = top->right;

                    top->right = nullptr;
                    top->left = nullptr;
                    top = nullptr;
                    this->copy(newRoot);
                    newRoot = nullptr;
                }
            }
        }
        else
        {
            if (top->right == nullptr && top->left == nullptr)     //если лист
            {
                if (parentTop->left == top)
                    parentTop->left = nullptr;
                else
                    parentTop->right = nullptr;
            }
            else if (top->left != nullptr && top->right == nullptr)   //если есть левое поддерево
            {
                if (parentTop->left == top)
                    parentTop->left = top->left;
                else
                    parentTop->right = top->left;
                top->left = nullptr;
            }
            else if (top->right != nullptr && top->left == nullptr)    //если есть правое поддерево
            {
                if (parentTop->left == top)
                    parentTop->left = top->right;
                else
                    parentTop->right = top->right;
                top->right = nullptr;
            }
            else                                                       //если есть оба
            {
                Tree* parentNewTop = Tree::findMinTopOnRight(top->right);
                
                if (parentNewTop->left == nullptr)          //данная вершина является самой заменяющей вершиной
                {
                    parentNewTop->left = top->left;
                    top->copy(parentNewTop);
                    parentNewTop = nullptr;
                }
                else
                {
                    Tree* newTop = new Tree;
                    newTop->copy(parentNewTop->left);
                    //cout << parentNewTop->right->item << endl << endl;
                    
                    if (newTop->right != nullptr)
                    {
                        parentNewTop->left->copy(newTop->right);
                    }
                    else
                    {
                        parentNewTop->left = nullptr;
                    }

                    newTop->left = new Tree;
                    newTop->left->copy(top->left);

                    newTop->right = new Tree;
                    newTop->right->copy(top->right);  

                    if (parentTop->right == top)
                    {
                        parentTop->right = newTop;
                    }
                    else
                    {
                        parentTop->left = newTop;
                    }
                    top = nullptr;
                    newTop = nullptr;
                    parentNewTop = nullptr;
                }
            }
        }
    }


    int getValue()
    {
        return this->item;
    }

    bool getInit()
    {
        return initialization;
    }
};

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    vector<int> values;
    int key;
    input >> key;
    //cout << key << endl;
    int value;
    while (input >> value)
    {
        values.push_back(value);
    }

    Tree* tree = new Tree();
    for (int i = 0; i < values.size(); i++)
    {
        tree->insert(values[i]);
    }
    //tree->straigthLeftOrder(cout);
    //cout << endl << endl;
    tree->removeTop(key);

    tree->straigthLeftOrder(output);
    return 0;
}