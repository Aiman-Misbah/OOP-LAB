#include <iostream>
#include <exception>
#include <string>
using namespace std;

class QueueOverflowException : public exception
{
};

class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
    T* items;
    int frontIndex;
    int rearIndex;
    int currentSize;
    int maximumCapacity;

public:
    Queue(int capacity)
    {
        maximumCapacity = capacity;
        items = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    ~Queue()
    {
        delete[] items;
    }

    void addToQueue(T value)
    {
        if (currentSize == maximumCapacity)
        {
            throw QueueOverflowException();
        }

        rearIndex = (rearIndex + 1) % maximumCapacity;
        items[rearIndex] = value;
        currentSize++;
    }

    T removeFromQueue()
    {
        if (currentSize == 0)
        {
            throw QueueUnderflowException();
        }

        T value = items[frontIndex];
        frontIndex = (frontIndex + 1) % maximumCapacity;
        currentSize--;
        return value;
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    bool isFull() const
    {
        return currentSize == maximumCapacity;
    }
};

int main()
{
    Queue<string> customerQueueInIslamabad(3);

    try
    {
        customerQueueInIslamabad.addToQueue("Ahmed");
        customerQueueInIslamabad.addToQueue("Fatima");
        customerQueueInIslamabad.addToQueue("Bilal");
        cout << "Attempting to enqueue to a full queue..." << endl;
        customerQueueInIslamabad.addToQueue("Zainab");
    }
    catch (const QueueOverflowException& e)
    {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    Queue<int> tokenQueueForNadra(2);

    try
    {
        cout << "Attempting to dequeue from an empty queue..." << endl;
        tokenQueueForNadra.removeFromQueue();
    }
    catch (const QueueUnderflowException& e)
    {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
