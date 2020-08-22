// CPP code to illustrate  
// Queue in Standard Template Library (STL) 
#include <iostream> 
#include <queue> 
  
using namespace std; 
  
void showq(queue <int> temp) 
{ 
    queue <int> g = temp; 
    while (!g.empty()) 
    { 
        cout<<" "<<g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main() 
{ 
    queue <int> myqueue; 
    myqueue.push(10); 
    myqueue.push(20); 
    myqueue.push(30); 
  
    cout << "The queue myqueue is : "; 
    showq(myqueue); 
  
    cout << "\nmyqueue.size()  : " << myqueue.size(); 
    cout << "\nmyqueue.front() : " << myqueue.front(); 
    cout << "\nmyqueue.back()  : " << myqueue.back(); 
  
    cout << "\nmyqueue.pop()   : "; 
    myqueue.pop(); 
    showq(myqueue); 
  
    return 0; 
} 
