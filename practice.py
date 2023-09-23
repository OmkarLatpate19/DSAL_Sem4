'''
class set:
	
	def __init__(self):
		self.arr=[]

	def initialize(self):
		n=int(input("Enter number of entries :"))
		for i in range (n):
			val= int(input("enter val to add:"))
			self.add(val)

	def add(self,val):
		if val not in self.arr:
			self.arr.append(val)

	def remove(self,val):
		if val in self.arr:
			self.arr.remove(val)
			return True
		return False

	def iterate(self):
		return iter(self.arr)

	def size(self):
		return len(self.arr)
	
	def contains(self,val):
		return val in self.arr

	def intersection(self,lst):
		temp =[] 
		for i in lst:
			if i  in self.arr:
				temp.append(i)
		return temp

	def union(self,lst):
		temp=self.arr.copy()
		for i in lst:
			if i not in self.arr:
				temp.append(i)
		return temp

	def difference(self,lst):
		temp=self.arr.copy()
		for i in lst:
			if i in self.arr:
				temp.remove(i)
		return temp

	def subset(self,lst):
		flag = True
		for i in lst:
			if i not in self.arr:
				return False
		return True

	def display(self):
		return "{"+str(self.arr)[1:-1]+"}"

s = set()

while True:
	print("MENU\nAdd\nRemove\nIterate\nSize\nPresent or Absent\nIntersection\nUnion\nDifference\nSubset\nDisplay\nExit\n")
	ch = int(input("Enter your choice :"))

	if ch == 1:
		val = int(input("enter val to add :"))
		s.add(val)
		print("Added Successfully !!")

	elif ch ==2:
		print(s.display())
		val=int(input("Enter val to delete :"))
		if s.remove(val):
			print("Removed")
		else:
			print("Not Found")

	elif ch == 3:
		iterator = s.iterate()
		for i in range(s.size()):
			print(next(iterator))

	elif ch == 4:
		print("Size of set is :",s.size())
		

	elif ch == 5:
		val=int(input("Enter value to search :"))
		if s.contains(val):
			print("element present")
		else:
			print("not present")

	elif ch== 6 :
		obj = set()
		obj.initialize()
		print("Intersection is :",s.intersection(obj.arr))

	elif ch==7:
		obj = set()
		obj.initialize()
		print("Union is :",s.union(obj.arr))
		
	elif ch==8:
		obj= set()
		obj.initialize()
		print("Difference :",s.difference(obj.arr))

	elif ch == 9:
		obj=set()
		obj.initialize()
		if s.subset(obj.arr):
			print("subset present !!")
		else:
			print("Subset absent")

	elif ch== 10:
		print(s.display())

	else:
		break
'''
class hashing:
	
	def __init__(self):
		self.m=int(input("Enter size of hash table :"))

		if self.m<3:
			self.prime = self.m
		else:
			prime=[2,3]
			for i in range(self.m):
				for j in prime:
					if i%j == 0:
						p=False	
						break
				if p:
					prime.append(i)
			self.prime=prime[-1]

	def hashfunc1(self,a):
		return a % self.m
		
	def hashfunc2(self,a):
		return self.prime - a % self.prime

	def linear_probing(self,l):
		
		self.hasht = [0] * self.m
		self.linkt = [-1] * self.m
	
		for i in l:
			temp =-1
			flag = False

			index = self.hashfunc1(i[1])
			if self.hasht[index] != 0:
				flag = True

				while self.linkt[index] != -1:
					index=self.linkt[index]
				
				temp=index
		
				while self.hasht[index] != 0:
					index = (index + 1)%self.m

			self.hasht[index]=i
			if flag:
				self.linkt[temp]=index

	def doublehashing(self,l):
		
		self.doublehash = [0] *self.m
		
		for i in l:
			c=0
			index = self.hashfunc1(i[1])
			while self.doublehash[index] != 0:
				index = (self.hashfunc1(i[1]) + c*self.hashfunc2(i[1]))%self.m
				c+=1
			self.doublehash[index]=i

def rep_check(num):
	for i in entries:
		if i != 0:
			if num==i[1]:
				print("number already exist ")
				return False
	return True
	

hash = hashing()
entries =[] 
n= int(input("enter number of data inputs :"))
for i in range(n):
	d=[]
	d.append(input("enter name :"))
	tele = 0
	while (len(str(tele)) != 10 or str(tele).isnumeric()==False or rep_check(tele)==False) :
		tele=int(input("enter phone number :"))
		
	d.append(tele)
	entries.append(d)

while True :
		print("\nLinear\nDouble\nExit")
		ch = int(input("enter choice "))	
		
		if ch == 1:
			hash.linear_probing(entries)
			print("hash table ",hash.hasht)
			print("link table ",hash.linkt)

		elif ch  == 2:
			hash.doublehashing(entries)
			print("double hashing ",hash.doublehash)
		
		elif ch ==3 :
			break
				
			
		


	