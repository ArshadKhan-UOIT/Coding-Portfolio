# -*- coding: utf-8 -*-
"""
Created on Sun Nov  4 17:57:50 2018

@author: khanr
"""

class StudentEntry:
    def __init__(self, name, studentID):
        self.name=name
        self.studentID=studentID
        self.labs=0
        self.assignments=0
        self.midterm=0
        self.final=0
        self.averageGrade=0
        self.LetterGrade=" "
    def average(self, labs, assignments, midterm, final):
        self.averageGrade= ((.1*(self.labs/10))
                +(.2*(self.assignments/20))
                +(.3*(self.midterm/100))
                +(.4*(self.final/100)))
        return self.average
    def letterGrade(self):
        
        if (80<self.averageGrade<100):
            self.LetterGrade="A"
        elif (70<self.averageGrade>79):
            self.LetterGrade="B"
        elif (60<self.averageGrade<69):
            self.LetterGrade="C"
        elif (50<self.averageGrade<59):
            self.LetterGrade="D"
        elif (0<self.averageGrade<49):
            self.LetterGrade="F"
        return self.LetterGrade
bsmith = StudentEntry("Bob Smith", "10000001")
bsmith.labs = 9.0
bsmith.assignments = 17.0
bsmith.midterm = 57.7
bsmith.final = 60.0
print("Bob Smith: ", bsmith.letterGrade())

sjones = StudentEntry("Sally Jones", "10000002")
sjones.labs = 9.5
sjones.assignments = 19.5
sjones.midterm = 81.0
sjones.final = 74.5
print("Sally Jones: ", sjones.letterGrade())


            
        