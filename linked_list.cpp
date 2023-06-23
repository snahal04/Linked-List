#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insertval(Node *&head, int x)
{
    Node *newNode = new Node(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displaylist(Node *&head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void middlenode(Node *&head)
{
    Node *slow = head, *fast = head;
    while (fast->next->next != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
}

void reverselist(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nex = head->next;
    while (nex != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = nex;
        nex = nex->next;
    }
    curr->next = prev;
    head = curr;
    displaylist(head);
}

void delNthNodeFrmEnd(Node *&head, int n) //Optimal in one pass
{
    Node *fast = head, *slow = head;
    while (n--)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    displaylist(head);
}

void detectcycle(Node *&head)
{
    Node *fast = head, *slow = head;
    do
    {
        if (fast->next == NULL || fast->next->next == NULL)
        {
            cout << "NO cycle" << endl;
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    } while (fast != slow);

    if (fast == slow)
    {
        fast = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        cout << "Cycle detected at " << slow->data << endl;
    }
}

bool isPalindrome(Node *&head) //Optimal Palindrome Check
{
    //reverse the middle half and check
    Node *temp = head;
    Node *prev = NULL;
    Node *curr = temp;
    Node *next = temp->next;
    Node *slow = temp;
    Node *fast = temp;

    if (temp->next == NULL)
        return 1;
    if (temp->next->next == NULL)
    {
        if (temp->data != temp->next->data)
            return 0;
        else
            return 1;
    }
    temp = head;
    int count = 0;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        count++;
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;

    curr = slow->next;
    next = curr->next;

    while (next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    temp = curr;
    if (count % 2 != 0)
        slow->next = NULL;

    while (head->next != NULL && temp->next != NULL)
    {
        if (head->data != temp->data)
            return 0;
        head = head->next;
        temp = temp->next;
    }
    if (head->data != temp->data)
        return 0;

    return 1;
}

int main()
{
    Node *head = new Node(1);
    insertval(head, 2);
    insertval(head, 3);
    insertval(head, 4);
    insertval(head, 5);
    displaylist(head);
}
