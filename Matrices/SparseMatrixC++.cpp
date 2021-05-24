#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Element *ele; // Array of elements woh matrix 3 row wala diagram in notes
public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~Sparse()
    {
        delete[] ele;
    }
    void read()
    {
        cout << "Enter the Non-Zero elements\n";
        for (int i = 0; i < num; i++)
        {
            cin >> ele[i].i >> ele[i].j >> ele[i].x;
        }
    }
    int k=0;// For keeping the tracks of non-zero elements.
    void Display()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ele[k].i==i && ele[k].j==j)
                {
                    cout <<ele[k++].x<<" ";
                }
                else
                {
                    cout <<"0 ";
                }
            }
            cout <<endl;
        }
    }
};

int main()
{
    Sparse s1(5,5,5);
    s1.read();
    s1.Display();
    s1.~Sparse();
    return 0;
}
