#include "NodeManager.hpp"

NodeManager::NodeManager() : lastNode(NULL)
{
    SLIST_INIT(&list);
}

NodeManager::~NodeManager()
{
    clearList();
}

void NodeManager::pushNode(int val)
{
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));

    if (!newNode) {
        M5.Lcd.println("Memory allocation failed");
        return;
    }

    newNode->val = val;
    newNode->time = time(NULL) + TIME_BY_SPEED_TILL_END_SECOUNDS;

    if (lastNode)
        SLIST_INSERT_AFTER(lastNode, newNode, next);
    else
        SLIST_INSERT_HEAD(&list, newNode, next);

    lastNode = newNode;
    lastTime = time(NULL) + TIME_BY_SPEED_TILL_END_SECOUNDS;
}

void NodeManager::removeNode()
{
    Node_t *deletedNode = SLIST_FIRST(&list);

    if (!deletedNode) {
        M5.Lcd.println("Nothing to remove");
        return;
    }

    SLIST_REMOVE_HEAD(&list, next);
    free(deletedNode);

    if (SLIST_EMPTY(&list))
        lastNode = nullptr;
}

void NodeManager::printNodes()
{
    Node_t *tmp = SLIST_FIRST(&list);

    M5.Lcd.printf("Time: %d, LastTime: %d\n", time(NULL), getLastTime());
    while (tmp) {
        M5.Lcd.printf("%d,%d\n", tmp->val, tmp->time);
        tmp = SLIST_NEXT(tmp, next);
    }
}

NodeManager::Node *NodeManager::getFirstNode()
{
    return SLIST_FIRST(&list);
}

NodeManager::Node *NodeManager::getNextNode()
{
    return SLIST_NEXT(getFirstNode(), next);
}

int NodeManager::getLastTime()
{
    return lastTime;
}

bool NodeManager::isEmpty()
{
    return SLIST_EMPTY(&list);
}

void NodeManager::clearList()
{
    while (!isEmpty())
        removeNode();
}
