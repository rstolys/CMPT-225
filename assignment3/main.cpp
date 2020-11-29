/*-----------------------------------------------------------------------------
 * main.cpp -- Test program for comparison between BST and AVL.
 *
 * 28 Nov 2020	Ryan Stolys
 *
 -----------------------------------------------------------------------------*/

/***INCLUDES******************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <math.h>
#include <string>

#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

/***CONSTANTS + DEFINES*******************************************************************/
const int SUCCESS =                 0;
const int FAILURE =                 1;

const int NUM_KEYS =                1000000;             //100 Thousand Keys
const int KEY_GAP =                 8647;               //Randomish key gap to get good spread of keys
const int MAX_KEY =                 100000000;            //1 million

const int SIZE =                    0; 
const int HEIGHT =                  1;
const int AVG_NODE_DEPTH =          2;

const int MAX_OPERATIONS =          10000;
const int OPERATIONS_BN_TEST =      5; 
const int TESTS_PER_REPORT =        MAX_OPERATIONS / OPERATIONS_BN_TEST;

const string FILE_INSERT =          "insert";
const string FILE_REMOVE =          "remove";
const string FILE_SEARCH =          "search";

const int INSERT =                  0;
const int REMOVE =                  1;
const int SEARCH =                  2;


#define REPORT_INSERT(opNum, key)               (to_string(opNum) + ": insert: " + to_string(key))
#define REPORT_REMOVE(opNum, key)               (to_string(opNum) + ": remove: " + to_string(key))
#define REPORT_SEARCH(opNum, key, result)       (to_string(opNum) + ": search: " + to_string(key) + ", result: " + to_string(result))

#define FILE_HEADER  "operationNumber, size, height, averageNodeDepth, timeForOperation, operationType"
#define REPORT_TO_FILE(opNum, size, height, avgNodeDepth, timeForOperation, oppType)   (to_string(opNum) + ", " + to_string(size) + ", " + to_string(height) + ", " + to_string(avgNodeDepth) + ", " + to_string(timeForOperation) + ", " + oppType)



/***GLOBAL VARIABLES**********************************************************/
//NONE


/***FUNCTION DECLARATIONS*****************************************************/
double* obtainBSTinfo(BinarySearchTree<int> t_bst, int sizeOfTrees);
double* obtainAVLinfo(AvlTree<int> t_bst, int sizeOfTrees);
float computeTime(clock_t start, clock_t end);



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
    //Creates a BST instance and AVL instance
    BinarySearchTree<int> t_bst;
    AvlTree<int> t_avl;

    int sizeOfTrees = 0;         //Set the intial size of the trees
   
    clock_t start; 
    float timeElapsed;

    int key = MAX_KEY / KEY_GAP;        //Set the intial key to be modified key

    //Files for reporting 
    ofstream operationsFile;
    ofstream bstFile;
    ofstream avlFile;

    operationsFile.open ("operationsPerformed.txt");
    bstFile.open ("bstResults.csv");
    avlFile.open ("avlResults.csv");

    //Create headers for csv files
    bstFile << FILE_HEADER << endl;
    avlFile << FILE_HEADER << endl;
  

    //Generate a set of keys and insert into the trees 
    for(int i = 0; i < NUM_KEYS; i++)
        {
        //Make sure the key is not in the tree already before inserting it
        do 
            {
            key = (key + KEY_GAP) % MAX_KEY;        //Get a key
            }
        while(t_avl.contains(key));
        
        t_bst.insert(key);                      //Insert into bst
        t_avl.insert(key);                      //Insert into avl

        sizeOfTrees++;
        }

    //Report intial inserts to file 
    operationsFile << "-1: inserted: " << sizeOfTrees << " keys into trees" << endl;

    //Initalize random number generators for getting keys and for selecting operations
    default_random_engine generate;
    uniform_int_distribution<int> distribution(0, MAX_KEY);
    srand(1);                       //Use fixed key to get same sequence of operations

    //Performs a long sequence of operations on the two trees 
    for(int opNum = 0; opNum < MAX_OPERATIONS; opNum++) 
        {
        int operationType = rand() % 3;     //Get the operation to be performed
        int key;

        switch(operationType)
            {
            case INSERT: 
                {
                //Make sure the ket isnt already in the tree
                do 
                    {
                    key = distribution(generate);         //Get the key to insert 
                    }
                while (t_avl.contains(key));
                

                if(opNum % OPERATIONS_BN_TEST)
                    {
                    sizeOfTrees++;

                    //Insert the key into both trees -- don't need to measure speed or get info
                    t_bst.insert(key);
                    t_avl.insert(key);
                    }
                else 
                    {
                    sizeOfTrees++;

                    //Insert the key into BST tree -- measure and report information
                    start = clock();
                    t_bst.insert(key);
                    timeElapsed = computeTime(start, clock());

                    double* info = obtainBSTinfo(t_bst, sizeOfTrees);

                    //Report BST info
                    bstFile << REPORT_TO_FILE(opNum, (int)info[SIZE], (int)info[HEIGHT], info[AVG_NODE_DEPTH], timeElapsed, FILE_INSERT) << endl;


                    //Insert the key into AVL tree -- measure and report information
                    start = clock();
                    t_avl.insert(key);
                    timeElapsed = computeTime(start, clock());

                    info = obtainAVLinfo(t_avl, sizeOfTrees);

                    //Report BST info
                    avlFile << REPORT_TO_FILE(opNum, (int)info[SIZE], (int)info[HEIGHT], info[AVG_NODE_DEPTH], timeElapsed, FILE_INSERT) << endl;
                    }

                //Report operation 
                operationsFile << REPORT_INSERT(opNum, key) << endl;

                break;
                }
            case REMOVE: 
                {
                //Make sure the key is already in the tree
                do 
                    {
                    key = distribution(generate);         //Get the key to insert 
                    }
                while (!t_avl.contains(key));


                if(opNum % OPERATIONS_BN_TEST)
                    {
                    sizeOfTrees--;

                    //Insert the key into both trees
                    t_bst.remove(key);
                    t_avl.remove(key);
                    }
                else 
                    {
                    sizeOfTrees--;

                    //Insert the key into BST tree -- measure and report information
                    start = clock();
                    t_bst.remove(key);
                    timeElapsed = computeTime(start, clock());

                    double* info = obtainBSTinfo(t_bst, sizeOfTrees);

                    //Report BST info
                    bstFile << REPORT_TO_FILE(opNum, (int)info[SIZE], (int)info[HEIGHT], info[AVG_NODE_DEPTH], timeElapsed, FILE_REMOVE) << endl;


                    //Insert the key into AVL tree -- measure and report information
                    start = clock();
                    t_avl.remove(key);
                    timeElapsed = computeTime(start, clock());

                    info = obtainAVLinfo(t_avl, sizeOfTrees);

                    //Report BST info
                    avlFile << REPORT_TO_FILE(opNum, (int)info[SIZE], (int)info[HEIGHT], info[AVG_NODE_DEPTH], timeElapsed, FILE_REMOVE) << endl;
                    }

                //Report operation 
                operationsFile << REPORT_REMOVE(opNum, key) << endl;
            
                break;
                }
            case SEARCH: 
                {
                //Get a key to search for 
                key = distribution(generate);

                bool reportResult; 

                if(opNum % OPERATIONS_BN_TEST)
                    {
                    //Insert the key into both trees
                    bool resultBST = t_bst.contains(key);
                    bool resultAVL = t_avl.contains(key);

                    reportResult = (resultBST == resultAVL) ? resultAVL : false;
                    }
                else 
                    {
                    sizeOfTrees--;

                    //Insert the key into BST tree -- measure and report information
                    start = clock();
                    bool resultBST = t_bst.contains(key);
                    timeElapsed = computeTime(start, clock());

                    double* info = obtainBSTinfo(t_bst, sizeOfTrees);

                    //Report BST info
                    bstFile << REPORT_TO_FILE(opNum, (int)info[SIZE], (int)info[HEIGHT], info[AVG_NODE_DEPTH], timeElapsed, FILE_SEARCH) << endl;


                    //Insert the key into AVL tree -- measure and report information
                    start = clock();
                    bool resultAVL = t_avl.contains(key);
                    timeElapsed = computeTime(start, clock());

                    info = obtainAVLinfo(t_avl, sizeOfTrees);

                    //Report BST info
                    avlFile << REPORT_TO_FILE(opNum, (int)info[SIZE], (int)info[HEIGHT], info[AVG_NODE_DEPTH], timeElapsed, FILE_SEARCH) << endl;


                    reportResult = (resultBST == resultAVL) ? resultAVL : false;
                    }


                //Report operation 
                operationsFile << REPORT_SEARCH(opNum, key, reportResult) << endl;

                break;
                }
            default: 
                {
                //This should never happen but is here in case

                //Report error
                operationsFile << to_string(opNum) + ": ERROR: No Operation performed" << endl;

                break;
                }
            }
        }


    //Close files used for reporting 
    operationsFile.close();
    bstFile.close();
    avlFile.close();


    return SUCCESS;
    }



///////////////////////////////////////////////////////////////////
/// obtainBSTinfo -- will access the size, height, average node depth of each tree
///
/// @param[in]  t_bst       Binary Search Tree to get info of
///
/// @param[out]  int*       Array conatining info about the tree
///
///////////////////////////////////////////////////////////////////
double* obtainBSTinfo(BinarySearchTree<int> t_bst, int sizeOfTrees) 
    {
    double* info = new double[3];       //Create info array to return and initalize to 0

    //Set the size of the trees
    info[SIZE] = sizeOfTrees;

    //Get the height of the trees 
    info[HEIGHT] = t_bst.getHeight();

    //Get the average node depth
    info[AVG_NODE_DEPTH] = t_bst.ipl() / (double)sizeOfTrees;


    return info;
    }


///////////////////////////////////////////////////////////////////
/// obtainAVLinfo -- will access the size, height, average node depth of each tree
///
/// @param[in]  t_avl       AVL tree to get info of
///
/// @param[out]  int*       Array conatining info about the tree
///
///////////////////////////////////////////////////////////////////
double* obtainAVLinfo(AvlTree<int> t_avl, int sizeOfTrees) 
    {
    double* info = new double[3];       //Create info array to return and initalize to 0

    //Set the size of the trees
    info[SIZE] = sizeOfTrees;

    //Get the height of the trees 
    info[HEIGHT] = t_avl.getHeight();

    //Get the average node depth
    info[AVG_NODE_DEPTH] = t_avl.ipl() / (double)sizeOfTrees;


    return info;
    }


///////////////////////////////////////////////////////////////////
/// computeTime -- will compute the time between a start and end time
///
/// @param[in]  start           start time of operations
/// @param[in]  end             end time of operations
///
/// @param[out] float           time between start and end in milliseconds    
///
///////////////////////////////////////////////////////////////////
float computeTime(clock_t start, clock_t end)
    {
    return (float) ((end - start) / ((double) CLOCKS_PER_SEC / 1000));
    }
