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
struct Node *sortNumbers(struct Node *head)
{
    /*******************************
     * Code your program here
     *******************************/
}

struct Node *swapNode(struct Node *prev, struct Node *ptr)
{
    /*******************************
     * Code your program here
     *******************************/
}