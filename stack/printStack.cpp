template <class T>
void printStack(stack <T> s){
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}
