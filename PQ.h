//
// Created by Laila Nasser ElKoussy 900160812 on 11/30/17.
//

#ifndef ASSIGNMENT_6_PQ_H
#define ASSIGNMENT_6_PQ_H

struct E {
    int g;
    int h;
    int sum;
    int **arr;
};

class PQ
{
public:
    PQ(int **bArray, int n);
    ~PQ();
    void insert(E);	// insert element into heap
    E remove();			// remove & return the top of the heap
    void displayBorad(E b, int n);

private:
    void findIJ(E b, int x, int & iC, int & jC, int n); //find index i and index j of value x in the borad b
    int findH(E b, int n); //find sum of all distances

    E *a;   //Heap array
    int N;	// index of last element in the array
    int itemMin; //Very small value at index 0

    void upheap(int k);
    void downheap(int k);
};


#endif //ASSIGNMENT_6_PQ_H
