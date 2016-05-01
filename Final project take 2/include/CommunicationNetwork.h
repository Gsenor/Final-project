#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
struct City{
    std::string cityName;
    std::string message;
    City *next;
    City *previous;

    City(){}; // default constructor

    City(std::string initName, City *initNext, std::string initMessage, City *initPrevious)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
        message = initMessage;
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork();
        ~CommunicationNetwork();
        void addCity(std::string, std::string);
        void buildNetwork();
        void transmitMsg(std::string); //this is like a string
        void printNetwork();
        void deleteCity(std::string);
        void showMailPath(std::string, std::string);
        int countTotalCities();
        int countCitiestransit(std::string, std::string);
        void transmitmessback(std::string);
        void searchNetwork(std::string);


    protected:
    private:
        City *head;
        City *tail;
};

#endif // COMMUNICATIONNETWORK_H
