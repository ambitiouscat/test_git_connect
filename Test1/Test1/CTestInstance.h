#ifndef _CTEST_INSTANCE_H_
#define _CTEST_INSTANCE_H_

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class CTestInstance
{
public:
	static int num;
	static string name;


	int evalRPN(vector<string>& tokens)
	{
		if (tokens.empty())
			return 0;

		stack<int> runNumStack;
		int nResult = 0;
		int nLastNum = 0;
		EExepType nRunType = EET_ADD;

		for (int i = 0; i < tokens.size(); ++i)
		{
			string& temp = tokens.at(i);
			if (temp == "+")
				nRunType = EET_ADD;
			else if (temp == "*")
				nRunType = EET_CHENG;
			else if (temp == "/")
				nRunType = EET_CHU;
			else if (temp == "-")
				nRunType = EET_JIAN;
			else
			{
				runNumStack.push(atoi(tokens.at(i).c_str()));
				continue;
			}
			nLastNum = runNumStack.top();
			runNumStack.pop();
			nResult = runExep(runNumStack.top(), nLastNum, nRunType);
			runNumStack.pop();
			runNumStack.push(nResult);
		}
		return runNumStack.top();
		// write code here
	}

	enum EExepType
	{
		EET_ADD = 1,
		EET_JIAN,
		EET_CHENG,
		EET_CHU,
	};

	int runExep(int aNum, int bNum, EExepType eType)
	{
		switch (eType)
		{
		case EET_ADD:
			return aNum + bNum;
		case EET_JIAN:
			return aNum - bNum;
		case EET_CHENG:
			return aNum * bNum;
		case EET_CHU:
			return aNum / bNum;
		default:
			return 0;
		}
	}
};




#endif