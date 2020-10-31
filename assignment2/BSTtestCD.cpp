/*-----------------------------------------------------------------------------
 * BSTtestCD.cpp -- Test program for countDeep
 *
 * 30 Oct 2020	Ryan Stolys
 *
 -----------------------------------------------------------------------------*/

/***INCLUDES******************************************************************/
#include <iostream>
#include "BinarySearchTreeCD.h"

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

    cout << "Start of BSTtestCD" << endl;

    //Insert elements into the tree
    for(i = 1 ; i < num_Keys ; i++)
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
    cout << "The number of nodes at depth 2 or greater is 12" << endl;
    cout << "The computed number of nodes at depth 2 or greater is: " << t.countDeep(2) << endl;

    return SUCCESS;
    }