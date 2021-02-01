
#include <iostream> // for streams
#include <fstream>  // for file stream
#include <string>   // for strings
#include <cstdlib>  // for exit
#include <iomanip>  // for format
using namespace std;
class Taxi
{
public:
    //Constractors declarations
    Taxi();
    Taxi(string cDriversName,string cCarMake, string cCarColor);
    Taxi(int cTotalCall,int cTotalPass);
    
    // getters member functions
    string getDrName();
    string getCarMake();
    string getCarColor();
    int getTotalCall() const;
    int getTotalPass() const;
    
    //setters member functions
    void setTotalCall(int sTotalCall);
    void setTotalPass(int sTotalPass);
    
    // declaring static variables
    static int numCalls1;
    static int numCalls2;
    static int numCalls3;
    static int numCalls4;
    static int numCalls5;
    static int numCalls6;
    static int allCalls;

private:
    string driversName;
    string carMake;
    string carColor;
    int totalCall;
    int totalPass;
   
};

const Taxi operator +(const Taxi& a,const Taxi& b);     // Operator + overloading function declaration
bool operator <(const Taxi& a,const Taxi& b);           // Operator < overloading function declaration

// initializing static variables
int Taxi::numCalls1 = 0;
int Taxi::numCalls2 = 0;
int Taxi::numCalls3 = 0;
int Taxi::numCalls4 = 0;
int Taxi::numCalls5 = 0;
int Taxi::numCalls6 = 0;
int main()
{
    ofstream outFile;
    outFile.open("TaxiRepor.txt");
    if ( outFile.fail())
    {
        cerr << "Output file opening failed."<<endl;
        exit(1);
    }
    char response;
    Taxi taxiArr[6];
    taxiArr[0] = Taxi("James","Ford","Red");
    taxiArr[1] = Taxi("Peter","GM","Blue");
    taxiArr[2] = Taxi("Ahmed","Toyota","Yellow");
    taxiArr[3] = Taxi("Rodriguez","Honda","Green");
    taxiArr[4] = Taxi("John","Telsa","Orange");
    taxiArr[5] = Taxi("Chung","BMW","Black");
    Taxi taxi;
    cout << "Welcome to ABC  Taxi" <<endl;
    while(1)
    {
        srand(time(0));
    cout << "Do you need a Taxi ? 'Y' for yes and 'N' for no :" <<endl;
    cin >> response;
    if ( response != 'Y' && response != 'y' && response != 'N' && response != 'n')
    {
        cout << "Invalid entry Goodbye " <<endl;
        exit(1);
    }
    if ( response == 'N' || response == 'n')
        break;
        
        int randomNum = rand() % 6 + 1;             // generate random taxi object from 1 to 6 inclusive
        int ridePassCount = rand() % 3 + 1;
        switch (randomNum)
        {
                // rand() % 3 + 1 represents random selection of 1 to 3 passengers per taxi
        case 1:
                taxiArr[0].setTotalPass(taxiArr[0].getTotalPass() + ridePassCount);
                cout << "Taxi #1 \" Driver " << taxiArr[0].getDrName() << " in a " << taxiArr[0].getCarColor() <<" " << taxiArr[0].getCarMake() << " \" will pick you up in few min.(Taxi6 determined that they were "<< ridePassCount << " passengers)" <<endl;
                Taxi::numCalls1++;
                taxiArr[0].setTotalCall(Taxi::numCalls1);
                break;
        case 2:
                taxiArr[1].setTotalPass(taxiArr[1].getTotalPass() + ridePassCount);
                cout << "Taxi #2 \" Driver " << taxiArr[1].getDrName() << " in a " << taxiArr[1].getCarColor() <<" " << taxiArr[1].getCarMake() << " \" will pick you up in few min.(Taxi6 determined that they were "<< ridePassCount << " passengers)" <<endl;
                Taxi::numCalls2++;
                taxiArr[1].setTotalCall(Taxi::numCalls2);
                break;
        case 3:
                taxiArr[2].setTotalPass(taxiArr[2].getTotalPass() + ridePassCount);
                cout << "Taxi #3 \" Driver " << taxiArr[2].getDrName() << " in a " << taxiArr[2].getCarColor() <<" " << taxiArr[2].getCarMake() << " \" will pick you up in few min.(Taxi6 determined that they were "<< ridePassCount << " passengers)" <<endl;
                Taxi::numCalls3++;
                taxiArr[2].setTotalCall(Taxi::numCalls3);
                break;
        case 4:
                taxiArr[3].setTotalPass(taxiArr[3].getTotalPass() + ridePassCount);
                cout << "Taxi #4 \" Driver " << taxiArr[3].getDrName() << " in a " << taxiArr[3].getCarColor() <<" " << taxiArr[3].getCarMake() << " \" will pick you up in few min.(Taxi6 determined that they were "<< ridePassCount << " passengers)" <<endl;
                Taxi::numCalls4++;
                taxiArr[3].setTotalCall(Taxi::numCalls4);
                break;
        case 5:
                taxiArr[4].setTotalPass(taxiArr[4].getTotalPass() + ridePassCount);
                cout << "Taxi #5 \" Driver " << taxiArr[4].getDrName() << " in a " << taxiArr[4].getCarColor() <<" " << taxiArr[4].getCarMake() << " \" will pick you up in few min. (Taxi6 determined that they were "<< ridePassCount << " passengers)" <<endl;
                Taxi::numCalls5++;
                taxiArr[4].setTotalCall(Taxi::numCalls5);
                break;
        case 6:
                taxiArr[5].setTotalPass(taxiArr[5].getTotalPass() + ridePassCount);
                cout << "Taxi #6 \" Driver " << taxiArr[5].getDrName() << " in a " << taxiArr[5].getCarColor() <<" " << taxiArr[5].getCarMake() << " \" will pick you up in few min. (Taxi6 determined that they were "<< ridePassCount << " passengers)" <<endl;
                Taxi::numCalls6++;
                taxiArr[5].setTotalCall(Taxi::numCalls6);
                break;
                
        }
    }
    Taxi finalTotalPass = taxiArr[0] + taxiArr[1] + taxiArr[2] + taxiArr[3] + taxiArr[4] + taxiArr[5];
    // display the total number of passengers served
    outFile << "ABC taxi served a total of " << finalTotalPass.getTotalPass()  << " passengers today. "<<endl;
    
    outFile << left << setw(18) << "Taxi 1" << setw(18) << "Taxi 2" << setw(18) << "Taxi 3" << setw(18) << "Taxi 4" << setw(18) << "Taxi 5" << setw(18) << "Taxi 6" <<endl;
    
    outFile << left << taxiArr[0].getTotalCall() << setw(17) <<" calls" << taxiArr[1].getTotalCall() << setw(17) << " calls" << taxiArr[2].getTotalCall() << setw(17) << " calls" <<  taxiArr[3].getTotalCall() << setw(17) << " calls" << taxiArr[4].getTotalCall() << setw(17) << " calls" << taxiArr[5].getTotalCall() << setw(17) << " calls" <<endl;
   
    outFile << left << taxiArr[0].getTotalPass() << setw(17) << " passengers" << taxiArr[1].getTotalPass() << setw(17) << " passengers" << taxiArr[2].getTotalPass() << setw(17) << " passengers" <<  taxiArr[3].getTotalPass() << setw(17) << " passengers" << taxiArr[4].getTotalPass() << setw(17) << " passengers" << taxiArr[5].getTotalPass() << setw(17) << " passengers" <<endl;
    
    int index = 0;
    Taxi mostPass = taxiArr[0];
    for (int i = 0; i < 6; i++)
    {
        if ( mostPass < taxiArr[i] )
        {
            mostPass = taxiArr[i];
            index = i;
        }
    }
    outFile.setf(ios::fixed);
    outFile.setf(ios::showpoint);
    outFile.precision(2);
    
    outFile << "Today Taxi" << index + 1 << " served most passengers." <<endl;
    outFile << "Today on average each taxi served " << (static_cast<double> (finalTotalPass.getTotalPass()) / 6)<< " passengers."<<endl;
    
}
Taxi::Taxi()
{
    driversName = "No Name Yet";
    carMake = " No MAKE Yet";
    carColor = " NO COLOR YET";
    totalCall = 0;
    totalPass = 0;
}
Taxi::Taxi(string cDriversName,string cCarMake, string cCarColor)
{
    driversName = cDriversName;
    carMake = cCarMake;
    carColor = cCarColor;
}
Taxi::Taxi(int cTotalCall,int cTotalPass)
{
    totalCall = cTotalCall;
    totalPass = cTotalPass;
}
string Taxi::getDrName()
{
    return driversName;
}
string Taxi::getCarMake()
{
    return carMake;
}
string Taxi::getCarColor()
{
    return carColor;
}

//getters definition
int Taxi::getTotalCall() const { return totalCall; }
int Taxi::getTotalPass() const { return totalPass; }

//setters definition
void Taxi::setTotalCall(int sTotalCall) { totalCall = sTotalCall; }
void Taxi::setTotalPass(int sTotalPass) {  totalPass = sTotalPass; }

// the + operator overloading function definition
const Taxi operator +(const Taxi& a,const Taxi& b)
{
    int tempCall = a.getTotalCall() + b.getTotalCall();
    int tempPass = a.getTotalPass() + b.getTotalPass();
    return Taxi(tempCall,tempPass);
}
bool operator <( const Taxi& a,const Taxi& b)
{
    return a.getTotalPass() < b.getTotalPass();
}

