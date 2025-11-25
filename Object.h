#pragma once
#include "HewStd.h"
class Object
{
protected:
	MakeFloat2 pos;
	MakeFloat2 size;
public:
	void Init();
	void Draw();
	void Uninit();
	MakeFloat2 GetPosition() const;
	void SetPosition(const MakeFloat2& newPos);
};