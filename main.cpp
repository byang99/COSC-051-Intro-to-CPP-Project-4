/*
 * main.cpp
 *
 * COSC 051 Fall 2018
 * Project #4
 *
 * Due on: NOV 21, 2018
 * Author: byy2
 *
 *
 * In accordance with the class policies and Georgetown's
 * Honor Code, I certify that, with the exception of the
 * class resources and those items noted below, I have neither
 * given nor received any assistance on this project.
 *
 * References not otherwise commented within the program source code.
 * Note that you should not mention any help from the TAs, the professor,
 * or any code taken from the class textbooks.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;


// GLOBAL CONSTANTS
const double MARBLE_PRICE = 92.99;
const double GRANITE_PRICE = 78.99;
const double QUARTZ_PRICE = 56.99;
const double EDGE_FINISHING_RATE = 4.99;
const double WASTAGE_PERCENT = 0.26;
const double MAX_LENGTH = 25.0;
const double MIN_LENGTH = 5.0;
const double MAX_DEPTH = 25.0;
const double MIN_DEPTH = 5.0;
const int MIN_EDGES_FINISHED = 0;
const int MAX_EDGES_FINISHED = 2;
const int MONTH_DIFFERENCE = 8;
const double MIN_HEIGHT_FACTOR = 0.58;
const double MAX_HEIGHT_FACTOR = 0.80;
const int FOUR_MONTH_DIFFERENCE = 4;
const int TWO_YEAR_DIFFERENCE = 2;
const int ONE_YEAR_DIFFERENCE = 1;
const int FOUR_MONTH_DIFFERENCE_NEW_YEAR = -7;
const int TWELVE_MONTH_DIFFERENCE = 12;
const int ONE_ERROR = 1;
const int ZERO_ERRORS = 0;
const string NORTH = "North";
const string EAST = "East";
const string SOUTH = "South";
const string WEST = "West";
const string OTHER = "Other";


/********************************************************************************
 *                                                                              *                                                                              * 
 *                                                                              *
 *                                                                              *
 *                     CounterTop Class Declaration                             *
 *                                                                              *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

class CounterTop
{
    friend ostream& operator<<( ostream &os, const CounterTop &rhsObj );
    friend istream& operator>>( istream &is, CounterTop &rhsObj );
    
private:
    //required (you may change identifiers, but do so with caution)
    //you may NOT add any data members to the class declaration
    
    int orderYear;
    int orderMonth;
    int orderDay;
    
    int deliveryYear;
    int deliveryMonth;
    int deliveryDay;
    
    char stoneCode;
    
    double length;
    double depth;
    double height;
    
    int lengthEdgesToFinish;
    int depthEdgesToFinish;
    
    string orderNumber;
    string region;
    string fipsStateCode;
    string customerNameAddress;
    
public:
    //required constructors
    //you may change parameter identifiers, but the order and types of the parameters
    //must be the same as shown in the prototypes
    
    
    //CONSTRUCTOR PROTOTYPES
    CounterTop();
    
    CounterTop(int oYYYY, int oMM, int oDD, int dYYYY, int dMM, int dDD,
               char sCode, double len, double dep, double hei, int lenF, int depF,
               string oNum, string reg, string stCode, string custNameAdd);
    
    CounterTop( const CounterTop &otherObj );
    
    // required overloaded assignment operator implemented as member function
    CounterTop&  operator= (const CounterTop &  rhsObj);
    
    //required basic mutator functions, in-line implementation
    //you may change parameter identifiers but NOT the function identifiers
    
    //INLINE FUNCTIONS
    void setStoneCode(char sCode)
    { stoneCode = sCode; }
    
    void setLength( double len ) 
    { length = len; }    
    
    void setDepth( double dep ) 
    { depth = dep; }    
    
    void setHeight( double hei ) 
    { height = hei; }    
    
    void setLenEdgeF( int lenF ) 
    { lengthEdgesToFinish = lenF; }    
    
    void setDepEdgeF( int depF ) 
    { depthEdgesToFinish = depF; }    
    
    void setOrderNum( string oNum ) 
    { orderNumber = oNum; }
    
    void setRegion( string reg ) 
    { region = reg; }
    
    void setFIPS( string stCode ) 
    { fipsStateCode = stCode; }
    
    void setCustomerNameAdd( string custNameAdd ) 
    { customerNameAddress = custNameAdd; }
    
    //required basic accessor functions, in-line implementation
    //you may change parameter identifiers but NOT the function identifiers
    
    //ACCESSOR INLINE FUNCTION DEFINITIONS
    char getStoneCode() const 
    { return stoneCode; }
    
    double getLength() const 
    { return length; }
    
    double getDepth() const 
    { return depth; }
    
    double getHeight() const 
    { return height; }
    
    int getLenEdgeF() const 
    { return lengthEdgesToFinish; }
    
    int getDepEdgeF() const 
    { return depthEdgesToFinish; }
    
    string getOrderNum() const 
    { return orderNumber; }
    
    string getRegion() const 
    { return region; }
    
    string getFIPS() const 
    { return fipsStateCode; }
    
    string getCustomerNameAdd() const 
    { return customerNameAddress; }
    
    //required accessor functions that perform more detailed calculations
    //you may change parameter identifiers but NOT the function identifiers
    
    //DETAILED FUNCTION PROTOTYPES
    void setOrderDate(int yyyy, int mm, int dd);
    void setDeliveryDate(int yyyy, int mm, int dd);
    
    double getCounterTopArea() const;
    double getMaterialRequired() const;
    double getStoneCost() const;
    double getFinishingCost() const;
    double getTotalCost() const;
    
    string getStoneName() const;
};//END declaration class CounterTop



/********************************************************************************
 *                                                                              *                                                                              * 
 *                                                                              *
 *                                                                              *
 *                    CounterTop Constructor Definitions                        *
 *                                                                              *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

/****************************************************************************
 *                   class Widget default constructor                       *
 ****************************************************************************/
CounterTop:: CounterTop()
{
    orderYear = 0;
    orderMonth = 0;
    orderDay = 0;
    
    deliveryYear = 0;
    deliveryMonth = 0;
    deliveryDay = 0;
    
    stoneCode = ' ';
    
    length = 0.0;
    depth = 0.0;
    height = 0.0;
    
    lengthEdgesToFinish = 0;
    depthEdgesToFinish = 0;
    
    orderNumber = " ";
    region = " ";
    fipsStateCode = " ";
    customerNameAddress = " ";
}

/****************************************************************************
 *                class Widget constructor w/ Parameters                    *
 ****************************************************************************/
CounterTop:: CounterTop(int oYYYY, int oMM, int oDD, int dYYYY, int dMM, int dDD,
               char sCode, double len, double dep, double hei, int lenF, int depF,
               string oNum, string reg, string stCode, string custNameAdd)
{
    orderYear = oYYYY;
    orderMonth = oMM;
    orderDay = oDD;
    
    deliveryYear = dYYYY;
    deliveryMonth = dMM;
    deliveryDay = dDD;
    
    stoneCode = sCode;
    
    length = len;
    depth = dep;
    height = hei;
    
    lengthEdgesToFinish = lenF;
    depthEdgesToFinish = depF;
    
    orderNumber = oNum;
    region = reg;
    fipsStateCode = stCode;
    customerNameAddress = custNameAdd;
}

/****************************************************************************
 *                      class Widget copy constructor                       *
 ****************************************************************************/
CounterTop:: CounterTop( const CounterTop &otherObj )
{
    //cout << "enter copy constructor" << endl;
    this -> orderYear = otherObj.orderYear;
    this -> orderMonth = otherObj.orderMonth;
    this -> orderDay = otherObj.orderDay;
    
    this -> deliveryYear = otherObj.deliveryYear;
    this -> deliveryMonth = otherObj.deliveryMonth;
    this -> deliveryDay = otherObj.deliveryDay;
    
    this -> stoneCode = otherObj.stoneCode;
    
    this -> length = otherObj.length;
    this -> depth = otherObj.depth;
    this -> height = otherObj.height;
    
    this -> lengthEdgesToFinish = otherObj.lengthEdgesToFinish;
    this -> depthEdgesToFinish = otherObj.depthEdgesToFinish;
    
    this -> orderNumber = otherObj.orderNumber;
    this -> region = otherObj.region;
    this -> fipsStateCode = otherObj.fipsStateCode;
    this -> customerNameAddress = otherObj.customerNameAddress;
}


/****************************************************************************
 *                      overloaded assignment operator                      *
 ****************************************************************************/
// required overloaded assignment operator implemented as member function
CounterTop& CounterTop:: operator= (const CounterTop&  rhsObj)
{
    //cout << "Overloaded Assignment called." << endl;
    
    //Check for self assignment
    if (this != &rhsObj)
    {
        orderYear = rhsObj.orderYear;
        orderMonth = rhsObj.orderMonth;
        orderDay = rhsObj.orderDay;

        deliveryYear = rhsObj.deliveryYear;
        deliveryMonth = rhsObj.deliveryMonth;
        deliveryDay = rhsObj.deliveryDay;

        stoneCode = rhsObj.stoneCode;

        length = rhsObj.length;
        depth = rhsObj.depth;
        height = rhsObj.height;

        lengthEdgesToFinish = rhsObj.lengthEdgesToFinish;
        depthEdgesToFinish = rhsObj.depthEdgesToFinish;

        orderNumber = rhsObj.orderNumber;
        region = rhsObj.region;
        fipsStateCode = rhsObj.fipsStateCode;
        customerNameAddress = rhsObj.customerNameAddress;        
    }
    return *this;
}


/****************************************************************************
 *                  overloaded stream insertion operator                    *
 ****************************************************************************/
ostream& operator<<( ostream &os, const CounterTop &rhsObj )
{   
    os << fixed << setprecision(2);
    os << setw(13) << rhsObj.getOrderNum();
    os << setw(10) << rhsObj.getRegion();
    os << setw(7)  << rhsObj.getStoneCode();
    os << setw(10) << rhsObj.getLength();
    os << setw(10) << rhsObj.getDepth();
    os << setw(10) << rhsObj.getHeight();
    os << setw(7)  << rhsObj.getLenEdgeF();
    os << setw(7)  << rhsObj.getDepEdgeF();
    os << setw(12) << rhsObj.getMaterialRequired();
    os << setw(16) << rhsObj.getTotalCost() << endl;
    
    return os;
}


/****************************************************************************
 *                  overloaded stream extraction operator                   *
 ****************************************************************************/
istream& operator>>( istream &is, CounterTop &rhsObj )
{
    //cout << "Overloaded stream extraction operator called." << endl;
    
    int orderYear = 0;
    int orderMonth = 0;
    int orderDay = 0;
    
    int deliveryYear = 0;
    int deliveryMonth = 0;
    int deliveryDay = 0;
    
    char stoneCode = ' ';
    char slash = ' ';
    
    double length = 0.0;
    double depth = 0.0;
    double height = 0.0;
    
    int lengthEdgesToFinish = 0;
    int depthEdgesToFinish = 0;
    
    string orderNumber = " ";
    string region = " ";
    string fipsStateCode = " ";
    string customerNameAddress = " ";
    
    is >> rhsObj.orderYear >> slash >> rhsObj.orderMonth >> slash >> rhsObj.orderDay
       >> rhsObj.deliveryYear >> slash >> rhsObj.deliveryMonth >> slash >> rhsObj.deliveryDay
       >> rhsObj.stoneCode >> rhsObj.length >> rhsObj.depth >> rhsObj.height
       >> rhsObj.lengthEdgesToFinish >> rhsObj.depthEdgesToFinish
       >> rhsObj.orderNumber >> rhsObj.region >> rhsObj.fipsStateCode >> rhsObj.customerNameAddress;
    
   
    /*
    is >> orderYear >> slash >> orderMonth >> slash >> orderDay
       >> deliveryYear >> slash >> deliveryMonth >> slash >> deliveryDay
       >> stoneCode >> length >> depth >> height
       >> lengthEdgesToFinish >> depthEdgesToFinish
       >> orderNumber >> region >> fipsStateCode && getline(is,customerNameAddress);
    
    rhsObj.setStoneCode(stoneCode);
    rhsObj.setLength(length); 
    rhsObj.setDepth(depth);
    rhsObj.setHeight(height);
    rhsObj.setLenEdgeF(lengthEdgesToFinish);
    rhsObj.setDepEdgeF(depthEdgesToFinish);
    rhsObj.setOrderNum(orderNumber);
    rhsObj.setRegion(region);
    rhsObj.setFIPS(fipsStateCode);
    rhsObj.setCustomerNameAdd(customerNameAddress);
    */
    return is;
}


/********************************************************************************
 *                                                                              *                                                                              * 
 *                                                                              *
 *                                                                              *
 *                   CounterTop Member Function Definitions                     *
 *                                                                              *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

void CounterTop:: setOrderDate(int yyyy, int mm, int dd)
{
    orderYear = yyyy;
    orderMonth = mm;
    orderDay = dd;
}
void CounterTop:: setDeliveryDate(int yyyy, int mm, int dd)
{
    deliveryYear = yyyy;
    deliveryMonth = mm;
    deliveryDay = dd;
}
double CounterTop:: getCounterTopArea() const
{
    double counterTopArea = length * height;
    return counterTopArea;
}
double CounterTop:: getMaterialRequired() const
{
    double materialRequired = ceil(getCounterTopArea()*(1 + WASTAGE_PERCENT));
    return materialRequired;
}
double CounterTop:: getStoneCost() const
{
    double totalMaterialCost = 0.0;
    double stonePriceRate = 0.0;
    double totalMaterialSqFt = getMaterialRequired();
    
    //set price rates for stone
        //if stone is Granite
    if(toupper(stoneCode) == 'G')
    {
        stonePriceRate = GRANITE_PRICE;
    }
    //if stone is Marble
    if(toupper(stoneCode) == 'M')
    {
        stonePriceRate = MARBLE_PRICE;
    }
    //if stone is Quartz
    if(toupper(stoneCode) == 'Q')
    {
        stonePriceRate = QUARTZ_PRICE;
    }
    
    totalMaterialCost = totalMaterialSqFt * stonePriceRate;
    
    return totalMaterialCost;
}
double CounterTop:: getFinishingCost() const
{
    double totalFinishingLength = 0.0;
    double edgeFinishingCost = 0.0;
    totalFinishingLength = lengthEdgesToFinish * length + depthEdgesToFinish * depth;
    edgeFinishingCost = totalFinishingLength * EDGE_FINISHING_RATE;
    return edgeFinishingCost;
}
double CounterTop:: getTotalCost() const
{
    double totalMaterialCost = getStoneCost();
    double edgeFinishingCost = getFinishingCost();
    double totalCost = totalMaterialCost + edgeFinishingCost;
    return totalCost; 
}
string CounterTop:: getStoneName() const
{
    string stoneName = " ";
    if(toupper(stoneCode) == 'G')
    {
        stoneName = "Granite";
    }
    else if(toupper(stoneCode) == 'M')
    {
        stoneName = "Marble";
    }
    else if(toupper(stoneCode) == 'Q')
    {
        stoneName = "Quartz";
    }
    
    return stoneName;   
}


/********************************************************************************
 *                                                                              *                                                                              * 
 *                                                                              *
 *                                                                              *
 *                       Regular Function Prototypes                            *
 *                                                                              *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

char displayMenu();
void uploadFile(string fName, bool &loadSuccess, vector <CounterTop > &vCounterTops);
void allDetails(const vector <CounterTop> &vCounterTops);
void orderDetails(const vector <CounterTop> &vCounterTops);
void summaryByStone(const vector <CounterTop> &vCounterTops);
void summaryByRegion(const vector <CounterTop> &vCounterTops);


/********************************************************************************
 *                                                                              *                                                                              * 
 *                                                                              *
 *                                                                              *
 *                                 START MAIN                                   *
 *                                                                              *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/

int main()
{
    string fName;
    bool loadSuccess = false;
    vector<CounterTop> vCounterTops;
    char userChoice = ' ';
    
    
    //DISPLAY WELCOME MESSAGE
    cout << "Welcome to Claude's Custom Counters, Inc. Calculator" << endl;
    cout << "This application calculates cost and fabrication" << endl;
    cout << "data based on sales data input files." << endl;
    cout << endl;
    
    //do-while loop to display menu until user wants to quit
    
    do
    {
        userChoice = displayMenu();
        
        if(toupper(userChoice)=='Q')
        {
            cout << "Thanks for using Claude's Custom Counters, Inc. Calculator." << endl;
        }
        
        //UPLOAD FILE
        if(toupper(userChoice)=='U')
        {
            //file name initiation
            cout << "Please enter the complete path and name of the file: ";
            cin >> fName;
            cout << endl;
            
            uploadFile(fName, loadSuccess, vCounterTops);
        }
        
        //THESE FUNCTIONS CAN ONLY BE CALLED IF VECTORS HAVE AT LEAST ONE ELEMENT IN THEM
        if(vCounterTops.size()>0) 
        {
            //DISPLAY ALL DETAILS
            if(toupper(userChoice)=='A')
            {
                allDetails(vCounterTops);
            }

            //DISPLAY ORDER DETAILS
            else if(toupper(userChoice)=='O')
            {
                orderDetails(vCounterTops);
            }

            //SUMMARY BY REGION
            else if(toupper(userChoice)=='R') 
            {
                summaryByRegion(vCounterTops);
            }

            //SUMMARY BY STONE CODE
            else if(toupper(userChoice)=='S' )
            {
                summaryByStone(vCounterTops);
            }

            //CLEAR ALL VECTORS
            else if(toupper(userChoice)=='C')
            {
                
                vCounterTops.clear();
                cout << "All vectors have been cleared." << endl;
                cout << endl;
            }
        }
        else
        {
            if(toupper(userChoice)=='A'||toupper(userChoice)=='O' ||toupper(userChoice)=='R'
               ||toupper(userChoice)=='S')
            {
                cout << "Please load at least one data file before trying to display data.";
                cout << endl;
                cout << endl;
            }
            if(toupper(userChoice)=='C')
            {
                cout << "Nothing to clear. Vectors are already empty." << endl;
                cout << endl;
            }
        }
    }while(toupper(userChoice)!= 'Q');

    
    
    //test overloaded stream extraction operator
    
        cout << endl << endl;
        cout << "Testing stream extraction operator" << endl;
        CounterTop c2;
        cout << "Enter data: " << endl;
        cin >> c2;
        cout << endl;
        cout << "Values entered: " << endl;
        cout << c2 << endl;
    

        
        
    return 0;
} //END FUNCTION MAIN



/********************************************************************************
 *                                                                              *                                                                              * 
 *                                                                              *
 *                                                                              *
 *                 Function Definitions for Project #4                          *
 *                                                                              *
 *                                                                              *
 *                                                                              *
 ********************************************************************************/


/********************************************************************************
 *                            Display Menu                                      *
 ********************************************************************************/

char displayMenu()
{
    
    char choice = ' ';
    cout << setw(40) << "Upload a regional sales data file" << "\t" << "U" << endl;
    cout << setw(40) << "Display details (All loaded data)" << "\t" << "A" << endl;
    cout << setw(40) << "List details for specific Order number" << "\t" << "O" << endl;
    cout << setw(40) << "Display summary by Region" << "\t" << "R" << endl;
    cout << setw(40) << "Display summary by Stone code" << "\t" << "S" << endl;
    cout << setw(40) << "Clear all vectors" << "\t" << "C" << endl;
    cout << setw(40) << "Quit" << "\t" << "Q" << endl;   
    
    cout << endl;
    cout << "Please choose an option from the menu and enter the code: ";
    cin >> choice;
    
    //only read in first letter. Clear input stream of any extraneous chars
    cin.ignore(100000000, '\n');
    cout << endl;
    
    //if invalid input, display menu again
    while(toupper(choice)!='U' && toupper(choice)!='A' && toupper(choice)!='O'
          && toupper(choice)!='R' && toupper(choice)!='S' && toupper(choice)!='C'
          && toupper(choice)!='Q')
    {
        cout << endl;
        cout << "Invalid choice. Here are the valid choices: " << endl;
        cout << endl;
        cout << setw(40) << "Upload a regional sales data file" << "\t" << "U" << endl;
        cout << setw(40) << "Display details (All loaded data)" << "\t" << "A" << endl;
        cout << setw(40) << "List details for specific Order number" << "\t" << "O" << endl;
        cout << setw(40) << "Display summary by Region" << "\t" << "R" << endl;
        cout << setw(40) << "Display summary by Stone code" << "\t" << "S" << endl;
        cout << setw(40) << "Clear all vectors" << "\t" << "C" << endl;
        cout << setw(40) << "Quit" << "\t" << "Q" << endl;
        cout << endl;
        cout << "Please choose an option from the menu and enter the code: ";
        cin >> choice;
        cout << endl;
    }
    
    return choice;
}


/********************************************************************************
 *                               Upload File                                    *
 ********************************************************************************/

void uploadFile(string fName, bool &loadSuccess, vector <CounterTop > &vCounterTops)

{
    int previousSize = vCounterTops.size();
    
    //ifstream object
    ifstream inFile;

    //order date variables
    int ODYear = 0;
    int ODMonth = 0;
    int ODDay = 0;
    
    //delivery date variables
    int DDYear = 0;
    int DDMonth = 0;
    int DDDay = 0;
    
    //variable for slash between date
    char ch = ' '; 
    
    //variable to read over first line and "get it over with"
    string firstLine = " ";
    
    //variable to read rest of line (address, state code, name, etc)
    string restOfLine = " ";

    //data and calculation variables
    char stoneCode = ' ';
    double length = 0.0;
    double depth = 0.0;
    double height = 0.0;
    int numLengthEdgesFinished = 0;
    int numDepthEdgesFinished = 0;
    double minHeight = 0.0;
    double maxHeight = 0.0;
    string orderNumber = " ";
    string stateCode = " ";
    string region = " ";
    string nameAddress = " ";
            
    //variables to count number of records with errors
    int totalErrorCount = 0;
    int OrderDeliverySame = 0;
    int DeliveryDateTooFar = 0;
    int invalidStoneCode = 0;
    int invalidLength = 0;
    int invalidDepth = 0;
    int invalidHeight =0;
    int invalidLengthEdges = 0;
    int invalidDepthEdges = 0;
    
    //variables to count number of records without errors
    int marbleRecords = 0;
    int graniteRecords = 0;
    int quartzRecords = 0;
    int totalNonError = 0;
    int totalRecords = 0;

    //total count of all errors in all records
    int totalErrors = 0;

    //count of records with multiple errors
    int multipleErrorRecords = 0;

    
    //OPEN FILE
    inFile.open(fName.c_str());

    if(!inFile)
    {
        cout << "Error loading the file." << endl;
        //if file failed to load, set boolean parameter loadSuccess to false
        loadSuccess = false;
        cout << endl;
    }
    else
    {
        //PRINT HEADINGS
        cout << setw(8)<< "Order" << setw(17) << "Delivery" << setw(8) << "S";
        cout << setw(48) << "L" << "\t";
        cout << "D" << endl;
        cout << setw(8) << "Date" << setw(17) << "Date" <<"\t" << "C" << setw(15) << "Len.";
        cout << setw(14) << "Dep." << setw(12) << "Hei." << "\t" << "E" << "\t" << "E" << endl;
        cout << "_____________________________________________________________________________";
        cout << "__________________________________________\n";
        
        //read and ignore column headings
        getline(inFile, firstLine);
        
        //process the file until end of the file is reached
        while (inFile >> ODYear >> ch >> ODMonth >> ch >> ODDay >> DDYear >> ch 
                      >> DDMonth >> ch >> DDDay >> stoneCode >> length >> depth >> height
                      >> numLengthEdgesFinished >> numDepthEdgesFinished >> orderNumber 
                      >> region >> stateCode && getline(inFile, nameAddress))
        {
            //count number of total records in the file
            totalRecords++;
            
            //print data            
            //print order date
            cout << ODYear << ch;
            if(ODMonth <=9)
            {
                cout << "0" << ODMonth << ch;
            }
            else
            {
                cout << ODMonth << ch;
            }
            
            if(ODDay <=9)
            {
                cout << "0" << ODDay << "\t";
            }
            else
            {
                cout << ODDay << "\t";
            }
            
            //print delivery date
            cout << DDYear << ch;
            if(DDMonth <=9)
            {
                cout << "0" << DDMonth << ch;
            }
            else
            {
                cout << DDMonth << ch;
            }
            
            if(DDDay <=9)
            {
                cout << "0" << DDDay << "\t";
            }
            else
            {
                cout << DDDay << "\t";
            }
            
            cout << stoneCode << "\t";
            cout << fixed << setprecision(2) << setw(8) << length << "\t" << setw(6) << depth;
            cout << "\t" << setw(10) << height << "\t";
            cout << numLengthEdgesFinished << "\t" << numDepthEdgesFinished << "\t";
            
            /*         
            Test data validity and display error messages as necessary.
            Variable to count number of errors within one record
            in the while loop because it must be reset before reading every record
            to count number of errors within each record
            */
            
            int individualErrorCount = 0;
            
            //order date and delivery date are equal
            if(ODYear == DDYear && ODMonth == DDMonth && ODDay == DDDay)
            {
                cout << endl;
                cout << "\t";
                cout << "ERROR: order date and delivery date are equal.";
                individualErrorCount ++;
                OrderDeliverySame ++;
                totalErrors ++;
            }
            
            //order date and delivery date are too far apart
            
            if(DDYear >= ODYear && DDYear < ODYear + TWO_YEAR_DIFFERENCE)
            {
                if (DDYear == ODYear)
                {
                    if(DDMonth-ODMonth > FOUR_MONTH_DIFFERENCE)
                    {
                        cout << endl;
                        cout << "\t";
                        cout << "ERROR: order date and delivery date are too far apart.";
                        individualErrorCount ++;                       
                        DeliveryDateTooFar ++;
                        totalErrors ++;
                    } 
                }
                if (DDYear == ODYear + ONE_YEAR_DIFFERENCE)
                {
                    if(DDMonth-ODMonth >= FOUR_MONTH_DIFFERENCE_NEW_YEAR 
                            && DDMonth-ODMonth < TWELVE_MONTH_DIFFERENCE)
                    {
                        cout << endl;
                        cout << "\t";
                        cout << "ERROR: order date and delivery date are too far apart.";
                        individualErrorCount ++;
                        DeliveryDateTooFar ++;
                        totalErrors ++;
                    }
                }
            }
            else if(DDYear >= ODYear + TWO_YEAR_DIFFERENCE)
            {
                cout << endl;
                cout << "\t";
                cout << "ERROR: order date and delivery date are too far apart.";
                individualErrorCount ++;
                DeliveryDateTooFar ++;
                totalErrors ++;
            }
            
            
            //test stone type validity - stone code must be g, G, m, M, q, or Q
            if((toupper(stoneCode)!= 'G')&&(toupper(stoneCode)!= 'M')
               &&(toupper(stoneCode)!= 'Q'))
            {
                cout << endl;
                cout << "\t" << "ERROR: stone code is not a valid value.";
                individualErrorCount ++;
                invalidStoneCode ++;
                totalErrors ++;
            }
            
            //test length validity - MIN_LENGTH < length < MAX_LENGTH
            if((length < MIN_LENGTH) || (length > MAX_LENGTH))
            {
                cout << endl;
                cout << "\t" << "ERROR: Invalid length.";    
                individualErrorCount ++;
                invalidLength ++;
                totalErrors ++;
            }
            
            
            //test depth validity - MIN_DEPTH < depth < MAX_DEPTH and depth <=length
            if((depth < MIN_DEPTH) || (depth > MAX_DEPTH) || (depth > length))
            {
                cout << endl;
                cout << "\t" << "ERROR: Invalid depth.";
                individualErrorCount ++;
                invalidDepth ++;
                totalErrors ++;
            }
            
            //initialize range for min and max height
            minHeight = MIN_HEIGHT_FACTOR*depth;
            maxHeight = MAX_HEIGHT_FACTOR*depth;
            
            //test height entry validity
            if((height < minHeight) || (height > maxHeight))
            {
                cout << endl;
                cout << "\t" << "ERROR: Invalid height value."; 
                individualErrorCount ++;
                invalidHeight ++;
                totalErrors ++;
            }
            
            //test for validity of number of finished length edges
            if(numLengthEdgesFinished < MIN_EDGES_FINISHED
               || numLengthEdgesFinished > MAX_EDGES_FINISHED)
            {
                cout << endl;
                cout << "\t";
                cout << "ERROR: The number of length edges you want ";
                cout << "finished is out of our range.";

                individualErrorCount ++;
                invalidLengthEdges ++;
                totalErrors ++;
            }
            
            //test for validity of number of finished depth edges
            if(numDepthEdgesFinished < MIN_EDGES_FINISHED
               || numDepthEdgesFinished > MAX_EDGES_FINISHED)
            {
                cout << endl;
                cout << "\t";
                cout << "ERROR: The number of depth edges you want ";
                cout << "finished is out of our range.";
                individualErrorCount ++;
                invalidDepthEdges ++;
                totalErrors ++;
            }

            
            if (individualErrorCount > ZERO_ERRORS) 
            {
                cout << endl;
                totalErrorCount++;
                if (individualErrorCount > ONE_ERROR)
                {
                    multipleErrorRecords++;                    
                }
            }            
            else
            {
                //if the record has no error, then count it toward total number of
                //records without errors
                totalNonError++;
                
                
                /*if row of data passes all validation checks, pass those values to one object
                 * and add to CounterTop vector */
                CounterTop c1(ODYear, ODMonth, ODDay, DDYear, DDMonth, DDDay, stoneCode, 
                              length, depth, height, numLengthEdgesFinished, 
                              numDepthEdgesFinished, orderNumber, region, 
                              stateCode, nameAddress);
                
                vCounterTops.push_back(c1);
                cout << "\t";
                cout << endl;
            }
        } //END while loop

        
        //close the file
        inFile.close();
        
        
        //print out summary data
        cout << endl;
        cout << "Counts: " << "\t";
        cout << "Total Records = " << totalRecords << "\t";
        cout << "Records with Errors = " << totalErrorCount <<  "\t";
        cout << "Records without Errors = " << totalNonError << "\t" << endl;
        cout << endl;
        
        
        cout << "\t\t" << "*****************************************************" << endl;
        cout << "\t\t" << "*               Count of Overall Errors             *" << endl;
        cout << "\t\t" << "*****************************************************" << endl;
        cout << endl;
        
        cout << setw(25) << totalErrorCount << " - records with errors." << endl;
        cout << setw(25) << totalNonError << " - records without errors." << endl;
        cout << "\t\t" << "____________________________________________________" << endl;
        cout << setw(25) << totalRecords << " - total records." << endl;
        cout << endl;

        
        cout << "\t\t" << "*****************************************************" << endl;
        cout << "\t\t" << "*             Count of Individual Errors            *" << endl;
        cout << "\t\t" << "*****************************************************" << endl;
        cout << endl;
        
        cout << setw(25) << OrderDeliverySame << " - order date and delivery date same" << endl;
        cout << setw(25) << DeliveryDateTooFar << " - delivery date too far in future" << endl;
        cout << setw(25) << invalidStoneCode << " - stone code not valid." << endl;
        cout << setw(25) << invalidLength << " - length not valid" << endl;
        cout << setw(25) << invalidDepth << " - depth not valid" << endl;
        cout << setw(25) << invalidHeight << " - height not valid" << endl;
        cout << setw(25) << invalidLengthEdges << " - length edges to finish not valid" << endl;
        cout << setw(25) << invalidDepthEdges << " - depth edges to finish not valid" << endl;
        cout << "\t\t" << "____________________________________________________" << endl;
        cout << setw(25) << totalErrors << " - total count of all errors in all records" << endl;
        cout << setw(25) << multipleErrorRecords;
        cout << " - count of records with multiple errors" << endl;
        cout << endl;
        cout << endl;
        
        cout << setw(25) << totalNonError << " added to vectors,   ";
        cout << vCounterTops.size() << " total records now loaded." << endl;
        cout << endl;
        cout << endl;
        
        
        //set boolean variable loadSuccess - true if vector size increased, false if not
        if(vCounterTops.size() > previousSize)
        {
            loadSuccess = true;
        }
        else
        {
            loadSuccess = false;
        }
    } //END else part of if(!inputFile) 
}


/********************************************************************************
 *                           Display All Details                                *
 ********************************************************************************/

void allDetails(const vector <CounterTop> &vCounterTops)
{    
    //number of records for each stone type
    int graniteRecords = 0;
    int quartzRecords = 0;
    int marbleRecords = 0;
    
    //total square feet
    double totalSqFtMarble = 0.0;
    double totalSqFtGranite = 0.0;
    double totalSqFtQuartz = 0.0;   
    
    //total cost
    double totalCostMarble = 0.0;
    double totalCostGranite = 0.0;
    double totalCostQuartz = 0.0;
   
    int totalRecords = 0;
    
    //PRINT HEADINGS
    cout << setw(13) << "Order" << setw(17) << "S" << setw(37) << "L";
    cout << setw(7) <<  "D" << setw(12) << "Sq." << setw(16) << "Total" << endl;
    cout << setw(13) << "Number" << setw(10) << "Region" << setw(7) << "C";
    cout << "\t" << setw(8) << "Len." << setw(10) << "Dep.";
    cout << setw(10) << "Hei." << setw(7)<< "E";
    cout << setw(7) << "E"<< setw(12) << "Ft." << setw(16) << "Cost" << endl;
    cout << "______________________________________________________________";
    cout << "_________________________________________________________\n";
    cout << endl;

    //print all VALID data and calculated data WITHOUT DATES
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        totalRecords++;
        cout << vCounterTops.at(i) << endl;
        
        if(toupper(vCounterTops.at(i).getStoneCode()) == 'G')
        {
            graniteRecords++;
            //total cost of granite = sum of total cost for each granite record
            totalCostGranite += vCounterTops.at(i).getTotalCost();
            //total square feet of granite = sum of total sq ft of granite in each
           //granite record
            totalSqFtGranite += vCounterTops.at(i).getMaterialRequired();
        }
        else if(toupper(vCounterTops.at(i).getStoneCode()) == 'M')
        {
            marbleRecords++;
            totalCostMarble += vCounterTops.at(i).getTotalCost();
            totalSqFtMarble += vCounterTops.at(i).getMaterialRequired();
        }
        else if(toupper(vCounterTops.at(i).getStoneCode()) == 'Q')
        {
            quartzRecords++;
            totalCostQuartz += vCounterTops.at(i).getTotalCost();
            totalSqFtQuartz += vCounterTops.at(i).getMaterialRequired();
        }
    } // END for loop
    

    //print out summary data
    cout << endl;
    cout << "Counts: " << "\t";
    cout << "Total Records = " << totalRecords << "\t";
    cout << endl;
     
    cout << "\t\t\t" << "TOTALS" << endl;
    cout << setw(15) << "Stone" << setw(15) << "Count" << setw(20) << "Square Feet";
    cout << setw(25) << "Cost" << endl;
    cout << "______________________________________________________________________________";
    cout << "____________________";
    cout << endl;
        
        
    //print marble data
    cout << setw(15) << "Marble" << setw(15) << marbleRecords;
    cout << setw(20) << totalSqFtMarble << setw(30) <<totalCostMarble;
    cout << endl;
    
        
    //print granite data
    cout << setw(15) << "Granite" << setw(15) << graniteRecords;
    cout << setw(20) << totalSqFtGranite << setw(30) <<totalCostGranite;
    cout << endl;
        
        
    //print quartz data
    cout << setw(15) << "Quartz" << setw(15) << quartzRecords;
    cout << setw(20) << totalSqFtQuartz << setw(30) << totalCostQuartz;
    cout << endl;     
    cout << "______________________________________________________________________________";
    cout << "____________________" << endl;
    cout << endl;
}



/********************************************************************************
 *                       Display Specific Order Detail                          *
 ********************************************************************************/

void orderDetails(const vector <CounterTop> &vCounterTops)
{
    //prompt user for order number
    string orderNumberData = " ";
    bool matchNotFound = true;
    string orderNumberUser = " ";
    cout << "Please enter the order number of the order you want to see: ";
    cin >> orderNumberUser;
    
    //PRINT HEADINGS
    cout << setw(13) << "Order" << setw(17) << "S" << setw(37) << "L";
    cout << setw(7) <<  "D" << setw(12) << "Sq." << setw(16) << "Total" << endl;
    cout << setw(13) << "Number" << setw(10) << "Region" << setw(7) << "C";
    cout << "\t" << setw(8) << "Len." << setw(10) << "Dep.";
    cout << setw(10) << "Hei." << setw(7)<< "E";
    cout << setw(7) << "E"<< setw(12) << "Ft." << setw(16) << "Cost" << endl;
    cout << "______________________________________________________________";
    cout << "_________________________________________________________\n";
    cout << endl;

    //print specific order data
    for(unsigned long i=0; i<vCounterTops.size(); i++)
    {
        if(vCounterTops.at(i).getOrderNum() == orderNumberUser)
        {   
            cout << vCounterTops.at(i) << endl;
            cout << endl;

            orderNumberData = orderNumberUser;
            matchNotFound = false;
        }
    }
    
    if(orderNumberData == " " && matchNotFound /*== true*/)
    {
        cout << "Order number not found." << endl;
        cout << endl;
    }
}


/********************************************************************************
 *                     Display a Summary by Stone Code                          *
 ********************************************************************************/

void summaryByStone(const vector <CounterTop> &vCounterTops)
{
    //total square feet
    double totalSqFtMarble = 0.0;
    double totalSqFtGranite = 0.0;
    double totalSqFtQuartz = 0.0;
    
    
    //number of records for each stone type
    int graniteRecords = 0;
    int quartzRecords = 0;
    int marbleRecords = 0;
    
    //total cost
    double totalCostMarble = 0.0;
    double totalCostGranite = 0.0;
    double totalCostQuartz = 0.0;
    
    int totalRecords = 0;
    
    //print the granite records
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        if(toupper(vCounterTops.at(i).getStoneCode())=='G')
        {
            totalRecords++;
            graniteRecords++;
            totalCostGranite += vCounterTops.at(i).getTotalCost();
            //total square feet of granite = sum of total sq ft of granite in each
            //granite record
            totalSqFtGranite += vCounterTops.at(i).getMaterialRequired();
        }
    }
    
    //print the quartz records
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        if(toupper(vCounterTops.at(i).getStoneCode())=='Q')
        {
            totalRecords++;
            quartzRecords++;
            totalCostQuartz += vCounterTops.at(i).getTotalCost();
            //total square feet of granite = sum of total sq ft of quartz in each
            //quartz record
            totalSqFtQuartz += vCounterTops.at(i).getMaterialRequired();
        }
    }

    //print the marble records 
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        if(toupper(vCounterTops.at(i).getStoneCode())=='M')
        {
            totalRecords++;
            marbleRecords++;
            totalCostMarble += vCounterTops.at(i).getTotalCost();
            totalSqFtMarble += vCounterTops.at(i).getMaterialRequired();
        }
    }
    
    //print out summary data
    cout << endl;
    cout << "Counts: " << "\t";
    cout << "Total Records = " << totalRecords << "\t";
    cout << endl;
     
    cout << setw(25) << "TOTALS (All Loaded Files)" << endl;
    cout << setw(15) << "Stone" << setw(15) << "Count" << setw(20) << "Square Feet";
    cout << setw(15) << "Cost" << endl;
    cout << "______________________________________________________________________________";
    cout << "____________________";
    cout << endl;
        
        
    //print marble data
    cout << setw(15) << "Marble" << setw(15) << marbleRecords;
    cout << setw(20) << totalSqFtMarble << setw(20) <<totalCostMarble;
    cout << endl;
    
        
    //print granite data
    cout << setw(15) << "Granite" << setw(15) << graniteRecords;
    cout << setw(20) << totalSqFtGranite << setw(20) <<totalCostGranite;
    cout << endl;
        
        
    //print quartz data
    cout << setw(15) << "Quartz" << setw(15) << quartzRecords;
    cout << setw(20) << totalSqFtQuartz << setw(20) << totalCostQuartz;
    cout << endl;     
    cout << "______________________________________________________________________________";
    cout << "____________________" << endl;
    cout << endl;
}   


/********************************************************************************
 *                     Display a Summary by Region                              *
 ********************************************************************************/

void summaryByRegion(const vector <CounterTop> &vCounterTops)
{
    //variables to count number of records without errors
    int totalRecords = 0;
    int northRecords = 0;
    int eastRecords = 0;
    int southRecords = 0;
    int westRecords = 0;
    int otherRecords = 0;
    
    //total square feet
    double totalSqFtNorth = 0.0;
    double totalSqFtEast = 0.0;
    double totalSqFtSouth = 0.0;
    double totalSqFtWest = 0.0;
    double totalSqFtOther = 0.0;
    
    //total cost
    double totalCostNorth = 0.0;
    double totalCostEast = 0.0;
    double totalCostSouth = 0.0;
    double totalCostWest = 0.0;
    double totalCostOther = 0.0;
    
    
    //PRINT DATA BY REGION
    
    //NORTH RECORDS
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {

        if(vCounterTops.at(i).getRegion() == NORTH)
        {
            totalRecords++;
            northRecords++;
            totalCostNorth += vCounterTops.at(i).getTotalCost();
            totalSqFtNorth += vCounterTops.at(i).getMaterialRequired();
        }
    }
    
    //SOUTH RECORDS
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        if(vCounterTops.at(i).getRegion() == SOUTH)
        {
            totalRecords++;
            southRecords++;
            totalCostSouth += vCounterTops.at(i).getTotalCost();
            totalSqFtSouth += vCounterTops.at(i).getMaterialRequired();
        }
    }
    
    //EAST RECORDS
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        if(vCounterTops.at(i).getRegion() == EAST)
        {
            totalRecords++;
            eastRecords++;
            totalCostEast += vCounterTops.at(i).getTotalCost();
            totalSqFtEast += vCounterTops.at(i).getMaterialRequired();
        }
    }

    //WEST RECORDS
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        if(vCounterTops.at(i).getRegion() == WEST)
        {
            totalRecords++;
            westRecords++;
            totalCostWest += vCounterTops.at(i).getTotalCost();
            totalSqFtWest += vCounterTops.at(i).getMaterialRequired();
        }   
    }
    
    //OTHER RECORDS
    for(unsigned long i = 0; i<vCounterTops.size(); i++)
    {
        if(vCounterTops.at(i).getRegion() == OTHER)
        {
            totalRecords++;
            otherRecords++;
            totalCostOther += vCounterTops.at(i).getTotalCost();
            totalSqFtOther += vCounterTops.at(i).getMaterialRequired();
        }   
    }

    //print out summary data
    cout << endl;
    cout << "Counts: " << "\t";
    cout << "Total Records = " << totalRecords << "\t";
    cout << endl;
     
    cout << setw(25) << "TOTALS (All Loaded Files)" << endl;
    cout << setw(15) << "Region" << setw(15) << "Count" << setw(20) << "Square Feet";
    cout << setw(15) << "Cost" << endl;
    cout << "______________________________________________________________________________";
    cout << "____________________";
    cout << endl;
        
        
    //print North data
    cout << setw(15) << "North" << setw(15) << northRecords;
    cout << setw(20) << totalSqFtNorth << setw(20) <<totalCostNorth;
    cout << endl;
    
    //print South data
    cout << setw(15) << "South" << setw(15) << southRecords;
    cout << setw(20) << totalSqFtSouth << setw(20) << totalCostSouth;
    cout << endl;
    
    //print East data
    cout << setw(15) << "East" << setw(15) << eastRecords;
    cout << setw(20) << totalSqFtEast << setw(20) <<totalCostEast;
    cout << endl;

    //print West data
    cout << setw(15) << "West" << setw(15) << westRecords;
    cout << setw(20) << totalSqFtWest << setw(20) <<totalCostWest;
    cout << endl;
    
    //print Other data
    cout << setw(15) << "Other" << setw(15) << otherRecords;
    cout << setw(20) << totalSqFtOther << setw(20) <<totalCostOther;
    cout << endl;
    
    cout << "______________________________________________________________________________";
    cout << "____________________" << endl;
    cout << endl;
}