/*-----------------------------------------------------------------------------
 * part1.cpp -- Part 1 of CMPT 225 Assignment 1
 *
 * 25 Sep 2002	Ryan Stolys
 *
 -----------------------------------------------------------------------------*/


/***INCLUDES******************************************************************/
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Vector.h"
#include "List.h"
#include <time.h>


using namespace std;

/***DEFINES*******************************************************************/
#define SUCCESS             0
#define FAILURE             1

#define MY_NAME             "Ryan Stolys"
#define MY_STUDENT_NUM      "301303127"
#define MY_LOGIN_ID         "rstolys"


/***GLOBAL VARIABLES**********************************************************/


/***FUNCTION DECLARATIONS*****************************************************/
int printResults(string partNum, string elementType, int numElements, string timeUnits, float vectorInsertTime, 
                 float listInsertionTime, float vectorVisitTime, float listVisitTime);

void insertElementsToVector(int numElements, int arrayOfElements[], Vector<int> myVector);

void insertElementsToList(int numElements, int arrayOfElements[], List<int> myVector);

float computeTime(clock_t start, clock_t end);



/***FUNCTION DEFINITIONS******************************************************/



///////////////////////////////////////////////////////////////////
/// MAIN FUNCTION
///
/// @param[in]  argc    number of command line arguements
/// @param[in]  argv    array of command line arguements
///
///////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
    {
    int             rc;                     // Return Command

    Vector<int>     myVector;               // Vector list to perform operations on
    List<int>       myList;                 // Linked list to perform operations on

    clock_t         start;                  // Time varaible to record start time

    float           vectorInsertionTime;    // Time to insert elements into vector
    float           listInsertionTime;      // Time to insert elements into linked list
    float           vectorVisitTime;        // Time to visit all elements in vector
    float           listVisitTime;          // Time to visit all elements in linked list

    int             maxNumber = 1000;       // Maximum number to generate a random number
    int             numVals = 1000000;          // Number of values to insert into the array -- will change each test
    int             valuesToInsert[numVals];// Array of values
    
    
    srand(time(NULL));                      //Initalize the rand function

    // Generate random integers to fill in array
    for(int i = 0; i < numVals; i++)
        {
        valuesToInsert[i] = rand() % maxNumber;
        }


    try
        {
        //Insert elements into vector and record time
        start = clock();
        insertElementsToVector(21, valuesToInsert, myVector);
        vectorInsertionTime = computeTime(start, clock());          //end time is current clock value

        //Inset elements into list and record time
        start = clock();
        insertElementsToList(21, valuesToInsert, myList);
        listInsertionTime = computeTime(start, clock());


        //Visit all vector elements and record time
        start = clock();
        myVector.visitAll();
        vectorVisitTime = computeTime(start, clock());


        //Visit all list elements and record time
        start = clock();
        myList.visitAll();
        listVisitTime = computeTime(start, clock());


        //Print results 
        rc = printResults("Part 1", "int", sizeof(valuesToInsert)/ sizeof(valuesToInsert[0]), "milliseconds", vectorInsertionTime, listInsertionTime, vectorVisitTime, listVisitTime);
        }
    catch (const exception& e)
        {
        cerr << e.what() << endl;

        //Set return command to failure
        rc = FAILURE;
        }

    return rc;
    }


///////////////////////////////////////////////////////////////////
/// insertElementsToVector -- fills vector will elements defined in arrayOfElements
///
/// @param[in]  numElements         number of elements to fill, could be less than length of array
/// @param[in]  arrayOfElements[]   array of elements
/// @param[in]  myVector            vector to be filled
///
/// @param[out] float               time to complete insertion of elements     
///
///////////////////////////////////////////////////////////////////
void insertElementsToVector(int numElements, int arrayOfElements[], Vector<int> myVector)
    {
    int         sizeOfArray = sizeof(arrayOfElements) / sizeof(arrayOfElements[0]);
    int         maxIndex = (sizeOfArray > numElements) ? numElements : sizeOfArray;

    for(int i = 0; i < maxIndex; i++)
        {
        myVector.push_back(arrayOfElements[i]);         //Add elements to list
        }

    return;
    }


///////////////////////////////////////////////////////////////////
/// insertElementsToList -- fills vector will elements defined in arrayOfElements
///
/// @param[in]  numElements         number of elements to fill, could be less than length of array
/// @param[in]  arrayOfElements[]   array of elements
/// @param[in]  myList              list to be filled
///
/// @param[out] float               time to complete insertion of elements     
///
///////////////////////////////////////////////////////////////////
void insertElementsToList(int numElements, int arrayOfElements[], List<int> myList)
    {
    int         sizeOfArray = sizeof(arrayOfElements) / sizeof(arrayOfElements[0]);
    int         maxIndex = (sizeOfArray > numElements) ? numElements : sizeOfArray;


    for(int i = 0; i < maxIndex; i++)
        {
        myList.push_back(arrayOfElements[i]);         //Add elements to list
        }

    return; 
    }


///////////////////////////////////////////////////////////////////
/// printResults -- prints to results of the operations performed
///
/// @param[in]  elementType         type of elements stored in the lists
/// @param[in]  numElements         number of elements in lists
/// @param[in]  timeUnits           units of time used for reporting
/// @param[in]  vectorInsertTime    time to insert elements into vector
/// @param[in]  listInsertionTime   time to insert elements into list
/// @param[in]  vectorVisitTime     time to visit each element of vector
/// @param[in]  listVisitTime       time to visit each element of list
///
/// @param[out] rc                  function will print results, return success or failure code     
///
///////////////////////////////////////////////////////////////////
int printResults(string partNum, string elementType, int numElements, string timeUnits, float vectorInsertTime, 
                 float listInsertionTime, float vectorVisitTime, float listVisitTime)
    {
    int rc; 

    try
        {
        cout << endl;           //print blank line

        //Print student information
        cout << MY_NAME << endl;
        cout << MY_STUDENT_NUM << endl;
        cout << MY_LOGIN_ID << endl;

        //Print program information
        cout << "Program:" << partNum << endl;
        cout << "Type of Elements:" << elementType << endl;
        cout << "Number of Elements:" << numElements << endl;
        cout << "Time Units:" << timeUnits << endl;

        //Print time for insertions and visits
        cout << "Time for Vector Insertion:" << vectorInsertTime << endl;
        cout << "Time for List Insertion:" << listInsertionTime << endl;
        cout << "Time for Vector Visiting:" << vectorVisitTime << endl;
        cout << "Time for List Visiting:" << listVisitTime << endl;

        cout << endl;           //print blank line

        //Set return code
        rc = SUCCESS;
        }
    catch(const exception& error)
        {
        cerr << error.what() << endl;

        //set return code
        rc = FAILURE;
        }
    
    return rc;
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
