class Set:

	def __init__(self):
		self.arr = [ ]

	def Initialize_Set(self):
		n=int(input("Enter number of entries :"))
		for i in range(n):
			val=int(input("Enter value to add :"))
			self.Add(val)

	def Add(self, val):
		if val not in self.arr:
			self.arr.append(val)

	def Remove(self, val):
		if val in self.arr:
			self.arr.remove(val)
			return True
		return False 

	def Iterator(self):
		return iter(self.arr)

	def Contains(self, val):
		return val in self.arr

	def Size(self):
		return len(self.arr)

	def Intersection(self, lst):
		temp = []
		for i in lst:
			if i  in self.arr:
				temp.append(i)
		return temp

	def Union(self, lst):
		temp = self.arr.copy()
		for i in lst:
			if i not in self.arr:
				temp.append(i)
		return temp

	def Difference(self, lst):
		temp = self.arr.copy()
		for i in lst:
			if i in self.arr:
				temp.remove(i)
		return temp

	def SubSet(self, lst):
		flag = True
		for i in lst:
			if i not in self.arr:
				return False
		return True


	def Display(self):
		return "{" + str(self.arr)[1:-1] + "}"

obj1 = Set()

while True :
	
	print("\n-----------------MENU-----------------")
	print("\n1.Add Element")
	print("\n2.Remove Element")
	print("\n3.Iterate Over Set")
	print("\n4.Check if Present or Not")
	print("\n5.Size of Set")
	print("\n6.Intersection of Sets")
	print("\n7.Union of Sets")
	print("\n8.Difference of Sets")
	print("\n9.Subset of Set")
	print("\n10.Display Set")
	print("\n11.Exit")
	ch = int(input("\n\nEnter your choice :"))

	if ch == 1:
		val = int(input("Enter value to add :"))
		obj1.Add(val)
		print("Element Added !!")

	elif ch == 2:
		print(obj1.Display())
		val = int(input("Enter value to remove :"))
		if obj1.Remove(val):
			print("Element Removed")
		else :
			print("Element not found ")
		
	elif ch == 3:
		iterator = obj1.Iterator()
		for i in range(obj1.Size()):
			print(next(iterator))

	elif ch == 4:
		val = int(input("Enter value to Search :"))
		if obj1.Contains(val):
			print("Element Present !!")
		else :
			print("Element Absent !!")

	elif ch == 5:
		print("Size of set is :", obj1.Size());

	elif ch == 6:
		obj2 = Set()
		obj2.Initialize_Set()
		print("Intersection of sets is :" , obj1.Intersection(obj2.arr))

	elif ch == 7:
		obj2 = Set()
		obj2.Initialize_Set()
		print("Union of sets is :", obj1.Union(obj2.arr))

	elif ch == 8:
		obj2 = Set()
		obj2.Initialize_Set()
		print("Difference of Sets is :" , obj1.Difference(obj2.arr))

	elif ch == 9 :
		obj2 = Set()
		obj2.Initialize_Set()
		if obj1.SubSet(obj2.arr):
			print("Subset Present !!")
		else:
			print("Subset Absent !!")

	elif ch == 10:
		print("Set is :", obj1.Display())
		
	elif ch == 11:
		print("Exiting Program !!")
		break

	else:
		print("Wrong Choice")


		
		