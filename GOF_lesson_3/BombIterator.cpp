#include "BombIterator.h"

Bomb* BombIterator::operator++()
{
	for (; idx < refVec.size(); idx++)
	{
		Bomb* pBomb = dynamic_cast<Bomb*>(refVec[idx]);
		if (pBomb != nullptr)
		{
			bombIdx = idx++;
			check = true;
			return pBomb;

		}
	}

	check = false;

	return nullptr;
}

Bomb* BombIterator::operator--()
{
	for (; idx >= 0; idx--)
	{
		Bomb* pBomb = dynamic_cast<Bomb*>(refVec[idx]);
		if (pBomb != nullptr)
		{
			bombIdx = idx--;
			check = true;
			return pBomb;

		}
	}

	check = false;
	return nullptr;
}

Bomb* BombIterator::operator*()
{
	Bomb* pBomb = dynamic_cast<Bomb*>(refVec[bombIdx]);
	return pBomb;
}

bool BombIterator::checkIt()
{
	return check;
}