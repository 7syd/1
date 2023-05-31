#Collision Handling using Linear Probing -->
HashTable = [[] for i in range(10)]

def Hashing(keyvalue):
    return keyvalue%len(HashTable)

def insert(HashTable,keyvalue,value):
    Hash_key = Hashing(keyvalue)
    HashTable[Hash_key].append(value)
    
def display(HashTable):
    print("\t\tTelephone Database of Clients\n")
    print("\tIndex\tNames")
    for i in range(len(HashTable)):
        print("\t",i,end="  ")
        
        for j in HashTable[i]:
            print("--->",end=" ")
            print(j,end=" ")
            
        print()

#Main Code--->
print("\t\t*MENU*\n\t1)Insert new telephone number\n\t2)Display\n\t3)Quit")
choice = int(input("\n\tEnter choice: "))
while(choice!=3):
    if(choice==1):
        tele_no = int(input("Enter telephone number: "))
        name = input("Enter person's name: ")
        insert(HashTable,tele_no,name)
        print("Inserted successfully!")
    elif(choice==2):
        print("\n*******************\n")
        display(HashTable)
        print("\n*******************\n")

    else:
        print("Invalid input!")
    print("\t\t*MENU*\n\t1)Insert new telephone number\n\t2)Display\n\t3)Quit")
    choice = int(input("\n\tEnter choice: "))

#Collision Handling using Linked List -->

HashTable = [-1 for i in range(10)]

def Hashing(keyvalue):
    return keyvalue%len(HashTable)

def insert(HashTable,keyvalue,value):
    Hash_key = Hashing(keyvalue)
    loop_counter = 0
    if(HashTable[Hash_key]==-1):
            HashTable[Hash_key]=value
    else:
        while(HashTable[Hash_key]!=-1 and loop_counter<10):
            Hash_key = Hash_key + 1
            if(Hash_key==len(HashTable)):
                Hash_key = 0
            loop_counter = loop_counter+1
            if(HashTable[Hash_key]==-1):
                HashTable[Hash_key]=value
                break
    if(loop_counter>10): 
        print("Value ",value," cannot be inserted")
    else:
        print("Inserted successfully!")
    
def display(HashTable):
    print("\t\tTelephone Database of Clients\n")
    print("Index\tNames")
    for i in range(len(HashTable)):
        print(i,end=" ")
        print("--->",HashTable[i])

#Main Code--->
print("\t\t*MENU*\n\t1)Insert new telephone number\n\t2)Display\n\t3)Quit")
choice = int(input("\n\tEnter choice: "))
while(choice!=3):
    if(choice==1):
        tele_no = int(input("Enter telephone number: "))
        name = input("Enter person's name: ")
        insert(HashTable,tele_no,name)
    elif(choice==2):
        print("\n*******************\n")
        display(HashTable)
        print("\n*******************\n")

    else:
        print("Invalid input!")
    print("\t\t*MENU*\n\t1)Insert new telephone number\n\t2)Display\n\t3)Quit")
    choice = int(input("\n\tEnter choice: "))
