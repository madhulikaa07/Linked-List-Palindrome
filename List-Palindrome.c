#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode* reverse(struct ListNode* head);
void print(struct ListNode* head);

struct ListNode {
     int val;
     struct ListNode *next;
};

bool isPalindrome(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    if(head == NULL)
    {
        return true;
    }
    
    while( fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    struct ListNode *firstHalfhead = head;
    struct ListNode *secondHalfhead = reverse(slow->next);
    
    while(firstHalfhead != NULL && secondHalfhead != NULL)
    {
        if(firstHalfhead->val != secondHalfhead->val)
        {
            return false;
        }
        
        firstHalfhead = firstHalfhead->next;
        secondHalfhead = secondHalfhead->next;
            
    }
    
    return true;
}

struct ListNode* add_node(struct ListNode* head,int val)
{
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(!temp)
    {
        printf("Error allocating memory\n");
    }
    temp->val = val;
    temp->next = NULL;

    if(head == NULL)//if list is empty
    {
        head = temp;
        return head;
    }
    else
    {
        //iterate to the last node of the list
        struct ListNode* current = head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
        return head;
    }

}

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode *prev,*current,*next;
    prev = NULL;
    current = head;
    
    while( current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    return head;
}

void print(struct ListNode* head)
{
    printf("\n");
    struct ListNode* temp = head;
    while(temp != NULL)
    {
        printf(" %d",temp->val);
        temp = temp->next;
    }
    printf("\n");
    
    return;
}


int main()
{
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;
    struct ListNode* result = NULL;
    
    l1 = add_node(l1,1);
    l1 = add_node(l1,1);
    l1 = add_node(l1,2);
    l1 = add_node(l1,1);
    
    printf("L1:");
    print(l1);
 
    if(isPalindrome(l1))
    {
        printf("List is a Palindrome");
        
    }
    else{
        printf("List is not a Palindrome");
    }
    
}