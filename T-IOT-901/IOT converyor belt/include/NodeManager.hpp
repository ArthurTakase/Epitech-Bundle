#ifndef NODE_MANAGER_H
#define NODE_MANAGER_H

#include <M5Stack.h>
#include <Arduino.h>
#include <sys/queue.h>

#define TIME_BY_SPEED_TILL_END_SECOUNDS 13

class NodeManager
{
public:
    typedef struct Node {
        int val;
        int time;
        SLIST_ENTRY(Node) next;
    } Node_t;

private:
    SLIST_HEAD(NodeList, Node) list;
    Node_t *lastNode = NULL;
    time_t lastTime = time(NULL) + TIME_BY_SPEED_TILL_END_SECOUNDS;

public:
    NodeManager();
    ~NodeManager();

    void pushNode(int val);
    void removeNode();
    void printNodes();
    Node_t *getFirstNode();
    Node_t *getNextNode();
    int getLastTime();
    bool isEmpty();
    void clearList();
};

#endif
