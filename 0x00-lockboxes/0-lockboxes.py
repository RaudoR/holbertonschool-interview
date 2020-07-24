#!/usr/bin/python3
"""Determine if the box can be opened"""
def canUnlockAll(boxes):
    open = {0}
    for index, box in enumerate(boxes):
        for key in box:
            if key != index:
                open.add(key)
    for index in range(len(boxes)):
        if index not in open:
         return False
    return True