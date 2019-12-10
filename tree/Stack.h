template<typename T>

struct _StackNode
{
    T value;
    _StackNode* next;
    _StackNode(const T& v): value(v), next(nullptr) {}
};

template<typename T>
class Stack
{
private:
    _StackNode<T>* _top;

public:
    Stack(): _top(nullptr){}

    ~Stack()
    {
        _StackNode<T>* pNode = _top;
        while(pNode)
        {
            _StackNode<T>* tmp = pNode;
            pNode = pNode->next;
            delete tmp;
        }
    }

    bool empty()
    {
        if(_top == nullptr)
            return true;
        else
            return false;
    }

    void push(const T& v)
    {
        _StackNode<T>* pNode = new _StackNode<T>(v);
        pNode->next = _top;
        _top = pNode;
    }

    T pop(void)
    {
        _StackNode<T>* pNode = _top;
        T v = pNode->value;
        _top = pNode->next;
        delete pNode;

        return v;
    }

    T& get(void)
    {
        return _top->value;
    }

    T* getptr(void)
    {
        return &_top->value;
    }

};


