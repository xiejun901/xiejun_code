#pragma once
//https://leetcode.com/problemset/algorithms/ ,Palindrome Linked List
#include"leetcode.h"
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr)
			return true;
		if (head->next == nullptr)
			return true;
		ListNode *slow=head, *fast=head;
		while (fast->next!=nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode *head2 = reverseList(slow->next);
		slow->next = nullptr;
		ListNode *n1 = head, *n2 = head2;
		while (n1 != nullptr&&n2 != nullptr)
		{
			if (n1->val != n2->val)
				return false;
			n1 = n1->next;
			n2 = n2->next;
		}
		return true;
	}
	ListNode * reverseList(ListNode* head)
	{
		if (head == nullptr)
			return nullptr;
		ListNode *p = head->next;
		head->next = nullptr;
		while (p)
		{
			ListNode *next = p->next;
			p->next = head;
			head = p;
			p = next;
		}
		return head;
	}
};