
#include <iostream>
#include<fstream>
#include<vector>
#include<queue>
#include"timer.h"

using namespace std;

class NTree
{
public:
    NTree* left;
    NTree* right;
    long long item;
    long long depth;



    NTree() : left(nullptr), right(nullptr), /*init(false),*/ depth(0) /*cipher(0)*/ {};
    NTree(long long value) : left(nullptr), right(nullptr), item(value), /*init(true),*/ depth(0) /*cipher(0)*/ {};



    void SL_Order(long long& length,long long depth_val = 0)
    {
        this->depth = depth_val;
        cout << "Top: " << this->item << "\tDepth: " << this->depth /* << "\tCipher: " << bitset<10>(this->cipher)*/ << endl;

        if (right == nullptr && left == nullptr)
        {
            //cout << "\tLEAF"<<endl;
            length += this->item * this->depth;
        }
        if (left != nullptr)
        {
            left->SL_Order(length, this->depth + 1);
        }
        if (right != nullptr)
        {
            right->SL_Order(length, this->depth + 1);
        }
    }
};


struct GreaterNTree
{
    bool operator()(const NTree* x, const NTree* y)
    {
        return x->item > y->item;
    }
};

int main()
{
   ScopedTimer timer("main");

    ifstream input("huffman.in");
    ofstream output("huffman.out");
    //random_device rd;
    //mt19937 gen(rd());
    //uniform_int_distribution<> dis(1, 1000000000); //  1  1 
    //output << 2500000<<endl;
    //long long prev = dis(gen);  //  
    //output << prev << "\n";      //   

    ////   
    //for (int i = 1; i < 2500000; ++i) {
    //    long long next = dis(gen);

    //    // ,       
    //    if (next < prev) {
    //        next = prev;
    //    }

    //    output << next << endl; //    
    //    prev = next;            
    //}

    //output.close();
    long long n;
    input >> n;
    long long item;

    std::priority_queue < NTree*, vector<NTree*>, GreaterNTree> minHeap;
    for (int i = 0; i < n; i++)
    {
        input >> item;
        minHeap.push(new NTree (item));
    }
    while (minHeap.size() > 1)
    {
        NTree* TR1 = minHeap.top();
        minHeap.pop();
        NTree* TR2 = minHeap.top();
        minHeap.pop();

        NTree* parent = new NTree(TR1->item + TR2->item);
        parent->left = TR1;
        parent->right = TR2;
        minHeap.push(parent);

        cout << "Parent item: " << parent->item << "\t Left: " << parent->left->item << "\t Right: " << parent->right->item << endl;
    }
    NTree* tree = minHeap.top();
    cout << endl << endl << tree->item << " - root" << endl;

    long long length = 0;
    tree->SL_Order(length);
    output << length;
    cout << endl << endl << length << endl;
    
}