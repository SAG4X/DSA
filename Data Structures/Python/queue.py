queue = [] 

c=input("enter your choice (enqueue,dequeue,print,done):")

while(c!='done'):
        
        if(c=='enqueue'):
                no=input("enter number you want to push:")
                queue.append(no)
        elif(c=='print'):
                print("The queue")
                print(queue)
        elif(c=='dequeue'):
                print(queue.pop(0))
                print("dequeued")
        else:
                print("error wrong syntax")
                
        c=input("enter your choice(enqueue,dequeue,print,done):")
        

