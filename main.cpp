// Clientprogram.cpp

#include <iostream>
#include <fstream>
#include "AVLTree.h"

using namespace std;

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile);

// Open the file to be written in from in the main program
// pre: outfile is not open to a file
// post: outfile can be used to read from a file
// usage: openOutputFile(output);
void openOutputFile(ofstream& outfile);

void testHasNoPivot(ifstream& infile, ofstream& outfile);
void testIsAddedToShortSide(ifstream& infile, ofstream& outfile);
void testIsSingleRotateLeft(ifstream& infile, ofstream& outfile);
void testIsSingleRotateRight(ifstream& infile, ofstream& outfile);
void testIsDoubleRotateLeftRight(ifstream& infile, ofstream& outfile);
void testIsDoubleRotateRightLeft(ifstream& infile, ofstream& outfile);
void displayConditionsAndInsert(ifstream& infile, ofstream& outfile, AVLTree& mytree, Item& myItem);

int main()
{
    ifstream infile;
    ofstream outfile;
    openInputFile(infile);
    openOutputFile(outfile);
    
    // remove this
    for (int i = 0; i <= 80; i++)
    {
        outfile << "*";
    }
    outfile << endl;
    // remove this ^
    
    
    testHasNoPivot(infile, outfile);
    testIsAddedToShortSide(infile, outfile);
    testIsSingleRotateLeft(infile, outfile);
    testIsSingleRotateRight(infile, outfile);
    // testIsDoubleRotateLeftRight(infile, outfile);
    // testIsDoubleRotateRightLeft(infile, outfile);
    
    // remove this
    for (int i = 0; i <= 80; i++)
    {
        outfile << "*";
    }
    outfile << endl;
    // remove this ^
    
    infile.close();
    outfile.close();
}

void testHasNoPivot(ifstream& infile, ofstream& outfile) // 100's
{
    AVLTree noPivot;
    Item anItem;
    outfile << "\t\tCASE OF NO PIVOT" << endl;
    
    outfile << "\nTest 1: CASE OF EMPTY TREE:" << endl << endl;
    displayConditionsAndInsert(infile, outfile, noPivot, anItem);
    
    
    outfile << "\nTest 2: CASE OF FULL TREE OF HEIGHT 2" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        noPivot.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, noPivot, anItem);
    
    outfile << "\nTest 3: CASE OF FULL TREE OF HEIGHT 3" << endl;
    for (int i = 0; i < 3; i++)
    {
        infile >> anItem;
        noPivot.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, noPivot, anItem);
    outfile << endl;
}

void testIsAddedToShortSide(ifstream& infile, ofstream& outfile) // 200's
{
    AVLTree shortSide;
    Item anItem;
    
    outfile << "\n\t\tCASE OF IS ADDED TO SHORT SIDE" << endl;
    outfile << "\nTest 1: TREE HEIGHT 2 AND LEFT SIDE INSERT" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        shortSide.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);
    
    outfile << "\nTest 2: TREE HEIGHT 3, LEFT RIGHT INSERT" << endl;
    infile >> anItem;
    shortSide.insert(anItem);
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);
    
    outfile << "\nTest 3: TREE HEIGHT 3, RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);
    
    outfile << "\nTest 4: TREE HEIGHT 3, RIGHT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, shortSide, anItem);
}

void testIsSingleRotateLeft(ifstream& infile, ofstream& outfile) // 300's
{
    AVLTree singleLeft;
    Item anItem;
    
    outfile << "\n\t\tCASE OF SINGLE ROTATE LEFT" << endl;
    outfile << "\nTest 1: TREE HEIGHT 2, DEGENERATE" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        singleLeft.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, singleLeft, anItem);
    
    outfile << "\nTest 2: TREE HEIGHT 3, RIGHT RIGHT RIGHT INSERT" << endl;
    infile >> anItem;
    singleLeft.insert(anItem);
    displayConditionsAndInsert(infile, outfile, singleLeft, anItem);
    
    outfile << "\nTest 3: TREE HEIGHT 3, RIGHT RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, singleLeft, anItem);
    
    outfile << "\nTest 4: TREE HEIGHT 3, RIGHT RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, singleLeft, anItem);
    
    outfile << "\nTest 5: TREE HEIGHT 4, LEFT RIGHT RIGHT RIGHT INSERT" << endl;
    infile >> anItem;
    singleLeft.insert(anItem);
    displayConditionsAndInsert(infile, outfile, singleLeft, anItem);
    
    outfile << "\nTest 6: TREE HEIGHT 4, LEFT RIGHT RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, singleLeft, anItem);
}

void testIsSingleRotateRight(ifstream& infile, ofstream& outfile) // 400's
{
    AVLTree singleRight;
    Item anItem;
    
    
    outfile << "\n\t\tCASE OF SINGLE ROTATE RIGHT" << endl;
    outfile << "\nTest 1: TREE HEIGHT 3, DEGENERATE" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        singleRight.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, singleRight, anItem);
    
    
    outfile << "\nTest 2: TREE HEIGHT 3, LEFT LEFT LEFT INSERT" << endl;
    infile >> anItem;
    singleRight.insert(anItem);
    displayConditionsAndInsert(infile, outfile, singleRight, anItem);
    
    outfile << "\nTest 3: TREE HEIGHT 3, LEFT LEFT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, singleRight, anItem);
    
    outfile << "\nTest 4: TREE HEIGHT 3, LEFT LEFT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, singleRight, anItem);
    
    outfile << "\nTest 5: TREE HEIGHT 4, RIGHT RIGHT LEFT LEFT INSERT" << endl;
    infile >> anItem;
    singleRight.insert(anItem);
    displayConditionsAndInsert(infile, outfile, singleRight, anItem);
    
    outfile << "\nTest 6: TREE HEIGHT 4, LEFT RIGHT LEFT LEFT" << endl;
    infile >> anItem;
    singleRight.insert(anItem);
    displayConditionsAndInsert(infile, outfile, singleRight, anItem);
    
}

void testIsDoubleRotateLeftRight(ifstream& infile, ofstream& outfile) // 500's
{
    AVLTree doubleLeftRight;
    Item anItem;
    
    outfile << "\n\t\tCASE OF DOUBLE ROTATE LEFT RIGHT" << endl;
    outfile << "\nTest 1: TREE HEIGHT 2, DEGENERATE" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        doubleLeftRight.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);
    
    outfile << "\nTest 2: TREE HEIGHT 3, LEFT LEFT RIGHT INSERT" << endl;
    infile >> anItem;
    doubleLeftRight.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);
    
    outfile << "\nTest 3: TREE HEIGHT 3, LEFT RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);
    
    
    outfile << "\nTest 4: TREE HEIGHT 3, LEFT LEFT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);

    outfile << "\nTest 5: TREE HEIGHT 4, LEFT LEFT LEFT RIGHT INSERT" << endl;
    infile >> anItem;
    doubleLeftRight.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);
    
    outfile << "\nTest 6: edit this TREE HEIGHT 4, LEFT LEFT RIGHT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleLeftRight, anItem);
}

void testIsDoubleRotateRightLeft(ifstream& infile, ofstream& outfile) // 600's
{
    AVLTree doubleRightLeft;
    Item anItem;
    
    outfile << "\n\t\tCASE OF DOUBLE ROTATE RIGHT LEFT" << endl;
    outfile << "\nTest 1: TREE HEIGHT 2, DEGENERATE" << endl;
    for (int i = 0; i < 2; i++)
    {
        infile >> anItem;
        doubleRightLeft.insert(anItem);
    }
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);
    
    outfile << "\nTest 2: TREE HEIGHT 3, RIGHT RIGHT LEFT INSERT" << endl;
    infile >> anItem;
    doubleRightLeft.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);
    
    outfile << "\nTest 3: TREE HEIGHT 3, RIGHT LEFT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);
    
    outfile << "\nTest 4: TREE HEIGHT 3, RIGHT RIGHT LEFT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);

    outfile << "\nTest 5: edit this TREE HEIGHT 4, RIGHT RIGHT RIGHT LEFT INSERT" << endl;
    infile >> anItem;
    doubleRightLeft.insert(anItem);
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);
    
    outfile << "\nTest 6: edit this TREE HEIGHT 4, RIGHT RIGHT LEFT RIGHT INSERT" << endl;
    displayConditionsAndInsert(infile, outfile, doubleRightLeft, anItem);
}

void displayConditionsAndInsert(ifstream& infile, ofstream& outfile, AVLTree& mytree, Item& myItem)
{
    outfile << "Pre-insert Tree:" << endl;
    mytree.prettyDisplay(outfile);
    infile >> myItem;
    outfile << "Now inserting " << myItem << endl;
    mytree.insert(myItem);
    outfile << "Post-insert Tree:" << endl;
    mytree.prettyDisplay(outfile);
}

// Open the file to be read from in the main program
// pre: infile is not open to a file
// post: infile can be used to read from a file
// usage: openInputFile(infile);
void openInputFile(ifstream& infile)
{
    infile.open("in8.dat");
    if(infile.fail())
    {
        cout << "Sorry there was an error in opening the input file";
        exit(1);
    }
}

// Open the file to be written in from in the main program
// pre: outfile is not open to a file
// post: outfile can be used to read from a file
// usage: openOutputFile(output);
void openOutputFile(ofstream& outfile)
{
    outfile.open("avl.dat");
    if(outfile.fail())
    {
        cout << "Sorry there was an error in opening the output Dicionary file";
        exit(1);
    }
}
