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
        City *c = new City(cityName, head, "", NULL);
        head = c;
    }else{

        City * tmp = head;

        while(tmp->cityName != previousCity && tmp->next != NULL)
        {
            tmp = tmp->next;
        }


        City * newCity = new City(cityName, tmp->next, "", tmp->previous);

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
            cityAdded = new City(cityArray[i], NULL, "", NULL);
            currentCity = cityAdded;
            head = currentCity;
        }else{
            cityAdded = new City(cityArray[i], NULL, "", currentCity);
            currentCity->next = cityAdded;
            cityAdded->previous = currentCity;
            currentCity = cityAdded;
        }
    }
    tail = currentCity;
}
void CommunicationNetwork::transmitMsg(string message){

    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    City *sender = head;
    while(message == message){
    sender->message = message;
        cout<<sender->cityName<<" received "<<sender->message<<endl;
        while(sender->next != NULL){
            sender->previous->message = message;
            cout<<sender->next->cityName<<" received "<<sender->next->message<<endl;
            sender->message = "";
            sender = sender->next;
            }
            if(sender->next==NULL)
                break;
        }
        sender = head;
        }


void CommunicationNetwork::printNetwork(){

    cout << "===CURRENT PATH===" << endl;
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
    City *tmp = head;

    while (tmp != NULL && tmp->cityName != name)
    {
        tmp = tmp->next;
    }
    tmp->next->previous = tmp->previous;
    tmp->previous->next = tmp->next;
    delete tmp;

    }
void CommunicationNetwork::showMailPath(string beginCity, string endCity){
    City *tmp = head;

    while (tmp != NULL && tmp->cityName != beginCity)
    {
        tmp = tmp->next;
    }
    City *found = tmp;
    while(found->cityName != endCity){
        cout<<found->cityName<<"->";
    }
}

int CommunicationNetwork::countTotalCities(){
    int counter = 0;
    City *tmp = head;
    while(tmp!=NULL){
        tmp=tmp->next;
        counter++;
    }
        }
int CommunicationNetwork::countCitiestransit(string beginCity, string endCity){
    int counter = 0;
      City *tmp = head;

    while (tmp != NULL && tmp->cityName != beginCity)
    {
        tmp = tmp->next;
    }
    City *countC = tmp;
    while(countC->cityName != endCity){
        countC = countC->next;
        counter++;
        }
        }

void CommunicationNetwork::transmitmessback(string message){
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    City *sender = tail;
    while(message == message){
    sender->message = message;
        cout<<sender->cityName<<" received "<<sender->message<<endl;
        while(sender->next != NULL){
            sender->previous->message = message;
            cout<<sender->previous->cityName<<" received "<<sender->previous->message<<endl;
            sender->message = "";
            sender = sender->previous;
            }
            if(sender->previous==NULL)
                break;
        }
        sender = tail;
        }
void CommunicationNetwork::searchNetwork(string Name)
{
    City *tmp = head;
    while (tmp != NULL && tmp->cityName != Name)
    {
        tmp = tmp->next;
    }
    cout<< tmp->cityName<<"found"<<endl;
}

