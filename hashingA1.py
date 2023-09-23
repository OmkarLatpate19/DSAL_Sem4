class Hash_Table:

	def __init__(self):
		self.m=int(input("Enter size of hash table :"))

		if self.m<3 :
			self.prime = self.m
		else :
			prime = [2,3]
			for i in range(self.m):
				for j in prime:
					if i % j == 0:
						p=False
						break
				if p:
					prime.append(i)
			self.prime = prime[-1]

	def hashfunc(self,a):
		return a % self.m

	def hashfunc2(self, a):
		return self.prime - (a % self.prime)

	def linear_probing(self, l):
		self.hasht = [0]*self.m
		self.linkt = [-1] *self.m
		
		for i in l:
			temp = -1
			flag =False
	
			index = self.hashfunc(i[1])
			if self.hasht[index] != 0:
				flag = True
				
				while self.linkt[index] != -1:
					index = self.linkt[index]
				
				temp = index
 
				while self.hasht[index] != 0:
					index =  (index+1) % self.m

			self.hasht[index] = i
			if flag:
				self.linkt[temp] = index

	def double_hashing(self, l):
		self.doublehash = [0] * self.m
		
		for i in l:
			c =   0
			index = self.hashfunc(i[1])
			while self.doublehash[index] != 0:
				index = (self.hashfunc(i[1]) + c * self.hashfunc2(i[1])) % self.m
				c += 1
			self.doublehash[index] = i

def rep_check(num):
	for i in entries:
		if i != 0:
			if num == i[1]:
				print("Number already exist !!")
				return False
	return True

hash = Hash_Table()
entries = []
n = int(input("Enter number of data inputs :"))
for i in range (n):
	d = []
	d.append(input("Enter your name :"))
	tele = 0 
	while ( len(str(tele)) != 10 or str(tele).isnumeric() == False or rep_check(tele) == False ):
		tele = int(input("Enter telephone number :"))
	
	d.append(tele)
	entries.append(d)

while True :
	
	ch = int(input("\n1.Linear Probing\n2.Double Hashing\n3.Exit\n\nEnter your choice :"))

	if ch == 1:
		hash.linear_probing(entries)
		print("---------------Linear Probing---------------")
		print("Hash Table is : ", hash.hasht)
		print("Link Table is :", hash.linkt)
	elif ch == 2:
		hash.double_hashing(entries)
		print("---------------Double Hashing---------------")
		print("Hash Table is : ", hash.doublehash)
	elif ch == 3:
		print("Exiting !!")
		break
	

			