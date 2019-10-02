#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int iSize = 0, iSub = 0, iEsize = 0;
bool arr[100][100];
int main(int argc, char const *argv[])
{
    cout << setw(5) << "Starting programm...\n";

    // UNIVERSAL SECTION TOKEN
    cout << "Enter the number of elements in the universel set -> ";
    cin >> iSize;
    cout << "\n";
    string sUniversal[iSize];
    cout << "Now enter your universal elements: \n";
    for(int i = 0; i < iSize; ++i)
        cin >> sUniversal[i];
    sort(sUniversal, sUniversal + iSize);

    // SUBSETS SECTION
    cout << "Enter your number of subsets -> ";
    cin >> iSub;
    cout << "\n";
    for(int i = 0; i < iSize; ++i)
        arr[0][i] = 1;
    for(int i = 0; i < iSub; ++i) {
        iEsize = 0;
        cout << "Enter your subset size -> ";
        cin >> iEsize;
        while(iEsize > iSize) {
            cout << "A*a nt htst3bt -> ";
            cin >> iEsize;
            cout << "\n";
        }
        string sTemp[iEsize];
        cout << "Enter your elements: \n";
        for(int j = 0; j < iEsize; ++j)
            cin >> sTemp[j];
        sort(sTemp, sTemp + iEsize);
        int k, x;
        for(x = 0, k = 0; x < iSize && k < iEsize;)
            if(sTemp[k] != sUniversal[x])
                ++x;
            else
                arr[i+1][x] = 1, ++x, ++k;
        if(k != iEsize) {
            cout << "A*a tany -> there is an element isn't exist in the universal set bro7 omk\n";
            cout << "Enter your fucken subset again\n";
            --i;
            continue;
        }
    }

    // OPERATIONS SECTION
    while(1) {
        string exp = "";
        cout << "/**\nEnter YOUR EXPRESSION seperated by spaces. <<But take care>> \n enter \"^\" for \"intersection\" \n \"+\" for \"union\" \n \"-\" for \"diff\"\n";
        cout << "And your subSet are numbered from 1 to n containing universal as number 0\n";
        int iOne, iTwo;
        char x;
        cin >> iOne >> x >> iTwo;
        switch(x) {
            case '^':
                intersection(iOne, iTow);
                break;
            case '+':
                _union(iOne, iTwo);
                break;
            default:
                difference(iOne, iTow);
        }

    }
    return 0;
}
