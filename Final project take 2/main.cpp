#include <iostream>
#include <fstream>
#include "CommunicationNetwork.h"
using namespace std;
int main()
{

    int x = 0;
    CommunicationNetwork cn;


    while (x != 9)
    {
    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Count Total Cities" << endl;
    cout << "7. Count number of cities between two cities" << endl;
    cout << "8. Show path between cities" << endl;
    cout << "9. Quit" << endl;
        cin>>x;
        string city1;
        string city2;
        string message;
            if(x = 1){
                cn.buildNetwork();
                cn.printNetwork();
                }
            else if(x = 2){
                cn.printNetwork();
            }
            else if(x = 3){
                cout<<"Type a message"<<endl;
                cin>>message;
                cn.transmitMsg(message);
                cout<<"type a return message"<<endl;
                cin>>message;
                cn.transmitmessback(message);
                }


            else if( x = 4){
                cout << "Enter a city name: " << endl;
                cin>>city1;
                cout << "Enter a previous city name: " << endl;
                cin>>city2;

                cn.addCity(city2, city1);
                }
                else if(x = 5){
                cout << "Enter a city name: " << endl;
                cin>>city1;
                cn.deleteCity(city1);

                }
                else if (x = 6){
                cn.countTotalCities();

                }
                else if(x = 7){
                cout << "Enter the starting city: " << endl;
                cin>>city1;
                cout << "Enter the end city: " << endl;
                cin>>city2;
                cn.countCitiestransit(city1, city2);

                }
                else if(x = 8){
                cout << "Enter the starting city: " << endl;
                cin>>city1;
                cout << "Enter the end city: " << endl;
                cin>>city2;
                cn.showMailPath(city1, city2);
                }





        }
        if(x = 9){
            cout<<"GoodBye"<<endl;
        }
        return 0;
    }
