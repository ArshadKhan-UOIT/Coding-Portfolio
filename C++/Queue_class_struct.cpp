//testign queue with classes and struct 
/*
  Notes:
  - front = font->next, add to the back,
  have a class member to keep track of size

  - Queue, first in first out

  - newtop->data = d;//remember this is the same as (*newtop).data=d;
*/
#include <iostream>
#include <string>

using namespace std;

// TODO: Create a struct containing a string (element_name)as well as a node pointer (Node* next)
struct Node {
  string element_name;
  Node* next;
};
// Queue class
class Queue {
    // --- public members ---
  public:
    // TODO: Constructor (with no parameters) - Creates an empty queue.
    Queue();
    // TODO: Deconstructor - Deletes the queue.
    ~Queue();
    // TODO: isEmpty - Checks if the queue is empty.
    bool isEmpty() {return (front == NULL);};
    // TODO: Enqueue - Adds a new Node to the Queue. The new Node should be added to the back of the queue.
    void Enqueue(string d);
    // TODO: Dequeue - Deletes a Node from the Queue. The Node deleted should be from the front of the queue (and it should return the element_name of the deleted Node)
    string Dequeue();
    // TODO: toString - Returns a string containing the contents of the queue from the back Node to the front Node. For example:
    //           [Cat] -> [Dog] -> [Fish]
    string toString();
    // --- private members ---
  private:
    // TODO: Node* front - a pointer to the front of the Queue
    Node* front;
    // TODO: Node* back - a pointer to the back of the Queue
    Node* back;
};

Queue::Queue()//constructor
{
  front = NULL;//
  back = NULL;
}

Queue::~Queue()//destructor frees up all of the memory allocated to nodes
{
  while (!isEmpty())
  {
    Dequeue();//using the dequeue operator in the destructor
  }
}

void Queue::Enqueue(string d)//adds to the back of the queue
{
  Node *newback = new Node;//new node
  newback->element_name = d;//assigning element_name
  newback->next = NULL;
  if (!isEmpty())//if its not empty
  {
    //places an element at the back of the queue
    back->next = newback;//points the new node next to the
                         //old back of the queue
    back = newback;//makes the new node the back of the queue
  }
  else
  {
    //makes it only element
    front = newback;
    back = newback;
    front->next = NULL;
    back->next = NULL;
  }
}

string Queue::Dequeue()//deletes element from front. and returns deleted element
{
  Node *oldfront = new Node;//new node
  if (!isEmpty())
  {
    string value = front->element_name;//sets aside the current element in the front
    oldfront = front;//old front points to the front
    front = front->next;//make the front second
    delete oldfront;//delete the front
    return value;//returns value of deleted element
  }
  else
  {
    cout << "ERROR: you can't dequeue from empty Queue!\n";
    exit(1);
  }
}

string Queue::toString()
{
  string result = "";
  Node *current = front;//makeing the current node the front
  while(current->next != NULL)//looping over the elements in the queue
  // while(current != NULL)
  {
    result += " [" + current->element_name + "] " + "->";
    current = current->next;
  }
  result += " [" + current->element_name + "] ";//for the last element
  return result;//returns the result
}



int main() {

    Queue* q = new Queue();

    q->Enqueue("Turtle");
    q->Enqueue("Cat");
    q->Enqueue("Dog");
    q->Enqueue("Fish");

    cout << "Before ->" << endl;
    cout << q->toString() << endl;

    q->Dequeue();

    cout << "After ->" << endl;
    cout << q->toString() << endl;

    delete q;

    return 0;
}
