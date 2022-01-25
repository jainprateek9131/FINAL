#include <bits/stdc++.h>
using namespace std;
struct listnode {
   int data;
   listnode * next, * random;
   listnode(int d) {
      data = d;
      next = NULL;
      random = NULL;
   }
};
void print(listnode * head) {
   listnode * curr = head;
   while (curr) {
      cout << curr -> data << " " << curr -> random -> data << endl;
      curr = curr -> next;
   }
}
listnode * copyRandomList(listnode * head) {
   if (!head) {
      return head;
   }
   //Insert a new node with the same value after each node in the original list.
   unordered_map<listnode *,listnode *>m;
        m[NULL]=NULL;
        listnode * temp,*ptr=head,*t;
        while(ptr!=NULL){
            m[ptr]=new listnode(0);
            ptr=ptr->next;
        }
        ptr=head;
        temp=new listnode(0);
        t=temp;
        while(ptr!=NULL){
            temp->next=m[ptr];
            m[ptr]->data=ptr->data;
            cout<<ptr->data<<"  "<<m[ptr]->data<<endl;
            m[ptr]->next=m[ptr->next];
            m[ptr]->random=m[ptr->random];
            ptr=ptr->next;
            temp=m[ptr];
        }
        return t->next;
}
int main() {
   listnode * head = new listnode(5);
   head -> next = new listnode(6);
   head -> next -> next = new listnode(3);
   head -> next -> next -> next = new listnode(4);
   head -> next -> next -> next -> next = new listnode(2);
   head -> random = head -> next -> next;
   head -> next -> random = head;
   head -> next -> next -> random =
      head -> next -> next -> next -> next;
   head -> next -> next -> next -> random =
      head -> next -> next -> next -> next;
   head -> next -> next -> next -> next -> random =
      head -> next;
   cout << "Original list :" << endl;
   print(head);
   cout << "Deep Copy of the List:" << endl;
   listnode * deep_copyList = copyRandomList(head);
   print(deep_copyList);
   return 0;
}
