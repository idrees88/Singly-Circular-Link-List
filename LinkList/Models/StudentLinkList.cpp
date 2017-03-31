//
//  StudentLinkList.cpp
//  LinkList
//
//  Created by Eddie on 3/18/17.
//  Copyright © 2017 Idrees Ashraf. All rights reserved.
//

#include "StudentLinkList.hpp"
#include <iostream>

StudentLinkList::StudentLinkList() {
    this->head = nullptr;
    this->size = 0;
}

void StudentLinkList::addStudent(StudentData *studentData) {
    if (this->head == nullptr) {
        this->head = studentData;
        this->head->setNext(this->head);
        this->size++;
        return;
    }
    
    StudentData *traversePointer = this->head;
    while (traversePointer->getNext() != this->head) {
        traversePointer = traversePointer->getNext();
    }
    
    traversePointer->setNext(studentData);
    studentData->setNext(this->head);
    this->size++;
}

void StudentLinkList::addStudent(StudentData *studentData, int position) {
    if (position < 0 || position > this->size) {
        cout<<"addStudent/Error: Index out of bound"<<"\n";
        return;
    }
    
    StudentData *traversePointer = this->head;
    StudentData *backToTraversePointer = this->head;
    int currentPosition = 0;
    
    while (traversePointer != this->head) {
        if (currentPosition == position) {
            studentData->setNext(traversePointer);
            if (position == 0) {
                this->head = studentData;
            }
            else {
                backToTraversePointer->setNext(studentData);
            }
            
            this->size++;
            return;
        }
        backToTraversePointer = traversePointer;
        traversePointer = traversePointer->getNext();
        currentPosition++;
    }
}

void StudentLinkList::removeStudent(StudentData *studentData) {
    if (this->size == 0) {
        cout<<"removeStudent/Error: Student not found";
        return;
    }
    int count = 0;
    StudentData *traversePointer = this->head;
    StudentData *backTraversePointer = this->head;
    do {
        if (!traversePointer->getStudentName().compare(studentData->getStudentName())
            && !traversePointer->getStrudentTollNo().compare(studentData->getStrudentTollNo())) {
            if (count == 0) {
                StudentData *lastNode = this->head;
                while (lastNode->getNext() != this->head) {
                    lastNode = lastNode->getNext();
                }
                this->head = traversePointer->getNext();
                lastNode->setNext(this->head);
                delete traversePointer;
                traversePointer = nullptr;
                this->size--;
                return;
            }
            backTraversePointer->setNext(traversePointer->getNext());
            delete traversePointer;
            this->size--;
            return;
        }
        
        backTraversePointer = traversePointer;
        traversePointer = traversePointer->getNext();
        count++;
        
    }while (traversePointer->getNext() != this->head);
    
    cout<<"removeStudent/Error: Student not found in list";
}

void StudentLinkList::removeStudentAtPosition(int position) {
    if (position < 0 || position > this->size-1 || this->size == 0) {
        cout<<"Error: position is out of bound";
    }
    
    int count = 0;
    StudentData *traversePointer = this->head;
    StudentData *backToTraversePointer = this->head;
    
    do {
        if (count == position && count == 0) {
            StudentData *lastNode = this->head;
            while (lastNode->getNext() != this->head) {
                lastNode = lastNode->getNext();
            }
            this->head = traversePointer->getNext();
            delete traversePointer;
            traversePointer = nullptr;
            lastNode->setNext(this->head);
            this->size--;
            return;
        }
        else if(count == position) {
            backToTraversePointer->setNext(traversePointer->getNext());
            delete traversePointer;
            this->size--;
            return;
        }
        
        backToTraversePointer = traversePointer;
        traversePointer = traversePointer->getNext();
        count++;
        
    }while(traversePointer->getNext() != this->head);
    
    cout<<"removeStudentAtPosition/Error: Remove unsuccessful";
}

void StudentLinkList::removeLastStudent() {
    if (this->size == 0) {
        cout<<"removeLastStudent/Error: No student found";
        return;
    }
    
    StudentData *traversePointer = this->head;
    StudentData *backToTraversePointer = this->head;
    
    do {
        if (this->size == 1) {
            this->head = traversePointer->getNext();
            delete traversePointer;
            traversePointer = nullptr;
            this->size--;
            return;
        }
        backToTraversePointer = traversePointer;
        traversePointer = traversePointer->getNext();
    }while(traversePointer->getNext() != this->head);
    
    backToTraversePointer->setNext(traversePointer->getNext());
    delete traversePointer;
    traversePointer = nullptr;
    this->size--;
}

void StudentLinkList::removeAll() {
    StudentData *traversePointer = this->head;
    
    while (this->head != nullptr) {
        this->head = this->head->getNext();
        delete traversePointer;
        traversePointer = nullptr;
        traversePointer = this->head;
        this->size--;
    }
}

void StudentLinkList::printAllStudents() {
    StudentData *traversePointer = this->head;
    if (this->size > 0) {
        do {
            cout<<"Student Name: "<<traversePointer->getStudentName()<<"\n";
            cout<<"Student Roll No: "<<traversePointer->getStrudentTollNo()<<"\n";
            traversePointer = traversePointer->getNext();
        }while(traversePointer != nullptr);
    }
    
}






