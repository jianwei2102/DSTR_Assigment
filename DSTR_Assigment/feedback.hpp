#pragma once
#include "reply.hpp"
#include "user.hpp"
#include <string>
#include <ctime>
using namespace std;

class ReplyList; // forward declaration
class UserList; // forward declaration

struct UserNode;
struct FeedbackNode {
    string FeedbackID, UserID, Feedback, UserName;
    time_t CreateTime, UpdateTime;  // UpdateTime need added for reply
    ReplyList* ReplyList;
    FeedbackNode* PrevFeedback;
    FeedbackNode* NextFeedback;
};

class Feedbacklist {
public:
    FeedbackNode* head = NULL;
    FeedbackNode* tail = NULL;

    // FeedbackID
    FeedbackNode* createNewFeedbackNode(string UserID, string Username, const string& Feedback);

    FeedbackNode* getFeedbackNode(string FeedbackID);

    void insertIntoFeedbackList(UserNode* User, const string& Feedback);

    void insertIntoAllFeedbackList(FeedbackNode* NewFeedback);
    
    void sortFeedbackList();

};