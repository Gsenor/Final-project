#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>

using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    head = NULL;
    tail = NULL;
}

CommunicationNetwork::~CommunicationNetwork()
{
    //dtor
}
void CommunicationNetwork::addCity(string previousCity, string cityName){
    
    if(previousCity == "First")
    {
        City *c = new City(cityName, head, "");
        head = c;
    }else{

        City * tmp = head;

        while(tmp->cityName != previousCity && tmp->next != NULL)
        {
            tmp = tmp->next;
        }


        City * newCity = new City(cityName, tmp->next, "");

        tmp->next = newCity;
        tmp->next->previous = newCity;
    }


}
void CommunicationNetwork::buildNetwork(){

    string cityArray[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};
    int numCities = 10;
    City *cityAdded;
    City *currentCity;
    for(int i = 0; i < numCities; i++){
        if(head == NULL){
            cityAdded = new City(cityArray[i], NULL, "");
            currentCity = cityAdded;
            head = currentCity;
        }else{
            cityAdded = new City(cityArray[i], NULL, "");
            currentCity->next = cityAdded;
            cityAdded->previous = currentCity;
            currentCity = cityAdded;
        }
    }
    tail = currentCity;
}
void CommunicationNetwork::transmitMsg(char *filename){
    ifstream inStream; 
    inStream.open(filename);
    string msg;
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    City *sender = head;
    while (inStream>>msg)
    {
        sender->message = msg;
        cout<<sender->cityName<<" received "<<sender->message<<endl;
        while(sender->next != NULL){
            sender->next->message = msg;
            cout<<sender->next->cityName<<" received "<<sender->next->message<<endl;
            sender->message = "";
            sender = sender->next;
        }
        sender = head;
    }

    inStream.close();

}
void CommunicationNetwork::printNetwork(){

    cout << "===CURRENT PATH===" << endl;

    // If the head is NULL
    if (head == NULL)
        cout << "NULL" << endl;

    else
    {
        City *current = head;
        while (current->next != NULL)
        {
            cout << current->cityName << " -> ";
            current = current->next;
        }
        cout << current->cityName << " -> ";
        cout << "NULL" << endl;
    }

    cout << "==================" << endl;
    }
void CommunicationNetwork::deleteCity(string name){
    City *tmp = searchNetwork(name);
    tmp->next->previous = tmp->previous;
    tmp->previous->next = tmp->next;
    delete tmp;
    
    }
void CommunicationNetwork::showMailPath(beginCity, endCity){
    City *tmp = searchNetwork(beginCity);
    while(tmp->cityName != endCity){
        cout<<tmp->cityName<<"to";
    }
    
int CommunicationNetwork::countTotalCities(City * head){
    int counter = 0;
    City *tmp = head;
    while(tmp!=NULL){
        tmp=tmp->next;
        counter++;
    }
        }
int CommunicationNetwork::countCitiestransit(beginCity, endCity){
    int counter = 0;
    City *tmp = searchNetwork(beginCity);
        while(tmp->cityName != endCity){
            tmp= tmp->next;
            counter++;
        }
        }
        }
void CommunicationNetwork::transmitmessback(char *filename){
        ifstream inStream; 
    inStream.open(filename);
    string msg;
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    City *sender = tail;

    while (inStream>>msg)
    {
        sender->message = msg;
        cout<<sender->cityName<<" received "<<sender->message<<endl;
        while(sender->next != NULL){
            sender->previous->message = msg;
            cout<<sender->previous->cityName<<" received "<<sender->previous->message<<endl;
            sender->message = "";
            sender = sender->previous;
        }
        sender = tail;
    }
    inStream.close();
        }
City CommunicationNetwork::searchNetwork(string cityName)
{   
    City *tmp = head; 
    while (tmp != NULL && tmp->name != cityName)
    {
        tmp = tmp->next;
    }
    return tmp;
}
