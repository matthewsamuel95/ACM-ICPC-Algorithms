"""
            Tower Of Hanoi

"""
#MoveTower function which uses recursion
def moveTower(height,fromPole, toPole, withPole):
    if height >= 1:
        moveTower(height-1,fromPole,withPole,toPole)
        moveDisk(fromPole,toPole)
        moveTower(height-1,withPole,toPole,fromPole)

#Printing the movements of disks
def moveDisk(fp,tp):
    print("moving disk from",fp,"to",tp)

#Enter number of disks
n = int(input("Enter number of disks "))
#call the function
moveTower(n,"A","B","C")
