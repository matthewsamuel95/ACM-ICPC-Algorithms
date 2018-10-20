'''
Activity Selection Problem

Input :
6
1 3 0 5 8 5
2 4 6 7 9 9

Output :
4
'''

#Activity Class
class Activity:

    #Store the start and end times of the activity
    def __init__(self, start, end):
        self.start = start
        self.end = end

    #Check if the current activity conflicts with the other activity
    def conflicts(self,activity):
        if self.end <= activity.start or self.start >= activity.end:
            return False
        return True

#Returns maximum number of activities that can be selected without collisions
def Activity_Selection(actList):
    #Sort the activities according to ending time
    actList.sort(key = lambda x : x.end)

    selectedActivities = []
    #First activity is always in the selected list of activities
    selectedActivities.append(actList[0])

    for i in range(1,len(actList)):
        #If the new activity does not conflict with the last activity, then add it to selected activities
        if not actList[i].conflicts(selectedActivities[-1]):
            selectedActivities.append(actList[i])

    #Return the length of the selected activities array
    return len(selectedActivities)

n = int(input())
activityList = []

startTimes = list(map(int,input().strip().split()))
endTimes = list(map(int,input().strip().split()))

for i in range(n):
    activityList.append(Activity(startTimes[i],endTimes[i]))

print(Activity_Selection(activityList))
