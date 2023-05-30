#include "reply.hpp"

ReplyNode* ReplyList::createNewReplyNode(string Username, const string& Reply) {
    ReplyNode* newReplyNode = new ReplyNode();
    newReplyNode->Username = Username;
    newReplyNode->Reply = Reply;
    newReplyNode->NextReply = NULL;

    return newReplyNode;
}

void ReplyList::insertReplyIntoFeedback(string Username, const string& Reply) {
    ReplyNode* newReplyNode = createNewReplyNode(Username, Reply);

    // If the list is empty, set the new node as the head and tail
    if (head == NULL) {
        head = newReplyNode;
        tail = newReplyNode;
    }
    // Otherwise, insert the new node at the end of the list
    else {
        tail->NextReply = newReplyNode;
        tail = newReplyNode;
    }
}
