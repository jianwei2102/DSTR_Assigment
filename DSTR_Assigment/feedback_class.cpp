#include "feedback_class.hpp"
#include <ctime>

Feedbacklist* AllFeedbackLists = NULL;

FeedbackNode* Feedbacklist::createNewFeedbackNode(string UserID, string Feedback) {
    // Create a new FeedbackNode
    FeedbackNode* newFeedback = new FeedbackNode();
    newFeedback->FeedbackID = to_string(rand());;
    newFeedback->UserID = UserID;
    newFeedback->Feedback = Feedback;
    newFeedback->CreateTime = time(0);
    newFeedback->ReplyList = new ReplyList; // For admin and user to reply
    newFeedback->PrevFeedback = NULL;
    newFeedback->NextFeedback = NULL;

    return newFeedback;
}

FeedbackNode* Feedbacklist::getFeedbackNode(string FeedbackID) {
    // Traverse the list to find a matching feedback

    if (AllFeedbackLists == NULL) {
        return NULL;
    }
    FeedbackNode* currentFeedback = AllFeedbackLists->head;

    while (currentFeedback != NULL) {
        if (currentFeedback->FeedbackID == FeedbackID) {
            return currentFeedback;
        }
        currentFeedback = currentFeedback->NextFeedback;
    }

    // If no matching feedback is found, return NULL
    return NULL;
}

void Feedbacklist::insertIntoFeedbackList(UserNode* User, string Feedback) {
    // Create a new FeedbackNode
    FeedbackNode* newFeedback = createNewFeedbackNode(User->UserID, Feedback);
    
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
   
    insertIntoAllFeedbackList(newFeedback);
}

void Feedbacklist::insertIntoAllFeedbackList(FeedbackNode* NewFeedback) {
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
