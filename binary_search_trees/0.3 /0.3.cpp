#include<iostream>
#include<vector>
#include<fstream>
#include<map>

using namespace std;

struct Tree
{
    public:
    int item;
    Tree* left;
    Tree* right;
    bool initialization;
public:

    Tree() : item(0), left(nullptr), right(nullptr), initialization(false) {};

    Tree(int value) : item(value), left(nullptr), right(nullptr), initialization(true) {};

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
    //bool insertByAddress(int value, int parent, int side) //функция возвращает false, если при добавлении вершины нарушаются свойства поискового дерева
    //{
    //    Tree* top = findItem(parent);
    //    //cout << "Parent:" << top->item << "\tChild:" << value << endl;
    //    if (top != nullptr)
    //    {
    //        //cout << "Top: " << top->item << "\t";
    //        if (side == 'L')
    //        {
    //            if (value >= top->item) return false;
    //            top->left = new Tree();
    //            top->left->item = value;
    //            //cout << "Left: " << value <<"\t" << endl;
    //        }
    //        else
    //        {
    //            top->right = new Tree();
    //            top->right->item = value;
    //            if (value < top->item) return false;
    //            //cout << "Right: " << value << "\t" << endl;
    //        }
    //        return true;
    //    }
    //    else
    //    {
    //        //cout << "Parent element does not found" << endl;
    //        return false;
    //    }
    //    
    //}
    bool isEmpty()
    {
        return !initialization;
    }
    const void straigthLeftOrder(ostream& output)
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

        if (value == item && right != nullptr)
        { 
            if (value == right->item)
            {
                //cout << value << endl;
                return right->findItem(value);
            }
        }
        if (value == item)
        {
            return this;
        }
        else if (value < item)
        {
            if (left != nullptr)    return left->findItem(value);
            else                    return nullptr;
        }
        else if (value >= item)
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

   bool isSearch(int Lrange, int Rrange, const Tree* parent = nullptr)
    {
        if (this == nullptr)
        {
            return true;
        }
        bool Lresult = true;
        bool Rresult = true;
        //cout << this->item << endl;
        if (parent != nullptr)
        {
            //cout << "Parent: " << parent->item << "\tChild: " << this->item << "\tLrange: " << Lrange << "\tRrange: " << Rrange << endl;
            if (parent->left == this)
            {
                if (this->item <= Lrange || this->item >= Rrange)   return false;

                if (this->left != nullptr)
                {
                    Lresult = this->left->isSearch(Lrange, this->item, this);

                }
                if (this->right != nullptr)
                {
                    Rresult = this->right->isSearch(this->item, Rrange, this);
                }
                return Lresult && Rresult;
            }
            else if(parent->right == this)
            {
                if (this->item < Lrange || this->item >= Rrange)     return false;

                if (this->left != nullptr)
                {
                    Lresult = this->left->isSearch(Lrange-1, this->item, this);

                }
                if (this->right != nullptr)
                {
                    Rresult = this->right->isSearch(this->item, Rrange, this);
                }
                return Lresult && Rresult;
            }
        }
        else
        {
            if (this->left != nullptr)
            {
                Lresult = this->left->isSearch(Lrange, this->item, this);

            }
            if (this->right != nullptr)
            {
                Rresult = this->right->isSearch(this->item, Rrange, this);
            }
            return Lresult && Rresult; 
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

    void setValue(int value)
    {
        this->item = value;
    }
    
};

struct Top
{
public:
    int value;
    int parentIndex;
    char side; //L - слева, R - справа

    friend istream& operator >> (istream& in, Top& obj)
    {
        in >> obj.value >> obj.parentIndex >> obj.side;
        return in;
    }
    friend ostream& operator << (ostream& out, Top& obj)
    {
        cout << obj.value << "\t" << obj.parentIndex << "\t" << obj.side;
        return out;
    }
};

int main()
{
    ifstream input("bst.in");
    ofstream out("bst.out");
    //ifstream input("input.txt");



    int n; //количество вершин дерева
    int m; //значение вершины

    input >> n;
    input >> m;

    if (n == 1)
    {
        out << "YES";
        return 0;
    }

    vector<Tree*>forest(n + 1);

    Top obj;
    forest[1] = new Tree(m);
    bool result = true;

    for (int i = 2; i < n + 1; i++)
    {
        input >> obj;
        forest[i] = new Tree();
        forest[i]->item = obj.value;

        if (obj.side == 'L')
        {
            forest[obj.parentIndex]->left = new Tree();
            forest[obj.parentIndex]->left = forest[i];
        }
        else
        {
            forest[obj.parentIndex]->right = new Tree();
            forest[obj.parentIndex]->right = forest[i];
        }

        if (obj.side == 'L') {
            if (forest[obj.parentIndex]->left != nullptr)
            {
                result = false;
                break;
                // Левый ребенок уже существует
            }
            forest[obj.parentIndex]->left = forest[i];
        }
        else
        {
            if (forest[obj.parentIndex]->right != nullptr)
            {
                result = false;
                break; // Правый ребенок уже существует
            }
            forest[obj.parentIndex]->right = forest[i];
        }

        if (result)
        {
            Tree* tree = new Tree();
            tree = forest[1];

            result = tree->isSearch(INT_MIN, INT_MAX);
        }

        //tree->straigthLeftOrder(cout);

        if (result == true) out << "YES";
        else       out << "NO";

        return 0;
    }
}