/*-----------------------------------------------------------------------------
 * BSTtestCL.cpp -- Test program for countLeaves
 *
 * 30 Oct 2020	Ryan Stolys
 *
 -----------------------------------------------------------------------------*/

/***INCLUDES******************************************************************/
#include <iostream>
#include "BinarySearchTreeCL.h"

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
    int num_Keys = 15;
    int keys[num_Keys] = {8, 5, 3, 1, 4, 7, 6, 12, 10, 11, 15, 14, 13, 18, 17};

    cout << "Start of BSTtestCL" << endl;

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
    cout << "Tree:" << endl ;
    t.displayTree(); 

    //Print the number of leaves
    cout << "The number of leaves is 6" << endl;
    cout << "The computed number of leaves is: " << t.countLeaves() << endl;

    return SUCCESS;
    }
