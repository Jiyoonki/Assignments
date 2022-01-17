# -*- coding: utf-8 -*-
"""
Created on Fri Oct 23 18:33:23 2020

@author: Jiyoon
"""

import random


sample_list = [[1,2,3],
               [1,2],
               [1,4,5,6,7]] # create a sample 2D list

flatten_list = [] # assign flatten_list as an empty list

for i in sample_list: # take each list out of the outter list sample_list
    for j in i: # take each values out of each lists
        flatten_list.append(j) # append the values in flatten_list

print(flatten_list)