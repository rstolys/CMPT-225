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
#include "Vector2.h"
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
//NONE

/***FUNCTION DECLARATIONS*****************************************************/
int main_int(int numVals);

int main_char(int numVals);

int main_float(int numVals);

int printResults(string partNum, string elementType, int numElements, string timeUnits, float vectorInsertTime, 
                 float listInsertionTime, float vectorVisitTime, float listVisitTime);

void insertElementsToVector_int(int numElements, int arrayOfElements[], Vector<int>* myVector);

void insertElementsToList_int(int numElements, int arrayOfElements[], List<int>* myVector);

void insertElementsToVector_char(int numElements, char arrayOfElements[], Vector<char>* myVector);

void insertElementsToList_char(int numElements, char arrayOfElements[], List<char>* myVector);

void insertElementsToVector_float(int numElements, float arrayOfElements[], Vector<float>* myVector);

void insertElementsToList_float(int numElements, float arrayOfElements[], List<float>* myVector);

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

    //Call function to test insertion and visits with ints
    rc = main_int(1000);

    //Call function to test insertion and visits with chars
<<<<<<< HEAD
    //rc = main_char(1000);

    //Call function to test insertion and visits with floats
    //rc = main_float(1000);
=======
    //rc = main_char(100);

    //Call function to test insertion and visits with floats
    //rc = main_float(100);
>>>>>>> f9d64fa61ce08b31ab79edb7c2b15efdc7d94799


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
void insertElementsToVector_int(int numElements, int arrayOfElements[], Vector<int>* myVector)
    {

    for(int i = 0; i < numElements; i++)
        {
        myVector->push_front(arrayOfElements[i]);         //Add elements to list
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
void insertElementsToList_int(int numElements, int arrayOfElements[], List<int>* myList)
    {

    for(int i = 0; i < numElements; i++)
        {
        myList->push_front(arrayOfElements[i]);         //Add elements to list
        }

    return;
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
void insertElementsToVector_char(int numElements, char arrayOfElements[], Vector<char>* myVector)
    {

    for(int i = 0; i < numElements; i++)
        {
        myVector->push_front(arrayOfElements[i]);         //Add elements to list
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
void insertElementsToList_char(int numElements, char arrayOfElements[], List<char>* myList)
    {

    for(int i = 0; i < numElements; i++)
        {
        myList->push_front(arrayOfElements[i]);         //Add elements to list
        }

    return;
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
void insertElementsToVector_float(int numElements, float arrayOfElements[], Vector<float>* myVector)
    {

    for(int i = 0; i < numElements; i++)
        {
        myVector->push_front(arrayOfElements[i]);         //Add elements to list
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
void insertElementsToList_float(int numElements, float arrayOfElements[], List<float>* myList)
    {

    for(int i = 0; i < numElements; i++)
        {
        myList->push_front(arrayOfElements[i]);         //Add elements to list
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
        cout << "Program: " << partNum << endl;
        cout << "Type of Elements: " << elementType << endl;
        cout << "Number of Elements: " << numElements << endl;
        cout << "Time Units: " << timeUnits << endl;

        //Print time for insertions and visits
        cout << "Time for Vector Insertion: " << vectorInsertTime << endl;
        cout << "Time for List Insertion: " << listInsertionTime << endl;
        cout << "Time for Vector Visiting: " << vectorVisitTime << endl;
        cout << "Time for List Visiting: " << listVisitTime << endl;

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


///////////////////////////////////////////////////////////////////
/// main function for integer testing
///
/// @param[in]  numVals    Number of values to insert into the array
///
///////////////////////////////////////////////////////////////////
int main_int(int numVals)
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
        insertElementsToVector_int(numVals, valuesToInsert, &myVector);
        vectorInsertionTime = computeTime(start, clock());          //end time is current clock value

        //Inset elements into list and record time
        start = clock();
        insertElementsToList_int(numVals, valuesToInsert, &myList);
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
        rc = printResults("Part 2", "int", sizeof(valuesToInsert)/ sizeof(valuesToInsert[0]), "milliseconds", vectorInsertionTime, listInsertionTime, vectorVisitTime, listVisitTime);
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
/// main function for character testing
///
/// @param[in]  numVals    Number of values to insert into the array
///
///////////////////////////////////////////////////////////////////
int main_char(int numVals)
    {
    int             rc;                     // Return Command

    Vector<char>     myVector;              // Vector list to perform operations on
    List<char>       myList;                // Linked list to perform operations on

    clock_t         start;                  // Time varaible to record start time

    float           vectorInsertionTime;    // Time to insert elements into vector
    float           listInsertionTime;      // Time to insert elements into linked list
    float           vectorVisitTime;        // Time to visit all elements in vector
    float           listVisitTime;          // Time to visit all elements in linked list

    char            valuesToInsert[numVals];// Array of values
    
    char            valueOptions[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


    srand(time(NULL));                      //Initalize the rand function

    // Generate random character to fill into array
    for(int i = 0; i < numVals; i++)
        {
        valuesToInsert[i] = valueOptions[rand() % 26];
        }


    try
        {
        //Insert elements into vector and record time
        start = clock();
        insertElementsToVector_char(numVals, valuesToInsert, &myVector);
        vectorInsertionTime = computeTime(start, clock());          //end time is current clock value

        //Inset elements into list and record time
        start = clock();
        insertElementsToList_char(numVals, valuesToInsert, &myList);
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
        rc = printResults("Part 2", "char", sizeof(valuesToInsert)/ sizeof(valuesToInsert[0]), "milliseconds", vectorInsertionTime, listInsertionTime, vectorVisitTime, listVisitTime);
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
/// main function for float values testing
///
/// @param[in]  numVals    Number of values to insert into the array
///
///////////////////////////////////////////////////////////////////
int main_float(int numVals)
    {
    int             rc;                     // Return Command

    Vector<float>     myVector;             // Vector list to perform operations on
    List<float>       myList;               // Linked list to perform operations on

    clock_t         start;                  // Time varaible to record start time

    float           vectorInsertionTime;    // Time to insert elements into vector
    float           listInsertionTime;      // Time to insert elements into linked list
    float           vectorVisitTime;        // Time to visit all elements in vector
    float           listVisitTime;          // Time to visit all elements in linked list

    float           maxNumber = 1000.0;     // Maximum number to generate a random number
    float           valuesToInsert[numVals];// Array of values
    

    srand(time(NULL));                      //Initalize the rand function

    // Generate random character to fill into array
    for(int i = 0; i < numVals; i++)
        {
        valuesToInsert[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / maxNumber));
        }


    try
        {
        //Insert elements into vector and record time
        start = clock();
        insertElementsToVector_float(numVals, valuesToInsert, &myVector);
        vectorInsertionTime = computeTime(start, clock());          //end time is current clock value

        //Inset elements into list and record time
        start = clock();
        insertElementsToList_float(numVals, valuesToInsert, &myList);
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
        rc = printResults("Part 2", "float", sizeof(valuesToInsert)/ sizeof(valuesToInsert[0]), "milliseconds", vectorInsertionTime, listInsertionTime, vectorVisitTime, listVisitTime);
        }
    catch (const exception& e)
        {
        cerr << e.what() << endl;

        //Set return command to failure
        rc = FAILURE;
        }

    return rc;
    }
