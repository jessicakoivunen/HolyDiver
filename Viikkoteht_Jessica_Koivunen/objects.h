#pragma once
class Objects
{
private:
	int treasure = 0;

public:
	virtual int getTreasure() { return treasure; }
	inline int RestoreBattery() { return 5; }
	inline int RestoreOxygen() { return 5; }
	inline int GiveDamage() { return 5; }
	virtual void AddTreasure();
	virtual void ResetTreasure();
};