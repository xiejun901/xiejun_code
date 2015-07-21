#pragma once
//https://leetcode.com/problemset/algorithms/  Basic Calculator II
#include"leetcode.h"
class Solution {
public:
	int calculate(string s) {
		stack<int> value_stack;
		stack<string> symbol_stack;
		auto strs = split(s);
		for (auto str : strs)
		{
			if (str == ")")
			{
				stack<int> value_stack_temp;
				stack<string> symbol_stack_temp;
				while (symbol_stack.top() != "(")
				{
					value_stack_temp.push(value_stack.top());
					value_stack.pop();
					symbol_stack_temp.push(symbol_stack.top());
					symbol_stack.pop();
				}
				value_stack_temp.push(value_stack.top());
				value_stack.pop();
				//symbol_stack_temp.push(symbol_stack.top());
				symbol_stack.pop();
				value_stack.push(calculate_without(value_stack_temp, symbol_stack_temp));
			}
			else if (str == "(" || str == "+" || str == "-")
				symbol_stack.push(str);
			else
				value_stack.push(stoi(str));
		}
		stack<int> value_stack_temp;
		stack<string> symbol_stack_temp;
		while (!value_stack.empty())
		{
			value_stack_temp.push(value_stack.top());
			value_stack.pop();
		}
		while (!symbol_stack.empty())
		{
			symbol_stack_temp.push(symbol_stack.top());
			symbol_stack.pop();
		}
		return calculate_without(value_stack_temp, symbol_stack_temp);

	}
	int calculate_without(stack<int> &value_stack, stack<string> &symbol_stack)
	{
		while (!symbol_stack.empty())
		{
			int value_left = value_stack.top();
			value_stack.pop();
			int value_right = value_stack.top();
			value_stack.pop();
			string symbol = symbol_stack.top();
			symbol_stack.pop();
			if (symbol == "+")
				value_stack.push(value_left + value_right);
			else
				value_stack.push(value_left - value_right);
		}
		return value_stack.top();
	}
	vector<string> split(const string &str)
	{
		int i = 0;
		int j = 0;
		vector<string> result;
		int n = str.length();
		while (j < n)
		{
			if (str[j] >= '0'&&str[j] <= '9')
			{
				j++;
			}
			else
			{
				string temp(str, i, j - i);
				if (temp != "")
					result.push_back(temp);
				i = j;
				while (i<n && (str[i] < '0' || str[i] > '9'))
				{
					if (str[i] != ' ')
						result.push_back(string(1, str[i]));
					i++;
				}
				j = i;
			}
		}
		string temp(str, i, j);
		if (temp != "")
			result.push_back(temp);
		return result;
	}
};