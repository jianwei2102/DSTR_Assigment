#pragma once
#include <string>
using namespace std;

struct ReplyNode {
    string Username, Reply;
    ReplyNode* NextReply;
};

class ReplyList {
public:
    ReplyNode* head = NULL;
    ReplyNode* tail = NULL;

    ReplyNode* createNewReplyNode(string Username, const string& Reply);

    void insertReplyIntoFeedback(string Username, const string& Reply);
};
