class Queue: 
	def __init__(self): 
		self.s1 = [] 
		self.s2 = [] 

	def enQueue(self, x): 
		
		while len(self.s1) != 0: 
			self.s2.append(self.s1[-1]) 
			self.s1.pop() 

		self.s1.append(x) 

		while len(self.s2) != 0: 
			self.s1.append(self.s2[-1]) 
			self.s2.pop() 

	def deQueue(self): 
		
		if len(self.s1) == 0: 
			print("Q is Empty") 
	
		x = self.s1[-1] 
		self.s1.pop() 
		return x 

if __name__ == '__main__':

        q = Queue()
        c=input("enter your choice (enqueue,dequeue,done):")

        while(c!='done'):
        
                if(c=='enqueue'):
                        no=input("enter number you want to push:")
                        q.enQueue(no) 
                elif(c=='dequeue'):
                        print(q.deQueue()) 
                else:
                        print("error wrong syntax")
                
                c=input("enter your choice(enqueue,dequeue,done):")
	 
	



