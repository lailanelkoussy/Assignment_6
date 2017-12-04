//
// Created by Laila Nasser ElKoussy 900160812 on 11/30/17.
//

#ifndef ASSIGNMENT_6_PQ_H
#define ASSIGNMENT_6_PQ_H


class PQ
{
public:
    PQ(int **bArray, int n);
    ~PQ();


private:

    struct E {
        int g; // cost of reaching this node
        int h; // cost of reaching model node
        int sum; //total cost
        E* predecessor; //pointer to predecessor search node
        int **arr; // board
        int size; //size of the arrays //TODO (how to know the fucking size, it's only passed on to the )
        bool sameAsPredecessor(); //checks if same as predecessor to avoid repetition in insertions
    };

    void findIJ(E b, int x, int & iC, int & jC, int n); //find index i and index j of value x in the board b
    int findH(E b, int n); //find sum of all distances
    void insert(E);	// insert element into heap
    E remove();			// remove & return the top of the heap
    void displayBoard(E b, int n);
    E *a;   //Heap array
    int N;	// index of last element in the array
    int itemMin; //Very small value at index 0
    int **goal; //the goal board to compare with

    void upheap(int k);
    void downheap(int k);

};


#endif //ASSIGNMENT_6_PQ_H
