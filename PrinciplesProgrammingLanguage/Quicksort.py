# -*- coding: utf-8 -*-
"""
Created on Fri Oct 23 18:20:37 2020

@author: Jiyoon
"""


import random

def Quicksort(L): # Define Quicksort function applying to L list
    def Sort(L, g, d): # Define Sort that with variables g, d that will keep looping until the quicksort is accomplished
        pivot = L[(g+d)//2] # Pivot is 2 values in list L that are floor divided
        i = g 
        j = d # Assign g, d to i, j respectively
        while True: 
            while L[i]<pivot: 
                i+=1 # look for one up index value until that value < pivot
            while L[j]>pivot:
                j-=1 # look for one down index value until that value > pivot
            if i>j:
                break # Break whileloop if i>j
            if i<j:
                L[i], L[j] = L[j], L[i] # If i<j permute ith value and jth value
            i+=1 # Add 1 to i
            j-=1 # Substract 1 to j
        if g<j: # If j is a bigger index than the initial one, recall function Sort with g, j
            Sort(L,g,j)
        if i<d: # If i is a smaller index than the initial one, recall function Sort with i, d
            Sort(L,i,d)
 
    g=0 # Set initial value g to the first index of the list
    d=len(L)-1 # Set initial value d to the last index of the list
    Sort(L,g,d) # Call Sort function, last command for function Quicksort
    
# TEST
nmax=100 
L=[]
for i in range(0,nmax):
    L.append(random.randint(1000,9999)) # create a L list with 100 random numbers from 1000 to 9999

print("random list") 
for i in range(1,nmax):
     print (L[i]) # Show random list


Quicksort(L) # Apply Quicksort to that random list
 
# check if error
for i in range(1,nmax):
    if L[i]<L[i-1]:
        print ("error index ",i, L[i])
 
# Show sorted list
print("sorted list")
for i in range(1,nmax):
    print (L[i])