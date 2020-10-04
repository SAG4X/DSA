from sys import maxsize 

def createStack(): 
	stack = [] 
	return stack 

def isEmpty(stack): 
	return len(stack) == 0
 
def push(stack, item): 
	stack.append(item) 
	print(item + " pushed to stack ") 
	 
def pop(stack): 
	if (isEmpty(stack)): 
		return str(-maxsize -1) 
	
	return stack.pop() 

def peek(stack): 
	if (isEmpty(stack)): 
		return str(-maxsize -1) 
	return stack[len(stack) - 1] 

	 
stack = createStack()
c=input("enter your choice (push,pop,done):")
while(c!='done'):
        
        if(c=='push'):
                no=input("enter number you want to push:")
                push(stack,no)
        elif(c=='pop'):
                print(pop(stack) + " popped from stack")
        else:
                print("error wrong syntax")
                
        c=input("enter your choice (push,pop,done):")
        
        

