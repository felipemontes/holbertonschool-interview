#!/usr/bin/python3
""" determines if all the boxes can be opened """

def canUnlockAll(boxes):
    """ check boxes """
    for key in range(1, len(boxes) - 1):
        res = False
        for index in range(len(boxes)):
            res = key in boxes[index] and key != index
            if res:
                break
        if res is False:
            return res
    return True