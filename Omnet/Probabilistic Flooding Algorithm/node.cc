/*
 * node.cc
 *   
 *  Created on: 17 Aug 2020
 *    Original Author: gtsou
 *   Edited by Alexandros Panagiotakopoulos
 */

#include <string.h>
#include <omnetpp.h>
#include "floodPacket_m.h"

/* seed functions srand */
#include <stdlib.h>
#include <time.h>

using namespace omnetpp;
int transmissionCounter = 0;



int success(){
   int x;
   x = rand() % 101; /* 100% chance 20% to fail 80% to succeed */
   return x;
}

class node : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    virtual bool isNetworkConnected();
    int startingNode;
    cMessage* timer;
    bool receivedPacket=false;
  public:
    int x;
};

Define_Module(node);

void node::initialize()
{
    startingNode = getAncestorPar("startingNode").intValue();
    if (getIndex()==startingNode){
        isNetworkConnected();
        timer = new cMessage();
        scheduleAt(simTime()+1, timer);
    }
}

void node::handleMessage(cMessage *msg)
{

    if (msg->isSelfMessage()){
        char name[50];
        sprintf(name, "Node %d packet", getIndex());
        FloodPacket* packet = new FloodPacket(name);
        packet->setSender(getIndex());
        for (int i=gateCount()/2;i<gateCount();i++){
            x=success(); /* we call the success function to determine whether or not the package was successful or not */
            send(packet->dup(), "gate$o", i - gateCount()/2);
            transmissionCounter++;
        }
        /* if received packet == true 0.9 chance */
        if(x>90){
        delete packet;
        receivedPacket = true;
        }
        /* else if received packet == false 0.2 chance */
        else{
        receivedPacket = false;
        }
    }
    else{
        if (receivedPacket)
            delete msg;
        else{
            FloodPacket* Packet = (FloodPacket*)msg;
            for (int i=gateCount()/2;i<gateCount();i++){
                x=success(); /* we call the success function to determine whether or not the package was successful or not */
                if (gateByOrdinal(i)->getNextGate()->getOwnerModule()->getIndex() != Packet->getSender()){
                    FloodPacket* PacketDup = Packet->dup();
                    PacketDup->setSender(getIndex());
                    send(PacketDup, "gate$o", i - gateCount()/2);
                    transmissionCounter++;
                }
            }
            if(x>90){ /* 90% if message was received */
                   delete msg;
                   receivedPacket = true;
                   }
                   /* else if message was not received 0.1 chance */
                   else{
                    delete msg;
                   receivedPacket = false;
               }
        }
    }
}

bool node::isNetworkConnected(){
    cTopology topo;
    topo.extractByProperty("node");
    topo.calculateUnweightedSingleShortestPathsTo(topo.getNode(0));
    for (int i=0;i<topo.getNumNodes();i++){
        if (i!=0 && topo.getNode(i)->getNumPaths()==0)
            {
                std::cout << "NOT CONNECTED";
                error("NOT CONNECTED");
            }
    }
    return true;
}

void node::finish(){
    if (getIndex() == startingNode){
        delete timer;
        recordScalar("Packet transmissions", transmissionCounter);
//        std::cout << "Packet transmissions " << transmissionCounter <<endl;
    }
}

