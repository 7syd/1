HashTable = [[] for _ in range(10)]

def Hashing(keyvalue):
    return keyvalue % len(HashTable)

def linear_probe_insert(HashTable,keyvalue,value):
    Hashkey = Hashing(keyvalue)
    if not HashTable[Hashkey]:
        HashTable[Hashkey].append((keyvalue,value))
    else:
        i=Hashkey + 1
        while HashTable[i%len(HashTable)]:
            i += 1
        HashTable[i%len(HashTable)].append((keyvalue,value))

def seperate_chaining_insert(HashTable,keyvalue,value):
    Hashkey = Hashing(keyvalue)
    HashTable[Hashkey].append((keyvalue,value))

def display(HashTable):
    print("\n\t\tTelephone Database")
    print("\n\tIndex\tNames")
    for i in range(len(HashTable)):
        print("\t",i,end=" ")
        if not HashTable[i]:
            print("====> ---")
        else:
            for keyvalue,value in HashTable[i]:
                print("====> ",keyvalue,value)


#main
print("\t\t**MENU**\n\t1.INSERT TO PERFORM LINEAR PROBING\n\t2.INSERT TO PERFORM SEPERATE CHAINING\n\t3.DISPLAY THE HASHTABLE\n\t4.QUIT")
choice=int(input("Enter your Choice : "))
while choice!=4:
    if choice == 1:
        tel=int(input("\nEnter Telephone Number : "))
        name = input("\nEnter the Name : ")
        linear_probe_insert(HashTable,tel,name)
        print("\nInserted.....")
    elif choice == 2:
        tel=int(input("\nEnter Telephone Number : "))
        name = input("\nEnter the Name : ")
        seperate_chaining_insert(HashTable,tel,name)
        print("\nInserted.....")
    elif choice == 3:
        print("\n------------------------------")
        display(HashTable)
        print("\n------------------------------")
    else:
        print("Invalid Input...")
    print("\t\t**MENU**\n\t1.INSERT TO PERFORM LINEAR PROBING\n\t2.INSERT TO PERFORM SEPERATE CHAINING\n\t3.DISPLAY THE HASHTABLE\n\t4.QUIT")
    choice=int(input("Enter your Choice : "))
