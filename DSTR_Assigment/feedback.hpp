#pragma once

#include "reply.hpp"
#include "user.hpp"

#include <string>
#include <ctime>

using namespace std;

class ReplyList; // forward declaration

struct UserNode;
struct FeedbackNode {
    string FeedbackID, UserID, Feedback, UserName;
    time_t CreateTime, UpdateTime;
    ReplyList* ReplyList;
    FeedbackNode* PrevFeedback;
    FeedbackNode* NextFeedback;
};

class Feedbacklist {
private:
    static int size;
public:
    FeedbackNode* head = NULL;
    FeedbackNode* tail = NULL;

    FeedbackNode* createNewFeedbackNode(string UserID, string Username, const string& Feedback, int id);

    FeedbackNode* getFeedbackNode(string FeedbackID);

    void insertIntoFeedbackList(UserNode* User, const string& Feedback);

    void insertIntoAllFeedbackList(FeedbackNode* NewFeedback);
    
    void sortFeedbackList();

    void deleteFeedbackNode(string feedbackID);

    void deleteAllFeedbackNode(string feedbackID);
};