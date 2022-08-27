
//=====================LINKED LIST=======================

#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val = 0)
    {
        data = val;
        next = NULL;
    }
};
node *head = NULL;

//----------------------------------------------------------------------------------------

node *insert_node_at_head(node *head, int val)
{
    node *newnode = new node(val);
    newnode->next = head;
    head = newnode;
    return head;
}

//----------------------------------------------------------------------------------------

void insert_node_at_tail(node *&head, int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    node *ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
}

//----------------------------------------------------------------------------------------

int count_nodes(node *&head)
{
    if(head == NULL || head->next == NULL) return -1;
    node *ptr;
    ptr = head;
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    cout << endl;
    return count;
}

//----------------------------------------------------------------------------------------

void delete_node(node *&head, int pos)
{
    if(head == NULL || head->next == NULL) return;
    node *todel;
    if(pos == 1)
    {
        todel = head;
        head = head->next;
    }
    else
    {
        node *ptr = new node(0);
        ptr->next = head;
        int count = 1;
        while(ptr != NULL && count < pos)
        {
            count++;
            ptr = ptr->next;
        }
        todel = ptr->next;
        ptr->next = ptr->next->next;
    }
    delete(todel);

}

//----------------------------------------------------------------------------------------

void print_list(node *&head)
{
    if(head == NULL || head->next == NULL) return;
    node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "X " << endl;
}

//----------------------------------------------------------------------------------------

node *reverse_list(node *&head)
{
    if(head == NULL || head->next == NULL) return NULL;
    node *prev = NULL;
    node *curr = head;
    node *Next;
    while(curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
}

//----------------------------------------------------------------------------------------

node *merge_two_sorted_lists(node *h1, node *h2)
{
    if(h1==NULL || h2==NULL) return NULL;
    if(h1->data > h2->data) swap(h2, h1);
    node *newhead = h1;
    node *temp;
    while(h1 != NULL && h2 != NULL)
    {
        temp = NULL;
        while(h1 != NULL && h1->data <= h2->data)
        {
            temp = h1;
            h1 = h1->next;
        }
        temp->next = h2;
        swap(h1, h2);
    }
    return newhead;
}

//----------------------------------------------------------------------------------------

node *find_middle_node(node *&head)
{
    if(head == NULL) return NULL;
    node *fast = head;
    node *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//----------------------------------------------------------------------------------------

int main()
{
    int k, num;
    cin >> k;

    node *head = new node();

    while(k--)
    {
        cin >> num;
        insert_node_at_tail(head, num);
    }

    print_list(head);

}


//-------------------------------------------------------------------------------------
