#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct IntNode_struct {
   int dataVal;
   struct IntNode_struct* nextNodePtr;
} IntNode;

// Initialization
void InitializeIntNode(int dataInit, IntNode* thisNode) {
   thisNode->dataVal = dataInit;
   thisNode->nextNodePtr = NULL;
}

// Get node value
int GetNodeData(IntNode* thisNode) {
   return thisNode->dataVal;
}

// Get pointer to next node
IntNode* GetNext(IntNode* thisNode) {
   return thisNode->nextNodePtr;
}

/* Insert node after this node.
   Before: this -- next
   After:  this -- node -- next
*/
void InsertAfter(IntNode* thisNode, IntNode* newNode) {
   IntNode* tempNext = NULL;

   tempNext = thisNode->nextNodePtr;
   thisNode->nextNodePtr = newNode;
   newNode->nextNodePtr = tempNext;
}

// Return true if list items are in asending order
bool IsSorted(IntNode* headNode) {
   bool sorted = true;
   IntNode* currNode = GetNext(headNode);

   // Check for empty list
   if (currNode == NULL) {
      return true;
   }

   // Step through list one item at a time searching for target
   while (GetNext(currNode) != NULL) {
      if (GetNodeData(currNode) > GetNodeData(GetNext(currNode))) {
         sorted = false;
      }
      // move forward one item
      currNode = GetNext(currNode);
   }

   return sorted;
}

int main(void) {
   IntNode* headNode;
   IntNode* currNode;
   IntNode* lastNode;

   // Initiaize head node
   headNode = (IntNode*)malloc(sizeof(IntNode));
   InitializeIntNode(-1, headNode);
   lastNode = headNode;

   // Add nodes to the list
   for (int i = 0; i < 20; ++i) {
      currNode = (IntNode*)malloc(sizeof(IntNode));
      InitializeIntNode(i, currNode);
      InsertAfter(lastNode, currNode);
      lastNode = currNode;
   }

   if (IsSorted(headNode)) {
      printf("true\n");
   }
   else {
      printf("false\n");
   }
   
   return 0;
}
