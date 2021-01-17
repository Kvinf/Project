#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct post {
  char para[255]; // Content of Post
  char title[100]; // Title of Post
};

struct publicDashboard { 
  int id; // User's ID
  post publicPost; // User's Post
  publicDashboard *next, *prev; // point to the left and right
} *headpub, *tailpub; // point to the leftmost and rightmost node

struct privateDashboard {
  int id; // User's ID
  int access[4]; // Limited to 3 selected users
  post privatePost; // Private Post
  privateDashboard *next, *prev; // point to the left and right
} *headpriv, *tailpriv; // point to the leftmost and rightmost node

post *createPost() { // Still needs to be implemented in creating heads (private or public)
  post *newPost = (post*)malloc(sizeof(post));

  printf("Please enter the title of your post...");
  scanf("%[\n]", newPost->title);

  printf("Enter your thoughts here...");
  scanf("%[\t]s", newPost->para);
}

publicDashboard *createPubNode(int value, const char *para) { // UNFINISHED POST
  publicDashboard *newNode = (publicDashboard*)malloc(sizeof(publicDashboard));
  newNode->id = value;
  //strcpy(newNode->publicPost.para, para);
  newNode->next = newNode->prev = NULL;
  return newNode;
}

privateDashboard *createPrivNode(int value, const char *para) { // UNFINISHED POST
  privateDashboard *newNode = (privateDashboard*)malloc(sizeof(privateDashboard));
  newNode->id = value;
  //strcpy(newNode->post, para);
  newNode->next = newNode->prev = NULL;
  return newNode;
}

void pushPubHead(int value, const char *para) {
  publicDashboard *temp = createPubNode(value, para);

  if(!headpub) { // No public post
    headpub = tailpub = temp; // temp (head and tail)
  } else { // A (head), insert B
    headpub->prev = temp; // B (temp) <- A (head)
    temp->next = headpub; // B (temp) -><- A (head)
    headpub = temp; // B (temp, head) -><- A
  }
}

void pushPrivHead(int value, const char *para) {
  privateDashboard *temp = createPrivNode(value, para);

  if(!headpriv) { // No public post
    headpriv = tailpriv = temp; // temp (head and tail)
  } else { // A (head), insert B
    headpriv->prev = temp; // B (temp) <- A (head)
    temp->next = headpriv; // B (temp) -><- A (head)
    headpriv = temp; // B (temp, head) -><- A
  }
}

// void pushTail(int value) {
//   Node *temp = createNode(value);

//   if(!head) { // empty list
//     head = tail = temp; // temp (head dan tail)
//   } else { // A (tail), insert B
//     tail->next = temp; // A (tail) -> B (temp)
//     temp->prev = tail; // A (tail) -><- B (temp)
//     tail = temp;  // A -><- B (temp, tail)
//   }
// }

// void pushMid(int value) {
//   if(!head) { // empty list
//     Node *temp = createNode(value);
//     head = tail = temp;
//   } else if(value < head->value) { // add to the leftmost
//     pushHead(value);
//   } else if(value > tail->value) { // add to the rightmost
//     pushTail(value);
//   } else { // value is between head and tail
//     Node *temp = createNode(value); // 9 (temp)
//     Node *curr = head; // 1 (head, curr) -><- 8 -><- 12 -><- 15, insert 9

//     while(curr->value < value) {
//       curr = curr->next; // traverse until curr->value > value
//     }

//     // 1 -><- 8 -><- 12 (curr) -><- 15 || 9 (temp)
//     temp->prev = curr->prev; // 9->prev = 8
//     temp->next = curr; // 9->next = 12
    
//     // 1 -><- 8 ->      <- 12 (curr) -><- 15
//     //        \(prev)   /(next)
//     //               9 (temp)

//     curr->prev->next = temp; // 8->next = 9
//     curr->prev = temp; // 12->prev = 9
//     // 1 -><- 8                           12 (curr) -><- 15
//     //       \(prev)\(next)     /(next)/(prev)
//     //                   9 (temp)
//   }
// }

// void popHead() {
//   if(!head) { // empty list
//     return;
//   } else if(head == tail) { // 1 node
//     free(head);
//     head = tail = NULL;
//   } else { // >= 1 node
//     Node *newHead = head->next; // A (head) -><- B (newHead) -><- C
//     head->next = newHead->prev = NULL; // A (head) || B (newHead) -><- C
//     free(head); // B (newHead) -><- C
//     head = newHead; // B (head, newHead) -><- C
//   }
// }

// void popTail() {
//   if(!head) { // empty list
//     return; 
//   } else if(head == tail) { // 1 node
//     free(head);
//     head = tail = NULL;
//   } else { // >= 1 node
//     Node *newTail = tail->prev; // A -><- B (newTail) -><- C (tail)
//     tail->prev = newTail->next = NULL; // A -><- B (newTail) || C (tail)
//     free(tail); // A -><- B (newTail)
//     tail = newTail; // A -><- B (tail, newTail)
//   }
// }

// void popMid(int value) {
//   if(!head) { // empty list
//     return;
//   } else if(head->value == value) {
//     popHead(); 
//   } else if(tail->value == value) {
//     popTail(); 
//   } else { // value is between head and tail
//     Node *curr = head; // 10 (curr) 20 30 40 50, remove 30

//     while(curr && curr->value != value) {
//       curr = curr->next; // traverse until we find the value
//     }

//     // 10 -><- 20 -><- 30 (curr) -><- 40 -><- 50, remove 30
//     curr->prev->next = curr->next; // 20->next = 40
//     curr->next->prev = curr->prev; // 40->prev = 20

//     // 10 -><- 20      -><-     40 -><- 50, mau hapus 30
//     //          \<- 30 (curr) ->/ 

//     curr->prev = curr->next = NULL; // set pointers to NULL
//     free(curr); // free assigned memory
//     curr = NULL; // remove value
//   }
// }

void printPub() { // UNFINISHED
  publicDashboard *curr = headpub;
  printf("PUBLIC DASHBOARD: ");

  while(curr) {
    //printf("%d's content: %s -> ", curr->id, curr->post);
    curr = curr->next;
  }
  puts("NULL");
}

void printPriv() { // UNFINISHED
  privateDashboard *curr = headpriv;
  printf("Linked List: ");

  while(curr) {
    //printf("%d's content: %s -> ", curr->id, curr->post);
    curr = curr->next;
  }
  puts("NULL");
}

// void visualizeList(int N, int values[]) {
//   for(int i = 0; i < N; i++) {
//     pushMid(values[i]);
//     printf("Inserted %d to the list.\n", values[i]);
//     printLinkedList();
//     getchar();
//   }

//   for(int i = 0; i < N; i++) {
//     popMid(values[i]);
//     printf("Removed %d from the list.\n", values[i]);
//     printLinkedList();
//     getchar();
//   }
// }

int main() {
  // UNFINISHED

  return 0;
}