/*-----------------------------------------------------------------------------
 * BSTtest2.cpp -- Test program 2 provided by assignment 2
 *
 * 30 Oct 2020	Ryan Stolys
 *
 -----------------------------------------------------------------------------*/


/***INCLUDES******************************************************************/
#include <iostream>
#include "BinarySearchTreeDL.h"

using namespace std;

/***DEFINES*******************************************************************/
//NONE

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
    //int NUMS = 400000;
    int NUMS = 10;
    const int GAP  = 3 ;
    const int CAP  = 19;
    int i;
    int key;

    cout << "Start of BSTtest" << endl;

    key = CAP/2;
    for( i = 1 ; i <= NUMS ; i++ )
        {
        key = (key + GAP) % CAP ;
        t.insert( key );
        }

    if( NUMS < 40 )
        {
        cout << "Keys:" << endl ;
        t.printTree( );
        cout << "Tree:" << endl ;
        t.displayTree(); 
        cout << "Links:" << endl ;
        t.displayLinks();                   //Need to add function displayLinks to BinarySearchTree.h
        }

/*
    for( i = 1; i < NUMS; i+= 2 )
        t.remove( i );

    if( NUMS < 40 ) t.printTree( );

    BinarySearchTree<int> t2;
    t2 = t;
*/
    cout << "End of BSTtest" << endl;

    return 0;
    }