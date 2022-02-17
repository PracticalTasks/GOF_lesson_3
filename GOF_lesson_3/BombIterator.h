#pragma once
#include"SBomber.h"

class BombIterator
{
	std::vector<DynamicObject*>& refVec;
	int bombIdx;
	int idx;
	bool check;

public:
	BombIterator(std::vector<DynamicObject*>& _refVec) : refVec(_refVec), bombIdx(0), idx(0), check(false)
	{
		for (; idx < refVec.size(); idx++)
		{
			Bomb* pBomb = dynamic_cast<Bomb*>(refVec[idx]);
			if (pBomb != nullptr)
			{
				bombIdx = idx++;
				check = true;
				return;
			}
		}
	}

	Bomb* operator++ ();
	Bomb* operator-- ();
	Bomb* operator*();
	bool checkIt();

};
