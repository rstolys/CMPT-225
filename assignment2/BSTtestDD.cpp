/*-----------------------------------------------------------------------------
 * BSTtestDD.cpp -- Test program for displayDeep
 *
 * 30 Oct 2020	Ryan Stolys
 *
 -----------------------------------------------------------------------------*/

/***INCLUDES******************************************************************/
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

/***DEFINES*******************************************************************/
#define SUCCESS             0
#define FAILURE             1


/***GLOBAL VARIABLES**********************************************************/
//NONE


/***FUNCTION DECLARATIONS*****************************************************/
//NONE


/***FUNCTION DEFINITIONS******************************************************/


///////////////////////////////////////////////////////////////////
/// MAIN FUNCTION -- test prgram
///
/// @param[in]  argc    number of command line arguements
/// @param[in]  argv    array of command line arguements
///
///////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
    {
    BinarySearchTree<int> t;
    
    int i;
    int num_Keys = 23;
    int keys[num_Keys] = {20, 10, 30, 5, 2, 1, 12, 15, 13, 18, 7, 6, 9, 25, 23, 22, 39, 35, 31, 38, 45, 40, 60};

    cout << "Start of BSTtestDD" << endl;

    //Insert elements into the tree
    for(i = 0; i < num_Keys ; i++)
        {
        t.insert(keys[i]);
        }


    //
    //Print the results from the tree
    //
    cout << "Keys:" << endl ;
    t.printTree();

    cout << "Display Deep (starting from depth of 2):" << endl ;
    t.displayDeep(2); 

    return SUCCESS;
    }
