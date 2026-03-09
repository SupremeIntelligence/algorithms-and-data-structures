#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<set>

using namespace std;

struct Tree
{
private:
    int item;
    Tree* left;
    Tree* right;
    int height;
    bool initialization;
public:

    Tree() : item(0), left(nullptr), right(nullptr), initialization(false), height(0) {};

    Tree(int value) : item(value), left(nullptr), right(nullptr), initialization(true), height(0) {};

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

    int getValue()
    {
        return this->item;
    }

    bool getInit()
    {
        return initialization;
    }

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
    void reversedLeftOrder(ostream& output)
    {
        if (!this->isEmpty())
        {
            if (left != nullptr)     left->straigthLeftOrder(output);
            if (right != nullptr)    right->straigthLeftOrder(output);
            output << item << endl;
        }
    }

    void setHeights()
    {
        if (!this->isEmpty())
        {
            if (left != nullptr)     left->setHeights();
            if (right != nullptr)    right->setHeights();
            if (left != nullptr && right != nullptr)
            {
                this->height = max(left->height, right->height) + 1;
            }
            else if (left != nullptr)
            {
                this->height = left->height + 1;
            }
            else if (right != nullptr)
            {
                this->height = right->height + 1;
            }
            //cout << "Top, height "<<item << "\t" << height << endl;
        }
    }

    void findRootOfGreatestHalfPath(vector<pair<Tree*, int>>& roots)        //если не влезу по времени, сделаю метод Int и буду помещать значения максимумов в вектор, передав его по ссылке
    {
        if (!this->isEmpty())
        {
            int maximum = 0;
 
            if (left != nullptr)
            {
                maximum = maximum + left->height + 1;
                left->findRootOfGreatestHalfPath(roots);
            }
            if (right != nullptr)
            {
                maximum = maximum + right->height + 1;
                right->findRootOfGreatestHalfPath(roots);
            }
            if (maximum != 0)                       //поправить
            {
                //cout << item << "\t" << maximum << endl;
                roots.push_back({ this, maximum });
            }
            
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

    //void pathTracing (set<)

    static int findSecondPathTop(vector<Tree*>& maxRoots)
    {
        int secondTopValue;
        Tree* top;
        Tree* parentTop;
        //Tree* firstMin;
        /*
        if (maxRoots.size() == 1) 
        {
            if (maxRoots[0]->left != nullptr)
            {
                parentTop = maxRoots[0];
                top = maxRoots[0]->left;
                while (top->right != nullptr || top->left != nullptr)
                {
                    if (top->left != nullptr && top->right == nullptr)
                    {
                        parentTop = top;
                        top = top->left;
                    }
                    else if (top->left == nullptr && top->right != nullptr)
                    {
                        parentTop = top;
                        top = top->right;
                    }
                    else
                    {
                        if (top->left->height >= top->right->height)
                        {
                            parentTop = top;
                            top = top->left;
                        }
                        else
                        {
                            parentTop = top;
                            top = top->right;
                        }
                    }
                }
                secondTopValue = parentTop->item;
                return secondTopValue;
            }
            else
            {
                top = maxRoots[0]->right;

                if (top->left != nullptr && top->right != nullptr && top->left->height > top->right->height)
                {
                    top = Tree::findMinTopOnRight(maxRoots[0]->right);
                    if (top->left != nullptr)
                    {
                        top = top->left;
                    }
                }
                 else if (top->left != nullptr && top->right == nullptr)
                {
                    top = Tree::findMinTopOnRight(maxRoots[0]->right);
                    if (top->left != nullptr)
                    {
                        top = top->left;
                    }
                }
                secondTopValue = top->item;
                return secondTopValue;
            }

        }
        */
        set<int>minTops;
        
        int j = 0;
        for (int i = maxRoots.size() - 1; i >= 0; i--)
        {
            if (maxRoots[i]->left != nullptr)
            {
                parentTop = maxRoots[i];
                top = maxRoots[i]->left;
                while (top->right != nullptr || top->left != nullptr)
                {

                    if (parentTop->left == top)
                    {
                        minTops.insert(top->item);
                    }
                    if (top->left != nullptr && top->right == nullptr)
                    {
                        parentTop = top;
                        top = top->left;
                        
                    }
                    else if (top->left == nullptr && top->right != nullptr)
                    {
                        minTops.insert(top->item);
                        parentTop = top;
                        top = top->right;
                    }
                    else
                    {
                        if (top->left->height >= top->right->height)
                        {
                            parentTop = top;
                            top = top->left;
                        }
                        else
                        {
                            minTops.insert(top->item);
                            parentTop = top;
                            top = top->right;
                        }
                    }
                }
                secondTopValue = top->item;

                minTops.insert(secondTopValue);
                minTops.insert(parentTop->item);
                minTops.insert(maxRoots[i]->item);
            }
            else
            {
                minTops.insert(maxRoots[i]->item);
                top = maxRoots[i]->right;

                while (top->right != nullptr || top->left != nullptr)
                {
                    if (top->left != nullptr && top->right != nullptr && top->left->height >= top->right->height) //путь ведет влево
                    {
                        top = top->left;
                    }
                    else if (top->left != nullptr && top->right != nullptr) //путь ведет вправо
                    {
                        top = top->right;
                    }
                    else if (top->left != nullptr && top->right == nullptr)
                    {
                        top = top->left;
                    }
                    else
                    {
                        minTops.insert(top->item);
                        top = top->right;
                    }
                }
                secondTopValue = top->item;
                minTops.insert(secondTopValue);



                ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                //if (top->left != nullptr && top->right != nullptr && top->left->height >= top->right->height)
                //{
                //    top = Tree::findMinTopOnRight(maxRoots[i]->right);
                //    
                //    if (top->left != nullptr)
                //    {
                //        top = top->left;
                //    }
                //}
                //else if (top->left != nullptr && top->right == nullptr)
                //{
                //    top = Tree::findMinTopOnRight(maxRoots[i]->right);
                //    if (top->left != nullptr)
                //    {
                //        top = top->left;
                //    }
                //}
                //else
                //{
                //    //top->
                //}
                secondTopValue = top->item;
                minTops.insert(secondTopValue);
                //minTops.insert(maxRoots[i]->item);
            }
            
            //cout << secondTopValue << "\t" << endl;
        }

        //sort(minTops.begin(), minTops.end()); //!!!!
        /*for (int x : minTops)
        {
            cout << x << " '" << endl;
        }*/

        if (minTops.size() > 1)
        {
            //return minTops[1];
            auto itr = minTops.begin();
            ++itr;
            return *itr;
        }
    }
    
};

int main()
{
    ifstream input("in.txt");
    ofstream output("out.txt");

    vector<int> values;
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

    //tree->reversedLeftOrder(cout);
    
    //cout << endl << endl;

    tree->setHeights();
    vector<pair<Tree*, int>>roots;          //вершина и длина полупути

    tree->findRootOfGreatestHalfPath(roots);

    auto maxRootIt = max_element(roots.begin(), roots.end(), [](const pair<Tree*, int>& x, const pair<Tree*, int>& y) {
                                                                       return x.second < y.second; });
    pair<Tree*, int> maxRoot = *maxRootIt;  //нашли элемент с максимальным значением
    //cout << endl << maxRoot.second << endl << endl;;

    //cout << endl << endl;

    vector<Tree*> maxRoots;
    for (int i = 0; i < roots.size(); i++)      //получаем массив пар с корнями
    {
        if (maxRoot.second == roots[i].second)      
        {
            maxRoots.push_back(roots[i].first);
           //cout << "Root, length "<< roots[i].first->getValue() << "\t" << roots[i].second << endl;
        }
    }

    //cout << endl << endl;
    int key = Tree::findSecondPathTop(maxRoots);
    //cout << "Removing top: " << key << endl;
    tree->removeTop(key);
    tree->straigthLeftOrder(output);
    return 0;
}