#include <iostream>

using namespace std;

template <typename Iterator, typename T>
auto find_two_elements_with_sum(Iterator first, Iterator last, T c)->std::pair<bool, std::pair<Iterator, Iterator>>
{
    bool answer = false;
    int foo[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    while(first!=last)
    {
        int Sum = foo[first] + foo[last];

        if(Sum < c)
            first++;
        else if(Sum > c)
            last--;
        else
        {
            answer = true;
            cout << "bool = " << answer << endl;
            cout << "iterators: " << first << " " << last <<endl;
            break;
        }
    }
    cout << "No more found..." <<endl;
//}

}

int main()
{
    int X;
    cin >> X;
    find_two_elements_with_sum(0, 9, X);
    return 0;
}
