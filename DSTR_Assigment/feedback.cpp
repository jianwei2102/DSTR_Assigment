#include "feedback.hpp"
#include "repository.h"

int Feedbacklist::size = 1;

FeedbackNode* Feedbacklist::createNewFeedbackNode(string UserID, string Username, const string& Feedback, int id) {
    // Create a new FeedbackNode
    FeedbackNode* newFeedback = new FeedbackNode();
    newFeedback->FeedbackID = "FB"+to_string(id);;
    newFeedback->UserID = UserID;
    newFeedback->UserName = Username;
    newFeedback->Feedback = Feedback;
    newFeedback->CreateTime = time(0);
    newFeedback->UpdateTime = time(0);
    newFeedback->ReplyList = new ReplyList; // For admin and user to reply
    newFeedback->PrevFeedback = NULL;
    newFeedback->NextFeedback = NULL;
    return newFeedback;
}

FeedbackNode* Feedbacklist::getFeedbackNode(string FeedbackID) {
    FeedbackNode* currentFeedback = head;
    
    // if not feedback available
    if (currentFeedback == NULL) {
        return NULL;
    }

    // Traverse the list to find a matching feedback
    while (currentFeedback != NULL) {
        if (currentFeedback->FeedbackID == FeedbackID) {
            return currentFeedback;
        }
        currentFeedback = currentFeedback->NextFeedback;
    }

    // If no matching feedback is found, return NULL
    return NULL;
}

void Feedbacklist::insertIntoFeedbackList(UserNode* User, const string& Feedback) {
    Repository* r = Repository::getInstance();
    Feedbacklist* AllFeedbackLists = r->AllFeedbackLists;

    // Retrieve new ID and add 1 to it
    int id = AllFeedbackLists->size;
    AllFeedbackLists->size += 1;

    // Create a new FeedbackNode
    FeedbackNode* newFeedback = createNewFeedbackNode(User->UserID, User->Username, Feedback, id);
    FeedbackNode* newAllFeedback = createNewFeedbackNode(User->UserID, User->Username, Feedback, id);

    // If the list is empty, set the new node as the head and tail
    if (head == NULL) {
        head = newFeedback;
        tail = newFeedback;

    }
    // Otherwise, insert the new node at the end of the list
    else {
        tail->NextFeedback = newFeedback;
        newFeedback->PrevFeedback = tail;
        tail = newFeedback;
    }

    insertIntoAllFeedbackList(newAllFeedback);
}

void Feedbacklist::insertIntoAllFeedbackList(FeedbackNode* NewFeedback) {
    Repository* r = Repository::getInstance();
    Feedbacklist* AllFeedbackLists = r->AllFeedbackLists;

    if (AllFeedbackLists == NULL) {
        AllFeedbackLists = new Feedbacklist;
    }

    // If the list is empty, set the new node as the head and tail
    if (AllFeedbackLists->head == NULL) {
        AllFeedbackLists->head = NewFeedback;
        AllFeedbackLists->tail = NewFeedback;
    }
    // Otherwise, insert the new node at the end of the list
    else {
        AllFeedbackLists->tail->NextFeedback = NewFeedback;
        NewFeedback->PrevFeedback = AllFeedbackLists->tail;
        AllFeedbackLists->tail = NewFeedback;
    }
}

void Feedbacklist::sortFeedbackList() {
    // if the list is empty or has only one element, no sorting needed
    if (head == nullptr || head->NextFeedback == nullptr) {
        return;
    }

    bool swapped;
    FeedbackNode* current;
    FeedbackNode* lastNode = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->NextFeedback != lastNode) {
            if (current->UpdateTime < current->NextFeedback->UpdateTime) {
                // Swap the nodes
                if (current == head) {
                    head = current->NextFeedback;
                }

                FeedbackNode* nextNode = current->NextFeedback;
                FeedbackNode* prevNode = current->PrevFeedback;
                FeedbackNode* nextNextNode = nextNode->NextFeedback;

                current->NextFeedback = nextNextNode;
                current->PrevFeedback = nextNode;
                nextNode->NextFeedback = current;
                nextNode->PrevFeedback = prevNode;

                if (prevNode != nullptr) {
                    prevNode->NextFeedback = nextNode;
                }

                if (nextNextNode != nullptr) {
                    nextNextNode->PrevFeedback = current;
                }

                swapped = true;
            }
            else {
                current = current->NextFeedback;
            }
        }

        tail = current;
    } while (swapped);
}