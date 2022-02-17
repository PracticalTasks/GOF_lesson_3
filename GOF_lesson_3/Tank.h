#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

//class Tank : public DestroyableGroundObject
//{
//public:
//
//	bool __fastcall isInside(double x1, double x2) const override;
//
//	inline uint16_t GetScore() const override { return score; }
//
//	void Draw() const override;
//
//private:
//
//	const uint16_t score = 30;
//};

class TankAdaptee {
public:

	TankAdaptee() : x(0.0), y(0.0), width(0) { }

	void Paint() const;
	bool isInRange(double x1, double x2) const;

	uint16_t GetScore() const { return score; }

	void SetPos(double nx, double ny) { x = nx; y = ny; }
	double GetY() const { return y; }
	double GetX() const { return x; }

	void SetWidth(uint16_t widthN) { width = widthN; }
	uint16_t GetWidth() const { return width; }

protected:

	double x, y;
	uint16_t width;
	const uint16_t score = 30;
};

class TankAdapter : public DestroyableGroundObject
{
private:
	TankAdaptee tank;

public:
	void SetPos(double nx, double ny) override;
	uint16_t GetWidth()const override;
	double GetY() const override;
	double GetX() const override;
	void SetWidth(uint16_t widthN) override;
	void Draw() const override;
	bool isInside(double x1, double x2) const override;
	uint16_t GetScore() const override;

};

