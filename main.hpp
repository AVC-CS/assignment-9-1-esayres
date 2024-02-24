#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    double value;
    struct Node *next;
};

struct Node *makeNumbers(int N);
void printNumbers(struct Node *head);
int getLength(struct Node *head);
struct Node *sortNumbers(struct Node *head);
struct Node *swapNode(struct Node *prev, struct Node *ptr);

struct Node *makeNumbers(int N){
    struct Node *head, *tmp, *prev;
    for (int i = 0; i < N; i++){
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->value = rand() % 100;
        tmp->next = NULL;
        if (i == 0)
            head = tmp;
        else
            prev->next = tmp;
        prev = tmp;
    }
    return head;
}

void printNumbers(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value << "\t";
        ptr = ptr->next;
    }
    cout << endl;
    
}
int getLength(struct Node *head){
    struct Node *ptr = head;
    int  cnt = 0;
    while (ptr != NULL)
    {
        cnt++;  
        ptr = ptr->next;
    }
    return cnt;
}
struct Node *sortNumbers(struct Node *head){
    int length = getLength(head);
    
    if (length <= 1)
        return head;

    // bubble sort
    for (int i = 0; i < length - 1; ++i) {
        struct Node *current = head;
        struct Node *nextNode = head->next;
        struct Node *prev = NULL; // Keep track of the previous node for swapping

        for (int j = 0; j < length - i - 1 && nextNode != NULL; ++j) {
            // Compare values of adjacent nodes and swap if necessary
            if (current->value > nextNode->value) {
                // Swap the nodes
                if (current == head) {
                    head = swapNode(NULL, current);
                } else {
                    swapNode(prev, current);
                }
                
                // Update prev for the next iteration
                prev = nextNode;
                nextNode = current->next;
            } else {
                // Move to the next pair of nodes
                prev = current;
                current = nextNode;
                nextNode = nextNode->next;
            }
        }
    }
    return head;
}

struct Node *swapNode(struct Node *prev, struct Node *ptr){
    struct Node *nextNode = ptr->next;
    ptr->next = nextNode->next;
    nextNode->next = ptr;
    if (prev != NULL) {
        prev->next = nextNode;
    }
    return nextNode;
}