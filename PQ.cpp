//
// Created by Laila Nasser ElKoussy 900160812 on 11/30/17.
//

#include "PQ.h"
#include "iostream"

using namespace std;

//Constructor
PQ::PQ(int **bArray, int n)
{   a = new E[10];
    N = 0;

    itemMin = -32767; // Minimum Heap
    a[0].sum = itemMin ;

    for (int i =0; i<n; i++) {
        int count = 1;
        for (int j = 0; j < n; j++) {
            goal[i][j] = count;
            count++;
        }
    }
        goal[n-1][n-1] = 0;

    E initial;
    //Allocate memory for board 2D array
    initial.arr = new int *[n];
    for (int i = 0; i < n; i++)
        initial.arr[i] = new int[n];

    //Prepare initial element to be inserted in the heap
    //Copy received array to initial element array
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            initial.arr[i][j] = bArray[i][j];

    initial.g   = 0;
    initial.h   = findH(initial, n);
    initial.sum =  initial.h + initial.g;
    initial.size = n;

    cout << endl << "Initial" << endl;
    displayBoard(initial, n);

    insert(initial);
}

//Destructor
PQ::~PQ()
{
    delete []a;
};

// Insert element (v) in the heap and adjust heap
void PQ::insert(E v)
{
    N++;
    a[N] = v ;
    upheap(N) ;
}
void PQ::upheap(int k)
{
    E v = a[k] ;
    while ( a[k/2].sum >= v.sum)
    { a[k] = a[k/2] ;   k = k/2 ; }
    a[k] = v ;
}

// remove and return top of the heap, then adjust heap
E PQ::remove()
{
    E v = a[1] ;
    a[1] = a[N--] ; downheap(1) ;
    return v;
}
void PQ::downheap(int k)
{
    int j = 2 * k ;     E v = a[k] ;
    while (j <= N) {
        if ((j < N) && (a[j].sum > a[j+1].sum)) j++ ;
        if ( v.sum <= a[j].sum ) break;
        a[j/2] = a[j] ;     j *= 2 ;   }
    a[j/2] = v ;
}

//Display a board
void PQ::displayBoard(E b, int n)
{
    cout << "========" << endl << "g " << " " << "h " << " " << "c " << endl;
    cout << b.g << "  " << b.h << "  " << b.sum << endl << "--------" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << b.arr[i][j] << "  ";
        cout << endl;
    }
    cout << "=========" << endl << endl;
}

//find index i and index j of value x in the board b
void PQ::findIJ(E b, int x, int & i, int & j, int n)
{
    i = 0; j = 0;
    int r, c;
    for(r = 0; r < n; r++)
    {
        for(c = 0; c < n; c++)
        {
            if(b.arr[r][c] == x)
            {
                i = r;
                j = c;
            }
        }
    }
}

//find sum of all distances
int PQ::findH(E b, int n)
{
    int difX, difY;
    int s = 0;
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            //generating values from 1 up to n*n: 1 2 3 4 5 ...
            int value = j + n*i + 1;
            if(value == n*n) //ignore value n*n
                break;

            int iC = 0, jC = 0; //i and j position of current value
            findIJ(b, value, iC, jC, n); //find index i and index j of current value (its current position)

            int iG = (value - 1)/n;   //Goal i position
            int jG = (value - 1)%n;   //Goal j position

            difX = abs(iC - iG); //find horizontal distance from its goal position
            difY = abs(jC - jG); //find vertical distance

            s = s + difX + difY;
        }
    }
    return s;
}

bool PQ::E::sameAsPredecessor() {
    bool temp = true;
    for (int i = 0 ; (i<size) && temp; i++)
        for (int j = 0; (j<size) && temp; j++){
            if (arr[i][j] != predecessor->arr[i][j])
                temp = false ;
        }

    return temp;
}
